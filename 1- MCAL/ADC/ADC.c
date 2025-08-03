/*
 * ADC.c
 *
 * Created: 6/23/2025 5:55:33 AM
 *  Author: ibrah
 */ 
#include "ADC.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "../Interrupt/GIE_INTERFACE.h"


static void (*ADC_ISR_PTR)(void);


#if ADC_DRIVER_PREBUILD_CONFIG==ADC_CONFIG_ENABLED
STD_RETURN_TYPE ADC_config_file_init(void (*ADC_ISR_ptr)(void))
{
	STD_RETURN_TYPE ret=E_OK;
	if (NULL==ADC_ISR_ptr)
	{
		ret=E_NOK;
	}
	else
	{
	#if ADC_STATE==ADC_ENABLED
	ADC_DISABLE();
	/*ADC settings*/
	#if (ADC_VALIDATE_VOLTAGE_REF(ADC_VOLTAGE_REF))&&(ADC_VALIDATE_PRESACLER(ADC_PRESCALER))
	ADC_SELECT_VOLTAFE_REF(ADC_VOLTAGE_REF);
	ADC_SELECT_PRESCALER(ADC_PRESCALER);
	ADC_SELECT_RIGHT_ADJUST_RESULT();
	/*ADC interrupt*/
	#if ADC_INTERRUPT_DISABLED==ADC_INTERRUPT_STATE
	ADC_INTERRUPT_DISABLE();
	#elif ADC_INTERRUPT_ENABLED==ADC_INTERRUPT_STATE
	ADC_ISR_PTR=ADC_ISR_ptr;
	GIE_ENABLE();
	ADC_INTERRUPT_ENABLE();
	/*ADC interrupt*/
	#else 
	ret=E_NOK;
	#endif 
	#else 
	ret=E_NOK;
	#endif 
	/*ADC settings*/
	ADC_ENABLE();
	#elif ADC_STATE==ADC_DISABLED
	ADC_DISABLE();
	#else 
	ret=E_NOK;
	#endif 	
	}
	return ret;
}
#endif

#if ADC_DRIVER_RUNTIME_CONFIG==ADC_CONFIG_ENABLED
STD_RETURN_TYPE ADC_init(const ADC_t *ADC_obj)
{
	STD_RETURN_TYPE ret=E_OK;
	if (NULL==ADC_obj)
	{
		ret=E_NOK;
	}
	else
	{
		if((ADC_VALIDATE_PRESACLER(ADC_obj->ADC_prescaler))&&(ADC_VALIDATE_VOLTAGE_REF(ADC_obj->ADC_voltage_refernce)))
		{
			ADC_DISABLE();
			ADC_SELECT_PRESCALER(ADC_obj->ADC_prescaler);
			ADC_SELECT_VOLTAFE_REF(ADC_obj->ADC_voltage_refernce);
			ADC_SELECT_RIGHT_ADJUST_RESULT();
			if(ADC_INTERRUPT_ENABLED==ADC_obj->ADC_interrupt_state)
			{
				GIE_ENABLE();
				ADC_INTERRUPT_ENABLE();
				ADC_ENABLE();
			}
			else if(ADC_INTERRUPT_DISABLED==ADC_obj->ADC_interrupt_state) 
			{
				ADC_INTERRUPT_DISABLE();
				ADC_ENABLE();
			}
			else
			{
				ret=E_NOK;
			}
		}
		else
		{
			ret=E_NOK;
		}
	}
	return ret;	
}
#endif
STD_RETURN_TYPE ADC_enable()
{
	STD_RETURN_TYPE ret=E_OK;
	ADC_ENABLE();
	return ret;
	
}
STD_RETURN_TYPE ADC_disable()
{
	STD_RETURN_TYPE ret=E_OK;
	ADC_DISABLE();
	return ret;
}
STD_RETURN_TYPE ADC_start_conversion_blocking(uint8 channel,uint16 *result)
{
	STD_RETURN_TYPE ret=E_OK;
	if((!ADC_VALIDATE_CHANNEL(channel))||(NULL==result))
	{
		ret=E_NOK;
	}
	else 
	{
		while(!ADC_CONVERSION_COMPLETED());
		ADC_SELECT_CHANNEL(channel);
		ADC_START_CONVERSION();
		while(!ADC_CONVERSION_COMPLETED());
		*result =ADC_READ_CONVERSION();
	}
	return ret;
}
STD_RETURN_TYPE ADC_start_conversion_nonblocking(uint8 channel)
{
	STD_RETURN_TYPE ret=E_OK;
	if((!ADC_VALIDATE_CHANNEL(channel))||(!ADC_CONVERSION_COMPLETED()))
	{
		ret=E_NOK;
	}
	else
	{
		ADC_SELECT_CHANNEL(channel);
		ADC_START_CONVERSION();
	}
	return ret;
}
STD_RETURN_TYPE ADC_read_conversion_result(uint16 *result)
{
	STD_RETURN_TYPE ret=E_OK;
	if(NULL==result)
	{
		ret=E_NOK;
	}
	else
	{
		*result=ADC_READ_CONVERSION();
	}
	return ret;
}

STD_RETURN_TYPE ADC_send_conversion_completed_isr(void (*isr)(void))
{
	STD_RETURN_TYPE ret=E_OK;
	if(NULL==isr)
	{
		ret=E_NOK;
	}
	else
	{
		ADC_ISR_PTR=isr;
	}
	return ret;
}

__attribute__((signal)) void __vector_16(void)
{
	if(ADC_ISR_PTR)
	{
		ADC_ISR_PTR();
	}
	
}