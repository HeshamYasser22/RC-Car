/*
 * UART_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "..\Include\MCAL\UART\UART_Interface.h"
#include "..\Include\MCAL\UART\UART_private.h"
#include "..\Include\MCAL\UART\UART_Configurations.h"



void MUART_voidInit (void)
{
#if (DOUBLE_SPEED == ON)
		SET_BIT (UCSRA , U2X);
#else
		CLR_BIT (UCSRA , U2X);
#endif
#if (CHARACTER_SIZE == NINE_BIT)
	#define USCZ0_VALUE		1
	#define USCZ1_VALUE		1
	#define USCZ2_VALUE		1
#elif (CHARACTER_SIZE == EIGHT_BIT)
	#define USCZ0_VALUE		1
	#define USCZ1_VALUE		1
	#define USCZ2_VALUE		0
#elif (CHARACTER_SIZE == SEVEN_BIT)
	#define USCZ0_VALUE		0
	#define USCZ1_VALUE		1
	#define USCZ2_VALUE		0
#elif (CHARACTER_SIZE == SIX_BIT)
	#define USCZ0_VALUE		1
	#define USCZ1_VALUE		0
	#define USCZ2_VALUE		0
#elif (CHARACTER_SIZE == FIVE_BIT)
	#define USCZ0_VALUE		0
	#define USCZ1_VALUE		0
	#define USCZ2_VALUE		0
#endif
#if (PARITY_MODE == DISABLED)
	#define UPM0_VALUE		0
	#define UPM1_VALUE		0
#elif (PARITY_MODE == EVEN_PARITY)
	#define UPM0_VALUE		0
	#define UPM1_VALUE		1
#elif (PARITY_MODE == ODD_PARITY)
	#define UPM0_VALUE		1
	#define UPM1_VALUE		1
#endif

		UCSRB = CONC_BIT(RX_COMPLETE_INTERRUPT,TX_COMPLETE_INTERRUPT,DATA_REGISTER_EMPTY_INTERRUPT,RECEIVER_ENABLE,TRANSMITTER_ENABLE,USCZ2_VALUE,0,0);
		UCSRC = CONC_BIT(1,UART_MODE,UPM1_VALUE,UPM0_VALUE,STOP_BIT_SELECT,USCZ1_VALUE,USCZ0_VALUE,CLK_POLARITY);
		UBRRL = (u8) UBRR;
		UBRRH = (u8) (UBRR>>8);

}

void MUART_voidSendSyncBlocking (u8 A_u8Data)
{
	while (GET_BIT(UCSRA , UDRE)==0);
	UDR = A_u8Data;
	while (GET_BIT(UCSRA , UDRE)==0);
	SET_BIT(UCSRA , TXC);
}


void MUART_voidSendSyncNoBlocking (u8 A_u8Data)
{
	u16 local_u16Timer = 0;
	while (GET_BIT(UCSRA , UDRE)==0)
	{
		local_u16Timer ++;
		if (local_u16Timer == TIME_OUT)
		{
			break;
		}
	}
	if (local_u16Timer != TIME_OUT)
	{
		local_u16Timer = 0;
		UDR = A_u8Data;
		while (GET_BIT(UCSRA , TXC)==0)
		{
			local_u16Timer ++;
			if (local_u16Timer == TIME_OUT)
			{
				break;
			}
		}
		SET_BIT(UCSRA , TXC);
	}
}

void MUART_voidSendAsync (u8 A_u8Data)
{
	UDR = A_u8Data;
}


u8 MUART_u8ReadSyncBlocking (void)
{
	u8 local_u8Data = NO_READING;
	while (GET_BIT(UCSRA , RXC)==0);
	local_u8Data = UDR;
	return local_u8Data;
}


u8 MUART_u8ReadSyncNoBlocking (void)
{
	u8 local_u8Data = NO_READING;
	u16 local_u16Timer = 0;
	while (GET_BIT(UCSRA , RXC)==0)
	{
		local_u16Timer ++;
		if (local_u16Timer == TIME_OUT)
		{
			break;
		}
	}
	if (local_u16Timer != TIME_OUT)
	{
		local_u8Data = UDR;
	}

	return local_u8Data;
}

u8 MUART_u8ReadAsync (void)
{
	return UDR;
}

void MUART_voidSendString (u8* Ptr_String)
{
	for (u8 i = 0 ; Ptr_String[i] != '\0' ; i++)
			{
					MUART_voidSendSyncBlocking(Ptr_String[i]);
			}
}


