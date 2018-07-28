#include "grbl_hal.h"
#include "driver/gpio.h"

void hal_limits_interrupts_enable() {
    ESP_CHECK(gpio_intr_enable( X_LIMIT_BIT + (LIMIT_DDR*8) ));
	ESP_CHECK(gpio_intr_enable( Y_LIMIT_BIT + (LIMIT_DDR*8) ));
	ESP_CHECK(gpio_intr_enable( Z_LIMIT_BIT + (LIMIT_DDR*8) ));
}

void hal_limits_interrupts_disable() {
    ESP_CHECK(gpio_intr_disable( X_LIMIT_BIT + (LIMIT_DDR*8) ));
	ESP_CHECK(gpio_intr_disable( Y_LIMIT_BIT + (LIMIT_DDR*8) ));
	ESP_CHECK(gpio_intr_disable( Z_LIMIT_BIT + (LIMIT_DDR*8) ));
}
