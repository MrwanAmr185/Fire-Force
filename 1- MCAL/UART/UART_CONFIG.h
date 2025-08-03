#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


#define BAUDE_RATE_8MHZ 	9600
#define UCSRC_CONFIG    	134


/*
134 = 10000110
BIT  7    access UCSRC not UBRRH
BIT  6    Asynchronous
BITS 5,4  no parity
BIT  3    1stop bit
BITS 2,1  8bit mode
BIT  0    clock polarity
*/

/*

9600 :51
4800 :103
*/

#endif