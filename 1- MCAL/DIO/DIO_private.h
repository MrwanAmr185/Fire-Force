/************************************************************************/
/************************************************************************/
/*******************        Leader: Elghazali      **********************/
/*******************        Author: Mrwan Amr      **********************/
/*******************        Layer:  MCAL           **********************/
/*******************        SWC:    DIO            **********************/
/*******************        Version:1.00           **********************/
/************************************************************************/
/************************************************************************/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/***************Section:includes***************/


/***************Section:macro definitions***************/


/***************Section:function like macro***************/
#define CONC(BIT7,BIT5,BIT6,BIT4,BIT3,BIT2,BIT1,BIT0)   ((BIT7<<7)|(BIT6<<6)|(BIT5<<5)|(BIT4<<4)|(BIT3<<3)|(BIT2<<2)|(BIT1<<1)|(BIT0<<0))

#define PORTA_INIT_DIR()       DDRA=CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,\
PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR, \
PORTA_PIN0_DIR)

#define PORTA_INIT_INITIAL_VALUE()       PORTA=CONC(PORTA_PIN7_INITIAL_VALUE,PORTA_PIN6_INITIAL_VALUE,PORTA_PIN5_INITIAL_VALUE,\
PORTA_PIN4_INITIAL_VALUE,PORTA_PIN3_INITIAL_VALUE,PORTA_PIN2_INITIAL_VALUE,PORTA_PIN1_INITIAL_VALUE, \
PORTA_PIN0_INITIAL_VALUE)


#define PORTB_INIT_DIR()        DDRB=CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,\
PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR, \
PORTB_PIN0_DIR)

#define PORTB_INIT_INITIAL_VALUE()       PORTB=CONC(PORTB_PIN7_INITIAL_VALUE,PORTB_PIN6_INITIAL_VALUE,PORTB_PIN5_INITIAL_VALUE,\
PORTB_PIN4_INITIAL_VALUE,PORTB_PIN3_INITIAL_VALUE,PORTB_PIN2_INITIAL_VALUE,PORTB_PIN1_INITIAL_VALUE, \
PORTB_PIN0_INITIAL_VALUE)

#define PORTC_INIT_DIR()        DDRC=CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,\
PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR, \
PORTC_PIN0_DIR)

#define PORTC_INIT_INITIAL_VALUE()       PORTC=CONC(PORTC_PIN7_INITIAL_VALUE,PORTC_PIN6_INITIAL_VALUE,PORTC_PIN5_INITIAL_VALUE,\
PORTC_PIN4_INITIAL_VALUE,PORTC_PIN3_INITIAL_VALUE,PORTC_PIN2_INITIAL_VALUE,\
PORTC_PIN1_INITIAL_VALUE,PORTC_PIN0_INITIAL_VALUE)

#define PORTD_INIT_DIR()        DDRD=CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,\
PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR, \
PORTD_PIN0_DIR)

#define PORTD_INIT_INITIAL_VALUE()       PORTD=CONC(PORTD_PIN7_INITIAL_VALUE,PORTD_PIN6_INITIAL_VALUE,PORTD_PIN5_INITIAL_VALUE,\
PORTD_PIN4_INITIAL_VALUE,PORTD_PIN3_INITIAL_VALUE,PORTD_PIN2_INITIAL_VALUE,\
PORTD_PIN1_INITIAL_VALUE,PORTD_PIN0_INITIAL_VALUE)

/***************Section:type definitions***************/



/***************Section:function decleratoins***************/



#endif /* DIO_PRIVATE_H_ */