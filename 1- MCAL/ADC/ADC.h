/*
 * ADC.h
 *
 * Created: 6/23/2025 5:55:01 AM
 *  Author: ibrah
 */ 


#ifndef ADC_H_
#define ADC_H_


/***************Section:includes***************/
#include "../MCAL_STD_TYPES.h"
/***************Section:macro definitions***************/
/*******Definitions for user ******/

/**************volatage refernce selection*******/
/*
ADC_AREF_VOLTAGE_REF
ADC_AVCC_VOLTAGE_REF		//you should connect capcitor in AREF
ADC_2_56_VOLTAGE_REF		//you should connect capcitor in AREF
*/

/******ADC interrupt state******/
/*
ADC_INTERRUPT_ENABLED
ADC_INTERRUPT_DISABLED
*/

/******ADC prescaler*******/
/*
ADC_PRESCALER_DIV_2
ADC_PRESCALER_DIV_4
ADC_PRESCALER_DIV_8
ADC_PRESCALER_DIV_16
ADC_PRESCALER_DIV_32
ADC_PRESCALER_DIV_64
ADC_PRESCALER_DIV_128
*/

/**************volatage refernce selection*******/
#define ADC_AREF_VOLTAGE_REF		0
#define ADC_AVCC_VOLTAGE_REF		1/*you should connect capcitor in AREF*/
#define ADC_2_56_VOLTAGE_REF		2/*you should connect capcitor in AREF*/

/***************ADC result ADJUST*****************/

#define ADC_RIGHT_ADJUST_RESULT		1


/*******************ADC  analog channel selection*****/
#define ADC_0	0
#define ADC_1	1
#define ADC_2	2
#define ADC_3	3
#define ADC_4	4
#define ADC_5	5
#define ADC_6	6
#define ADC_7	7

/*********ADC state*****/
#define ADC_ENABLED	1
#define ADC_DISABLED	0

/*******ADC auto trigger state****/
#define ADC_AUTO_TRIGGER_ENABLED	1
#define ADC_AUTO_TRIGGER_DISABLED	0

/******ADC interrupt state******/
#define ADC_INTERRUPT_ENABLED	1
#define ADC_INTERRUPT_DISABLED	0


/******ADC prescaler*******/
#define ADC_PRESCALER_DIV_2		1
#define ADC_PRESCALER_DIV_4		2
#define ADC_PRESCALER_DIV_8		3
#define ADC_PRESCALER_DIV_16	4
#define ADC_PRESCALER_DIV_32	5
#define ADC_PRESCALER_DIV_64	6
#define ADC_PRESCALER_DIV_128	7



#define ADC_MAX_CHANNEL ADC_7



/***************Section:function like macro***************/



/***************Section:type definitions***************/

#if ADC_DRIVER_RUNTIME_CONFIG==ADC_CONFIG_ENABLED
typedef struct 
{
	uint8 ADC_prescaler				:3;
	uint8 ADC_voltage_refernce		:2;
	uint8 ADC_interrupt_state		:1;
}ADC_t;
#endif 
/***************Section:function decleratoins**************/
#if ADC_DRIVER_PREBUILD_CONFIG==ADC_CONFIG_ENABLED
STD_RETURN_TYPE ADC_config_file_init(void (*ADC_ISR_ptr)(void));
#endif 

#if ADC_DRIVER_RUNTIME_CONFIG==ADC_CONFIG_ENABLED
STD_RETURN_TYPE ADC_init(const ADC_t *ADC_obj);
#endif 
STD_RETURN_TYPE ADC_enable();
STD_RETURN_TYPE ADC_disable();
STD_RETURN_TYPE ADC_start_conversion_blocking(uint8 channel,uint16 *result);
STD_RETURN_TYPE ADC_start_conversion_nonblocking(uint8 channel);
STD_RETURN_TYPE ADC_read_conversion_result(uint16 *result);
STD_RETURN_TYPE ADC_send_conversion_completed_isr(void (*isr)(void));


/**note : in run time case used if you have more than one ADC in microcontroller so functions ADC_start_conversion ,
ADC_read_conversion and ... should pass adc_obj as a parameter but in ATMEGA32 we have just one and to make it more easier we didn't 
pass it */

#endif /* ADC_H_ */