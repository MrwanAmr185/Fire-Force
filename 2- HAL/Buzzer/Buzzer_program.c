/******************************************************************/
/***************     Author: Zeinab EL_tantawy      **************/
/***************     Layer: HAL                      **************/
/***************     BUZZER_interface.c              **************/
/******************************************************************/

#include "BUZZER_interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void BUZZER_voidInit(BUZZER_T buzzer) {
	DIO_set_pin_direction(buzzer.port, buzzer.pin, DIO_uint8PIN_OUTPUT);
	
	if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_LOW);
		} else {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_HIGH);
	}
}

void BUZZER_voidOn(BUZZER_T buzzer) {
	if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_HIGH);
		} else {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_LOW);
	}
}

void BUZZER_voidOff(BUZZER_T buzzer) {
	if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_LOW);
		} else {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, DIO_uint8PIN_HIGH);
	}
}

void BUZZER_voidToggle(BUZZER_T buzzer) {
	uint8 pinValue = 0;
	DIO_read_pin_logic(buzzer.port, buzzer.pin, &pinValue);

	if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, pinValue == DIO_uint8PIN_HIGH ? DIO_uint8PIN_LOW : DIO_uint8PIN_HIGH);
		} else {
		DIO_set_pin_logic(buzzer.port, buzzer.pin, pinValue == DIO_uint8PIN_LOW ? DIO_uint8PIN_HIGH : DIO_uint8PIN_LOW);
	}
}