/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : HAL           ************************/
/***********************    SWC     : GPS            ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 22/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/


/** 
 * @note This driver works with any NMEA‑compliant GPS module (NEO‑6M, NEO‑7M, NEO‑M8N) 
 * that outputs standard GPGGA and GPRMC sentences at the configured UART baud rate. 
**/


#ifndef GPS_INTERFACE_H_
#define GPS_INTERFACE_H_

#include "../../MCAL/MCAL_STD_TYPES.h"

/**
 * @brief Initialize GPS module driver
 * 
 * Configures UART for GPS communication (default 9600 bps),
 * and prepares internal buffers.
 * 
 * @return
 *   1 = OK, 0 = error (UART not initialized)
 */
uint8 GPS_voidInit(void);

/**
 * @brief Service routine to read and parse incoming NMEA sentences.
 * 
 * Should be called periodically (e.g., in main loop or via UART interrupt).
 * Parses GPGGA and GPRMC sentences according to configuration.
 * 
 * @return
 *   1 = New valid fix data available,
 *   0 = No new data or parse error
 */
uint8 GPS_voidUpdate(void);

/**
 * @brief Get number of satellites currently in view
 * 
 * @return satellite count (0 if no fix)
 */
uint8 GPS_uint8GetSatelliteCount(void);

/**
 * @brief Get current latitude in decimal degrees
 * 
 * Positive = North, Negative = South
 * 
 * @return latitude as float (e.g., 48.1173)
 */
float32 GPS_f32GetLatitude(void);

/**
 * @brief Get current longitude in decimal degrees
 * 
 * Positive = East, Negative = West
 * 
 * @return longitude as float (e.g., 11.5167)
 */
float32 GPS_f32GetLongitude(void);

/**
 * @brief Get current altitude above mean sea level in meters
 * 
 * @return altitude in meters
 */
float32 GPS_f32GetAltitude(void);

/**
 * @brief Get speed over ground from RMC sentence in knots
 * 
 * @return speed in knots
 */
float32 GPS_f32GetSpeed(void);

/**
 * @brief Get UTC time (hours, minutes, seconds)
 * 
 * @param hours Pointer to receive hours (0..23)
 * @param mins  Pointer to receive minutes (0..59)
 * @param secs  Pointer to receive seconds (0..60)
 * @return      1 = valid time, 0 = no fix/time invalid
 */
uint8 GPS_uint8GetUTCTime(uint8 *hours, uint8 *mins, uint8 *secs);

#endif /* GPS_INTERFACE_H_ */
