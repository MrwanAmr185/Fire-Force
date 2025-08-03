/************************************************************************/
/************************************************************************/
/*******************        Author: Mrwan Amr      **********************/
/*******************        Layer:  HAL            **********************/
/*******************        SWC:    LED            **********************/
/*******************        Version:1.00           **********************/
/************************************************************************/
/************************************************************************/

#ifndef LED_INTERFACE_H_INCLUDED
#define LED_INTERFACE_H_INCLUDED

#define LED_uint8Source			1
#define LED_uint8Sink			    0
		
#define LED_uint8OFF				0
#define LED_uint8ON				1

#define delay					1000

typedef struct
{
	uint8 Port;
	uint8 Pin;
	uint8 Conn_Type;
}LED_t;


uint8 LED_uint8State (LED_t* Copy_pLED_t1, uint8 Copy_uint8LEDState);

uint8 LED_uint8Toggle (LED_t* Copy_pLED_t1);

uint8 LED_uint8Intensity (LED_t* Copy_pLED_t1, uint16 Copy_u16Intensity);




#endif // LED_INTERFACE_H_INCLUDED
