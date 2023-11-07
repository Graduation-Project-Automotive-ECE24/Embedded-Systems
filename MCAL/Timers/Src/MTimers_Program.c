/*
 * MTIM_Program.c
 *
 *  Created on: Nov 4, 2023
 *      Author: AbdElrhman Mamdouh
 */
 /* LIB Includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

 /* MCAL Includes */
#include "MTimers_Interface.h"
#include "MTimers_Config.h"
#include "MTimers_Private.h"

 /* HAL Includes */


/*Pointer to callback functions*/
static void (*ptrF_Timer1) (void);
static void (*ptrF_Timer2) (void);
static void (*ptrF_Timer3) (void);
static void (*ptrF_Timer4) (void);

/******************************** Funtions Implementation ********************************/

/*Function used to initialize timers*/
void MTIMERS_voidInit(TIMERConfig_t * TIMERConfig)
{
	/*Disable timer*/
	MTIMERS_voidDisableTimer(TIMERConfig->u8TimerID);

	/*Reload value*/
	MTIMERS_voidSetReloadValue(TIMERConfig->u8TimerID, TIMERConfig->u16ReloadValue);

	/*Interrupt*/
	SET_BIT(TIM2->DIER,0);
	MTIMERS_voidPutISRFunction(TIMERConfig->u8TimerID,TIMERConfig->ptrFCalback);
	MTIMERS_voidEnableInterrupt(TIMERConfig->u8TimerID,TIMERConfig->u8Interrupt);

	/*Enable timer*/
	MTIMERS_voidEnableTimer(TIMERConfig->u8TimerID);
}

void MTIMERS_voidEnableTimer(u8 copy_u8TimerID){
		switch(copy_u8TimerID)
	{
	case TIMER_1:	
		SET_BIT(TIM1->CR1,0) ;	
		break;
		
	case TIMER_2:
		SET_BIT(TIM2->CR1,0) ;	
		break;
	
	case TIMER_3:
		SET_BIT(TIM3->CR1,0) ;	
		break;
		
	case TIMER_4:
		SET_BIT(TIM4->CR1,0) ;	
		break;	
	}
}

void MTIMERS_voidDisableTimer(u8 copy_u8TimerID){
		switch(copy_u8TimerID)
	{
	case TIMER_1:	
		CLR_BIT(TIM1->CR1,0) ;	
		break;
		
	case TIMER_2:
		CLR_BIT(TIM2->CR1,0) ;	
		break;
	
	case TIMER_3:
		CLR_BIT(TIM3->CR1,0) ;	
		break;
		
	case TIMER_4:
		CLR_BIT(TIM4->CR1,0) ;	
		break;	
	}
}

void MTIMERS_voidEnableInterrupt(u8 copy_u8TimerID,u8 copy_u8Interrupt){
		switch(copy_u8TimerID)
	{
	case TIMER_1:	
		SET_BIT(TIM1->DIER,copy_u8Interrupt) ;	
		break;
		
	case TIMER_2:
		SET_BIT(TIM2->DIER,copy_u8Interrupt) ;	
		break;
	
	case TIMER_3:
		SET_BIT(TIM3->DIER,copy_u8Interrupt) ;	
		break;
		
	case TIMER_4:
		SET_BIT(TIM4->DIER,copy_u8Interrupt) ;	
		break;	
	}
}

void MTIMERS_voidPutISRFunction(u8 copy_u8TimerID, void (*ptrF) (void)){
	switch(copy_u8TimerID)
	{
	case TIMER_1:
		ptrF_Timer1 = ptrF;
		break;
	
	case TIMER_2:
		ptrF_Timer2 = ptrF;
		break;
	
	case TIMER_3:
		ptrF_Timer3 = ptrF;
		break;
		
	case TIMER_4:
		ptrF_Timer4 = ptrF;
		break;
	}
	
}

void MTIMERS_voidSetReloadValue(u8 copy_u8TimerID, u16 copy_u16Value){
	switch(copy_u8TimerID)
	{
	case TIMER_1:
		TIM1->ARR=copy_u16Value;
		break;
	
	case TIMER_2:
		TIM2->ARR=copy_u16Value;
		break;
	
	case TIMER_3:
		TIM3->ARR=copy_u16Value;
		break;
		
	case TIMER_4:
		TIM4->ARR=copy_u16Value;
		break;
	}
	
}



void TIM1_ISR(void)
{
	ptrF_Timer1();

}

void TIM2_ISR(void)
{
	ptrF_Timer2();

}

void TIM3_ISR(void)
{
	ptrF_Timer3();
}

void TIM4_ISR(void)
{
	ptrF_Timer4();
}
