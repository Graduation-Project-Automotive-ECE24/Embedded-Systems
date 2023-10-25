/*******************************************************************************************************/
/* Author            : ECE24                                                                           */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 October 2023                                                                 */
/* Description       : MGPIO_Program.c --> implementations                                             */
/* Module  Features  :                                                                                 */
/*      01- GPIO_u8PinInit                                                                             */
/*      02- GPIO_u8SetPinValue                                                                         */
/*      03- GPIO_u8TogglePinValue                                                                      */
/*      04- GPIO_u8ReadPinValue                                                                        */
/*      05- GPIO_u8SetPortValue                                                                         */
/*      06- GPIO_u8SetResetPort                                                                       */
/*******************************************************************************************************/



/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include<stdint.h>
#include"../Inc/LIB/Stm32F103C8xx.h"
#include"../Inc/LIB/ErrorType.h"

#include"../Inc/MCAL/MGPIO/MGPIO_interface.h"
#include"../Inc/MCAL/MGPIO/MGPIO_private.h"



static GPIO_RegDef_t* GPIOPort[GPIO_PERIPPHERAL_NUM]={GPIOA,GPIOB,GPIOC};

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/


/*******************************************************************************************************/
/*                                      01- GPIO_u8PinInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         01- GPIO_u8PinInit                                                                    */
/*   @brief      The function initializes the GPIO pin according to the input parameters                                        */
/*   @param[in]  PinConfig: the initialization values of the pin                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig)
{
	uint8_t Local_u8RegNum =(PinConfig ->PinNum / CR_PIN_SHIFTING);
	uint8_t Local_u8BitNum =(PinConfig ->PinNum % CR_PIN_SHIFTING);
	uint8_t Local_u8ErrorState = OK;
	if (PinConfig != NULL)
	{
		if((PinConfig -> Port < INVALID_PORT) && (PinConfig ->PinNum <INVALID_PIN))
		{
			/*Select  Mode :Input,Output mode, max speed (10/2/50) MHz */
			(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) &= ~(CR_MASK << (Local_u8BitNum * CR_PIN_ACCESS));
			(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) |=  ((PinConfig->Mode) << (Local_u8BitNum * CR_PIN_ACCESS));

			/*Select Input Mode :Analog,Floating input or Input with pull-up / pull-down */
			if(PinConfig -> Mode ==INPUT)
			{
				(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) &= ~(CR_MASK << ((Local_u8BitNum * CR_PIN_ACCESS) + CNF_PIN_SHIFTING));
				(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) |=  ((PinConfig->InputType) << ((Local_u8BitNum * CR_PIN_ACCESS) + CNF_PIN_SHIFTING));
			}

			/*Select Output or  Alternate function Mode : Pushpull or open drain */
			else if((PinConfig -> Mode > INPUT) && (PinConfig -> Mode < INVALID_CRMODE_MODE))
			{
				(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) &= ~(CR_MASK << ((Local_u8BitNum * CR_PIN_ACCESS) + CNF_PIN_SHIFTING));
				(GPIOPort[PinConfig -> Port] -> CR[Local_u8RegNum]) |= ((PinConfig->OutputType) << ((Local_u8BitNum * CR_PIN_ACCESS)+ CNF_PIN_SHIFTING));
			}
			else
			{
				Local_u8ErrorState = NOK;
			}
		}
	}


	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


/*******************************************************************************************************/
/*                                      02- GPIO_u8SetPinValue                                         */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         02- GPIO_u8SetPinValue                                                                */
/*   @brief      The function outputs a certain value on an output pin                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                       */
/*   @param[in]  PinVal: The output value, get options @PinVal_t enum                                  */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNum,PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	if((Port < INVALID_PORT) && (PinNum <INVALID_PIN))
	{
		switch(PinVal)
		{
		case PIN_LOW:
			(GPIOPort[Port] ->BSRR) = BSRR_MASK<< (BSRR_PIN_SHIFTING+ PinNum);
			/*(GPIOPort[Port] ->ODR) &= ~(ODR_MASK <<PinNum);*/
			break;
		case PIN_HIGH:
			(GPIOPort[Port] ->BSRR) = BSRR_MASK<< (PinNum);
			/*(GPIOPort[ Port] -> ODR) |= (PinVal<< PinNum);*/
			break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************************************/
/*                                      03- GPIO_u8TogglePinValue                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         03- GPIO_u8TogglePinValue                                                                    */
/*   @brief      The function sets the pin using PinVal                                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                      */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8TogglePinValue(Port_t Port,Pin_t PinNum)
{
	uint8_t Local_u8ErrorState = OK;
	if((Port < INVALID_PORT) && (PinNum <INVALID_PIN))
	{
		GPIOPort[Port] -> ODR ^= (ODR_MASK<<PinNum);	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


/*******************************************************************************************************/
/*                                      04- GPIO_u8ReadPinValue                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         04- GPIO_u8ReadPinValue                                                                    */
/*   @brief      The function sets the pin using PinVal                                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                       */
/*   @param[out] PinVal: The output value, get options @PinVal_t enum                                    */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8ReadPinValue(Port_t Port,Pin_t PinNum,PinVal_t *PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	if((Port < INVALID_PORT) && (PinNum <INVALID_PIN))
	{
		*PinVal =(IDR_MASK & ((GPIOPort[Port] ->IDR) >> PinNum));
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************************************/
/*                                      05- GPIO_u8SetPortValue                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         05- GPIO_u8SetPortValue                                                                    */
/*   @brief      The function sets the Port value                                                      */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  A_u8Value: The Value to set port the Port                                            */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8SetPortValue(Port_t Port,uint8_t A_u8Value)
{
	uint8_t Local_u8ErrorState = OK;
	if(Port < INVALID_PORT)
	{
		GPIOPort[Port] -> ODR = A_u8Value;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
/*******************************************************************************************************/
/*                                      06- GPIO_u8SetResetPort                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         06- GPIO_u8SetResetPort                                                                    */
/*   @brief      The function sets the pin using PinVal                                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  Status: The port status you need to choose between{SET/RESET}                                    */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t GPIO_u8SetResetPort(Port_t Port,uint8_t Status)
{
	uint8_t Local_u8ErrorState = OK;
	if(Port < INVALID_PORT)
	{
		if(Status == SET)
		{
			GPIOPort[Port] -> ODR = 0xFF;
		}
		else if(Status == RESET)
		{
			GPIOPort[Port] -> ODR = 0x00;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
