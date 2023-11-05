/*
 * MAFIO_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: pc castle
 */

#ifndef MCAL_MAFIO_MAFIO_INTERFACE_H_
#define MCAL_MAFIO_MAFIO_INTERFACE_H_




/*************
 *@EXTI_t enum
 */
typedef enum
{
	EXTI0=0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
	INVALID_EXTI
}EXTI_t;

/*************
 *@EXTI_t enum
 */
typedef enum
{
	SPI=0,
	I2C1,
	USART1,
	USART2,
	USART3=4,
	TIM1=6,
	TIM2=8,
	TIM3=10,
	TIM4=12,
	CAN=13,
	PD01=15,
	TIM5CH4,
	ADC1_ETRGINJ,
	ADC2_ETRGINJ,
	ADC2_ETRGREG,
	SWJ_CFG,
	TIM9,
	TIM10,
	TIM11,
	TIM13,
	TIM14,
	FSMC_NADV,
}AltFunc_t;

/*******************************************************************************************************/
/*                                      05- AFIO_U8SetEXTIPort                                         */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         05- AFIO_U8SetEXTIPort                                                                */
/*   @brief      This Function Sets A Specific Port for A Specific External Interrupt Line             */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t AFIO_u8SetAltFun(Port_t Port,Pin_t PinNum,AltFunc_t AltFunc);

/*******************************************************************************************************/
/*                                      06- AFIO_U8SetEXTIPort                                         */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         06- AFIO_U8SetEXTIPort                                                                */
/*   @brief      This Function Sets A Specific Port for A Specific External Interrupt Line             */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  EXTI_Line: The External Interrupt line @EXTI_t enum                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t AFIO_U8SetEXTIPort(Port_t Port,EXTI_t EXTI_Line);
#endif /* MCAL_MAFIO_MAFIO_INTERFACE_H_ */
