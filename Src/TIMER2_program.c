/*
 * TIMER_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_private.h"
#include "../Include/MCAL/TIMER2/TIMER2_Configurations.h"

void (*TIMER2_OVF_CallBack) (void) = NULL;
void (*TIMER2_CTC_CallBack) (void) = NULL;

void MTIMER2_voidInit (void)
{
#if TIMER2_MODE == NORMAL_MODE
	//Select TIMER2 Mode
	CLR_BIT(TCCR2 , WGM20);
	CLR_BIT(TCCR2 , WGM21);
	//Select Compare Match Output Mode
	TCCR2 &= ~(TWO_BIT_MASK<<COM2_B0);
	TCCR2 |= (OC2_MODE<<COM2_B0);
	//Enable TIMER2 Interrupts
	SET_BIT(TIMSK , TOIE2);
	//Clear CLK Bits
	TCCR2 &= ~(THREE_BIT_MASK<<CS2_B0);
	//Select CLK Source
	TCCR2 |= (CLK2_CONFIG<<CS2_B0);
#elif TIMER2_MODE == PHASE_CORRECT_MODE

#elif TIMER2_MODE == CTC_MODE
	//Select TIMER2 Mode
	CLR_BIT(TCCR2 , WGM20);
	SET_BIT(TCCR2 , WGM21);
	//Select Compare Match Output Mode
	TCCR2 &= ~(TWO_BIT_MASK<<COM2_B0);
	TCCR2 |= (OC2_MODE<<COM2_B0);
	//Enable CTC Interrupts
	SET_BIT(TIMSK , OCIE2);
	//Clear CLK Bits
	TCCR2 &= ~(THREE_BIT_MASK<<CS2_B0);
	//Select CLK Source
	TCCR2 |= (CLK2_CONFIG<<CS2_B0);
#elif TIMER2_MODE == FAST_PWM_MODE
	//Select TIMER2 Mode
	SET_BIT(TCCR2 , WGM20);
	SET_BIT(TCCR2 , WGM21);
	//Select Compare Match Output Mode
	TCCR2 &= ~(TWO_BIT_MASK<<COM2_B0);
	TCCR2 |= (OC2_MODE_PWM<<COM2_B0);
	OCR2 = OCR2_VALUE;
	//Clear CLK Bits
	TCCR2 &= ~(THREE_BIT_MASK<<CS2_B0);
	//Select CLK Source
	TCCR2 |= (CLK2_CONFIG<<CS2_B0);
#else
	#error  Wrong TIMER2 Mode Configuration
#endif

}

void MTIMER2_voidSetPreLoadValue (u8 A_u8PreLoadValue)
{
	TCNT2 = A_u8PreLoadValue;
}
void MTIMER2_voidSetCallBackOVF (void (*Ptr_Function)(void))
{
	if (Ptr_Function != NULL)
	{
		TIMER2_OVF_CallBack = Ptr_Function;
	}
}
void MTIMER2_voidSetCallBackCTC (void (*Ptr_Function)(void))
{
	if (Ptr_Function != NULL)
	{
		TIMER2_CTC_CallBack = Ptr_Function;
	}
}

void MTIMER2_voidSetOCR2Value (u8 A_u8OCR2Value)
{
	OCR2 = A_u8OCR2Value;
}

void MTIMER2_voidStopClock (void)
{
	//Clear CLK Bits
	TCCR2 &= ~(THREE_BIT_MASK<<CS2_B0);
}

void __vector_5 (void)  __attribute__ ((signal));
void __vector_5 (void)
{
	if (TIMER2_OVF_CallBack!= NULL)
	{
		TIMER2_OVF_CallBack();
	}
}

void __vector_4 (void)  __attribute__ ((signal));
void __vector_4 (void)
{
	if (TIMER2_CTC_CallBack!= NULL)
	{
		TIMER2_CTC_CallBack();
	}
}


