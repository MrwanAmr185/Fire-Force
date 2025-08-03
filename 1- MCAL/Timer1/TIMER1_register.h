/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : MCAL          ************************/
/***********************    SWC     : TIMER1        ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 20/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

#include "../MCAL_STD_TYPES.h"

/* Timer/Counter1 Control Register A */
#define TCCR1A            *((volatile uint8*)0x4F)
#define TCCR1A_COM1A1     7    /* Compare Output Mode 1, bit 1 */
#define TCCR1A_COM1A0     6    /* Compare Output Mode 1, bit 0 */
#define TCCR1A_COM1B1     5    /* Compare Output Mode B, bit 1 */
#define TCCR1A_COM1B0     4    /* Compare Output Mode B, bit 0 */
#define TCCR1A_FOC1A      3    /* Force Output Compare A */
#define TCCR1A_FOC1B      2    /* Force Output Compare B */
#define TCCR1A_WGM11      1    /* Waveform Gen Mode bit 1 */
#define TCCR1A_WGM10      0    /* Waveform Gen Mode bit 0 */

/* Timer/Counter1 Control Register B */
#define TCCR1B            *((volatile uint8*)0x4E)
#define TCCR1B_CS12       2    /* Clock Select bit 2 */
#define TCCR1B_CS11       1    /* Clock Select bit 1 */
#define TCCR1B_CS10       0    /* Clock Select bit 0 */
#define TCCR1B_WGM13      4    /* Waveform Gen Mode bit 3 */
#define TCCR1B_WGM12      3    /* Waveform Gen Mode bit 2 */
#define TCCR1B_ICES1      6    /* Input Capture Edge Select */
#define TCCR1B_ICNC1      7    /* Input Capture Noise Canceler */

/* Timer/Counter1 Registers (16-bit) */
#define TCNT1             *((volatile uint16*)0x4C)  /* Counter Value */
#define OCR1A             *((volatile uint16*)0x4A)  /* Output Compare Register A */
#define OCR1B             *((volatile uint16*)0x48)  /* Output Compare Register B */
#define ICR1              *((volatile uint16*)0x46)  /* Input Capture Register */

/* Timer Interrupt Mask Register */
#define TIMSK             *((volatile uint8*)0x59)
#define TIMSK_TICIE1      5    /* Input Capture Interrupt Enable */
#define TIMSK_OCIE1A      4    /* Output Compare A Interrupt Enable */
#define TIMSK_OCIE1B      3    /* Output Compare B Interrupt Enable */
#define TIMSK_TOIE1       2    /* Overflow Interrupt Enable */

/* Timer Interrupt Flag Register */
#define TIFR              *((volatile uint8*)0x58)
#define TIFR_ICF1         5    /* Input Capture Flag */
#define TIFR_OCF1A        4    /* Output Compare A Flag */
#define TIFR_OCF1B        3    /* Output Compare B Flag */
#define TIFR_TOV1         2    /* Overflow Flag */

#endif /* TIMER1_REGISTER_H_ */