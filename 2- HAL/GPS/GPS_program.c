/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : HAL           ************************/
/***********************    SWC     : GPS           ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 22/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#include "GPS_interface.h"
#include "GPS_private.h"
#include "../../MCAL/UART/UART_INTERFACE.h"
#include <string.h>
#include <stdlib.h>

volatile uint8 GPS_Buffer[GPS_BUFFER_SIZE];
 GPS_Data_t GPS_Data;

/**
 * @brief   Initialize GPS driver and UART
 * @return 1 = OK, 0 = UART error
 */
uint8 GPS_voidInit(void)
{
    UART_INTI();  // configure UART (GPS_UART_BAUDRATE assumed)

    return 1;
}

/**
 * @brief   Read and parse NMEA sentences into GPS_Data.
 * @return 1 if new valid fix data available, 0 otherwise
 */
uint8 GPS_voidUpdate(void)
{
    uint16 len = UART_Receive_String(GPS_Buffer, GPS_BUFFER_SIZE);
    if (len < 6) return 0; // too short

    // Identify sentence type
    if (GPS_PARSE_GPGGA && strncmp((char*)GPS_Buffer, "$GPGGA,", 7) == 0)
    {
        // Tokenize fields
        char *fields[GPS_MAX_FIELDS];
        uint8 count = 0;
        char *p = (char*)GPS_Buffer;
        fields[count++] = p;
        while (*p && count < GPS_MAX_FIELDS)
        {
            if (*p == GPS_FIELD_SEPARATOR)
            {
                *p = '\0';
                fields[count++] = p+1;
            }
            p++;
        }
        // Parse fix quality
        GPS_Data.fixQuality = (uint8)atoi(fields[GPGGA_IDX_FIX_QUALITY]);
        if (GPS_Data.fixQuality == 0) return 0; // no fix
        // Satellites
        GPS_Data.numSatellites = (uint8)atoi(fields[GPGGA_IDX_NUM_SATS]);
        // Latitude
        {
            float32 raw = atof(fields[GPGGA_IDX_LATITUDE]);
            uint8 deg = (uint8)(raw/100);
            float32 min = raw - deg*100;
            GPS_Data.latitude = deg + (min/60.0f);
            if (fields[GPGGA_IDX_LAT_DIR][0] == 'S') GPS_Data.latitude = -GPS_Data.latitude;
        }
        // Longitude
        {
            float32 raw = atof(fields[GPGGA_IDX_LONGITUDE]);
            uint8 deg = (uint8)(raw/100);
            float32 min = raw - deg*100;
            GPS_Data.longitude = deg + (min/60.0f);
            if (fields[GPGGA_IDX_LONG_DIR][0] == 'W') GPS_Data.longitude = -GPS_Data.longitude;
        }
        // Altitude
        GPS_Data.altitude = atof(fields[GPGGA_IDX_ALTITUDE]);
        return 1;
    }
    else if (GPS_PARSE_GPRMC && strncmp((char*)GPS_Buffer, "$GPRMC,", 7) == 0)
    {
        char *fields[GPS_MAX_FIELDS];
        uint8 count = 0;
        char *p = (char*)GPS_Buffer;
        fields[count++] = p;
        while (*p && count < GPS_MAX_FIELDS)
        {
            if (*p == GPS_FIELD_SEPARATOR)
            {
                *p = '\0';
                fields[count++] = p+1;
            }
            p++;
        }
        // Status: A = valid, V = void
        if (fields[GPRMC_IDX_STATUS][0] != 'A') return 0;
        // Speed in knots
        GPS_Data.speed = atof(fields[GPRMC_IDX_SPEED]);
        // UTC time
        {
            char *t = fields[GPRMC_IDX_TIME];
            uint8 hh = (t[0]-'0')*10 + (t[1]-'0');
            uint8 mm = (t[2]-'0')*10 + (t[3]-'0');
            uint8 ss = (t[4]-'0')*10 + (t[5]-'0');
            GPS_Data.utcHours = hh;
            GPS_Data.utcMinutes = mm;
            GPS_Data.utcSeconds = ss;
        }
        return 1;
    }
    return 0;
}

/** Getters **/
uint8 GPS_uint8GetSatelliteCount(void) { return GPS_Data.numSatellites; }
float32 GPS_f32GetLatitude(void)   { return GPS_Data.latitude; }
float32 GPS_f32GetLongitude(void)  { return GPS_Data.longitude; }
float32 GPS_f32GetAltitude(void)   { return GPS_Data.altitude; }
float32 GPS_f32GetSpeed(void)      { return GPS_Data.speed; }
uint8 GPS_uint8GetUTCTime(uint8 *h,uint8 *m,uint8 *s)
{
    if (!h||!m||!s) return 0;
    *h = GPS_Data.utcHours;
    *m = GPS_Data.utcMinutes;
    *s = GPS_Data.utcSeconds;
    return 1;
}