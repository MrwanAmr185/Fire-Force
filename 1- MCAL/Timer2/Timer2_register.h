/*
 * Timer2_register.h
 *
 * Created: 7/16/2025 12:41:25 AM
 *  Author: ibrah
 */ 


#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_
/***************Section:includes***************/


/***************Section:macro definitions***************/


/***************Section:function like macro***************/

/***************Section:type definitions***************/
typedef struct
{
	HWREG_t CS2			:3;
	HWREG_t WGM21		:1;
	HWREG_t COM2		:2;
	HWREG_t WGM20		:1;
	HWREG_t FOC2		:1;
}TCCR2_BITS_t;

typedef union
{
	TCCR2_BITS_t TCCR2_BITS;
	HWREG_t TCCR2_ALL_BITS;
}TCCR2_t;


#define TCCR2	((volatile TCCR2_t*)(0x45))
#define TCNT2	*((volatile uint8*)(0x44))
#define OCR2	*((volatile uint8*)(0x43))

/***************Section:function decleratoins***************/




#endif /* TIMER2_REGISTER_H_ */