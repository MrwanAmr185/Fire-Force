
#define F_CPU 8000000UL
#include <util/delay.h>
#include "App_Drowsiness.h"
#include "MCAl/MCAL_STD_TYPES.h"
uint8 proteus;

int main(void)
{
	
	DIO_PIN_INIT();
	Drowsiness_App_Init();
	

	while (1)
	{
		
		Drowsiness_App_Update();
	}

	
}

