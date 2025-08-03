/*
 * Timer2.h
 *
 * Created: 6/26/2025 2:27:37 PM
 *  Author: ibrah
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

/***************Section:includes***************/
#include "../MCAL_STD_TYPES.h"
/***************Section:macro definitions***************/

/***************Section:function like macro***************/



/***************Section:type definitions***************/


/***************Section:function decleratoins***************/
STD_RETURN_TYPE TIMER2_confiG_file_init();
STD_RETURN_TYPE TIMER2_disable();
STD_RETURN_TYPE TIMER2_set_compare_value(uint8 compare_value);
STD_RETURN_TYPE TIMER2_write_value(uint8 value);
STD_RETURN_TYPE TIMER2_send_overflow_isr(void (*ISR_ptr)(void));
STD_RETURN_TYPE TIMER2_send_compare_match_isr(void (*ISR_ptr)(void));
STD_RETURN_TYPE TIMER2_set_duty_cycle(uint8 duty_cycle);


#endif /* TIMER2_H_ */