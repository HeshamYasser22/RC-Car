/*
 * SERVO_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Configurations.h"
#include "../Include/HAL/SERVO/SERVO_Interface.h"
#include "../Include/HAL/SERVO/SERVO_private.h"
#include "../Include/HAL/SERVO/SERVO_Configurations.h"

void HSERVO_voidSetAngle (s16 A_s16Angle)
{
	s16 OCRVal = 1500 + (s16)(A_s16Angle*11.11);
	MTIMER_voidSetOCR1B(OCRVal);
}


