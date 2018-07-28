#include "grbl_hal.h"
#include "driver/timer.h"

#define STEPPER_PULSE_PERIOD_TIMER_DIVIDER		(TIMER_BASE_CLK/ORIGINAL_F_CPU)
#define STEPPER_PULSE_LENGTH_TIMER_DIVIDER		(STEPPER_PULSE_PERIOD_TIMER_DIVIDER*8)

void IRAM_ATTR stepper_pulse_rising_edge_(void* dummy) {
	stepper_pulse_rising_edge(NULL);

	TIMERG0.int_clr_timers.t0 = 1;
	/* After the alarm has been triggered
      we need enable it again, so it is triggered the next time */
	TIMERG0.hw_timer[TIMER_0].config.alarm_en = TIMER_ALARM_EN;
}

void hal_stepper_pulse_period_engine_init() {
	timer_config_t config;
    config.divider = STEPPER_PULSE_PERIOD_TIMER_DIVIDER;
    config.counter_dir = TIMER_COUNT_UP;
    config.counter_en = TIMER_PAUSE;
    config.alarm_en = TIMER_ALARM_EN;
    config.intr_type = TIMER_INTR_LEVEL;
    config.auto_reload = true;
	ESP_CHECK(timer_init(TIMER_GROUP_0, TIMER_0, &config));

	//AutoReload value on alarm
	ESP_CHECK(timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0x00000000ULL));

	// Configure the alarm value and the interrupt on alarm. 
    ESP_CHECK(timer_enable_intr(TIMER_GROUP_0, TIMER_0));
    ESP_CHECK(timer_isr_register(TIMER_GROUP_0, TIMER_0, stepper_pulse_rising_edge_,
							 NULL, ESP_INTR_FLAG_IRAM, NULL));
}


void IRAM_ATTR stepper_pulse_falling_edge_(void* dummy) {
	stepper_pulse_falling_edge(NULL);
	TIMERG0.int_clr_timers.t1 = 1;
	TIMERG0.hw_timer[TIMER_1].config.alarm_en = TIMER_ALARM_EN;
}


void hal_stepper_pulse_length_engine_init() {
	timer_config_t config;
    config.divider = STEPPER_PULSE_LENGTH_TIMER_DIVIDER;
    config.counter_dir = TIMER_COUNT_DOWN;
    config.counter_en = TIMER_PAUSE;
    config.alarm_en = TIMER_ALARM_EN;
    config.intr_type = TIMER_INTR_LEVEL;
    config.auto_reload = true;
	ESP_CHECK(timer_init(TIMER_GROUP_0, TIMER_1, &config));

	ESP_CHECK(timer_set_counter_value(TIMER_GROUP_0, TIMER_1, 0xFFFFFFFFFFFFFFFFULL));

	//Fifed alarm at 0. Value of hal_stepper_pulse_length_engine_start is negative.
//	ESP_CHECK(timer_set_alarm_value(TIMER_GROUP_0, TIMER_1, 0xFFFFFFFFFFFFFFFFULL));
//	ESP_CHECK(timer_set_alarm(TIMER_GROUP_0, TIMER_1, TIMER_ALARM_EN));

	// Configure the alarm value and the interrupt on alarm. 
    ESP_CHECK(timer_enable_intr(TIMER_GROUP_0, TIMER_1));
    ESP_CHECK(timer_isr_register(TIMER_GROUP_0, TIMER_1, stepper_pulse_falling_edge_,
			 NULL, ESP_INTR_FLAG_IRAM, NULL));
}