/***************************************************************************/
/***************************************************************************/
/***********************	Author  : GoldeN		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : DC_MOTOR 		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 14/07/2025	************************/
/***************************************************************************/
/***************************************************************************/

#ifndef DC_INTERFACE_H_
#define DC_INTERFACE_H_

/**
* @brief DC Motor Configuration Structure
*
* Contains all necessary configuration pins and ports for one DC motor.
*/
typedef struct {
	uint8 PORT_IN1; /**< PORT for Motor Direction IN1 */
	uint8 PIN_IN1;  /**< PIN for Motor Direction IN1 */

	uint8 PORT_IN2; /**< PORT for Motor Direction IN2 */
	uint8 PIN_IN2;  /**< PIN for Motor Direction IN2 */

	uint8 PORT_EN;  /**< PORT for Motor Enable (PWM Speed Control) */
	uint8 PIN_EN;   /**< PIN for Motor Enable (PWM Speed Control) */
} DC_MOTOR_t;


/**
 * @brief Initialize DC Motor Pins
 * 
 * This function sets the direction pins and enable pin as OUTPUT.
 * Call this function once in the initialization stage before using the motor.
 * 
 * @param motor Pointer to the DC Motor configuration structure
 */
void DC_MOTOR_voidInit(const DC_MOTOR_t* motor);

/**
 * @brief Rotate Motor Clockwise
 * 
 * This function rotates the DC motor in the clockwise direction.
 * 
 * @param motor Pointer to the DC Motor configuration structure
 */
void DC_MOTOR_voidRotateCW(const DC_MOTOR_t* motor);


/**
 * @brief Rotate Motor Counter-Clockwise
 * 
 * This function rotates the DC motor in the counter-clockwise direction.
 * 
 * @param motor Pointer to the DC Motor configuration structure
 */
void DC_MOTOR_voidRotateCCW(const DC_MOTOR_t* motor);


/**
 * @brief Stop the Motor
 * 
 * This function stops the DC motor by disabling both direction pins.
 * 
 * @param motor Pointer to the DC Motor configuration structure
 */
void DC_MOTOR_voidStop(const DC_MOTOR_t* motor);


/**
 * @brief Set Motor Speed (Future Expansion)
 * 
 * This function sets the speed of the DC motor using PWM.
 * We need to implement a PWM driver before using this function.
 * 
 * @param motor Pointer to the DC Motor configuration structure
 * @param speed_percent Speed percentage (0 to 100)
 */
void DC_MOTOR_voidSetSpeed(const DC_MOTOR_t* motor, uint8 speed_percent);


/***** Example Usage in main *****/
/**
DC_MOTOR_t motor1 = {DIO_uint8PORTA, DIO_uint8PIN0, DIO_uint8PORTA, DIO_uint8PIN1, DIO_uint8PORTA, DIO_uint8PIN2};
DC_MOTOR_voidInit(&motor1);
DC_MOTOR_voidRotateCW(&motor1);
DC_MOTOR_voidSetSpeed(&motor1, 75);  // 75% speed
**/

#endif /** DC_INTERFACE_H_ **/

