/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : MCAL          ************************/
/***********************    SWC     : TIMER1        ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 20/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#include "TIMER1_register.h"

/**
 * @file    TIMER1_private.h
 * @brief   Private definitions for Timer1 driver (bit positions and masks).
 */

/* Waveform Generation Mode bits positions */
#define TIMER1_WGM10_BIT   0   /**< WGM10 bit in TCCR1A */
#define TIMER1_WGM11_BIT   1   /**< WGM11 bit in TCCR1A */
#define TIMER1_WGM12_BIT   3   /**< WGM12 bit in TCCR1B */
#define TIMER1_WGM13_BIT   4   /**< WGM13 bit in TCCR1B */
#define TIMER1_ENABLED 1
#define TIMER1_DISABLED 0

/* Compare Output Mode A bits positions */
#define TIMER1_COM1A0_BIT  6   /**< COM1A0 bit in TCCR1A */
#define TIMER1_COM1A1_BIT  7   /**< COM1A1 bit in TCCR1A */

/* Compare Output Mode B bits positions */
#define TIMER1_COM1B0_BIT  4   /**< COM1B0 bit in TCCR1A */
#define TIMER1_COM1B1_BIT  5   /**< COM1B1 bit in TCCR1A */

/* Clock Select bits positions */
#define TIMER1_CS10_BIT    0   /**< Clock select bit 0 in TCCR1B */
#define TIMER1_CS11_BIT    1   /**< Clock select bit 1 in TCCR1B */
#define TIMER1_CS12_BIT    2   /**< Clock select bit 2 in TCCR1B */

/* Input Capture bits positions */
#define TIMER1_ICES1_BIT   6   /**< Input capture edge select in TCCR1B */
#define TIMER1_ICNC1_BIT   7   /**< Input capture noise cancel in TCCR1B */

/* Force Output Compare bits positions */
#define TIMER1_FOC1A_BIT   3   /**< FOC1A bit in TCCR1A */
#define TIMER1_FOC1B_BIT   2   /**< FOC1B bit in TCCR1A */

/* Interrupt Mask Register bit positions for Timer1 */
#define TIMSK_ICIE1_BIT    5   /**< Input Capture Interrupt Enable */
#define TIMSK_OCIE1A_BIT   4   /**< Output Compare A Interrupt Enable */
#define TIMSK_OCIE1B_BIT   3   /**< Output Compare B Interrupt Enable */
#define TIMSK_TOIE1_BIT    2   /**< Timer1 Overflow Interrupt Enable */

/* Interrupt Flag Register bit positions for Timer1 */
#define TIFR_ICF1_BIT      5   /**< Input Capture Flag */
#define TIFR_OCF1A_BIT     4   /**< Output Compare A Flag */
#define TIFR_OCF1B_BIT     3   /**< Output Compare B Flag */
#define TIFR_TOV1_BIT      2   /**< Timer1 Overflow Flag */

#endif /* TIMER1_PRIVATE_H_ */
