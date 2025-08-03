#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_



#include "../MCAL_STD_TYPES.h"


void GIE_ENABLE();
void GIE_DISABLE();


#define  SREG *((volatile uint8*)0x5F)
#define  I    			7

#endif