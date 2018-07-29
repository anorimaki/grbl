#include "grbl_hal.h"
#include "esp_attr.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "freertos/task.h"


static void IRAM_ATTR hal_gpio_intr_service(void* arg) {
    //read status to get interrupt status for GPIO0-31
    uint32_t gpio_intr_status = GPIO.status;

	assert( LIMIT_DDR < 4 );		//Must be a GPIO < 32
	assert( CONTROL_DDR < 4 );		//Must be a GPIO < 32

	if ( gpio_intr_status & (LIMIT_MASK<<(LIMIT_DDR*8)) ) {
		limits_isr(arg);
		GPIO.status_w1tc = (LIMIT_MASK<<(LIMIT_DDR*8));
	}
	else if ( gpio_intr_status & (CONTROL_MASK<<(CONTROL_DDR*8)) ) {
		control_isr(arg);
		GPIO.status_w1tc = (CONTROL_MASK<<(CONTROL_DDR*8));
	}
}


static void disable_wdt_of_cpu0() {
	TaskHandle_t idle_0 = xTaskGetIdleTaskHandleForCPU(0);
	ESP_CHECK(esp_task_wdt_delete(idle_0));
}


static gpio_isr_handle_t gpio_isr_handle;

void hal_init() {
	disable_wdt_of_cpu0();

	//gpio_int_type_t int_type = GPIO_PIN_INTR_ANYEDGE;
	gpio_int_type_t int_type = GPIO_PIN_INTR_NEGEDGE;

	ESP_CHECK(gpio_set_intr_type(X_LIMIT_BIT + (LIMIT_DDR*8), int_type));
	ESP_CHECK(gpio_set_intr_type(Y_LIMIT_BIT + (LIMIT_DDR*8), int_type));
	ESP_CHECK(gpio_set_intr_type(Z_LIMIT_BIT + (LIMIT_DDR*8), int_type));

	ESP_CHECK(gpio_set_intr_type( CONTROL_RESET_BIT + (CONTROL_DDR*8), int_type ));
	ESP_CHECK(gpio_set_intr_type( CONTROL_FEED_HOLD_BIT + (CONTROL_DDR*8), int_type ));
	ESP_CHECK(gpio_set_intr_type( CONTROL_CYCLE_START_BIT + (CONTROL_DDR*8), int_type ));

	ESP_CHECK(gpio_isr_register(hal_gpio_intr_service, NULL,  0, &gpio_isr_handle));
}

