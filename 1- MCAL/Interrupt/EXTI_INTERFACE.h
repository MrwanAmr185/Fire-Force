#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#include "EXTI_REGISTER.h"
#include "../MCAL_STD_TYPES.h"


void EXTI_Enable(uint8 EXTI_NUM);
void INT1_SetMode(uint8 Mode);
void INT2_SetMode(uint8 Mode);
void INT0_SetMode(uint8 Mode);
void EXTI_Disable(uint8 EXTI_NUM);


//macros of modes for user
#define FaliingEdge		0
#define RisingEdge		1
#define LowLevel		2
#define OnChange		3

#endif