#ifndef HAL_H
#define	HAL_H

#if defined(_18F26K80)
#include "pic18/pic18f26k80_hal.h"
#elif defined(ESP32)
#include "esp32/esp32_hal.h"
#else
#error Unsupported target chip
#endif

void hal_init();

void hal_stepper_pulse_period_engine_init();
void hal_stepper_pulse_period_engine_stop();
void hal_stepper_pulse_period_engine_start();
void hal_stepper_pulse_length_engine_init();
ISR(stepper_pulse_rising_edge);
ISR(stepper_pulse_falling_edge);

void hal_spindle_pwm_init();

ISR(limits_isr);

ISR(control_isr);

void hal_serial_init();
ISR(uart_tx_isr);
ISR(uart_rx_isr);

#endif	/* HAL_H */

