/*****************************************************************************
 * Module 	  : Data Types definition
 *
 * File name  : std_types.h
 *
 * Created on : Apr 9, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/
#ifndef DIO_MAP_H_
#define DIO_MAP_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "StandardTypes.h"


#define DIO_PORTA (*(volatile uint8_t*)0x3B)
#define DIO_PORTB (*(volatile uint8_t*)0x38)
#define DIO_PORTC (*(volatile uint8_t*)0x35)
#define DIO_PORTD (*(volatile uint8_t*)0x32)

#define DIO_DDRA (*(volatile uint8_t*)0x3A)
#define DIO_DDRB (*(volatile uint8_t*)0x37)
#define DIO_DDRC (*(volatile uint8_t*)0x34)
#define DIO_DDRD (*(volatile uint8_t*)0x31)

#define DIO_PINA (*(volatile uint8_t*)0x39)
#define DIO_PINB (*(volatile uint8_t*)0x36)
#define DIO_PINC (*(volatile uint8_t*)0x33)
#define DIO_PIND (*(volatile uint8_t*)0x30)



#define PIN0 	0u
#define PIN1 	1u
#define PIN2 	2u
#define PIN3 	3u
#define PIN4 	4u
#define PIN5 	5u
#define PIN6 	6u
#define PIN7 	7u
#define PIN8 	8u
#define PIN9 	9u
#define PIN10 	10u
#define PIN11 	11u
#define PIN12 	12u
#define PIN13 	13u
#define PIN14 	14u
#define PIN15 	15u
#define PIN16 	16u
#define PIN17 	17u
#define PIN18 	18u
#define PIN19 	19u
#define PIN20 	20u
#define PIN21 	21u
#define PIN22 	22u
#define PIN23 	23u
#define PIN24 	24u
#define PIN25 	25u
#define PIN26 	26u
#define PIN27 	27u
#define PIN28 	28u
#define PIN29 	29u
#define PIN30 	30u
#define PIN31 	31u





#endif /* DIO_MAP_H_ */
