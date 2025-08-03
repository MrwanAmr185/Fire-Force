/************************************************************************/
/************************************************************************/
/*******************        Leader: Elghazali      **********************/
/*******************        Author: Mrwan Amr      **********************/
/*******************        Layer:  MCAL           **********************/
/*******************        SWC:    DIO            **********************/
/*******************        Version:1.00           **********************/
/************************************************************************/
/************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***************Section:includes***************/
#include "../MCAL_STD_TYPES.h"
/***************Section:macro definitions***************/

#define DIO_uint8PIN_OUTPUT			1
#define DIO_uint8PIN_INPUT			0

#define DIO_uint8PIN_HIGH			1
#define DIO_uint8PIN_LOW			0

#define DIO_uint8PORT_OUTPUT		0xFF
#define DIO_uint8PORT_INPUT			0

#define DIO_uint8PORT_HIGH			0xFF
#define DIO_uint8PORT_LOW			0

#define DIO_uint8PORTA		  	    0
#define DIO_uint8PORTB			    1
#define DIO_uint8PORTC			    2
#define DIO_uint8PORTD			    3

#define DIO_uint8PIN0				0
#define DIO_uint8PIN1				1
#define DIO_uint8PIN2				2
#define DIO_uint8PIN3				3
#define DIO_uint8PIN4				4
#define DIO_uint8PIN5				5
#define DIO_uint8PIN6				6
#define DIO_uint8PIN7			 	7

/***************Section:function like macro***************/

/***************Section:type definitions***************/

/***************Section:function decleratoins***************/

void DIO_config_file_init(void);

uint8 DIO_set_pin_direction(uint8 Copy_uint8Port, uint8 Copy_uint8Pin, uint8 Copy_uint8Direction);

uint8 DIO_set_port_direction(uint8 Copy_uint8Port, uint8 Copy_uint8Direction);

uint8 DIO_set_pin_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Pin, uint8 Copy_uint8Value);

uint8 DIO_set_port_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Value);

uint8 DIO_set_pin_pull_up_resisitor(uint8 Copy_uint8Port, uint8 Copy_uint8Pin);

STD_RETURN_TYPE DIO_read_pin_logic(uint8 Copy_uint8Port, uint8 Copy_uint8Pin,uint8 *logic);
STD_RETURN_TYPE DIO_read_port_logic(uint8 Copy_uint8Port,uint8 *logic);

#endif /* DIO_INTERFACE_H_ */