/*
 * TCRT5000.c
 *
 * Created: 7/21/2025 1:37:58 AM
 *  Author: ibrah
 */ 
#include "TCRT.h"
volatile uint8 debug_flag=0;
static uint16 *TCRT_analog_value_ptr=NULL;
void TCRT_get_analog_value_nonblocking(void);
STD_RETURN_TYPE TCRT_init(const TCRT_t *TCRT_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==TCRT_obj)
    {
        ret=E_NOK;
    }
    else
    {
        /*initializing pin with direction and initial state*/
       ret=(ret)&&(DIO_set_pin_direction(TCRT_obj->port,TCRT_obj->pin,DIO_uint8PIN_INPUT));
        ret=(ret)&&(DIO_set_pin_logic(TCRT_obj->port,TCRT_obj->pin,DIO_uint8PIN_LOW));

        /*initializing ADC cofigurations*/
        ret=ADC_init(&(TCRT_obj->TCRT_ADC));
    }
    return ret;
}
STD_RETURN_TYPE TCRT_read_digital_value(const TCRT_t *TCRT_obj,uint8 *logic)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==TCRT_obj)||(NULL==logic))
    {
        ret=E_NOK;
    }
    else
    {
        ret=DIO_read_pin_logic(TCRT_obj->port,TCRT_obj->pin,logic);
    }
    return ret;
}
STD_RETURN_TYPE TCRT_read_analog_value_blocking(const TCRT_t *TCRT_obj,uint16 *analog_value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==TCRT_obj)
    {
        ret=E_NOK;
    }
    else
    {
		ret=ADC_start_conversion_blocking(TCRT_obj->TCRT_ADC_channel,analog_value);   
    }
    return ret;
}
STD_RETURN_TYPE TCRT_read_analog_value_nonblocking(const TCRT_t *TCRT_obj,uint16 *analog_value_ptr)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==TCRT_obj)||(NULL==analog_value_ptr))
    {
        ret=E_NOK;
    }
    else
    {
        ret=(ret)&&(ADC_send_conversion_completed_isr(TCRT_get_analog_value_nonblocking));
		TCRT_analog_value_ptr=analog_value_ptr;
        ret=(ret)&&(ADC_start_conversion_nonblocking(TCRT_obj->TCRT_ADC_channel));
    }
    return ret;
}
STD_RETURN_TYPE TCRT_read_values_blocking(const TCRT_t *TCRT_obj,uint8 *logic,uint16 *analog_value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==TCRT_obj)
    {
        ret=E_NOK;
    }
    else
    {
        ret=TCRT_read_digital_value(TCRT_obj,logic);
        ret=(ret)&&(TCRT_read_analog_value_blocking(TCRT_obj,analog_value));
    }
    return ret;
}
STD_RETURN_TYPE TCRT_read_values_nonblocking(const TCRT_t *TCRT_obj,uint8 *logic,uint16 *analog_value_ptr)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==TCRT_obj)
    {
        ret=E_NOK;
    }
    else
    {
        ret=TCRT_read_digital_value(TCRT_obj,logic);
        ret=(ret)&&(TCRT_read_analog_value_nonblocking(TCRT_obj,analog_value_ptr));
    }
    return ret;
}



void TCRT_get_analog_value_nonblocking(void)
{

    if(TCRT_analog_value_ptr)
    {
		debug_flag=1;
        ADC_read_conversion_result(TCRT_analog_value_ptr);
    }
}