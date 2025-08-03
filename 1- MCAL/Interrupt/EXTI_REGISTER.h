#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

//Registers of EXTI
#define  MCUCR 		*((volatile uint8*)0x55)
#define  MCUCSR 	*((volatile uint8*)0x54)
#define  GICR   	*((volatile uint8*)0x5B)
#define  GIFR   	*((volatile uint8*)0x5A)


//Flags of EXTI
#define INTF1  				7
#define INTF0  				6
#define INTF2  				5


//Bits of GICR to configure which external interrupt pins active
#define INT1   				7
#define INT0   				6
#define INT2   				5


//Bit to configure INT2 mode
#define ISC2   				6


//Bits to configure INT0 mode
#define ISC00  				0
#define ISC01  				1


//Bits to configure INT1 mode
#define ISC10  				2
#define ISC11  				3


#define INT0_Vector_Num 	1
#define INT1_Vector_Num 	2
#define INT2_Vector_Num 	3


#endif