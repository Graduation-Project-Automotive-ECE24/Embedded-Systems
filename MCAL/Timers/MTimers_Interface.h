/*
 * MTIM_Interface.h
 *
 *  Created on: Nov 4, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef MTIM_INTERFACE_H_
#define MTIM_INTERFACE_H_

void MTIMERS_voidInit(TIMERConfig_t * TIMERConfig);
void MTIMERS_voidPutISRFunction(u8 copy_u8TimerID, void (*ptrF) (void));
void MTIMERS_voidSetReloadValue(u8 copy_u8TimerID, u16 copy_u16Value);
void MTIMERS_voidEnableTimer(u8 copy_u8TimerID);
void MTIMERS_voidDisableTimer(u8 copy_u8TimerID);
void MTIMERS_voidEnableInterrupt(u8 copy_u8TimerID,u8 copy_u8Interrupt);

#define TIMER_1 1
#define TIMER_2 2
#define TIMER_3 3
#define TIMER_4 4

#define TIMERS_DIRECTION_UP 0
#define TIMERS_DIRECTION_DOWN 1

#define TIMERS_INTERRUPT_UPDATE 0
#define TIMERS_INTERRUPT_CAPTCOMP1 1
#define TIMERS_INTERRUPT_CAPTCOMP2 2
#define TIMERS_INTERRUPT_CAPTCOMP3 3
#define TIMERS_INTERRUPT_CAPTCOMP4 4

#endif /* MTIM_INTERFACE_H_ */
