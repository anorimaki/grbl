#ifndef PIC18F26K80_HAL_H
#define	PIC18F26K80_HAL_H
  
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define IO_SET_OUTPUT(tris, mask) tris &= ~(mask)
#define IO_SET_INPUT(tris, mask) tris |= mask

#define ISR(func) void func()
#define cli() INTCONbits.GIE = 0
#define sei() INTCONbits.GIE = 1
#define SREG INTCON

#define PSTR(v) v

#define pgm_read_byte_near(s) (*s)

#define _delay_ms(v) __delay_ms(v)

typedef union CCPR2Reg_tag {
  struct {
    uint8_t ccprl;
    uint8_t ccprh;
  };
  struct {
    uint16_t ccpr;
  };
} CCP_PERIOD_REG_T ;

/*
 * Original code:
 *  OCR1A = st.exec_segment->cycles_per_tick;
 */
#define stepper_pulse_period_set(value) \
  CCP_PERIOD_REG_T module;  \
  module.ccpr = value;      \
  CCPR5L = module.ccprl;    \
  CCPR5H = module.ccprh; 

/*
 * Original code:
 *  TCNT0 = st.step_pulse_time;  // Reload Timer0 counter
 *  TCCR0B = (1<<CS01);          // Begin Timer0. Full speed, 1/8 prescaler
 */
#define stepper_pulse_length_engine_start(value) \
  TMR0L = value;        \
  T0CONbits.TMR0ON = 1;

/*
 * Original code:
 *  TCCR0B = 0; // Disable Timer0 to prevent re-entering this interrupt when it's not needed.
 */
#define stepper_pulse_length_engine_stop() \
  T0CONbits.TMR0ON = 0;

/*
 * Original code:
 *  LIMIT_PCMSK |= LIMIT_MASK; // Enable specific pins of the Pin Change Interrupt
 *  PCICR |= (1 << LIMIT_INT); // Enable Pin Change Interrupt
 */
// INT1, INT2, INT3 Edge Select bit: Interrupt on falling edge
// INT3 External Interrupt Priority bit: low = 0
// --
// INT2 External Interrupt Priority bit: low = 0
// INT1 External Interrupt Priority bit: low = 0
// INT3 External Interrupt Enable bit: 1
// INT2 External Interrupt Enable bit: 1
// INT1 External Interrupt Enable bit: 1
// INT3 External Interrupt Flag bit: 0
// INT2 External Interrupt Flag bit: 0
// INT1 External Interrupt Flag bit: 0
#define limits_interrupts_enable() \
  INTCON2 &= 0b11000101;  \
  INTCON3 = 0b00111000;   \

/*
 * Original code:
 *  LIMIT_PCMSK &= ~LIMIT_MASK;  // Disable specific pins of the Pin Change Interrupt
 *  PCICR &= ~(1 << LIMIT_INT);  // Disable Pin Change Interrupt
 */
#define limits_interrupts_disable() \
  INTCON3 &= 0b11000111;    // Disable INT1, INT2 and INT3 External Interrupts

/*
 * Original code:
 *   CONTROL_PCMSK |= CONTROL_MASK;  // Enable specific pins of the Pin Change Interrupt
 *   PCICR |= (1 << CONTROL_INT);   // Enable Pin Change Interrupt
 */
#define system_interrupts_enable()  \
      /*Interrupt-on-Change PORTB Control bits: IOCB4-IOCB7 enabled */  \
  IOCB = 0xF0;                      \
      /*RB Port Change Interrupt Priority bit: Low priority*/ \
  INTCON2bits.RBIP = 0;             \
      /*RB Port Change Interrupt enbaled*/  \
  INTCONbits.RBIE = 1;

/*
 * Original code:
 *  (SPINDLE_TCCRA_REGISTER & (1<<SPINDLE_COMB_BIT)
 */
#define spindle_pwm_enabled() \
  (CCP2CON & 0x0C)

/*
 * Original code:
 *  SPINDLE_TCCRA_REGISTER |= (1<<SPINDLE_COMB_BIT); // Ensure PWM output is enabled.
 */
#define spindle_pwm_enable() \
  CCP2CON = 0x0C;   // CCP2M PWM; DC2B 0; 

/*
 * Original code:
 *  SPINDLE_TCCRA_REGISTER &= ~(1<<SPINDLE_COMB_BIT); // Disable PWM. Output voltage is zero.
 */
#define spindle_pwm_disable() \
  CCP2CON = 0;

/*
 * Original code:
 *  Enable Data Register Empty Interrupt to make sure tx-streaming is running
 *  UCSR0B |=  (1 << UDRIE0);
 */
#define uart_tx_interrupt_enable() \
  PIE1bits.TX1IE = 1;   /*Enable interrupt*/
  

/*
 * Original code:
 *  UCSR0B &= ~(1 << UDRIE0); 
 */
#define uart_tx_interrupt_disable() \
  PIE1bits.TX1IE = 0;

#define uart_tx_interrupt_is_enabled() \
  (PIE1bits.TX1IE==1)

/*
 * Original code:
 *  UDR0 = serial_tx_buffer[tail];
 */
#define uart_send(v) \
  TXREG1 = v;

#define UART_RCV_DATA RCREG1

#endif	/* PIC18F26K80_HAL_H */