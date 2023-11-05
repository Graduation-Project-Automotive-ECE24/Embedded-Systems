/*
 * SysTick_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: pc castle
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_


/*******************************************************************************************************/
/*                                      01- SysTick_Delay_us                                               */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         01- SysTick_Delay_us                                                                      */
/*   @brief      The function makes a delay                                                            */
/*   @param[in]  time_us: the time in  micro seconds                                                   */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/
uint8_t SysTick_Delay_us(uint16_t time_us);

/*******************************************************************************************************/
/*                                      02- SysTick_Delay_ms                                               */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         02- SysTick_Delay_ms                                                                      */
/*   @brief      The function outputs a certain value on an output pin                                 */
/*   @param[in]  time_us: the time in  milli seconds                                                   */
/*******************************************************************************************************/
uint8_t SysTick_Delay_ms(uint16_t time_ms);


#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
