/*
 * TIMER_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR2	(*(volatile u8 *)0x45)
#define	TCNT2	(*(volatile u8 *)0x44)
#define OCR2	(*(volatile u8 *)0x43)
#define TIMSK	(*(volatile u8 *)0x59)
#define TIFR	(*(volatile u8 *)0x58)
#define ASSR	(*(volatile u8 *)0x42)
#define SFIOR	(*(volatile u8 *)0x50)


#define WGM20	6
#define WGM21	3
#define CS2_B0	0
#define TOIE2	6
#define OCIE2	7
#define TWO_BIT_MASK	0b11
#define THREE_BIT_MASK	0b111
#define NULL 	0

#define COM2_B0		4

#define NORMAL_MODE        0
#define PHASE_CORRECT_MODE 1
#define CTC_MODE           2
#define FAST_PWM_MODE      3


#define NORMAL_PIN	0b00
#define TOGGLE_PIN	0b01
#define CLEAR_PIN	0b10
#define SET_PIN		0b11



#define NORMAL_DIO		0b00
#define NON_INVERTING	0b10
#define INVERTING		0b11


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
