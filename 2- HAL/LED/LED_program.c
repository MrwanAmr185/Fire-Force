/************************************************************************/
/************************************************************************/
/*******************        Author: Mrwan Amr      **********************/
/*******************        Layer:  HAL            **********************/
/*******************        SWC:    LED            **********************/
/*******************        Version:1.00           **********************/
/************************************************************************/
/************************************************************************/

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../MCAL/MCAL_STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_config.h"
#include "LED_inerface.h"
#include "LED_private.h"


/*
Function to set the state of a LED.
Description: This function check if the led is connected by source or sink way then the state the user want then set the value of the pin.
Parameters: It takes struct containing port,pin, and connection state(source or sink), then the state the user needs (ON or OFF).
Return: Local_uint8ErrorState to check if there is error or not (0 => No error		1 => There is an error).
*/
uint8 LED_uint8State (LED_t* Copy_pLED_t1, uint8 Copy_uint8LEDState)
{
	uint8 Local_uint8ErrorState=0; 
	
	if (Copy_pLED_t1->Conn_Type == LED_uint8Source)
	{
		if (Copy_uint8LEDState == LED_uint8ON)
		{
			 DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_HIGH);
		}
		else if (Copy_uint8LEDState == LED_uint8OFF)
		{
			 DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_LOW);
		}
		else
		{
			Local_uint8ErrorState = 1;
		}
	}
	else if (Copy_pLED_t1->Conn_Type == LED_uint8Sink)
	{
		if (Copy_uint8LEDState == LED_uint8ON)
		{
			 DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_LOW);
		}
		else if (Copy_uint8LEDState == LED_uint8OFF)
		{
			DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_HIGH);
		}
		else
		{
			Local_uint8ErrorState = 1;
		}
	}
	else
	{
		Local_uint8ErrorState = 1;
	}
	
	return Local_uint8ErrorState;
}


/*
Function to toggle a LED.
Description: This function check if the led is connected by source or sink,then toggle the LED according to the time entered by the user.
Parameters: It takes struct containing port,pin, and connection state(source or sink), then the delay time the user wants to toggle the LED.
Return: Local_uint8ErrorState to check if there is error or not (0 => No error		1 => There is an error).
*/
uint8 LED_uint8Toggle (LED_t* Copy_pLED_t1)
{
	uint8 Local_uint8ErrorState=0;
	
	if (Copy_pLED_t1->Conn_Type == LED_uint8Source)
	{
			DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_HIGH);
			_delay_ms(delay);
			DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_LOW);
			_delay_ms(delay);
	}
	else if (Copy_pLED_t1->Conn_Type == LED_uint8Sink)
	{
			DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_LOW);
			_delay_ms(delay);
			DIO_set_pin_logic( Copy_pLED_t1->Port, Copy_pLED_t1->Pin, DIO_uint8PIN_HIGH);
			_delay_ms(delay);
	}
	else
	{
		Local_uint8ErrorState = 1;
	}
	
	return Local_uint8ErrorState;
}



/*
Function to control light intensity for a LED by calling function in timers to set duty cycle.
Description: This function check which pin LED is connected to (Timer0 or Timer2) and the intensity wanted for the LED.
Parameters: It takes the pin which the LED is connected to(OCR0 or OCR1), and the intensity wanted for the LED.
Return: Local_uint8ErrorState to check if there is error or not (0 => No error		1 => There is an error).


uint8 LED_uint8Intensity (LED_t* Copy_pLED_t1, uint16 Copy_uint16Intensity)
{
	uint8 Local_uint8ErrorState = 0;
	if ((LED_t->Port == DIO_uint8PORTB) && (LED_t->Pin == DIO_uint8PIN3))
	{
		TIMER0_set_duty_cycle(Copy_uint16Intensity);
	}
	else if ((LED_t->Port == DIO_uint8PORTD) && (LED_t->Pin == DIO_uint8PIN7))
	{
		TIMER2_set_duty_cycle(Copy_uint16Intensity);
	}
	else
	{
		Local_uint8ErrorState = 1;
	}
}


*/