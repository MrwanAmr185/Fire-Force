/*
 * heart_rate.h
 *
 * Created: 7/23/2025 3:38:04 AM
 *  Author: ibrah
 */ 


#ifndef HEART_RATE_H_
#define HEART_RATE_H_

/***************Section:includes***************/
#include "../../MCAL/MCAL_STD_TYPES.h"

/***************Section:macro definitions***************/
#define OVERFLOW_TICKS 65535
#define BUSY_OPERATION 1
#define NOT_BUSY_OPERATION 0

/***************Section:function like macro***************/

/***************Section:type definitions***************/


/***************Section:function decleratoins***************/
STD_RETURN_TYPE Heart_rate_init(void);
STD_RETURN_TYPE Heart_rate_measure_freq_blocking(uint32 *freq);
STD_RETURN_TYPE Heart_rate_measure_nonblocking(uint32 *freq,uint8 *duty_cycle);
STD_RETURN_TYPE Heart_rate_measure_duty_cycle_blocking(uint8 *duty_cycle);





#endif /* HEART_RATE_H_ */