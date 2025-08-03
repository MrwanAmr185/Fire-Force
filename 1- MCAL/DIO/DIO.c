/************************************************************************/
/************************************************************************/
/*******************        Leader: Elghazali      **********************/
/*******************        Author: Mrwan Amr      **********************/
/*******************        Layer:  MCAL           **********************/
/*******************        SWC:    DIO            **********************/
/*******************        Version:1.00           **********************/
/************************************************************************/
/************************************************************************/


/***************Section:includes***************/

#include "../MCAL_STD_TYPES.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_register.h"

STD_RETURN_TYPE GPIO_config_file_init()
{
	
	PORTA_INIT_DIR();
	PORTA_INIT_INITIAL_VALUE();
	
	PORTB_INIT_DIR();
	PORTB_INIT_INITIAL_VALUE();
	
	PORTC_INIT_DIR();
	PORTC_INIT_INITIAL_VALUE();
	
	PORTD_INIT_DIR();
	PORTD_INIT_INITIAL_VALUE();
	return E_OK;
}
uint8 DIO_set_pin_direction(uint8 Copy_uint8Port, uint8 Copy_uint8Pin, uint8 Copy_uint8Direction)
{
	uint8 Local_uint8ErrorState = 0;
	
	if (Copy_uint8Pin <= DIO_uint8PIN7)
	{
		if (Copy_uint8Direction == DIO_uint8PIN_INPUT)
		{
			switch (Copy_uint8Port)
			{
				case DIO_uint8PORTA: CLEAR_BIT(DDRA,Copy_uint8Pin); break;
				case DIO_uint8PORTB: CLEAR_BIT(DDRB,Copy_uint8Pin); break;
				case DIO_uint8PORTC: CLEAR_BIT(DDRC,Copy_uint8Pin); break;
				case DIO_uint8PORTD: CLEAR_BIT(DDRD,Copy_uint8Pin); break;
				default: Local_uint8ErrorState = 1; break;
			}
		}
		else if (Copy_uint8Direction == DIO_uint8PIN_OUTPUT)
		{
			switch (Copy_uint8Port)
			{
				case DIO_uint8PORTA: SET_BIT(DDRA,Copy_uint8Pin); break;
				case DIO_uint8PORTB: SET_BIT(DDRB,Copy_uint8Pin); break;
				case DIO_uint8PORTC: SET_BIT(DDRC,Copy_uint8Pin); break;
				case DIO_uint8PORTD: SET_BIT(DDRD,Copy_uint8Pin); break;
				default: Local_uint8ErrorState = 1; break;
			}
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

uint8 DIO_set_port_direction(uint8 Copy_uint8Port, uint8 Copy_uint8Direction)
{
	uint8 Local_uint8ErrorState = 0;
	
	switch (Copy_uint8Port)
	{
		case DIO_uint8PORTA : DDRA = Copy_uint8Direction; break;
		case DIO_uint8PORTB : DDRB = Copy_uint8Direction; break;
		case DIO_uint8PORTC : DDRC = Copy_uint8Direction; break;
		case DIO_uint8PORTD : DDRD = Copy_uint8Direction; break;
		default: Local_uint8ErrorState = 1;
	}
	
	
	
	return Local_uint8ErrorState;	
}

uint8 DIO_set_pin_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Pin, uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = 0;
	
	if (Copy_uint8Pin <= DIO_uint8PIN7)
	{
		if (Copy_uint8Value == DIO_uint8PIN_LOW)
		{
			switch (Copy_uint8Port)
			{
				case DIO_uint8PORTA: CLEAR_BIT(PORTA,Copy_uint8Pin); break;
				case DIO_uint8PORTB: CLEAR_BIT(PORTB,Copy_uint8Pin); break;
				case DIO_uint8PORTC: CLEAR_BIT(PORTC,Copy_uint8Pin); break;
				case DIO_uint8PORTD: CLEAR_BIT(PORTD,Copy_uint8Pin); break;
				default: Local_uint8ErrorState = 1; break;
			}
		}
		else if (Copy_uint8Value == DIO_uint8PIN_HIGH)
		{
			switch (Copy_uint8Port)
			{
				case DIO_uint8PORTA: SET_BIT(PORTA,Copy_uint8Pin); break;
				case DIO_uint8PORTB: SET_BIT(PORTB,Copy_uint8Pin); break;
				case DIO_uint8PORTC: SET_BIT(PORTC,Copy_uint8Pin); break;
				case DIO_uint8PORTD: SET_BIT(PORTD,Copy_uint8Pin); break;
				default: Local_uint8ErrorState = 1; break;
			}
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

uint8 DIO_set_port_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = 0;
	
	switch(Copy_uint8Port)
	{
		case DIO_uint8PORTA : PORTA = Copy_uint8Value; break;
		case DIO_uint8PORTB : PORTB = Copy_uint8Value; break;
		case DIO_uint8PORTC : PORTC = Copy_uint8Value; break;
		case DIO_uint8PORTD : PORTD = Copy_uint8Value; break;
		default: Local_uint8ErrorState = 1;
	}
	
	
	
	return Local_uint8ErrorState;
}

uint8 DIO_set_pin_pull_up_resisitor(uint8 Copy_uint8Port, uint8 Copy_uint8Pin)
{
	uint8 Local_uint8ErrorState = 0;
	uint8 Pin_State=0;
	
	if (Copy_uint8Pin <= DIO_uint8PIN7)
	{
		switch (Copy_uint8Port)
		{
			case DIO_uint8PORTA: Pin_State = GET_BIT(DDRA,Copy_uint8Pin); break;
			case DIO_uint8PORTB: Pin_State = GET_BIT(DDRB,Copy_uint8Pin); break;
			case DIO_uint8PORTC: Pin_State = GET_BIT(DDRC,Copy_uint8Pin); break;
			case DIO_uint8PORTD: Pin_State = GET_BIT(DDRD,Copy_uint8Pin); break;
			default: Local_uint8ErrorState = 1; break;
		}
		if (Pin_State == 0)		// To check if the pin is INPUT to active pull-up resistor
		{
			switch (Copy_uint8Port)
			{
				case DIO_uint8PORTA: SET_BIT(PORTA,Copy_uint8Pin); break;
				case DIO_uint8PORTB: SET_BIT(PORTB,Copy_uint8Pin); break;
				case DIO_uint8PORTC: SET_BIT(PORTC,Copy_uint8Pin); break;
				case DIO_uint8PORTD: SET_BIT(PORTD,Copy_uint8Pin); break;
				default: Local_uint8ErrorState = 1; break;
			}
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

STD_RETURN_TYPE DIO_read_pin_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Pin,uint8 *logic)
{
	STD_RETURN_TYPE ret=E_OK;
	if((NULL==logic)||(Copy_uint8Pin > DIO_uint8PIN7)||(Copy_uint8Port>DIO_uint8PORTD))
	{
		ret=E_NOK;
	}
	else
	{
		if(DIO_uint8PORTA==Copy_uint8Port)
		{
			*logic=GET_BIT(PINA,Copy_uint8Pin);
		}
		else if(DIO_uint8PORTB==Copy_uint8Port)
		{
			*logic=GET_BIT(PINB,Copy_uint8Pin);
		}
		else if(DIO_uint8PORTC==Copy_uint8Port)
		{
			*logic=GET_BIT(PINC,Copy_uint8Pin);
		}
		else if(DIO_uint8PORTD==Copy_uint8Port)
		{
			*logic=GET_BIT(PIND,Copy_uint8Pin);
		}
		else
		{
			ret=E_NOK;
		}	
	}
	return ret;
}
STD_RETURN_TYPE DIO_read_port_logic(uint8 Copy_uint8Port,uint8 *logic)
{
	STD_RETURN_TYPE ret=E_OK;
	if((NULL==logic)||(Copy_uint8Port>DIO_uint8PORTD))
	{
		ret=E_NOK;
	}
	else
	{
		if(DIO_uint8PORTA==Copy_uint8Port)
		{
			*logic=PINA;
		}
		else if(DIO_uint8PORTB==Copy_uint8Port)
		{
			*logic=PINB;
		}
		else if(DIO_uint8PORTC==Copy_uint8Port)
		{
			*logic=PINC;
		}
		else if(DIO_uint8PORTD==Copy_uint8Port)
		{
			*logic=PIND;
		}
		else
		{
			ret=E_NOK;
		}
	}
	return ret;
}