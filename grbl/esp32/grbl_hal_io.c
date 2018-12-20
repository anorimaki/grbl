#include "grbl_hal.h"
#include "driver/gpio.h"
#include "../print.h"

void hal_io_set_output_( uint64_t mask ) {
	uint32_t io_num = 0;
	do {
        if ( (mask >> io_num) & BIT(0) ) {	
			gpio_pulldown_dis(io_num);
			gpio_pullup_dis(io_num);
			gpio_set_direction(io_num, GPIO_MODE_INPUT_OUTPUT);
			PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[io_num], PIN_FUNC_GPIO);
        }
        io_num++;
    } while (io_num < GPIO_PIN_COUNT);
}

void hal_io_set_input_( uint64_t mask ) {
	uint32_t io_num = 0;
	do {
        if ( (mask >> io_num) & BIT(0) ) {	
			gpio_pulldown_dis(io_num);
			gpio_pullup_dis(io_num);
			gpio_set_direction(io_num, GPIO_MODE_DEF_INPUT);
			PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[io_num], PIN_FUNC_GPIO);
        }
        io_num++;
    } while (io_num < GPIO_PIN_COUNT); 
}

void hal_io_enable_pull_up_( uint64_t mask ) {
	uint32_t io_num = 0;
	do {
        if ( (mask >> io_num) & BIT(0) ) {	
            gpio_pullup_en((gpio_num_t)io_num);
        }
        io_num++;
    } while (io_num < GPIO_PIN_COUNT);
}

void IRAM_ATTR hal_io_set( uint8_t index, uint8_t mask, uint8_t value) {
	if ( index < 4)	 {	//GPIO: 0..31 
		uint32_t mask32 = mask;
		uint32_t value32 = value & mask;

		int bits_to_shift = index << 3;
		mask32 <<= bits_to_shift;
		value32 <<= bits_to_shift;

		GPIO.out = (GPIO.out & ~mask32) | value32;
	}
	else {				//GPIO: 32..39 (index == 5)
		GPIO.out1.val = (GPIO.out1.val & ~mask) | value;
	}
}

