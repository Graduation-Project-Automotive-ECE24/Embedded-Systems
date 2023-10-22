/*
 * stm32f103c8xx.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ali Emad
 */

/*MCU Device Header content:
 * Base addresses for each module
 * Clock management macros
 * IRQs definitions
 * Each peripheral registers definition structure??
 * Any other useful MCU related macros */

#ifndef INC_STM32F103C8XX_H_
#define INC_STM32F103C8XX_H_

//========================
/*		Includes		*/
//========================
#include <stdint.h>

//=============================
/*Base Addresses for memories*/
//=============================

#define SRAM_BASE 					0x20000000UL
#define SYSMEM_BASE 				0x1FFFF000UL //ROM
#define FLASH_BASE 					0x08000000UL

#define PERIPHIRALS_BASE 			0xE000000UL
#define CORTEX_M3_PERIPHIRALS_BASE 	0x4000000UL

//====================================
/*Base Addresses for bus peripherals*/
//====================================

/*AHB Peripherals*/
#define RCC_BASE					 0x40021000UL // OR (PERIPHIRALS_BASE + 0x00021000UL)

/*APB2 Peripherals*/
#define GPIOA_Base					 0x40010800
#define GPIOB_Base 					 0x40010C00
#define GPIOC_Base 					 0x40011000
#define GPIOD_Base 					 0x40011400
#define GPIOE_Base 					 0x40011800
#define GPIOF_Base 					 0x40011C00
#define EXTI_Base 					 0x40010400
#define AFIO_Base 					 0x40010000

/*APB1 Peripherals*/

//===========================================
/*peripheral registers definition structure*/
//===========================================

typedef struct{
	volatile uint32_t  CR;              /*RCC clock control register (0x00) */
	volatile uint32_t  CFGR;            /*RCC clock configuration register (0x04) */
	volatile uint32_t  CIR;             /*RCC clock interrupt register (0x08) */
	volatile uint32_t  APB2RSTR;        /*RCC APB2 Peripheral reset register (0x0C) */
	volatile uint32_t  APB1RSTR;        /*RCC APB1 Peripheral reset register (0x10) */
	volatile uint32_t  AHBENR;          /*RCC AHB Peripheral clock Enable register (0x14) */
	volatile uint32_t  APB2ENR;         /*RCC APB2 Peripheral clock Enable register (0x18) */
	volatile uint32_t  APB1ENR;         /*RCC APB1 Peripheral clock Enable register (0x1C) */
	volatile uint32_t  BDCR;            /*RCC Backup domain control register (0x20) */
	volatile uint32_t  CSR;             /*RCC control/status register (0x24) */

	//Connectivity line devices (STM32F105xx and STM32F107xx)
	//	 volatile uint32_t  AHBSTR;          /*RCC AHB peripheral clock reset register*/
	//	 volatile uint32_t  CFGR2;           /*RCC clock configuration register 2*/

}RCC_TypeDef;

typedef struct{
	volatile uint32_t  CRL;       /*GPIO PORT configuration Register low*/
	volatile uint32_t  CRH;       /*GPIO PORT configuration Register high*/
	volatile uint32_t  IDR;       /*GPIO PORT Input data Register*/
	volatile uint32_t  ODR;       /*GPIO PORT Output data Register*/
	volatile uint32_t  BSRR;      /*GPIO PORT Bit set/Reset Register*/
	volatile uint32_t  BRR;       /*GPIO PORT Bit Reset Register*/
	volatile uint32_t  LCKR;      /*GPIO PORT Lock Register*/

}GPIO_TypeDef;

typedef struct{
	volatile uint32_t  EVCR;          /*AFIO PORT Event control register Register */
	volatile uint32_t  MAPR;          /*AFIO PORT remap and debug I/O configuration register*/
	volatile uint32_t  EXTICR1;       /*AFIO PORT External interrupt configuration register 1*/
	volatile uint32_t  EXTICR2;       /*AFIO PORT External interrupt configuration register 2*/
	volatile uint32_t  EXTICR3;       /*AFIO PORT External interrupt configuration register 3*/
	volatile uint32_t  EXTICR4;       /*AFIO PORT External interrupt configuration register 4*/
	uint32_t  RESERVED0;        	   /*reserved*/
	volatile uint32_t  MAPR2;         /*AFIO PORT remap and debug I/O configuration register2*/

}AFIO_TypeDef;

typedef struct{
	volatile uint32_t  IMR;		   /*Interrupt mask register*/
	volatile uint32_t  EMR;		   /*Event mask register*/
	volatile uint32_t  RTSR;          /*Rising trigger selection register */
	volatile uint32_t  FTSR;          /*Falling trigger selection register */
	volatile uint32_t  SWIER;         /*Software interrupt event register*/
	volatile uint32_t  PR;            /*Pending register*/
}EXTI_TypeDef;


//======================
/* Peripheral Instants */ //just a way for beautiful interfacing and coding
//======================

#define RCC		 	((RCC_TypeDef*)RCC_BASE)
#define GPIOA 		((GPIO_TypeDef *)GPIOA_Base)
#define GPIOB	 	((GPIO_TypeDef *)GPIOB_Base)
#define GPIOC 		((GPIO_TypeDef *)GPIOC_Base)
#define GPIOD 		((GPIO_TypeDef *)GPIOD_Base)
#define GPIOE 		((GPIO_TypeDef *)GPIOE_Base)
#define GPIOF 		((GPIO_TypeDef *)GPIOF_Base)
#define AFIO 		((AFIO_TypeDef *)AFIO_Base)
#define EXTI 		((EXTI_TypeDef *)EXTI_Base)

//============================
/*		Generic macros		*/
//============================


//================================
/*		IRQs definitions		*/
//================================

#endif /* INC_STM32F103C8XX_H_ */
