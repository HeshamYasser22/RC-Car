/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "..\Include\MCAL\DIO\DIO_Interface.h"
#include "..\Include\MCAL\DIO\DIO_private.h"
#include "..\Include\MCAL\DIO\DIO_Configurations.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Configurations.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_private.h"
#include "../Include/MCAL/TIMER2/TIMER2_Configurations.h"
#include "../Include/HAL/SERVO/SERVO_Interface.h"
#include "../Include/HAL/SERVO/SERVO_private.h"
#include "../Include/HAL/SERVO/SERVO_Configurations.h"
#include "..\Include\MCAL\UART\UART_Interface.h"
#include "..\Include\MCAL\UART\UART_private.h"
#include "..\Include\MCAL\UART\UART_Configurations.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_Configurations.h"
#include "../Include/HAL/MOTORS/MOTORS_Configurations.h"
#include "../Include/HAL/MOTORS/MOTORS_Interface.h"
#include "../Include/HAL/MOTORS/MOTORS_private.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_Configurations.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_Interface.h"
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_private.h"

#define RIGHTSENSOR_PIN		PIN2
#define LEFTSENSOR_PIN		PIN3

void main (void)
{
	MDIO_voidInit();
	MTIMER0_voidInit();
	MTIMER1_voidInit();
	MTIMER2_voidInit();
	MUART_voidInit();
	u8 Mode = '0';
	u8 LeftDistance;
	u8 RightDistance;
	HSERVO_voidSetAngle(0);
	while (1)
	{
		while (MUART_u8ReadSyncBlocking() != '1');
		MUART_voidSendString("A)Controller\nB)Avoid Obstacles\nC)Line Follower\n");
		MUART_voidSendString("Wanted Mode : ");
		while (Mode != 'A' && Mode != 'B' && Mode != 'C')
		{
			Mode = MUART_u8ReadSyncBlocking();
		}
		switch (Mode)
		{
		case 'A':
			HMOTORS_voidStop();
			MUART_voidSendString("Contoller Mode\n");
			while (1)
			{
				HMOTORS_SetSpeedPercentage(40);
				switch (MUART_u8ReadSyncBlocking())
				{
				case 'R' :
					HMOTORS_voidTurnRight();
					break;
				case 'L' :
					HMOTORS_voidTurnLeft();
					break;
				case 'F' :
					HMOTORS_voidTurnUp();
					break;
				case 'B' :
					HMOTORS_voidTurnDown();
					break;
				case 'S' :
					HMOTORS_voidStop();
					break;
				}
			}
			break;
		case 'B':
			MUART_voidSendString("Obstacle Mode\n");
			while (1)
			{
				HMOTORS_SetSpeedPercentage(40);
				HMOTORS_voidTurnUp();
				while (HULTRASONIC_u8ReadDistance() >= 20);
				HMOTORS_voidTurnDown();
				_delay_ms (100);
				HMOTORS_voidStop();
				HSERVO_voidSetAngle(90);
				_delay_ms (1000);
				LeftDistance = HULTRASONIC_u8ReadDistance();
				HSERVO_voidSetAngle(-90);
				_delay_ms (1000);
				RightDistance = HULTRASONIC_u8ReadDistance();
				HSERVO_voidSetAngle(0);

				if (LeftDistance >= RightDistance)
				{
					HMOTORS_voidTurnLeft();
					_delay_ms(1000);
				}
				else
				{
					HMOTORS_voidTurnRight();
					_delay_ms(1000);
				}
			}
			break;
		case 'C':
			MUART_voidSendString("Line Follower Mode\n");
			while (1)
			{
				HMOTORS_SetSpeedPercentage(20);
				if (MDIO_u8GetPinValue(PORTD , RIGHTSENSOR_PIN) == 1 && MDIO_u8GetPinValue(PORTD , LEFTSENSOR_PIN) == 1)
				{
					HMOTORS_voidTurnUp();
				}
				else if (MDIO_u8GetPinValue(PORTD , RIGHTSENSOR_PIN) == 0 && MDIO_u8GetPinValue(PORTD , LEFTSENSOR_PIN) == 1)
				{
					HMOTORS_voidTurnLeft();
				}
				else if (MDIO_u8GetPinValue(PORTD , RIGHTSENSOR_PIN) == 1 && MDIO_u8GetPinValue(PORTD , LEFTSENSOR_PIN) == 0)
				{
					HMOTORS_voidTurnRight();
				}
				else
				{
					HMOTORS_voidStop();
				}
			}
			break;
		}


	}
}

