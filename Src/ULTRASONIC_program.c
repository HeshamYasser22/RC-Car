/*
 * ULTRASONIC_program.c
 *
 *  Created on: Jul 21, 2023
 *      Author: Hesha
 */
#include <util/delay.h>
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Configurations.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Configurations.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_Configurations.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_Interface.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_private.h"


u16 HULTRASONIC_u8ReadDistance(void)
{
	_delay_ms (100);
	u16  A_u16_Start ,A_u16End , A_u16Distance = 0;
	MDIO_voidSetPinValue(ULTRASONIC_PORT , ULTRASONIC_TRIG_PIN , 1);
	_delay_us (20);
	MDIO_voidSetPinValue(ULTRASONIC_PORT , ULTRASONIC_TRIG_PIN , 0);
	TCCR1B |= (1<<ICES1);
	while ((TIFR&(1<<ICF1)) == 0);
	MDIO_voidSetPinValue(ULTRASONIC_PORT , PIN6 , 1);

	A_u16_Start = ICR1;
	SET_BIT (TIFR , ICF1);
	TCCR1B &= ~(1<<ICES1);
	while ((TIFR&(1<<ICF1)) == 0);

	A_u16End = ICR1;
	SET_BIT (TIFR , ICF1);
	A_u16Distance = (u16)((A_u16End-A_u16_Start)/58);

	return A_u16Distance ;
}
