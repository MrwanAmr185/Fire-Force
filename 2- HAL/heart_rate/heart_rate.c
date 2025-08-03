/*
 * heart_rate.c
 *
 * Created: 7/23/2025 3:38:14 AM
 *  Author: ibrah
 */ 
#include "heart_rate.h"
#include "../../MCAL/Timer1/TIMER1_interface.h"
#include "../../MCAL/Timer1/TIMER1_config.h"
#include "../../MCAL/Timer1/TIMER1_register.h"
#define TIMER1_READ_ICU_INTERRUPT_FLAG()		(GET_BIT(TIFR,TIFR_ICF1))

static uint32 counter=0;
static uint16 first_edge_time=0;
static uint16 second_edge_time=0;
static uint16 duty_edge_time=0;

static uint32 *freq_save_ptr;
static uint8 *duty_cycle_ptr;
static uint8 op_flag=NOT_BUSY_OPERATION;


void timer1_overflow_counter(void);
void timer1_first_edge_isr(void);
void timer1_second_edge_isr(void);
void timer1_duty_edge_isr(void);


uint16 timer1_prescaler=0;
STD_RETURN_TYPE Heart_rate_init(void)
{
	STD_RETURN_TYPE ret=E_OK;
	TIMER1_voidInit();
	TIMER1_ICU_interrupt_disable();
	TIMER1_overflow_interrupt_disable();
	TIMER1_voidSetOverflowCallback(timer1_overflow_counter);
	if(1==TIMER1_CLOCK_SOURCE)
	{
		timer1_prescaler=1;
	}
	else if(2==TIMER1_CLOCK_SOURCE)
	{
		timer1_prescaler=8;
	}
	else if(3==TIMER1_CLOCK_SOURCE)
	{
		timer1_prescaler=64;
	}
	else if(4==TIMER1_CLOCK_SOURCE)
	{
		timer1_prescaler=256;
	}
	
	else if(5==TIMER1_CLOCK_SOURCE)
	{
		timer1_prescaler=1024;
	}
	else
	{
		ret=E_NOK;
	}
	
	return ret;
}
STD_RETURN_TYPE Heart_rate_measure_freq_blocking(uint32 *freq)
{
	STD_RETURN_TYPE ret=E_OK;
	if(NULL==freq||BUSY_OPERATION==op_flag)
	{
		ret=E_NOK;
	}
	else
	{
		counter=0;
		op_flag=BUSY_OPERATION;
		TIMER1_overflow_interrupt_enable();
		
		ret=TIMER1_set_ICU_rising_edge();
		while(TIMER1_READ_ICU_INTERRUPT_FLAG());
		ret=TIMER1_read_capture_value(&first_edge_time);
		while(TIMER1_READ_ICU_INTERRUPT_FLAG());
		ret=TIMER1_read_capture_value(&second_edge_time);
		
		
		TIMER1_overflow_interrupt_disable();
		
		*freq=(_XTAL_FREQ/timer1_prescaler)*((second_edge_time+(counter*OVERFLOW_TICKS)-first_edge_time));
		counter=0;
		first_edge_time=0;
		second_edge_time=0;
		op_flag=NOT_BUSY_OPERATION;
		
	}
	return ret;
}
STD_RETURN_TYPE Heart_rate_measure_nonblocking(uint32 *freq,uint8 *duty_cycle)
{
	STD_RETURN_TYPE ret=E_OK;
	if(NULL==freq||(BUSY_OPERATION==op_flag)||(NULL==duty_cycle))
	{
		ret=E_NOK;
	}
	else
	{
		op_flag=BUSY_OPERATION;
		counter=0;
		freq_save_ptr=freq;
		
		duty_cycle_ptr=duty_cycle;
		
		
		TIMER1_overflow_interrupt_enable();
		TIMER1_ICU_interrupt_enable();
		
		TIMER1_voidSetInputCaptureCallback(timer1_first_edge_isr);
		TIMER1_set_ICU_rising_edge();
		
		
		
	}
	return ret;
}
STD_RETURN_TYPE Heart_rate_measure_duty_cycle_blocking(uint8 *duty_cycle)
{
	STD_RETURN_TYPE ret=E_NOK;
	if(NULL==duty_cycle||1==op_flag)
	{
		ret=E_OK;
	}
	else
	{
		counter=0;
		op_flag=BUSY_OPERATION;
		TIMER1_overflow_interrupt_enable();
		
		ret=TIMER1_set_ICU_rising_edge();
		while(TIMER1_READ_ICU_INTERRUPT_FLAG());
		ret=TIMER1_read_capture_value(&first_edge_time);
		ret=TIMER1_set_ICU_falling_edge();
		while(TIMER1_READ_ICU_INTERRUPT_FLAG());
		ret=TIMER1_read_capture_value(&duty_edge_time);
		ret=TIMER1_set_ICU_rising_edge();
		while(TIMER1_READ_ICU_INTERRUPT_FLAG());
		ret=TIMER1_read_capture_value(&second_edge_time);
		
		TIMER1_overflow_interrupt_disable();
		*duty_cycle=(second_edge_time+(OVERFLOW_TICKS*counter)-first_edge_time)/(duty_edge_time+(OVERFLOW_TICKS*counter)-first_edge_time);
		
	}
	return ret;
}



void timer1_overflow_counter(void)
{
	counter++;
}

void timer1_first_edge_isr(void)
{
	TIMER1_read_capture_value(&first_edge_time);
	TIMER1_voidSetInputCaptureCallback(&timer1_duty_edge_isr);
	TIMER1_set_ICU_falling_edge();
	
}
void timer1_second_edge_isr(void)
{
	TIMER1_ICU_interrupt_disable();
	TIMER1_overflow_interrupt_disable();
	
	*freq_save_ptr=(_XTAL_FREQ/timer1_prescaler)*((second_edge_time+(counter*OVERFLOW_TICKS)-first_edge_time));
	*duty_cycle_ptr=(second_edge_time+(OVERFLOW_TICKS*counter)-first_edge_time)/(duty_edge_time+(OVERFLOW_TICKS*counter)-first_edge_time);
	op_flag=NOT_BUSY_OPERATION;
	

	
}
void timer1_duty_edge_isr(void)
{
		TIMER1_read_capture_value(&duty_edge_time);
		TIMER1_voidSetInputCaptureCallback(&timer1_second_edge_isr);
		TIMER1_set_ICU_rising_edge();
}

