#include "grbl_hal.h"
#include "driver/ledc.h"

//Platformio uses old version of espidf framework that doesn't have this enum defined in 
// ledc_timer_bit_t. Remove it when it was updated.
const uint8_t LEDC_TIMER_8_BIT = 8;

void hal_spindle_pwm_init()
{
	ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_8_BIT, // resolution of PWM duty
        .freq_hz = 5000,                      // frequency of PWM signal
        .speed_mode = LEDC_HIGH_SPEED_MODE,           // timer mode
        .timer_num = LEDC_TIMER_0            // timer index
    };
    // Set configuration of timer0 for high speed channels
	ESP_CHECK(ledc_timer_config(&ledc_timer));

	ledc_channel_config_t ledc_channel = {
            .channel    = LEDC_CHANNEL_0,
            .duty       = 0,
            .gpio_num   = (SPINDLE_PWM_DDR*8) + SPINDLE_PWM_BIT,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .timer_sel  = LEDC_TIMER_0
	};
	ESP_CHECK(ledc_channel_config(&ledc_channel));

	hal_spindle_pwm_disable();
}

