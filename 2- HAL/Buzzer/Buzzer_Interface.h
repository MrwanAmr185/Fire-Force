/******************************************************************/
/***************     Author: Zeinab EL_tantawy      **************/
/***************     Layer: HAL                 ******************/
/***************     LED_interface  *****************************/
/***************************************************************/

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "../../MCAL/MCAL_STD_TYPES.h"

#define BUZZER_ACTIVE_HIGH   1
#define BUZZER_ACTIVE_LOW    0

typedef struct {
	uint8 port;
	uint8 pin;
	uint8 Active_State;
} BUZZER_T;

void BUZZER_voidInit(BUZZER_T buzzer);
void BUZZER_voidOn(BUZZER_T buzzer);
void BUZZER_voidOff(BUZZER_T buzzer);
void BUZZER_voidToggle(BUZZER_T buzzer);

#endif /* BUZZER_INTERFACE_H_ */
