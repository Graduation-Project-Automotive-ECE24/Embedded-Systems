/*
 * RCC.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ali Emad
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f103c8xx.h"
#include "BIT_Math.h"

//========================================
/*		RCC enable registers bits		*/
//========================================

/*<<<<<<<<<<<< NOTE: this is not the optimum implementation as using enum consumes 4 bytes for each element>>>>>>>>>>*/

enum{
	AFIOEN,
	IOPAEN = 2, IOPBEN, IOPCEN,	IOPDEN,	IOPEEN,	IOPFEN,	IOPGEN,	ADC1EN, ADC2EN, TIM1EN, SPI1EN, TIM8EN, USART1EN, ADC3EN,
	TIM9EN = 19, TIM10EN, TIM11EN
}RCC_APB2EN_t;

enum{
	TIM2EN, TIM3EN, TIM4EN, TIM5EN, TIM6EN, TIM7EN,
	WWDGEN = 11,
	SPI2EN = 14, SPI3EN,
	USART2EN = 17, USART3EN, USART4EN, USART5EN, I2C1EN, I2C2EN,
	CAN1EN = 25, CAN2EN, BKPEN, PWREN, DACEN
}RCC_APB1EN_t;


//=========================
/*		RCC Macros		*/
//=========================

/* Enable AHB bus Peripherals*/

/* Disable AHB bus Peripherals*/

/* Enable APB2 bus Peripherals*/
#define RCC_AFIO_EN() 		SET_BIT(RCC->APB2ENR, AFIOEN)
#define RCC_GPIOA_EN() 		SET_BIT(RCC->APB2ENR, IOPAEN)
#define RCC_GPIOB_EN() 		SET_BIT(RCC->APB2ENR, IOPBEN)
#define RCC_GPIOC_EN() 		SET_BIT(RCC->APB2ENR, IOPCEN)
#define RCC_GPIOD_EN() 		SET_BIT(RCC->APB2ENR, IOPDEN)
#define RCC_GPIOE_EN() 		SET_BIT(RCC->APB2ENR, IOPEEN)
#define RCC_ADC1_EN() 		SET_BIT(RCC->APB2ENR, ADC1EN)
#define RCC_ADC2_EN() 		SET_BIT(RCC->APB2ENR, ADC2EN)
#define RCC_TIM1_EN() 		SET_BIT(RCC->APB2ENR, TIM1EN)
#define RCC_SPI1_EN() 		SET_BIT(RCC->APB2ENR, SPI1EN)
#define RCC_TIM8_EN() 		SET_BIT(RCC->APB2ENR, TIM8EN)
#define RCC_USART1_EN() 	SET_BIT(RCC->APB2ENR, USART1EN)
#define RCC_ADC3_EN() 		SET_BIT(RCC->APB2ENR, ADC3EN)
#define RCC_TIM9_EN() 		SET_BIT(RCC->APB2ENR, TIM9EN)
#define RCC_TIM1O_EN() 		SET_BIT(RCC->APB2ENR, TIM10EN)
#define RCC_TIM11_EN() 		SET_BIT(RCC->APB2ENR, TIM11EN)

/* Enable APB1 bus Peripherals*/
#define RCC_TIM2_EN() 		SET_BIT(RCC->APB1ENR, TIM2EN)
#define RCC_TIM3_EN() 		SET_BIT(RCC->APB1ENR, TIM3EN)
#define RCC_TIM4_EN() 		SET_BIT(RCC->APB1ENR, TIM4EN)
#define RCC_TIM5_EN() 		SET_BIT(RCC->APB1ENR, TIM5EN)
#define RCC_TIM6_EN() 		SET_BIT(RCC->APB1ENR, TIM6EN)
#define RCC_TIM7_EN() 		SET_BIT(RCC->APB1ENR, TIM7EN)
#define RCC_WWDG_EN() 		SET_BIT(RCC->APB1ENR, WWDGEN)
#define RCC_SPI2_EN() 		SET_BIT(RCC->APB1ENR, SPI2EN)
#define RCC_SPI3_EN() 		SET_BIT(RCC->APB1ENR, SPI3EN)
#define RCC_USART2_EN() 	SET_BIT(RCC->APB1ENR, USART2EN)
#define RCC_USART3_EN() 	SET_BIT(RCC->APB1ENR, USART3EN)
#define RCC_USART4_EN() 	SET_BIT(RCC->APB1ENR, USART4EN)
#define RCC_USART5_EN() 	SET_BIT(RCC->APB1ENR, USART5EN)
#define RCC_I2C1_EN() 		SET_BIT(RCC->APB1ENR, I2C1EN)
#define RCC_I2C2_EN() 		SET_BIT(RCC->APB1ENR, I2C2EN)
#define RCC_CAN1_EN() 		SET_BIT(RCC->APB1ENR, CAN1EN)
#define RCC_CAN2_EN() 		SET_BIT(RCC->APB1ENR, CAN2EN)
#define RCC_BKP_EN() 		SET_BIT(RCC->APB1ENR, BKPEN)
#define RCC_PWR_EN() 		SET_BIT(RCC->APB1ENR, PWREN)
#define RCC_DAC_EN() 		SET_BIT(RCC->APB1ENR, DACEN)

/* Disable APB2 bus Peripherals*/
#define RCC_AFIO_Disable() 		CLR_BIT(RCC->APB2ENR, AFIOEN)
#define RCC_GPIOA_Disable() 	CLR_BIT(RCC->APB2ENR, IOPAEN)
#define RCC_GPIOB_Disable() 	CLR_BIT(RCC->APB2ENR, IOPBEN)
#define RCC_GPIOC_Disable() 	CLR_BIT(RCC->APB2ENR, IOPCEN)
#define RCC_GPIOD_Disable() 	CLR_BIT(RCC->APB2ENR, IOPDEN)
#define RCC_GPIOE_Disable() 	CLR_BIT(RCC->APB2ENR, IOPEEN)
#define RCC_ADC1_Disable() 		CLR_BIT(RCC->APB2ENR, ADC1EN)
#define RCC_ADC2_Disable() 		CLR_BIT(RCC->APB2ENR, ADC2EN)
#define RCC_TIM1_Disable() 		CLR_BIT(RCC->APB2ENR, TIM1EN)
#define RCC_SPI1_Disable() 		CLR_BIT(RCC->APB2ENR, SPI1EN)
#define RCC_TIM8_Disable() 		CLR_BIT(RCC->APB2ENR, TIM8EN)
#define RCC_USART1_Disable() 	CLR_BIT(RCC->APB2ENR, USART1EN)
#define RCC_ADC3_Disable() 		CLR_BIT(RCC->APB2ENR, ADC3EN)
#define RCC_TIM9_Disable() 		CLR_BIT(RCC->APB2ENR, TIM9EN)
#define RCC_TIM1O_Disable() 	CLR_BIT(RCC->APB2ENR, TIM10EN)
#define RCC_TIM11_Disable() 	CLR_BIT(RCC->APB2ENR, TIM11EN)

/* Disable APB1 bus Peripherals*/
#define RCC_TIM2_Disable() 		CLR_BIT(RCC->APB1ENR, TIM2EN)
#define RCC_TIM3_Disable() 		CLR_BIT(RCC->APB1ENR, TIM3EN)
#define RCC_TIM4_Disable() 		CLR_BIT(RCC->APB1ENR, TIM4EN)
#define RCC_TIM5_Disable() 		CLR_BIT(RCC->APB1ENR, TIM5EN)
#define RCC_TIM6_Disable() 		CLR_BIT(RCC->APB1ENR, TIM6EN)
#define RCC_TIM7_Disable() 		CLR_BIT(RCC->APB1ENR, TIM7EN)
#define RCC_WWDG_Disable() 		CLR_BIT(RCC->APB1ENR, WWDGEN)
#define RCC_SPI2_Disable() 		CLR_BIT(RCC->APB1ENR, SPI2EN)
#define RCC_SPI3_Disable() 		CLR_BIT(RCC->APB1ENR, SPI3EN)
#define RCC_USART2_Disable() 	CLR_BIT(RCC->APB1ENR, USART2EN)
#define RCC_USART3_Disable() 	CLR_BIT(RCC->APB1ENR, USART3EN)
#define RCC_USART4_Disable() 	CLR_BIT(RCC->APB1ENR, USART4EN)
#define RCC_USART5_Disable() 	CLR_BIT(RCC->APB1ENR, USART5EN)
#define RCC_I2C1_Disable() 		CLR_BIT(RCC->APB1ENR, I2C1EN)
#define RCC_I2C2_Disable() 		CLR_BIT(RCC->APB1ENR, I2C2EN)
#define RCC_CAN1_Disable() 		CLR_BIT(RCC->APB1ENR, CAN1EN)
#define RCC_CAN2_Disable() 		CLR_BIT(RCC->APB1ENR, CAN2EN)
#define RCC_BKP_Disable() 		CLR_BIT(RCC->APB1ENR, BKPEN)
#define RCC_PWR_Disable() 		CLR_BIT(RCC->APB1ENR, PWREN)
#define RCC_DAC_Disable() 		CLR_BIT(RCC->APB1ENR, DACEN)


#endif /* INC_RCC_H_ */
