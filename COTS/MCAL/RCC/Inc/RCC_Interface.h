/*
 * RCC_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* Buses */
#define RCC_AHB  0
#define RCC_APB2 1
#define RCC_APB1 2

/* Peripherals Name and Bit Num For the 3 buses RCC_AHB,RCC_APB2 and RCC_APB1 */
typedef enum 
{
	DMA1=0,
	DMA2,
	SRAM,
	FLITF=4,
	CRC=6,
	FSMC=8,
	SDIO=10,
	AFIO=0,
	IOPA=2,
	IOPB,
	IOPC,
	IOPD,
	IOPE,
	IOPF,
	IOPG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART,
	ADC3,
	TIM9=19,
	TIM10,
	TIM11,
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	USART4,
	USART5,
	I2C1,
	I2C2,
	USB,
	CAN=25,
	BKP=27,
	PWR,
	DAC
	
}peripheralName_t;

/* Functions Prototype*/
void RCC_voidINT(void);
void RCC_voidPeripheralClkEnable (u8 copy_u8BusName, peripheralName_t copy_tPeripheralName);
void RCC_voidPeripheralClkDisable(u8 copy_u8BusName, peripheralName_t copy_tPeripheralName);

#endif /* RCC_INTERFACE_H_ */
