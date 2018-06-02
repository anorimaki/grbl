
#ifndef HAL_H
#define	HAL_H

#include "pic18f26k80_hal.h"

void hal_init();

void stepper_pulse_period_engine_init();
void stepper_pulse_period_engine_stop();
void stepper_pulse_period_engine_start();
void stepper_pulse_length_engine_init();
ISR(stepper_pulse_rising_edge);
ISR(stepper_pulse_falling_edge);

void spindle_pwm_init();

ISR(limits_isr);

ISR(control_isr);

void uart_init();
ISR(uart_tx_isr);
ISR(uart_rx_isr);

#endif	/* HAL_H */

