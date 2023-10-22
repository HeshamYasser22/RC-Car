/*
 * TIMER_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_


void MTIMER2_voidInit (void);
void MTIMER2_voidSetPreLoadValue (u8 A_u8PreLoadValue);
void MTIMER2_voidSetOCR2Value (u8 A_u8OCR2Value);
void MTIMER2_voidSetCallBackOVF (void (*Ptr_Function)(void));
void MTIMER2_voidSetCallBackCTC (void (*Ptr_Function)(void));
void MTIMER2_voidStopClock (void);

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
