#include "hal.h"
#include "grbl.h"


void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; HFIOFS not stable; IDLEN disabled; IRCF 16MHz_HF; 
    OSCCON = 0x70;
    // SOSCGO disabled; MFIOSEL disabled; SOSCDRV Low Power; 
    OSCCON2 = 0x00;
    // INTSRC INTRC; PLLEN enabled; TUN 0; 
    OSCTUNE = 0x40;
    // ROSEL System Clock(FOSC); ROON disabled; ROSSLP Disabled in Sleep mode; RODIV Fosc; 
    REFOCON = 0x00;
}


void hal_init() {
  OSCILLATOR_Initialize();
  
  // PORTB pull-ups are enabled by individual port TRIS values
  INTCON2bits.RBPU = 0;
  
  // Configure RB0, RB1 and RB4 as digital PINs
  ANCON1bits.ANSEL8 = 0;
  ANCON1bits.ANSEL9 = 0;
  ANCON1bits.ANSEL10 = 0;
  
  // Enable Interrupt Priority Vectors
  RCONbits.IPEN = 1;
  
  // Enables all low-priority peripheral interrupts
  INTCONbits.PEIE = 1;
  
  // Enables all high-priority interrupts
  INTCONbits.GIE = 1;
  
  //Indicator 
  TRISCbits.TRISC5 = 0;
  LATCbits.LATC5 = 0;
  
  __delay_ms(1000);
}

/*
 * Original code:
 *  TCCR1B &= ~(1<<WGM13); // waveform generation = 0100 = CTC
 *  TCCR1B |=  (1<<WGM12);
 *  TCCR1A &= ~((1<<WGM11) | (1<<WGM10));
 *  TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0)); // Disconnect OC1 output
 */
void stepper_pulse_period_engine_init() {
  //************** Timer1 configuration
  // T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
  T1GCON = 0x00;
  
  //************** CCP5 configuration
  // CCPI - low priority
  IPR4bits.CCP5IP = 0;
  
  // CCP5 is based off of TMR1
  CCPTMRSbits.C5TSEL = 0;
  
  // CCP5M Compare mode: Special Event Trigger; 
  // reset timer on CCPx match (CCPxIF bit is set); DC2B 0; 
  CCP5CON = 0b00001011;
}

/*
 * Original code:
 *  Enable Stepper Driver Interrupt
 *  TIMSK1 |= (1<<OCIE1A);  
 */
void stepper_pulse_period_engine_start() {
  // Clear the CCP5 interrupt flag
  //PIR4bits.CCP5IF = 0;
  
  // Enable the CCP5 interrupt
  PIE4bits.CCP5IE = 1;
}

/*
 * Original code:
 *  TIMSK1 &= ~(1<<OCIE1A);         // Disable Timer1 interrupt
 *  TCCR1B = (TCCR1B & ~((1<<CS12) | (1<<CS11))) | (1<<CS10); // Reset clock to no prescaling.
 */
void stepper_pulse_period_engine_stop() {
  // Disable the CCP5 interrupt
  PIE4bits.CCP5IE = 0;
  
  // T1CKPS 1:1; RD16 disabled; SOSCEN disabled; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON enabled; 
  T1CON = 0x01;
}


/*
 * Original code:
 *  TIMSK0 &= ~((1<<OCIE0B) | (1<<OCIE0A) | (1<<TOIE0)); // Disconnect OC0 outputs and OVF interrupt.
 *  TCCR0A = 0; // Normal operation
 *  TCCR0B = 0; // Disable Timer0 until needed
 *  TIMSK0 |= (1<<TOIE0); // Enable Timer0 overflow interrupt
 */
void stepper_pulse_length_engine_init() {
  // TMRI - high priority
  INTCON2bits.TMR0IP = 1;
  
  // Clear Interrupt flag before enabling the interrupt
  INTCONbits.TMR0IF = 0;

  // Enabling TMR0 interrupt.
  INTCONbits.TMR0IE = 1;
  
  // T0PS 1:8; T08BIT 8-bit; T0SE Increment_hi_lo; T0CS FOSC/4; TMR0ON disabled; PSA assigned; 
  //T0CON = 0x58;
  T0CON = 0b01010010;
}

/*
 * Otiginal code:
 *  #define SPINDLE_TCCRA_INIT_MASK   ((1<<WGM20) | (1<<WGM21))  // Configures fast PWM mode.
 *  //#define SPINDLE_TCCRB_INIT_MASK   (1<<CS20)               // Disable prescaler -> 62.5kHz
 *  //#define SPINDLE_TCCRB_INIT_MASK   (1<<CS21)               // 1/8 prescaler -> 7.8kHz (Used in v0.9)
 *  //#define SPINDLE_TCCRB_INIT_MASK   ((1<<CS21) | (1<<CS20)) // 1/32 prescaler -> 1.96kHz
 *  #define SPINDLE_TCCRB_INIT_MASK   (1<<CS22)               // 1/64 prescaler -> 0.98kHz (J-tech laser)
 * 
 *  SPINDLE_TCCRA_REGISTER = SPINDLE_TCCRA_INIT_MASK; // Configure PWM output compare timer
 *  SPINDLE_TCCRB_REGISTER = SPINDLE_TCCRB_INIT_MASK;
 */
void spindle_pwm_init() {
  // Selecting Timer 2 for CCP2
  CCPTMRSbits.C2TSEL = 0;
    
  PR2 = 0xFF;   //Max: 3.90625 kHz at 64 MHz clock
  
  // T2CKPS 1:16; T2OUTPS 1:1; TMR2ON on; 
  T2CON = 0x06;     
}


void uart_init() {
  // disable interrupts before changing states
  PIE1bits.RC1IE = 0;
  PIE1bits.TX1IE = 0;
  
  // ABDOVF no_overflow; TXCKP async_noninverted_sync_fallingedge; BRG16 16bit_generator; WUE disabled; ABDEN disabled; RXDTP not_inverted; 
  BAUDCON1 = 0x08;
  
  // SPEN enabled; RX9 8-bit; RX9D 0; CREN enabled; ADDEN disabled; SREN disabled; 
  RCSTA1 = 0x90;
  
  // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC master_mode; 
  TXSTA1 = 0xA4;
  
  uint16_t bgr = ((_XTAL_FREQ/BAUD_RATE)/4)-1;
  SPBRGH1 = bgr >> 8;
  SPBRG1 = bgr;
  
  // TXI - low priority
  IPR1bits.TX1IP = 0;    

  // RCI - low priority
  IPR1bits.RC1IP = 0;    
  
  // enable receive interrupt
  PIE1bits.RC1IE = 1;
  
  // Transmission pin as output
  TRISCbits.TRISC6 = 0;
}


unsigned char eeprom_get_char( unsigned int addr )
{
    EEADRH = addr >> 8;
	EEADR = (unsigned char)(addr & 0xFF);
    EECON1bits.CFGS = 0;
    EECON1bits.EEPGD = 0;
    EECON1bits.RD = 1;
    NOP();  // NOPs may be required for latency at high frequencies
    NOP();
 
    return (EEDATA);
}


void eeprom_put_char( unsigned int addr, unsigned char new_value )
{
	unsigned char GIEBitValue = INTCONbits.GIE;

    EEADRH = addr >> 8;
    EEADR = (unsigned char)(addr & 0xFF);
    EEDATA = new_value;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;     // Disable interrupts
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    // Wait for write to complete
    while (EECON1bits.WR)
    {
    }

    EECON1bits.WREN = 0;
    INTCONbits.GIE = GIEBitValue;   // Restore interrupt enable
}

// interrupt handler
void interrupt high_priority_interrupt_manager() {
  if( (INTCONbits.TMR0IE==1) && (INTCONbits.TMR0IF==1) ) {
    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;
    
    stepper_pulse_falling_edge();
  }
}

// interrupt handler
void interrupt low_priority low_priority_interrupt_manager () {
  if( (PIE4bits.CCP5IE==1) && (PIR4bits.CCP5IF==1) ) {
    // Clear the CCP5 interrupt flag
    PIR4bits.CCP5IF = 0;
    
    stepper_pulse_rising_edge();
  }
  else if( (PIE1bits.TX1IE == 1) && (PIR1bits.TX1IF == 1) ) {
      uart_tx_isr();
  }
  else if( (PIE1bits.RC1IE == 1) && (PIR1bits.RC1IF == 1) ) {
      uart_rx_isr();
  }
  else if ( ((INTCON3bits.INT1IE == 1) && (INTCON3bits.INT1IF == 1)) ||
           ((INTCON3bits.INT2IE == 1) && (INTCON3bits.INT2IF == 1)) ||
           ((INTCON3bits.INT3IE == 1) && (INTCON3bits.INT3IF == 1)) )  {
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT2IF = 0;
    INTCON3bits.INT3IF = 0;
    limits_isr();
  }
  else if ( (INTCONbits.RBIE == 1) && (INTCONbits.RBIF == 1) )  {
    // Clear global Interrupt-On-Change flag
    INTCONbits.RBIF = 0;
    
    control_isr();
  }
}


void putch(char data) {
  serial_write(data);
}
