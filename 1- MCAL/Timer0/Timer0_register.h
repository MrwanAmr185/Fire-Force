/*
 * Timer0_register.h
 *
 * Created: 7/16/2025 12:37:37 AM
 *  Author: ibrah
 */ 


#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_


/***************Section:includes***************/


/***************Section:macro definitions***************/


/***************Section:function like macro***************/

/***************Section:type definitions***************/
typedef struct
{
	HWREG_t CS0			:3;
	HWREG_t WGM01		:1;
	HWREG_t COM0		:2;
	HWREG_t WGM00		:1;
	HWREG_t FOC0		:1;
}TCCR0_BITS_t;

typedef union
{
	TCCR0_BITS_t TCCR0_BITS;
	HWREG_t TCCR0_ALL_BITS;
}TCCR0_t;


typedef struct
{
	HWREG_t TOIE0	:1;
	HWREG_t OCIE0	:1;
	HWREG_t TOIE1	:1;
	HWREG_t OCIE1B	:1;
	HWREG_t OCIE1A	:1;
	HWREG_t TICIE1	:1;
	HWREG_t TOIE2	:1;
	HWREG_t OCIE2	:1;
}TIMSK_BITS_t;

typedef union
{
	TIMSK_BITS_t TIMSK_BITS;
	HWREG_t TIMSK_ALL_BITS;
}TIMSK_t;

typedef struct
{
	HWREG_t TOV0	:1;
	HWREG_t OCF0	:1;
	HWREG_t TOV1	:1;
	HWREG_t OCF1B	:1;
	HWREG_t OCF1A	:1;
	HWREG_t ICF1	:1;
	HWREG_t TOV2	:1;
	HWREG_t OCF2	:1;
}TIFR_BITS_t;
typedef union
{
	TIFR_BITS_t TIFR_BITS;
	HWREG_t TIFR_ALL_BITS;
}TIFR_t;


#define TCCR0	((volatile TCCR0_t*)(0x53))
#define TIMSK	((volatile TIMSK_t*)(0x59))
#define TIFR	((volatile TIFR_t*)(0x58))
#define TCNT0	*((volatile HWREG_t*)(0x52))
#define OCR0	*((volatile HWREG_t*)(0x5C))

/***************Section:function decleratoins***************/


#endif /* TIMER0_REGISTER_H_ */