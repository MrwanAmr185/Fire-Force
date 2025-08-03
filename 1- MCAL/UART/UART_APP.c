
#include "UART_INTERFACE.h"
#include "../Interrupt/GIE_INTERFACE.h"


#define F_CPU 8000000UL
#define BAUD_RATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD_RATE)) - 1)

uint8 received_data, sending_data;
uint8 *  sending_ptr = &sending_data;
uint8 *  receiving_ptr = &received_data;

#define TIME_OUT_VALUE 100
//initializing UART
void UART_INTI(void)
{


    // Set baud rate: UBRR = (F_CPU / (16 * BAUD)) - 1
    // 9600 baud, 8MHz → UBRR = 51 = 0x33
    UBRRH = 0x00;      // [UBRRH is shared with UCSRC at 0x40 — URSEL=0 to access UBRRH]
    UBRRL = 51;        // Set lower 8 bits of UBRR

    // UCSRC: URSEL=1 to write to UCSRC
    // 8-bit data: UCSZ1=1, UCSZ0=1
    // 1 stop bit: USBS=0
    // No parity: UPM1=0, UPM0=0
    // Async mode: UMSEL=0
    UCSRC = (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);

    // Enable transmitter and receiver
    UCSRB = (1 << UCSRB_RXEN) | (1 << UCSRB_TXEN);


	
}


//Sending Data 
void UART_Send_Data_PolingMethod(uint16 data)
{
	
	while (!(UCSRA & (1 << UCSRA_UDRE)));  // انتظر لحد ما UDRE = 1

	UDR=data;
}


void UART_Send_Data_InterruptMethod(uint8 data)
{
*(sending_ptr) = data; 			//store data
GIE_ENABLE();        		//active Golble interrupt enable
SET_BIT(UCSRB,UCSRB_UDRIE); //active UDRE interrupt enable
}

void UART_Send_String(const uint16 *str)
{
    while (*str)
    {
        UART_Send_Data_PolingMethod(*str++);
    }
}

//receiving data
uint16 UART_Receive_data_PolingMethod()
{
 while (!(UCSRA & (1 << UCSRA_RXC)));  // Wait for data to be received
received_data = UDR;                 //store recived data
SET_BIT(UCSRA,UCSRA_RXC);           //Clear flag
return received_data;	
}


void UART_Receive_data_interruptMethod(uint8 *recived_data_address)
{

GIE_ENABLE();        			   //active Golble interrupt enable
SET_BIT(UCSRB,UCSRB_RXCIE);        //active RX comblete interrupt enable
receiving_ptr = recived_data_address;
}

uint16 UART_Receive_String(uint16 *buffer, uint16 max_len)
{
    uint16 idx = 0;
   uint8  c;

    /* Ensure we have room for at least one char + '\\0' */
    if (max_len < 2) return 0;

    do
    {
        /* Block until a byte arrives */
        c = UART_Receive_data_PolingMethod();

        /* Store if space remains (leave room for '\\0') */
        if (idx < max_len - 1)
        {
            buffer[idx++] = c;
        }
        /* else: drop character */
    }
    while (c != '\n');

    /* Null‑terminate */
    buffer[idx] = '\0';
    return idx;
}

//cheaking errors
sint8 UART_Frame_Error()
{
uint8 farme_error=0;
farme_error = GET_BIT(UCSRA,UCSRA_FE);
if(farme_error)
	return -1;
else 
	return 0;
}


sint8 UART_Baudrate_Error()
{
uint8 UART_Baudrate_Error=0;
UART_Baudrate_Error = GET_BIT(UCSRA,UCSRA_DOR);
if(UART_Baudrate_Error)
	return -1;
else 
	return 0;
}


//sending interrupt
void __vector_14 (void) __attribute__((signal));
void __vector_14(void)
{
UDR = sending_data;
}

//receiving interrupt
void __vector_13 (void) __attribute__((signal));
void __vector_13(void)
{
*(receiving_ptr) = UDR;
}