/*
 * UART_Configurations.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_
#define INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_

#define F_CPU								8000000UL
#define BAUD_RATE							9600UL
#define DOUBLE_SPEED						OFF
#define RX_COMPLETE_INTERRUPT				OFF
#define TX_COMPLETE_INTERRUPT				OFF
#define	DATA_REGISTER_EMPTY_INTERRUPT		OFF
#define RECEIVER_ENABLE						ON
#define TRANSMITTER_ENABLE					ON
#define CHARACTER_SIZE						EIGHT_BIT
/*
 * Character Size :-
 * 		FIVE_BIT
 * 		SIX_BIT
 * 		SEVEN_BIT
 * 		EIGHT_BIT
 * 		NINE_BIT
 */
#define UART_MODE							ASYNCHRONOUS
/*
 * UART_Modes :-
 * 		SYNCHRONOUS
 * 		ASYNCHRONOUS
 */
#define PARITY_MODE							DISABLED
/*
 * Parity Modes :-
 * 		DISABLED
 * 		EVEN_PARITY
 * 		ODD_PARTIY
 */
#define STOP_BIT_SELECT						ONE_BIT
/*
 * Stop Bit Select Modes :-
 *		ONE_BIT
 *		TWO_BIT
 */

#define CLK_POLARITY						RISING_THEN_FALLING
/*
 *  Clock Polarity Modes :-
 *  	RISING_THEN_FALLING
 *  	FALLING_THEN_RISING
 */

#define TIME_OUT							500000

#endif /* INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_ */
