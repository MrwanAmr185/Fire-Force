/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : MCAL          ************************/
/***********************    SWC     : TIMER1        ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 20/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/
#include "TIMER1_private.h"
#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/* User Configuration for Timer1 */

/* Enable or Disable Timer1
 * Options:
 *  TIMER1_ENABLED
 *  TIMER1_DISABLED
 */
#define TIMER1_STATE         TIMER1_ENABLED

/* Waveform Generation Mode (0 to 15)
 *  0: Normal
 *  1: PWM, Phase Correct, 8-bit
 *  2: PWM, Phase Correct, 9-bit
 *  3: PWM, Phase Correct, 10-bit
 *  4: CTC (OCR1A as TOP)
 *  5: Fast PWM, 8-bit
 *  6: Fast PWM, 9-bit
 *  7: Fast PWM, 10-bit
 *  8: PWM, Phase and Frequency Correct (ICR1 as TOP)
 *  9: PWM, Phase and Frequency Correct (OCR1A as TOP)
 * 10: PWM, Phase Correct (ICR1 as TOP)
 * 11: PWM, Phase Correct (OCR1A as TOP)
 * 12: CTC (ICR1 as TOP)
 * 14: Fast PWM (ICR1 as TOP)
 * 15: Fast PWM (OCR1A as TOP)
 */
#define TIMER1_WAVEFORM_MODE  14

/* Clock Source / Prescaler
 * Options:
 *  0: No clock (Timer stopped)
 *  1: clk/1  (No prescaling)
 *  2: clk/8
 *  3: clk/64
 *  4: clk/256
 *  5: clk/1024
 *  6: External T1 pin, falling edge
 *  7: External T1 pin, rising edge
 */
#define TIMER1_CLOCK_SOURCE   3

/* Compare Output Mode for Channel A (0 to 3)
 * 0: Normal port operation, OC1A disconnected
 * 1: Toggle OC1A on compare match (PWM modes: reserved)
 * 2: Clear OC1A on compare match, set at BOTTOM (non-inverting)
 * 3: Set OC1A on compare match, clear at BOTTOM (inverting)
 */
#define TIMER1_COMPA_MODE     2

/* Compare Output Mode for Channel B (0 to 3)
 * Same options as channel A
 */
#define TIMER1_COMPB_MODE     2

/* Interrupts
 * Enable or disable specific interrupts
 */
#define TIMER1_INTERRUPT_OVERFLOW    TIMER1_ENABLED  /* Overflow Interrupt */
#define TIMER1_INTERRUPT_OCIEA       TIMER1_DISABLED /* Compare A Interrupt */
#define TIMER1_INTERRUPT_OCIEB       TIMER1_DISABLED /* Compare B Interrupt */
#define TIMER1_INTERRUPT_ICIE        TIMER1_DISABLED /* Input Capture Interrupt */

#endif /* TIMER1_CONFIG_H_ */
