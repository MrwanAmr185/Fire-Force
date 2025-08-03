
#include <util/delay.h>
#include "App_Drowsiness.h"
#include <stdio.h>

/* HAL drivers */
#include "HAL/TCRT/TCRT.h"
#include "HAL/Accel_sensor/Accel_Sensor.h"
#include "HAL/Buzzer/Buzzer_Interface.h"
#include "HAL/LED/LED_Inerface.h"
#include "HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "HAL/GPS/GPS_Interface.h"

/* MCAL */
#include "MCAL/ADC/ADC.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/UART/UART_INTERFACE.h"

/*=====================================================================*/
/*                         Configuration                              */
/*=====================================================================*/
#define EYE_CLOSED_MIN_MS        /*2000U*/40U
#define ACC_TILT_THRESHOLD       600U
#define NORMAL_SPEED             70U
#define STOP_SPEED               0U

/* TCRT IR Sensor configuration */
static const TCRT_t irSensor = {
	.port = DIO_uint8PORTA,
	.pin = DIO_uint8PIN0,
	.TCRT_ADC = ADC_4
};

static const BUZZER_T alertBuzzer = {
	DIO_uint8PORTB, DIO_uint8PIN1, BUZZER_ACTIVE_HIGH
};

static const LED_t alertLED = {
	DIO_uint8PORTB, DIO_uint8PIN0, LED_uint8Source
};

static const DC_MOTOR_t vehicleMotor = {
	DIO_uint8PORTB, DIO_uint8PIN3,
	DIO_uint8PORTC, DIO_uint8PIN3,
	DIO_uint8PORTC, DIO_uint8PIN4
};

static uint8 speed_flag=1;
static void UART_SendString(const char *str)
{
	while (*str)
	{
		UART_Send_Data_PolingMethod(*str++);
	}
}


static void Send_GPS_Alert(void)
{
	float32 lat = GPS_f32GetLatitude();
	float32 lon = GPS_f32GetLongitude();
	
	char buffer[100];
	sprintf(buffer, "ALERT: Drowsiness Detected! Location: Lat=%.5f, Lon=%.5f\r\n", lat, lon);
	UART_SendString(buffer);
}

static uint8 init_flag=1;
void Drowsiness_App_Init(void)
{
	TCRT_init(&irSensor);
	ACCEL_Init();
	BUZZER_voidInit(alertBuzzer);
	LED_uint8State(&alertLED, LED_uint8OFF);
	DC_MOTOR_voidInit(&vehicleMotor);
	


	
	DC_MOTOR_voidSetSpeed(&vehicleMotor, NORMAL_SPEED);
}

void Drowsiness_App_Update(void)
{
	static uint32_t eyeClosedTimeMs = 0;

	uint8_t logicVal = 1;
	TCRT_read_digital_value(&irSensor, &logicVal);

	if (logicVal == 0)
	{
		eyeClosedTimeMs += 100;
	}
	else
	{
		eyeClosedTimeMs = 0;
	}

	uint16_t accX, accY, accZ;
	ACCEL_ReadX(&accX);
	ACCEL_ReadY(&accY);
	ACCEL_ReadZ(&accZ);

	uint8_t tiltDetected = (accX > ACC_TILT_THRESHOLD) || (accY > ACC_TILT_THRESHOLD);

	if ((eyeClosedTimeMs >= EYE_CLOSED_MIN_MS) || tiltDetected)
	{
		BUZZER_voidOn(alertBuzzer);
		LED_uint8State(&alertLED, LED_uint8ON);
		if(1==speed_flag)
		{
			for(uint8 speed=NORMAL_SPEED;speed>STOP_SPEED;speed--)
			{
				DC_MOTOR_voidSetSpeed(&vehicleMotor, speed);
				_delay_ms(80);
			}
			speed_flag=0;
		}

		
		//DC_MOTOR_voidStop(&vehicleMotor);
		if(1==init_flag)
		{
				UART_INTI();
				GPS_voidInit();
				init_flag-0;
		}
	
		Send_GPS_Alert();
	}
	else
	{
		BUZZER_voidOff(alertBuzzer);
		LED_uint8State(&alertLED, LED_uint8OFF);
		speed_flag=1;

		
		DC_MOTOR_voidSetSpeed(&vehicleMotor, NORMAL_SPEED);
	}

	_delay_ms(100);
}

void DIO_PIN_INIT(void)
{
	DIO_set_pin_direction(DIO_uint8PORTB,DIO_uint8PIN0,DIO_uint8PIN_OUTPUT);
	
	
	DIO_set_pin_direction(DIO_uint8PORTA,DIO_uint8PIN0,DIO_uint8PIN_INPUT);
	DIO_set_pin_direction(DIO_uint8PORTA,DIO_uint8PIN1,DIO_uint8PIN_INPUT);
	DIO_set_pin_direction(DIO_uint8PORTA,DIO_uint8PIN2,DIO_uint8PIN_INPUT);
	DIO_set_pin_direction(DIO_uint8PORTA,DIO_uint8PIN3,DIO_uint8PIN_INPUT);
	
	/*DIO_set_pin_direction(DIO_uint8PORTC,DIO_uint8PIN2,DIO_uint8PIN_OUTPUT);
	DIO_set_pin_direction(DIO_uint8PORTC,DIO_uint8PIN3,DIO_uint8PIN_OUTPUT);
	DIO_set_pin_direction(DIO_uint8PORTC,DIO_uint8PIN4,DIO_uint8PIN_OUTPUT);*/
	
	
}