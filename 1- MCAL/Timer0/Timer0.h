/*
 * Timer0.h
 *
 * Created: 6/26/2025 6:47:04 AM
 *  Author: ibrah
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/***************Section:includes***************/

#include "../MCAL_STD_TYPES.h"
/***************Section:macro definitions***************/


/***************Section:function like macro***************/



/***************Section:type definitions***************/


/***************Section:function decleratoins***************/
STD_RETURN_TYPE TIMER0_confiG_file_init();
STD_RETURN_TYPE TIMER0_disable();
STD_RETURN_TYPE TIMER0_set_compare_value(uint8 compare_value);
STD_RETURN_TYPE TIMER0_set_duty_cycle(uint8 duty_cycle);
STD_RETURN_TYPE TIMER0_write_value(uint8 value);
STD_RETURN_TYPE TIMER0_send_overflow_isr(void (*ISR_ptr)(void));
STD_RETURN_TYPE TIMER0_send_compare_match_isr(void (*ISR_ptr)(void));
STD_RETURN_TYPE TIMER0_set_duty_cycle(uint8 duty_cycle);
#endif /* TIMER0_H_ */