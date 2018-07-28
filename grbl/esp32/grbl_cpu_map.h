#ifndef ESP32_CPU_MAP_H
#define ESP32_CPU_MAP_H

// Define step pulse output pins. NOTE: All step bit pins must be on the same byte.
#define STEP_DDR        3			//fourth byte
#define STEP_PORT		STEP_DDR
#define X_STEP_BIT      1  	// GPIO 25
#define Y_STEP_BIT      2  	// GPIO 26
#define Z_STEP_BIT      3  	// GPIO 27
#define STEP_MASK       ((1ULL<<X_STEP_BIT)|(1ULL<<Y_STEP_BIT)|(1ULL<<Z_STEP_BIT)) // All step bits

  // Define step direction output pins. NOTE: All direction pins must be on the same byte.
#define DIRECTION_DDR     1			//Second byte
#define DIRECTION_PORT    DIRECTION_DDR
#define X_DIRECTION_BIT   6  // GPIO 14
#define Y_DIRECTION_BIT   4  // GPIO 12
#define Z_DIRECTION_BIT   5  // GPIO 13
#define DIRECTION_MASK    ((1ULL<<X_DIRECTION_BIT)|(1ULL<<Y_DIRECTION_BIT)|(1ULL<<Z_DIRECTION_BIT)) 

  // Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_DDR    4
#define STEPPERS_DISABLE_PORT   STEPPERS_DISABLE_DDR
#define STEPPERS_DISABLE_BIT    1  // GPIO 33
#define STEPPERS_DISABLE_MASK   (1ULL<<STEPPERS_DISABLE_BIT)

// Define homing/hard limit switch input pins and limit interrupt vectors.
// NOTE: All limit bit pins must be on the same byte, but not on a byte with other input pins (CONTROL).
#define LIMIT_DDR		0			//fifth byte
#define LIMIT_PORT		LIMIT_DDR		
#define LIMIT_PIN		LIMIT_DDR
#define X_LIMIT_BIT		0  	// GPIO 0
#define Y_LIMIT_BIT		4  	// GPIO 4
#ifdef VARIABLE_SPINDLE // Z Limit pin and spindle enabled swapped to access hardware PWM on Pin 11.
	#define Z_LIMIT_BIT		5 	// GPIO 4
#else
	#define Z_LIMIT_BIT		5	// GPIO 5
#endif
#define LIMIT_MASK		((1ULL<<X_LIMIT_BIT)|(1ULL<<Y_LIMIT_BIT)|(1ULL<<Z_LIMIT_BIT))

 // Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_DDR    2
#define SPINDLE_ENABLE_PORT   SPINDLE_ENABLE_DDR
// Z Limit pin and spindle PWM/enable pin swapped to access hardware PWM on Pin 11.
#ifdef VARIABLE_SPINDLE
	#ifdef USE_SPINDLE_DIR_AS_ENABLE_PIN
		// If enabled, spindle direction pin now used as spindle enable, while PWM remains on D11.
		#define SPINDLE_ENABLE_BIT    7		// GPIO 23
	#else
		#define SPINDLE_ENABLE_BIT    7 	// GPIO 23
	#endif
#else
	#define SPINDLE_ENABLE_BIT    7  // GPIO 23
#endif
#ifndef USE_SPINDLE_DIR_AS_ENABLE_PIN
	#define SPINDLE_DIRECTION_DDR   2
	#define SPINDLE_DIRECTION_PORT  SPINDLE_DIRECTION_DDR
	#define SPINDLE_DIRECTION_BIT   2  // GPIO 18
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_DDR  2
#define COOLANT_FLOOD_PORT COOLANT_FLOOD_DDR
#define COOLANT_FLOOD_BIT  0	// GPIO 16
#define COOLANT_MIST_DDR   2
#define COOLANT_MIST_PORT  COOLANT_MIST_DDR
#define COOLANT_MIST_BIT   1	// GPIO 17

// Define user-control controls (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same byte and not on a byte with other input pins (limits).
#define CONTROL_DDR       2
#define CONTROL_PIN       CONTROL_DDR
#define CONTROL_PORT      CONTROL_DDR
#define CONTROL_RESET_BIT         5  // GPIO 21
#define CONTROL_FEED_HOLD_BIT     6  // GPIO 22
#define CONTROL_CYCLE_START_BIT   3  // GPIO 19
#define CONTROL_SAFETY_DOOR_BIT   6  // GPIO 22 NOTE: Safety door is shared with feed hold. Enabled by config define.
//#define CONTROL_INT       PCIE1  // Pin change interrupt enable pin
//#define CONTROL_INT_vect  PCINT1_vect
//#define CONTROL_PCMSK     PCMSK1 // Pin change interrupt register
#define CONTROL_MASK      ((1ULL<<CONTROL_RESET_BIT)|(1ULL<<CONTROL_FEED_HOLD_BIT)|(1ULL<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))
#define CONTROL_INVERT_MASK   CONTROL_MASK // May be re-defined to only invert certain control pins.

// Define probe switch input pin.
#define PROBE_DDR       4
#define PROBE_PIN       PROBE_DDR
#define PROBE_PORT      PROBE_DDR
#define PROBE_BIT       0  // GPIO 32
#define PROBE_MASK      (1ULL<<PROBE_BIT)

// Variable spindle configuration below. Do not change unless you know what you are doing.
// NOTE: Only used when variable spindle is enabled.
#define SPINDLE_PWM_MAX_VALUE     255 // Don't change. 328p fast PWM mode fixes top value as 255.
#ifndef SPINDLE_PWM_MIN_VALUE
#define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
#endif
#define SPINDLE_PWM_OFF_VALUE     0
#define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)
//#define SPINDLE_TCCRA_REGISTER	  TCCR2A
//#define SPINDLE_TCCRB_REGISTER	  TCCR2B
//#define SPINDLE_OCR_REGISTER      CCPR2L
//#define SPINDLE_COMB_BIT	        COM2A1

// Prescaled, 8-bit Fast PWM mode.
//#define SPINDLE_TCCRA_INIT_MASK   ((1<<WGM20) | (1<<WGM21))  // Configures fast PWM mode.
// #define SPINDLE_TCCRB_INIT_MASK   (1<<CS20)               // Disable prescaler -> 62.5kHz
// #define SPINDLE_TCCRB_INIT_MASK   (1<<CS21)               // 1/8 prescaler -> 7.8kHz (Used in v0.9)
// #define SPINDLE_TCCRB_INIT_MASK   ((1<<CS21) | (1<<CS20)) // 1/32 prescaler -> 1.96kHz
//#define SPINDLE_TCCRB_INIT_MASK      (1<<CS22)               // 1/64 prescaler -> 0.98kHz (J-tech laser)

// NOTE: On the 328p, these must be the same as the SPINDLE_ENABLE settings.
#define SPINDLE_PWM_DDR	  1
#define SPINDLE_PWM_PORT    SPINDLE_PWM_DDR
#define SPINDLE_PWM_BIT	  7    // GPIO 15

#endif

