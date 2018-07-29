#ifndef ESP32_GRBL_HAL_H
#define ESP32_GRBL_HAL_H

#include "soc/gpio_reg.h"
#include "soc/io_mux_reg.h"
#include "soc/gpio_struct.h"
#include "soc/uart_struct.h"
#include "esp_attr.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/timer.h"
#include "soc/ledc_struct.h"
#include "soc/ledc_reg.h"
#include "driver/ledc.h"
#include "grbl_cpu_map.h"
#include "missing.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#ifdef __cplusplus
extern "C" {
#endif


/**********************************************************************/
//	GRBL entrypoint
/**********************************************************************/
#define main app_main


/**********************************************************************/
//	HAL Misc
/**********************************************************************/
#define ORIGINAL_F_CPU					16000000L

#define CALLED_FROM_ISR_ATTR	IRAM_ATTR

void hal_init();


/**********************************************************************/
// Hal eeprom
/**********************************************************************/
#ifndef pgm_read_byte_near		//Compatibility with Arduino esp32 framework
								// that defines this macro
#define pgm_read_byte_near(s) (*s)
#endif

#ifndef PSTR					//Compatibility with Arduino esp32 framework
								// that defines this macro
#define PSTR(v) (v)
#endif

unsigned char hal_eeprom_get_char(unsigned int addr);
void hal_eeprom_put_char(unsigned int addr, unsigned char new_value);
void hal_eeprom_commit();


/**********************************************************************/
//	HAL interrups
/**********************************************************************/
#define sei()
#define ISR(func) void IRAM_ATTR func(void* arg)


/**********************************************************************/
//	HAL IO
/**********************************************************************/
void hal_io_set_output_( uint64_t mask ); 
#define hal_io_set_output( index, mask ) hal_io_set_output_( mask << (index*8) )

void hal_io_set_input_( uint64_t mask );
#define hal_io_set_input( index, mask ) hal_io_set_input_( mask << (index*8) )

void hal_io_enable_pull_up_( uint64_t mask );
#define hal_io_enable_pull_up( index, mask ) hal_io_enable_pull_up_( mask << (index*8) )

void IRAM_ATTR hal_io_set( uint8_t index, uint8_t mask, uint8_t value);

#define hal_io_set_bit(index, bit) \
	hal_io_set(index, 1<<(bit), 1<<(bit))

#define hal_io_clr_bit(index, bit) \
	hal_io_set(index, 1<<(bit), 0)

#define hal_io_get(index, mask) \
	((index < 4) ? ((GPIO.in >> (index*8)) & mask) : (GPIO.in1.val & mask))


/**********************************************************************/
//	HAL limits
/**********************************************************************/
ISR(limits_isr);
void hal_limits_interrupts_enable();
void hal_limits_interrupts_disable();


/**********************************************************************/
//	HAL system
/**********************************************************************/
extern xSemaphoreHandle hal_system_mutex;

void hal_system_init();

#define hal_system_mutex_lock() \
	do {} while (xSemaphoreTake(hal_system_mutex, portMAX_DELAY) != pdPASS)

#define hal_system_mutex_unlock() \
	xSemaphoreGive(hal_system_mutex)

//Redefine name of system_init function to avoid conflicts with ESP-IDF
void grbl_system_init();
#define system_init grbl_system_init

ISR(control_isr);


/**********************************************************************/
//	HAL stepper
/**********************************************************************/
//This macro is only used for stepper timer settings.
//Redefine it's value to be equal to the original ATmega value to prevents overflows in 
// grbl variable types. 
//Stepper HAL functions will compensate this value.
#undef TICKS_PER_MICROSECOND
#define TICKS_PER_MICROSECOND 	(ORIGINAL_F_CPU/1000000)


/**********************************************************************/
//	HAL stepper pulse period
/**********************************************************************/
ISR(stepper_pulse_rising_edge);
void hal_stepper_pulse_period_engine_init();

#define hal_stepper_pulse_period_engine_stop() \
	TIMERG0.hw_timer[TIMER_0].config.enable = 0

#define hal_stepper_pulse_period_engine_start() \
	TIMERG0.hw_timer[TIMER_0].config.enable = 1

#define hal_stepper_pulse_period_set(value) \
	TIMERG0.hw_timer[TIMER_0].alarm_high = 0; \
    TIMERG0.hw_timer[TIMER_0].alarm_low = (uint32_t)value


/**********************************************************************/
//	HAL stepper pulse length
/**********************************************************************/
ISR(stepper_pulse_falling_edge);
void hal_stepper_pulse_length_engine_init();

#define hal_stepper_pulse_length_engine_start(value) \
	TIMERG0.hw_timer[TIMER_1].alarm_high = 0xFFFFFFFF; 	\
    TIMERG0.hw_timer[TIMER_1].alarm_low = ((int8_t)value-2); \
	TIMERG0.hw_timer[TIMER_1].reload = 1;				\
	TIMERG0.hw_timer[TIMER_1].config.enable = 1


/*
 * Original code:
 *  TCCR0B = 0; // Disable Timer0 to prevent re-entering this interrupt when it's not needed.
 */
#define hal_stepper_pulse_length_engine_stop() \
	TIMERG0.hw_timer[TIMER_1].config.enable = 0


/**********************************************************************/
//	HAL spindle pwm
/**********************************************************************/
void hal_spindle_pwm_init();

#define hal_spindle_pwm_enabled() \
	LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf0.sig_out_en

//From ESP-IDF ledc_update_duty
#define hal_spindle_pwm_enable() \
	LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf0.sig_out_en = 1; \
    LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf1.duty_start = 1;

//From ESP-IDF ledc_stop
#define hal_spindle_pwm_disable() \
	LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf0.idle_lv = 0;	\
    LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf0.sig_out_en = 0; \
    LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf1.duty_start = 0;

//From ESP-IDF ledc_set_duty and ledc_update_duty
#define hal_spindle_pwm_duty(value)   \
	LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].hpoint.hpoint = 0;		\
    LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].duty.duty = value;	\
    LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].conf1.val = \
														LEDC_DUTY_INC_HSCH0 |	\
														(1 << LEDC_DUTY_NUM_HSCH0_S) |	\
														(1 << LEDC_DUTY_CYCLE_HSCH0_S);


/**********************************************************************/
//	HAL serial comm
/**********************************************************************/
#define UART UART0

void hal_serial_init();

#define hal_serial_tx_interrupt_enable() \
	UART.int_ena.txfifo_empty = 1

#define hal_serial_tx_interrupt_disable() \
	UART.int_ena.txfifo_empty = 0

#define hal_serial_tx_interrupt_is_enabled() \
	UART.int_ena.txfifo_empty

#define hal_serial_send( c ) \
	UART.fifo.rw_byte = c;

uint8_t hal_serial_recv();

ISR(uart_tx_isr);
ISR(uart_rx_isr);


/**********************************************************************/
//	HAL sockets comm
/**********************************************************************/
void hal_socket_init();


/**********************************************************************/
//	HAL internals
/**********************************************************************/
#define LOG_TAG "grbl"

#define ESP_CHECK(expression) do{ \
		esp_err_t err = expression; \
		if (err != ESP_OK) { ESP_LOGE(LOG_TAG, "esp_error: %d", err); } 	\
	} while(0)


#ifdef __cplusplus
}
#endif

#endif