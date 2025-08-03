/*
 * ADC_config.h
 *
 * Created: 6/23/2025 5:54:24 AM
 *  Author: ibrah
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/***************Section:includes***************/


/***************Section:macro definitions***************/

	
/****driver configuration*****/
/*
 ADC_CONFIG_ENABLED		
 ADC_CONFIG_DISABLED
 */		
#define ADC_DRIVER_PREBUILD_CONFIG		ADC_CONFIG_ENABLED
#define ADC_DRIVER_RUNTIME_CONFIG		ADC_CONFIG_ENABLED

/*********ADC state*****/
/*
#define ADC_ENABLED	
#define ADC_DISABLED	
*/

#define ADC_STATE	ADC_ENABLED


 

/**************volatage refernce selection*******/
/*
ADC_AREF_VOLTAGE_REF
ADC_AVCC_VOLTAGE_REF		//you should connect capcitor in AREF
ADC_2_56_VOLTAGE_REF		//you should connect capcitor in AREF
*/
#define ADC_VOLTAGE_REF		ADC_AVCC_VOLTAGE_REF
/***************ADC result ADJUST*****************/
/*
ADC_RIGHT_ADJUST_RESULT
*/

#define ADC_RESULT_ADJUST	ADC_RIGHT_ADJUST_RESULT

/*******ADC auto trigger state****/
/*
ADC_AUTO_TRIGGER_ENABLED	
ADC_AUTO_TRIGGER_DISABLED	
*/

#define ADC_AUTO_TRIGGER_STATE	ADC_AUTO_TRIGGER_DISABLED	

/******ADC interrupt state******/
/*
ADC_INTERRUPT_ENABLED	
ADC_INTERRUPT_DISABLED	
*/
#define ADC_INTERRUPT_STATE	ADC_INTERRUPT_ENABLED	

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

#define ADC_PRESCALER	ADC_PRESCALER_DIV_128


/***************Section:function like macro***************/

/***************Section:type definitions***************/

/***************Section:function decleratoins***************/




#endif /* ADC_CONFIG_H_ */