/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : HAL           ************************/
/***********************    SWC     : GPS            ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 22/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#ifndef GPS_CONFIG_H_
#define GPS_CONFIG_H_

/**
 * @file    GPS_config.h
 * @brief   Configuration for GPS driver
 */

/* UART baud rate for GPS module */
#define GPS_UART_BAUDRATE            9600u

/* Size of receive buffer for one NMEA sentence (including terminator) */
#define GPS_BUFFER_SIZE              120u

/* Enable parsing of specific NMEA sentences */
#define GPS_PARSE_GPGGA              1   /**< Global Positioning System Fix Data */
#define GPS_PARSE_GPRMC              1   /**< Recommended Minimum Navigation Info */

#endif /* GPS_CONFIG_H_ */
