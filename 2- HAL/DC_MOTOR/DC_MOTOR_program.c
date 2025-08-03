/***************************************************************************/
/***************************************************************************/
/***********************	Author  : GoldeN		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : DC_MOTOR 		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 14/07/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "../../MCAL/MCAL_STD_TYPES.h"


#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "DC_MOTOR_private.h"
#include "../../MCAL/Timer0/Timer0.h"
#include "../../MCAL/Timer2/Timer2.h"


void DC_MOTOR_voidInit(const DC_MOTOR_t* motor)
{
	DIO_set_pin_direction(motor->PORT_IN1, motor->PIN_IN1, DIO_uint8PIN_OUTPUT);
	DIO_set_pin_direction(motor->PORT_IN2, motor->PIN_IN2, DIO_uint8PIN_OUTPUT);
	DIO_set_pin_direction(motor->PORT_EN,  motor->PIN_EN,  DIO_uint8PIN_OUTPUT);
	TIMER0_confiG_file_init();
	
	/** Default motor state: stopped **/
	DC_MOTOR_voidStop(motor);
}

void DC_MOTOR_voidRotateCW(const DC_MOTOR_t* motor)
{
	DIO_set_pin_logic(motor->PORT_IN1, motor->PIN_IN1, DIO_uint8PIN_HIGH);
	DIO_set_pin_logic(motor->PORT_IN2, motor->PIN_IN2, DIO_uint8PIN_LOW);
	DIO_set_pin_logic(motor->PORT_EN,  motor->PIN_EN,  DIO_uint8PIN_HIGH);
}

void DC_MOTOR_voidRotateCCW(const DC_MOTOR_t* motor)
{
	DIO_set_pin_logic(motor->PORT_IN1, motor->PIN_IN1, DIO_uint8PIN_LOW);
	DIO_set_pin_logic(motor->PORT_IN2, motor->PIN_IN2, DIO_uint8PIN_HIGH);
	DIO_set_pin_logic(motor->PORT_EN,  motor->PIN_EN,  DIO_uint8PIN_HIGH);
}

void DC_MOTOR_voidStop(const DC_MOTOR_t* motor)
{
	TIMER0_set_duty_cycle(0);
	DIO_set_pin_logic(motor->PORT_IN1, motor->PIN_IN1, DIO_uint8PIN_LOW);
	DIO_set_pin_logic(motor->PORT_IN2, motor->PIN_IN2, DIO_uint8PIN_LOW);
	DIO_set_pin_logic(motor->PORT_EN,  motor->PIN_EN,  DIO_uint8PIN_LOW);
}

void DC_MOTOR_voidSetSpeed(const DC_MOTOR_t* motor, uint8 speed_percent)
{
	if (motor == NULL || speed_percent > 100)
	return;

	// Determine which channel to use based on PIN_EN
	if (motor->PIN_EN == DIO_uint8PIN5)  // Assuming OC1A is on Pin 5
	{
		TIMER0_set_duty_cycle(speed_percent);
	}
	else if (motor->PIN_EN == DIO_uint8PIN4)  // Assuming OC1B is on Pin 4
	{
		TIMER0_set_duty_cycle(speed_percent);
	}
	else
	{
		// Wrong En pin
	}
}