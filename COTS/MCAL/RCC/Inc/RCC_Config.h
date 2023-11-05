/*
 * RCC_Config.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*************************** For Clock control ***************************/

/* 	Select HSION 
	0: Disable internal 8 MHz oscillator
	1: Enable internal 8 MHz oscillator		*/
#define HSION 1

/* 	Select HSEON 
	0: HSE oscillator OFF
	1: HSE oscillator ON					*/
#define HSEON 0

/* 	Select HSEBYP 
	0: external 4-16 MHz oscillator not bypassed
	1: external 4-16 MHz oscillator bypassed with external clock		*/
#define HSEBYP 0

/* 	Select CSSON 
	0: Clock detector OFF
	1: Clock detector ON					*/
#define CSSON 0


/* 	Select PLLON 
	0: PLL OFF
	1: PLL ON  								*/
#define PLLON 0

/*************************** For Clock configuration ***************************/

/* 	Select SW  
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed							*/
#define SW 00

/* 	Select HPRE 
	to control the division factor of the AHB clock
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512				*/
#define HPRE 0000

/* 	Select PPRE1 
	to control the division factor of the APB1 clock
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16					*/
#define PPRE1 000

/* 	Select PPRE2 
	to control the division factor of the APB2 clock
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16					*/
#define PPRE2 000

/* 	Select ADCPRE 
	to select the frequency of the clock to the ADCs
	00: PCLK2 divided by 2
	01: PCLK2 divided by 4
	10: PCLK2 divided by 6	
	11: PCLK2 divided by 8					*/
#define ADCPRE 00

/* 	Select PLLSRC 
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: HSE oscillator clock selected as PLL input clock					*/
#define PLLSRC 0

/* 	Select PLLXTPRE HSE divider for PLL entry
	0: HSE clock not divided
	1: HSE clock divided by 2				*/
#define PLLXTPRE 0

/* 	Select PLLMUL: PLL multiplication factor
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8
	0111: PLL input clock x 9
	1000: PLL input clock x 10
	1001: PLL input clock x 11
	1010: PLL input clock x 12
	1011: PLL input clock x 13
	1100: PLL input clock x 14
	1101: PLL input clock x 15
	1110: PLL input clock x 16
	1111: PLL input clock x 16				*/
#define PLLMUL 0000

/* 	Select USBPRE: USB prescaler
	0: PLL clock is divided by 1.5
	1: PLL clock is not divided			*/
#define USBPRE 1

/* 	Select MCO: Microcontroller clock output
	0xx: No clock
	100: System clock (SYSCLK) selected
	101: HSI clock selected
	110: HSE clock selected
	111: PLL clock divided by 2 selected		*/
#define MCO 100

#endif /* RCC_CONFIG_H_ */
