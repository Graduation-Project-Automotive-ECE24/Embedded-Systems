/*******************************************************************************************************/
/* Author            : Ola Raafat Farghly                                                              */
/* Version           : V0.0.0                                                                          */
/* Data              : 25 October 2023                                                                 */
/* Description       : MAFIO_Program.c --> implementations                                             */
/* Module  Features  :                                                                                 */
/*      01- AFIO_U8SetEXTIPort                                                                         */
/*      02- AFIO_U8SetEXTIPort                                                                         */
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

#include"../Inc/MCAL/MAFIO/MAFIO_interface.h"
#include"../Inc/MCAL/MAFIO/MAFIO_private.h"



/*******************************************************************************************************/
/*                                      01- AFIO_U8SetEXTIPort                                         */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         01- AFIO_U8SetEXTIPort                                                                */
/*   @brief      This Function Sets A Specific Port for A Specific External Interrupt Line             */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                       */
/*   @param[in]  AltFunc: The Alturnative function of the pin, get options @AltFunc_t enum                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t AFIO_u8SetAltFun(Port_t Port,Pin_t PinNum,AltFunc_t AltFunc)
{
	uint8_t Local_u8ErrorState = OK;
	if((Port < INVALID_PORT) && (PinNum <INVALID_PIN))
	{
		/*Enable Event Out pin*/
		(AFIO ->EVCR) |=  (ECVR_PIN_ENABLE<< ECVR_ENABLE_SHIFTING);

		/*Select the desired Pin*/
		(AFIO ->EVCR) &=  ~EVCR_PIN_MASK ;
		(AFIO ->EVCR) |=  PinNum ;

		/*Select the desired Port*/
		(AFIO ->EVCR) &= ~(EVCR_PORT_MASK <<EVCR_PIN_SHIFTING);
		(AFIO ->EVCR) |=  (Port<<EVCR_PIN_SHIFTING);

		/*Select the desired ALtFunc*/
		if(AltFunc<20 && (AltFunc<4 || AltFunc== 12  ||AltFunc>14))
		{
			(AFIO ->MAPR) |=  (MAPR_OneBit_MASK<<AltFunc);
		}
		else if((AltFunc ==4) || (AltFunc ==6) || (AltFunc ==8) || (AltFunc ==10)|| (AltFunc ==13))
		{
			(AFIO ->MAPR) &= ~(MAPR_TwoBits_MASK << (AltFunc*MAPR_PIN_SHIFTING));
			(AFIO ->MAPR) |=  (AltFunc*MAPR_PIN_SHIFTING);
		}
		else if(AltFunc>=20 )
		{
			AltFunc-=15;
			(AFIO ->MAPR2) |=  (MAPR_OneBit_MASK<<AltFunc);
		}

	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************************************/
/*                                      02- AFIO_U8SetEXTIPort                                         */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         02- AFIO_U8SetEXTIPort                                                                */
/*   @brief      This Function Sets A Specific Port for A Specific External Interrupt Line             */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  EXTI_Line: The External Interrupt line @EXTI_t enum                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t AFIO_U8SetEXTIPort(Port_t Port,EXTI_t EXTI_Line)
{
	uint8_t Local_u8RegNum =(EXTI_Line / EXTI_PIN_SHIFTING);
	uint8_t Local_u8BitNum =(EXTI_Line % EXTI_PIN_SHIFTING);
	uint8_t Local_u8ErrorState = OK;
	if((Port < INVALID_PORT) && (EXTI_Line <INVALID_EXTI))
	{
		/*Enable Event Out pin*/
		(AFIO ->EVCR) |=  (ECVR_PIN_ENABLE<< ECVR_ENABLE_SHIFTING);

		/*Select the desired Port*/
		(AFIO ->EVCR) &= ~(EVCR_PORT_MASK <<EVCR_PIN_SHIFTING);
		(AFIO ->EVCR) |=  (Port<<EVCR_PIN_SHIFTING);

		/*Select Enable line*/
		(AFIO ->EXTICR[Local_u8RegNum]) &=  ~(EXTI_MASK << (Local_u8BitNum * EXTI_PIN_ACCESS));;
		(AFIO ->EXTICR[Local_u8RegNum]) |=  (Port << (Local_u8BitNum * EXTI_PIN_ACCESS));
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
