#include "Accel_Sensor.h"
#include "../../MCAL/ADC/ADC.h"   

void ACCEL_Init(void)
{
	ADC_t config = {
		.ADC_prescaler = ADC_PRESCALER_DIV_64,
		.ADC_voltage_refernce = ADC_AVCC_VOLTAGE_REF,
		.ADC_interrupt_state = ADC_INTERRUPT_DISABLED
	};

	ADC_init(&config);
	ADC_enable();
}

STD_RETURN_TYPE ACCEL_ReadX(uint16 *xVal)
{
	return ADC_start_conversion_blocking(ACCEL_X_CHANNEL, xVal);
}

STD_RETURN_TYPE ACCEL_ReadY(uint16 *yVal)
{
	return ADC_start_conversion_blocking(ACCEL_Y_CHANNEL, yVal);
}

STD_RETURN_TYPE ACCEL_ReadZ(uint16 *zVal)
{
	return ADC_start_conversion_blocking(ACCEL_Z_CHANNEL, zVal);
}