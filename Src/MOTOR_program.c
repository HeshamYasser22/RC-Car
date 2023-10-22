/*
 * MOTOR_program.c
 *
 *  Created on: Jul 21, 2023
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Configurations.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/HAL/MOTORS/MOTORS_Configurations.h"
#include "../Include/HAL/MOTORS/MOTORS_Interface.h"
#include "../Include/HAL/MOTORS/MOTORS_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_private.h"
#include "../Include/MCAL/TIMER2/TIMER2_Configurations.h"

void HMOTORS_SetSpeedPercentage (u8 A_u8Percentage)
{
	u8 A_u8OCR0Val = (u8)(A_u8Percentage*(2.56));
	MTIMER0_voidSetOCR0Value(A_u8OCR0Val);
	MTIMER2_voidSetOCR2Value(A_u8OCR0Val);

}

void HMOTORS_voidTurnLeft(void)
{
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN1 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN1 , 1);

}

void HMOTORS_voidTurnRight(void)
{
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN1 , 1);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN1 , 0);

}

void HMOTORS_voidTurnUp(void)
{
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN1 , 1);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN1 , 1);

}

void HMOTORS_voidTurnDown(void)
{
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN0 , 1);
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN1 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN0 , 1);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN1 , 0);

}

void HMOTORS_voidStop(void)
{
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , LEFTMOTORS_PIN1 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN0 , 0);
	MDIO_voidSetPinValue(MOTORS_PORT , RIGHTMOTORS_PIN1 , 0);
}
