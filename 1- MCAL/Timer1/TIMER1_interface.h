/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : MCAL          ************************/
/***********************    SWC     : TIMER1        ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 20/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "../MCAL_STD_TYPES.h"

/**
 * @file    TIMER1_interface.h
 * @brief   Public API for 16-bit Timer1 driver (returns 1=OK, 0=Not OK)
 */

/**
 * @brief Initialize Timer1 according to TIMER1_config.h.
 * @return 1 = E_OK (success), 0 = E_NOT_OK (invalid config)
 */
uint8 TIMER1_voidInit(void);

/**
 * @brief De-initialize / stop Timer1 (no clock source).
 * @return 1 = success
 */
uint8 TIMER1_voidDeInit(void);

/**
 * @brief Directly set the Output Compare Register A (OCR1A).
 * @param value 16-bit compare match value
 * @return 1 = success
 */
uint8 TIMER1_voidSetCompareA(uint16 value);

/**
 * @brief Directly set the Output Compare Register B (OCR1B).
 * @param value 16-bit compare match value
 * @return 1 = success
 */
uint8 TIMER1_voidSetCompareB(uint16 value);

/**
 * @brief Set Input Capture Register (ICR1) as TOP for PWM modes.
 * @param value 16-bit ICR1 value
 * @return 1 = success
 */
uint8 TIMER1_voidSetICR(uint16 value);

/**
 * @brief Load the timer counter (TCNT1) initial value.
 * @param value 16-bit start count
 * @return 1 = success
 */
uint8 TIMER1_voidSetCounter(uint16 value);

/**
 * @brief Register callback for Timer1 Overflow interrupt.
 * @param pf Pointer to user function
 * @return 1 if pf != NULL, 0 otherwise
 */
uint8 TIMER1_voidSetOverflowCallback(void (*pf)(void));

/**
 * @brief Register callback for Compare Match A interrupt.
 * @param pf Pointer to user function
 * @return 1 if pf != NULL, 0 otherwise
 */
uint8 TIMER1_voidSetCompareACallback(void (*pf)(void));

/**
 * @brief Register callback for Compare Match B interrupt.
 * @param pf Pointer to user function
 * @return 1 if pf != NULL, 0 otherwise
 */
uint8 TIMER1_voidSetCompareBCallback(void (*pf)(void));

/**
 * @brief Register callback for Input Capture interrupt.
 * @param pf Pointer to user function
 * @return 1 if pf != NULL, 0 otherwise
 */
uint8 TIMER1_voidSetInputCaptureCallback(void (*pf)(void));

/**
 * @brief Set PWM duty cycle on channel A (using OCR1A).
 * @param duty Duty cycle percentage 0..100
 * @return 1 = success, 0 if duty > 100 or not in PWM mode
 */
uint8 TIMER1_voidSetPWMDutyA(uint8 duty);

/**
 * @brief Set PWM duty cycle on channel B (using OCR1B).
 * @param duty Duty cycle percentage 0..100
 * @return 1 = success, 0 if duty > 100 or not in PWM mode
 */
uint8 TIMER1_voidSetPWMDutyB(uint8 duty);

/**
 * @brief Configure PWM frequency by selecting prescaler and ICR1 (TOP) value.
 *
 * This function determines the best prescaler and computes ICR1 using:
 *   ICR1 = (F_CPU / (prescaler × freq)) - 1
 *
 * The PWM frequency range (for F_CPU = 16 MHz) is:
 *   - Max frequency ~ 8 MHz (prescaler = 1, ICR1 = 1)
 *   - Min frequency ~ 0.24 Hz (prescaler = 1024, ICR1 = 65535)
 *
 * Prescaler options tried (in order): 1, 8, 64, 256, 1024
 *
 * Both OC1A and OC1B channels share this frequency (same TOP).
 * Use TIMER1_voidSetPWMDutyA() and TIMER1_voidSetPWMDutyB() for duty cycles.
 *
 * @param freq Desired PWM frequency in Hertz (1 .. ~8,000,000)
 * @return
 *   - 1 = success (ICR1 & prescaler set)
 *   - 0 = frequency out of range or Timer1 not in PWM mode
 */
uint8 TIMER1_voidSetPWMFrequency(uint32 freq);




uint8 TIMER1_set_ICU_rising_edge(void);

uint8 TIMER1_set_ICU_falling_edge(void);

STD_RETURN_TYPE TIMER1_read_capture_value(uint16 *capture_val);

STD_RETURN_TYPE TIMER1_overflow_interrupt_enable(void);
STD_RETURN_TYPE TIMER1_overflow_interrupt_disable(void);

STD_RETURN_TYPE TIMER1_ICU_interrupt_enable(void);
STD_RETURN_TYPE TIMER1_ICU_interrupt_disable(void);
#endif /* TIMER1_INTERFACE_H_ */
