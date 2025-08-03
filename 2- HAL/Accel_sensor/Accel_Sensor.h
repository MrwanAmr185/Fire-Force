#ifndef ACCEL_SENSOR_H_
#define ACCEL_SENSOR_H_

#include "../../MCAL/MCAL_STD_TYPES.H"

#define ACCEL_X_CHANNEL   ADC_1
#define ACCEL_Y_CHANNEL   ADC_2
#define ACCEL_Z_CHANNEL   ADC_3

void ACCEL_Init(void);
STD_RETURN_TYPE ACCEL_ReadX(uint16 *xVal);
STD_RETURN_TYPE ACCEL_ReadY(uint16 *yVal);
STD_RETURN_TYPE ACCEL_ReadZ(uint16 *zVal);

#endif /* ACCEL_SENSOR_H_ */