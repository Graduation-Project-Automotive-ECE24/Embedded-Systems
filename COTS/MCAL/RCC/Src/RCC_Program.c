/*
 * RCC_Program.c
 *
 *  Created on: Oct 21, 2023
 *      Author: AbdElrhman Mamdouh
 */
 /* LIB Includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

 /* MCAL Includes */
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Private.h"

 /* HAL Includes */


/******************************** Funtions Implementation ********************************/

/* Function To Initialize Clock Control and Condigration */
void RCC_voidINT(void)
{
	RCC->CR = 0X00 ;
	RCC->CFGR = 0X00;
	
	RCC->CR |= (HSION <<0);
	RCC->CR |= (HSEON <<16);
	RCC->CR |= (HSEBYP <<18);
	RCC->CR |= (CSSON <<19);
	RCC->CR |= (CSSON <<24);
		
	RCC->CFGR |= (SW<<0);
	RCC->CFGR |= (HPRE<<4);
	RCC->CFGR |= (PPRE1<<8);
	RCC->CFGR |= (PPRE2<<11);
	RCC->CFGR |= (ADCPRE<<14);
	RCC->CFGR |= (PLLSRC<<16);
	RCC->CFGR |= (PLLXTPRE<<17);
	RCC->CFGR |= (PLLMUL<<18);
	RCC->CFGR |= (USBPRE<<22);
	RCC->CFGR |= (MCO<<24);
	
}


/*
	Function To Enable Peripheral Clock
	copy_u8BusName 			: Pass Name of the bus -->  RCC_AHB, RCC_APB2 or RCC_APB1
	copy_tPeripheralName 	: Pass The Name of Peripheral You want to Enable in this bus 
*/
void RCC_voidPeripheralClkEnable (u8 copy_u8BusName, peripheralName_t copy_tPeripheralName)
{	
	switch (copy_u8BusName)
	{
		case RCC_AHB : 
			SET_BIT(RCC->AHBENR,copy_tPeripheralName) ;
			break;
	
		case RCC_APB2 :
			SET_BIT(RCC->APB2ENR,copy_tPeripheralName) ;	
			break;

		case RCC_APB1 :
			SET_BIT(RCC->APB1ENR,copy_tPeripheralName) ;				
			break;
			
		default : break;
	}
}

/*
	Function To Disable Peripheral Clock
	copy_u8BusName 			: Pass Name of the bus -->  RCC_AHB, RCC_APB2 or RCC_APB1
	copy_tPeripheralName 	: Pass The Name of Peripheral You want to Disable in this bus 
*/
void RCC_voidPeripheralClkDisable(u8 copy_u8BusName, peripheralName_t copy_tPeripheralName)
{
	switch (copy_u8BusName)
	{
		case RCC_AHB : 
			CLR_BIT(RCC->AHBENR,copy_tPeripheralName) ;
			break;
	
		case RCC_APB2 :
			CLR_BIT(RCC->APB2ENR,copy_tPeripheralName) ;	
			break;

		case RCC_APB1 :
			CLR_BIT(RCC->APB1ENR,copy_tPeripheralName) ;				
			break;
			
		default : break;
	}
	
}