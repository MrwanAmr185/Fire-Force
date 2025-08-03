#include "GIE_INTERFACE.h"
#include "EXTI_INTERFACE.h"
#include "../MCAL_STD_TYPES.h"

void EXTI_Enable(uint8 EXTI_NUM)
{
	if ((EXTI_NUM>=INT2)&&(EXTI_NUM<=INT1))
	{
	GIE_ENABLE();
	switch(EXTI_NUM)
	{
		case INT0 : SET_BIT(GICR,INT0);  break;
		case INT1 : SET_BIT(GICR,INT1);  break;
		case INT2 : SET_BIT(GICR,INT2);  break;
	}
    
    }
    else
    {
    	/* do nothing */
    }
}


void INT1_SetMode(uint8 Mode)
{
	if((Mode>=FaliingEdge)&&(Mode<=OnChange))
	{	
	switch(Mode)
	{
		case LowLevel:CLEAR_BIT(MCUCR,ISC10);  CLEAR_BIT(MCUCR,ISC11);  break;
		case OnChange:SET_BIT(MCUCR,ISC10);  CLEAR_BIT(MCUCR,ISC11);  break; 
		case FaliingEdge:CLEAR_BIT(MCUCR,ISC10);  SET_BIT(MCUCR,ISC11);  break; 
		case RisingEdge:SET_BIT(MCUCR,ISC10);  SET_BIT(MCUCR,ISC11);  break;
	}
    }
    else
    {
    	//do nothing
    }
}


void INT0_SetMode(uint8 Mode)
{
	if((Mode>=FaliingEdge)&&(Mode<=OnChange))
	{
	switch(Mode)
	{
		case LowLevel:CLEAR_BIT(MCUCR,ISC00);  CLEAR_BIT(MCUCR,ISC01);  break;
		case OnChange:SET_BIT(MCUCR,ISC00);  CLEAR_BIT(MCUCR,ISC01);  break; 
		case FaliingEdge:CLEAR_BIT(MCUCR,ISC00);  SET_BIT(MCUCR,ISC01);  break; 
		case RisingEdge:SET_BIT(MCUCR,ISC00);  SET_BIT(MCUCR,ISC01);  break;
	}
    }
    else
    {
    	//do nothing
    }
}


void INT2_SetMode(uint8 Mode)
{
	if((Mode>=FaliingEdge)&&(Mode<=RisingEdge))
	{
	switch(Mode)
	{

		case FaliingEdge:CLEAR_BIT(MCUCSR,ISC2);  break; 
		case RisingEdge :SET_BIT(MCUCSR,ISC2);  break;
	}
    }
    else
    {
    	//do nothing
    }
}
void EXTI_Disable(uint8 EXTI_NUM)
{
	if ((EXTI_NUM>=INT2)&&(EXTI_NUM<=INT1))
	{
	switch(EXTI_NUM)
	{
		case INT0 : CLEAR_BIT(GICR,INT0);  break;
		case INT1 : CLEAR_BIT(GICR,INT1);  break;
		case INT2 : CLEAR_BIT(GICR,INT2);  break;
	}

    }
    else
    {
    	/* do nothing */
    }
}
