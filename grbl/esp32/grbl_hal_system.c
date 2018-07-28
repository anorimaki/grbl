#include "grbl_hal.h"
#include "driver/gpio.h"

xSemaphoreHandle hal_system_mutex;

void hal_system_init() {
	hal_system_mutex = xSemaphoreCreateMutex();

    ESP_CHECK(gpio_intr_enable( CONTROL_RESET_BIT + (CONTROL_DDR*8) ));
	ESP_CHECK(gpio_intr_enable( CONTROL_FEED_HOLD_BIT + (CONTROL_DDR*8) ));
	ESP_CHECK(gpio_intr_enable( CONTROL_CYCLE_START_BIT + (CONTROL_DDR*8) ));
}

