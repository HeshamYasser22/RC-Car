/*
 * UART_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

void MUART_voidInit (void);

void MUART_voidSendSyncBlocking (u8 A_u8Data);

void MUART_voidSendSyncNoBlocking (u8 A_u8Data);

void MUART_voidSendAsync (u8 A_u8Data);

u8 MUART_u8ReadSyncBlocking (void);

u8 MUART_u8ReadSyncNoBlocking (void);

u8 MUART_u8ReadAsync (void);

void MUART_voidSendString (u8* Ptr_String);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
