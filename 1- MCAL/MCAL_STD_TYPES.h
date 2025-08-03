/* 
 * File:   MCAL_STD_TYPES.h
 * Author: ibraheem El-Ghazali
 *
 * Created on January 25, 2025, 7:31 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/***********SECTION: library includes*******************/

/***********SECTION: macro definition*******************/
#define _XTAL_FREQ 8000000UL
#define cpu_type_64 64
#define cpu_type_32 32
#define cpu_type_16 16
#define cpu_type_8 8

#define cpu_type cpu_type_8

/*STD for device state of peripheral*/
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK           (STD_RETURN_TYPE)0x01
#define E_NOK          (STD_RETURN_TYPE)0x00

#define NULL 0

/***********SECTION: function like macro*******************/
#if (cpu_type==cpu_type_16)
#define HWREG_16(ADDRESS) (*((volatile uint16*)ADDRESS))
#define HWREG(ADDRESS)  HWREG_16(ADDRESS)

#elif(cpu_type==cpu_type_8)
#define HWREG_8(ADDRESS) ((volatile uint8*)ADDRESS)
#define HWREG(ADDRESS)  HWREG_8(ADDRESS)
#endif



#define SET_BIT(REG,BIT_POS)       (REG|=(1<<BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)     (REG&=~(1<<BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS)    (REG^=(1<<BIT_POS))
#define GET_BIT(REG,BIT_POS)       ((REG>>BIT_POS)&(1))



/***********SECTION: data type definition*******************/
#if(cpu_type==cpu_type_64)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_32)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long uint32;
typedef signed long long uint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_16)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int uint32;
typedef signed long long uint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_8)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned  long uint24;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed  long sint24;
typedef signed long sint32;
typedef float float32;
typedef double float64;

#endif

typedef uint8 STD_RETURN_TYPE;


#if (cpu_type==cpu_type_16)
typedef volatile uint16    HWREG_type;      
typedef uint16          HWREG_t
#elif(cpu_type==cpu_type_8)
typedef volatile uint8    HWREG_type;
typedef uint8          HWREG_t;

#endif

/***********SECTION: function decleration*******************/


#endif	/* MCAL_STD_TYPES_H */

