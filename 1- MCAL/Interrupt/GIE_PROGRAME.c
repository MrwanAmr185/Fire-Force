#include "GIE_INTERFACE.h"
#include "../MCAL_STD_TYPES.h"

void GIE_ENABLE()        //Enable GIE
{
SET_BIT(SREG,I);
}


void GIE_DISABLE()       //Disable GIE
{
CLEAR_BIT(SREG,I);
}