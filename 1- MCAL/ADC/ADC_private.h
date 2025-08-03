/*
 * ADC_private.h
 *
 * Created: 6/23/2025 5:54:13 AM
 *  Author: ibrah
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/***************Section:includes***************/
#include "ADC_register.h"
#include "ADC.h"
/***************Section:macro definitions***************/


/******************ADC driver config********/
 #define ADC_CONFIG_ENABLED		1
 #define ADC_CONFIG_DISABLED	0

/***************Section:function like macro***************/
#define ADC_ENABLE()			(ADCSRA->ADCSRA_BITS.ADEN=ADC_ENABLED)
#define ADC_DISABLE()			(ADCSRA->ADCSRA_BITS.ADEN=ADC_DISABLED)

#define ADC_START_CONVERSION()	(ADCSRA->ADCSRA_BITS.ADSC=1)
#define ADC_CONVERSION_COMPLETED()	(0==ADCSRA->ADCSRA_BITS.ADSC)

#define ADC_INTERRUPT_ENABLE()	(ADCSRA->ADCSRA_BITS.ADIE=ADC_INTERRUPT_ENABLED)
#define ADC_INTERRUPT_DISABLE()	(ADCSRA->ADCSRA_BITS.ADIE=ADC_INTERRUPT_DISABLED)

#define ADC_READ_FLAG()			(ADCSRA->ADCSRA_BITS.ADIF)
#define ADC_CLEAR_FLAG()		(ADCSRA->ADCSRA_BITS.ADIF=1)

#define ADC_VALIDATE_PRESACLER(_PRESCALER_)		((ADC_PRESCALER_DIV_2<=_PRESCALER_)&&(ADC_PRESCALER_DIV_128>=_PRESCALER_))
#define ADC_SELECT_PRESCALER(_PRESCALER_)		(ADCSRA->ADCSRA_BITS.ADPS=_PRESCALER_)

#define ADC_VALIDATE_VOLTAGE_REF(_VOLTAGE_REF_)	((ADC_AREF_VOLTAGE_REF==_VOLTAGE_REF_)||(ADC_AVCC_VOLTAGE_REF==_VOLTAGE_REF_)||(ADC_2_56_VOLTAGE_REF==_VOLTAGE_REF_))
#define ADC_SELECT_VOLTAFE_REF(_VOLTAGE_REF_)	(ADMUX->ADMUX_BITS.REFS=_VOLTAGE_REF_)

#define ADC_SELECT_RIGHT_ADJUST_RESULT()				(ADMUX->ADMUX_BITS.ADLAR=0)

#define ADC_VALIDATE_CHANNEL(_CHANNEL_)					((ADC_0<=_CHANNEL_)&&(ADC_7>=_CHANNEL_))
#define ADC_SELECT_CHANNEL(_CHANNEL_)					(ADMUX->ADMUX_BITS.MUX=_CHANNEL_)

#define ADC_READ_CONVERSION()							(ADC_result_register)
/***************Section:type definitions***************/

/***************Section:function decleratoins***************/


#endif /* ADC_PRIVATE_H_ */