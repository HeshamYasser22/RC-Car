/*
 * UART_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define UBRR		((F_CPU/(16*BAUD_RATE))-1)
#define UCSRA		(*(volatile u8 *)0x2B)
#define RXC			7
#define TXC			6
#define UDRE		5
#define FE			4
#define PE 			2
#define U2X			1
#define UCSRB		(*(volatile u8 *)0x2A)
#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define UCSRC		(*(volatile u8 *)0x40)
#define URSEL		7
#define	UMSEL		6
#define	UPM1		5
#define	UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0
#define UBRRH		(*(volatile u8 *)0x40)
#define UBRRL		(*(volatile u8 *)0x29)
#define UDR			(*(volatile u8 *)0x2C)

#define ON			1
#define OFF			0

#define FIVE_BIT	0b000
#define SIX_BIT		0b001
#define SEVEN_BIT	0b010
#define EIGHT_BIT	0b011
#define NINE_BIT	0b111

#define SYNCHRONOUS		1
#define ASYNCHRONOUS	0

#define DISABLED		0
#define EVEN_PARITY		2
#define ODD_PARITY		3

#define ONE_BIT			0
#define TWO_BIT			1

#define RISING_THEN_FALLING		0
#define FALLING_THEN_RISING		1

#define ONE_BIT_MASK			0b1
#define TWO_BIT_MASK			0b11


#define NO_READING				255
#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
