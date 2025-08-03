/*
 * ADC_register.h
 *
 * Created: 7/16/2025 12:31:34 AM
 *  Author: ibrah
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/***************Section:includes***************/


/***************Section:macro definitions***************/


/***************Section:function like macro***************/

/***************Section:type definitions***************/
typedef struct
{
	HWREG_t MUX			:5;
	HWREG_t ADLAR		:1;
	HWREG_t REFS		:2;
}ADMUX_BITS_t;

typedef union
{
	ADMUX_BITS_t ADMUX_BITS;
	HWREG_t ADMUX_ALL_BITS;
}ADMUX_t;

typedef struct
{
	HWREG_t ADPS	:3;
	HWREG_t ADIE	:1;
	HWREG_t ADIF	:1;
	HWREG_t ADATE	:1;
	HWREG_t ADSC	:1;
	HWREG_t ADEN	:1;
}ADCSRA_BITS_t;

typedef union
{
	ADCSRA_BITS_t ADCSRA_BITS;
	HWREG_t ADCSRA_ALL_BITS;
}ADCSRA_t;



typedef struct
{
	HWREG_t PSR10		:1;
	HWREG_t PSR2		:1;
	HWREG_t PUD			:1;
	HWREG_t ACME		:1;
	HWREG_t RESERVED	:1;
	HWREG_t	ADTS		:3;
}SFIOR_BITS_t;

typedef union
{
	SFIOR_BITS_t SFIOR_bits;
	HWREG_t SFIOR_ALL_BITS;
}SFIOR_t;
#define ADMUX				((volatile ADMUX_t*)(0x27))
#define ADCSRA				((volatile ADCSRA_t*)(0x26))
#define ADC_result_register *((volatile uint16*)(0x24))
#define SFIOR				((volatile SFIOR_t *)(0x50))

/***************Section:function decleratoins***************/




#endif /* ADC_REGISTER_H_ */