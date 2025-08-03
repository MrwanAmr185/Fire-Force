/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : MCAL          ************************/
/***********************    SWC     : TIMER1        ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 20/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#include "../MCAL_STD_TYPES.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_register.h"

/* Callback function pointers */
static void (*Timer1_OVF_Callback)(void) = (void*)0;
static void (*Timer1_OCA_Callback)(void) = (void*)0;
static void (*Timer1_OCB_Callback)(void) = (void*)0;
static void (*Timer1_ICU_Callback)(void) = (void*)0;

/**
 * @brief Initialize Timer1 with user-defined configuration.
 * @return 1 = success, 0 = invalid configuration
 */
uint8 TIMER1_voidInit(void)
{
    /* Ensure Timer enabled */
    #if TIMER1_STATE == TIMER1_ENABLED
    /* Set waveform generation mode */
    #if (TIMER1_WAVEFORM_MODE) != 0
    /** mode bits 0-1 in TCCR1A, bits 2-3 in TCCR1B **/
    TCCR1A &= ~((1<<TCCR1A_WGM11)|(1<<TCCR1A_WGM10));
    TCCR1B &= ~((1<<TCCR1B_WGM13)|(1<<TCCR1B_WGM12));
    TCCR1A |= ((TIMER1_WAVEFORM_MODE & 0x03) << TIMER1_WGM10_BIT);
    TCCR1B |= (((TIMER1_WAVEFORM_MODE >> 2) & 0x03) << TIMER1_WGM12_BIT);
    #else
    return 0;
    #endif

    /* Set compare output modes */
    TCCR1A &= ~((1<<TCCR1A_COM1A1)|(1<<TCCR1A_COM1A0));
    TCCR1A |= ((TIMER1_COMPA_MODE & 0x03) << TCCR1A_COM1A0);

    TCCR1A &= ~((1<<TCCR1A_COM1B1)|(1<<TCCR1A_COM1B0));
    TCCR1A |= ((TIMER1_COMPB_MODE & 0x03) << TCCR1A_COM1B0);

    /* Set clock prescaler */
    TCCR1B &= ~((1<<TCCR1B_CS12)|(1<<TCCR1B_CS11)|(1<<TCCR1B_CS10));
    TCCR1B |= (TIMER1_CLOCK_SOURCE & 0x07);

    /* Enable interrupts as configured */
    if (TIMER1_INTERRUPT_OVERFLOW == TIMER1_ENABLED) { SET_BIT(TIMSK,TIMSK_TOIE1_BIT); }
    if (TIMER1_INTERRUPT_OCIEA  == TIMER1_ENABLED) { SET_BIT(TIMSK,TIMSK_OCIE1A_BIT); }
    if (TIMER1_INTERRUPT_OCIEB  == TIMER1_ENABLED) { SET_BIT(TIMSK,TIMSK_OCIE1B_BIT); }
    if (TIMER1_INTERRUPT_ICIE   == TIMER1_ENABLED) { SET_BIT(TIMSK,TIMSK_ICIE1_BIT); }

    return 1;
    #else
    /* Timer disabled */
    TCCR1B = 0;
    return 1;
    #endif
}

/**
 * @brief De-initialize Timer1 (stop timer and clear callbacks).
 * @return 1
 */
uint8 TIMER1_voidDeInit(void)
{
    /* Stop clock */
    TCCR1B = 0;
    /* Disable interrupts */
    CLEAR_BIT(TIMSK,TIMSK_TOIE1_BIT);
    CLEAR_BIT(TIMSK,TIMSK_OCIE1A_BIT);
    CLEAR_BIT(TIMSK,TIMSK_OCIE1B_BIT);
    CLEAR_BIT(TIMSK,TIMSK_ICIE1_BIT);
    /* Clear callbacks */
    Timer1_OVF_Callback = (void*)0;
    Timer1_OCA_Callback = (void*)0;
    Timer1_OCB_Callback = (void*)0;
    Timer1_ICU_Callback = (void*)0;
    return 1;
}

/** Set OCR1A value */
uint8 TIMER1_voidSetCompareA(uint16 value) { OCR1A = value; return 1; }
/** Set OCR1B value */
uint8 TIMER1_voidSetCompareB(uint16 value) { OCR1B = value; return 1; }
/** Set ICR1 value */   
uint8 TIMER1_voidSetICR(uint16 value)    { ICR1  = value; return 1; }
/** Load TCNT1 */       
uint8 TIMER1_voidSetCounter(uint16 value) { TCNT1 = value; return 1; }

/** Register overflow callback */
uint8 TIMER1_voidSetOverflowCallback(void (*pf)(void))
{ return (pf)? (Timer1_OVF_Callback = pf, 1) : 0; }

/** Register compare A callback */
uint8 TIMER1_voidSetCompareACallback(void (*pf)(void))
{ return (pf)? (Timer1_OCA_Callback = pf, 1) : 0; }

/** Register compare B callback */
uint8 TIMER1_voidSetCompareBCallback(void (*pf)(void))
{ return (pf)? (Timer1_OCB_Callback = pf, 1) : 0; }

/** Register input capture callback */
uint8 TIMER1_voidSetInputCaptureCallback(void (*pf)(void))
{ return (pf)? (Timer1_ICU_Callback = pf, 1) : 0; }

/** PWM duty on channel A (percent 0..100) */
uint8 TIMER1_voidSetPWMDutyA(uint8 duty)
{
    if (duty > 100) return 0;
    OCR1A = ((uint32)ICR1 * duty) / 100;
    return 1;
}

/** PWM duty on channel B (percent 0..100) */
uint8 TIMER1_voidSetPWMDutyB(uint8 duty)
{
    if (duty > 100) return 0;
    OCR1B = ((uint32)ICR1 * duty) / 100;
    return 1;
}

/**
 * @brief Set PWM frequency (both channels) by computing ICR1.
 * @param freq Desired frequency in Hz
 * @return 1 on success, 0 on failure
 */
uint8 TIMER1_voidSetPWMFrequency(uint32 freq)
{
    const uint32 F_CPU = 16000000UL;
    uint8 presc; uint32 top;
    static uint16 prescalers[5] = {1,8,64,256,1024};
    for (uint8 i=0; i<5; i++) {
        presc = prescalers[i];
        top = (F_CPU/(presc * freq)) - 1;
        if (top <= 0xFFFF) {
            /* set prescaler bits */
            TCCR1B = (TCCR1B & ~0x07) | (i+1);
            ICR1 = (uint16)top;
            return 1;
        }
    }
    return 0;
}


uint8 TIMER1_set_ICU_rising_edge(void)
{
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	return E_OK;
}

uint8 TIMER1_set_ICU_falling_edge(void)
{
	CLEAR_BIT(TCCR1B,TCCR1B_ICES1);
	return E_OK;
}

STD_RETURN_TYPE TIMER1_read_capture_value(uint16 *capture_val)
{
	STD_RETURN_TYPE ret=E_OK;
	if(NULL==capture_val)
	{
		ret=E_NOK;
	}
	else
	{
		*capture_val=ICR1;
	}
	return ret;
}


STD_RETURN_TYPE TIMER1_overflow_interrupt_enable(void)
{
	SET_BIT(TIMSK ,TIMSK_TOIE1);
	return E_OK;
}
STD_RETURN_TYPE TIMER1_overflow_interrupt_disable(void)
{
	CLEAR_BIT(TIMSK ,TIMSK_TOIE1);
	return E_OK;
}

STD_RETURN_TYPE TIMER1_ICU_interrupt_enable(void)
{
	SET_BIT(TIMSK ,TIMSK_TICIE1);
	return E_OK;
}
STD_RETURN_TYPE TIMER1_ICU_interrupt_disable(void)
{
	SET_BIT(TIMSK ,TIMSK_TICIE1);
	return E_OK;
}

/* ISR vectors (platform-specific names) */

void __vector_7(void) __attribute__((signal));
void __vector_7(void) { if (Timer1_OVF_Callback) Timer1_OVF_Callback(); CLEAR_BIT(TIFR,TIFR_TOV1_BIT); }

void __vector_8(void) __attribute__((signal));
void __vector_8(void) { if (Timer1_OCA_Callback) Timer1_OCA_Callback(); CLEAR_BIT(TIFR,TIFR_OCF1A_BIT); }

void __vector_9(void) __attribute__((signal));
void __vector_9(void) { if (Timer1_OCB_Callback) Timer1_OCB_Callback(); CLEAR_BIT(TIFR,TIFR_OCF1B_BIT); }

void __vector_6(void) __attribute__((signal));
void __vector_6(void) { if (Timer1_ICU_Callback) Timer1_ICU_Callback(); CLEAR_BIT(TIFR,TIFR_ICF1_BIT); }
