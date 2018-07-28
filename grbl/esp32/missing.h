#ifndef MISSING_H
#define	MISSING_H

#include "rom/ets_sys.h"

#define _delay_us(v) \
	ets_delay_us(v)

#define _delay_ms(v) \
	ets_delay_us(v*1000)

#endif