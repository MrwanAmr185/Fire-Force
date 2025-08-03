/*
 * TCRT5000.h
 *
 * Created: 7/21/2025 1:37:45 AM
 *  Author: ibrah
 */ 


#ifndef TCRT_H_
#define TCRT_H_

/***************Section:includes***************/
#include "../../MCAL/MCAL_STD_TYPES.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO_interface.h"
/***************Section:macro definitions***************/

/***************Section:function like macro***************/

/***************Section:type definitions***************/
typedef struct 
{
	uint8 port;
	uint8 pin;
	ADC_t TCRT_ADC;	
	uint8 TCRT_ADC_channel;
}TCRT_t;


/***************Section:function decleratoins***************/
STD_RETURN_TYPE TCRT_init(const TCRT_t *TCRT_obj);
STD_RETURN_TYPE TCRT_read_digital_value(const TCRT_t *TCRT_obj,uint8 *logic);
STD_RETURN_TYPE TCRT_read_analog_value_blocking(const TCRT_t *TCRT_obj,uint16 *analog_value);
STD_RETURN_TYPE TCRT_read_analog_value_nonblocking(const TCRT_t *TCRT_obj,uint16 *analog_value_ptr);
STD_RETURN_TYPE TCRT_read_values_blocking(const TCRT_t *TCRT_obj,uint8 *logic,uint16 *analog_value);
STD_RETURN_TYPE TCRT_read_values_nonblocking(const TCRT_t *TCRT_obj,uint8 *logic,uint16 *analog_value_ptr);

#endif /* TCRT_H_ */