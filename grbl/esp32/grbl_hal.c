#include "grbl_hal.h"
#include "esp_attr.h"
#include "driver/gpio.h"


static void IRAM_ATTR hal_gpio_intr_service(void* arg) {
    //read status to get interrupt status for GPIO0-31
    uint32_t gpio_intr_status = GPIO.status;

	assert( LIMIT_DDR < 4 );		//Must be a GPIO < 32

	if ( gpio_intr_status & (LIMIT_MASK<<(LIMIT_DDR*8)) ) {
		limits_isr(arg);
		GPIO.status_w1tc = (LIMIT_MASK<<(LIMIT_DDR*8));
	}
}

static gpio_isr_handle_t gpio_isr_handle;

void hal_init() {
#if 0
	gpio_int_type_t int_type = bit_isfalse(settings.flags,BITFLAG_INVERT_LIMIT_PINS) ?
									GPIO_PIN_INTR_NEGEDGE :
									GPIO_PIN_INTR_POSEDGE;
#else
	gpio_int_type_t int_type = GPIO_PIN_INTR_NEGEDGE;
#endif

	ESP_CHECK(gpio_set_intr_type(X_LIMIT_BIT + (LIMIT_DDR*8), int_type));
	ESP_CHECK(gpio_set_intr_type(Y_LIMIT_BIT + (LIMIT_DDR*8), int_type));
	ESP_CHECK(gpio_set_intr_type(Z_LIMIT_BIT + (LIMIT_DDR*8), int_type));

	ESP_CHECK(gpio_isr_register(hal_gpio_intr_service, NULL,  ESP_INTR_FLAG_IRAM, &gpio_isr_handle));
}

