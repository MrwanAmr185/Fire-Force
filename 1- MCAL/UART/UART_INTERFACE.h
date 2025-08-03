#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#include "../MCAL_STD_TYPES.h"
#include "UART_REGISTER.h"
#include "UART_CONFIG.h"
#include "UART_PRIVATE.h"


//initializing fucntion
void UART_INTI();


//sending functions
void UART_Send_Data_PolingMethod(uint16 data);
void UART_Send_Data_InterruptMethod(uint8 data);

/**
 * @brief Send a null-terminated string
 * @param str Pointer to string
 */
void UART_Send_String(const uint16 *str);


//receving functions
uint16 UART_Receive_data_PolingMethod();
void UART_Receive_data_interruptMethod(uint8 *recived_data_address);

/**
 * @brief Receive a null-terminated string (until \n or max size)
 * @param buffer Pointer to user buffer
 * @param max_len Maximum buffer size
 * @return Number of bytes received
 */
uint16 UART_Receive_String(uint16 *buffer, uint16 max_len);


//error check
sint8 UART_Frame_Error();
sint8 UART_Baudrate_Error();


#endif