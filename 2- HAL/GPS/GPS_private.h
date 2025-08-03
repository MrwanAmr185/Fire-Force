/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : HAL           ************************/
/***********************    SWC     : GPS            ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 22/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#ifndef GPS_PRIVATE_H_
#define GPS_PRIVATE_H_

#include "../../MCAL/MCAL_STD_TYPES.h"
#include "GPS_config.h"

/* NMEA sentence start and end markers */
#define GPS_CHAR_DOLLAR             '$'
#define GPS_CHAR_CR                 '\r'
#define GPS_CHAR_LF                 '\n'
#define GPS_FIELD_SEPARATOR         ','

/* GPGGA field indices */
#define GPGGA_IDX_TIME              1
#define GPGGA_IDX_LATITUDE          2
#define GPGGA_IDX_LAT_DIR           3
#define GPGGA_IDX_LONGITUDE         4
#define GPGGA_IDX_LONG_DIR          5
#define GPGGA_IDX_FIX_QUALITY       6
#define GPGGA_IDX_NUM_SATS          7
#define GPGGA_IDX_ALTITUDE          9

/* GPRMC field indices */
#define GPRMC_IDX_TIME              1
#define GPRMC_IDX_STATUS            2
#define GPRMC_IDX_LATITUDE          3
#define GPRMC_IDX_LAT_DIR           4
#define GPRMC_IDX_LONGITUDE         5
#define GPRMC_IDX_LONG_DIR          6
#define GPRMC_IDX_SPEED             7
#define GPRMC_IDX_DATE              9

/* Maximum number of fields in a sentence */
#define GPS_MAX_FIELDS              20

/* Internal data storage */
typedef struct {
	uint8     fixQuality;
	uint8     numSatellites;
	float32 latitude;
	float32 longitude;
	float32 altitude;
	float32 speed;       /* in knots */
	uint8     utcHours;
	uint8     utcMinutes;
	uint8     utcSeconds;
} GPS_Data_t;

/* Internal buffer and data */
extern volatile uint8 GPS_Buffer[GPS_BUFFER_SIZE];
extern GPS_Data_t  GPS_Data;

#endif /* GPS_PRIVATE_H_ */
