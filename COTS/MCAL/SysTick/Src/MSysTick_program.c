/*******************************************************************************************************/
/* Author            : Ola Raafat Farghly                                                              */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 October 2023                                                                 */
/* Description       : MSysTick_Program.c --> implementations                                          */
/* Module  Features  :                                                                                 */
/*      01- SysTick_Delay_us                                                                           */
/*      02- SysTick_Delay_ms                                                                           */
/*******************************************************************************************************/



/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include<stdint.h>
#include"../Inc/LIB/Stm32F103C8xx.h"
#include"../Inc/LIB/ErrorType.h"

#include"../Inc/MCAL/SysTick/SysTick_interface.h"
#include"../Inc/MCAL/SysTick/SysTick_private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/


/*******************************************************************************************************/
/*                                      01- SysTick_Delay_us                                               */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         01- SysTick_Delay_us                                                                      */
/*   @brief      The function makes a delay                                                            */
/*   @param[in]  time_us: the time in  micro seconds                                                   */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t SysTick_Delay_us(uint16_t time_us)
{
	/*Disable Counter*/
		(SysTick ->CTRL) &= ~STK_ENABLE;

		/*Load the counter into LOAD register*/
		 SysTick->LOAD= time_us;

		 /*Select the clock source to be AHB/8*/
		(SysTick ->CTRL) &= ~(STK_ENABLE<<STK_CLKSOURCE);

		/*Counter enable*/
		(SysTick ->CTRL) |=  STK_ENABLE;

		/*Busy wait until the counting flag becomes zero*/
		while(STK_COUNTFLAG_MASK&((SysTick ->CTRL)>>STK_COUNTFLAG)==0);

		/*Close CTRL register*/
		(SysTick ->CTRL)=0;

}


/*******************************************************************************************************/
/*                                      02- SysTick_Delay_ms                                               */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         02- SysTick_Delay_ms                                                                      */
/*   @brief      The function outputs a certain value on an output pin                                 */
/*   @param[in]  time_us: the time in  milli seconds                                                   */
/*******************************************************************************************************/

uint8_t SysTick_Delay_ms(uint16_t time_ms)
{
	/*Disable Counter*/
	(SysTick ->CTRL) &= ~STK_ENABLE;

	/*Load the counter into LOAD register*/
	 SysTick->LOAD= time_ms*1000;

	 /*Select the clock source to be AHB/8*/
	(SysTick ->CTRL) &= ~(STK_ENABLE<<STK_CLKSOURCE);

	/*Counter enable*/
	(SysTick ->CTRL) |=  STK_ENABLE;

	/*Busy wait until the counting flag becomes zero*/
	while(STK_COUNTFLAG_MASK&((SysTick ->CTRL)>>STK_COUNTFLAG)==0);

	/*Close CTRL register*/
	(SysTick ->CTRL)=0;
}



