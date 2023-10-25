/*
 * MGPIO_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: pc castle
 */

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_



/*************
 *@Port_t enum
 */
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	INVALID_PORT
}Port_t;

/*************
 * @pin_t enum
 */
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	INVALID_PIN,
}Pin_t;

/*************
 * @InputMode_t enum
 */
typedef enum
{
	ANALOG=0,
	FLOATING_INPUT,
	INPUT_PULLUP_PULLDOWN,
}InputMode_t;

/*************
 * @OutputMode_t enum
 */
typedef enum
{
	GPO_PUSHPULL=0,
	GPO_OPEN_DRAIN,
	ALTERNATIVE_FUNCTION_PUSHPULL,
	ALTERNATIVE_FUNCTION_OPEN_DRAIN,
	INVALID_OUTPUT_MODE
}OutputMode_t;

/*************
 * @CRMode_t enum
 */
typedef enum
{
	INPUT=0,
	OUTPUT_MAX_SPEED_10MHZ,
	OUTPUT_MAX_SPEED_2MHZ,
	OUTPUT_MAX_SPEED_50MHZ,
	INVALID_CRMODE_MODE
}CRMode_t;

/*************
 * @OutputType_t enum
 */
typedef enum
{
	PUSH_PULL=0,
	OPEN_DRAIN
}OutputType_t;

/*************
 * @PinVal enum
 */
typedef enum
{
	PIN_LOW=0,
	PIN_HIGH
}PinVal_t;


/*************
 * @PinConfig_t enum
 */
typedef struct
{
	Port_t        Port;
	Pin_t         PinNum;
	CRMode_t      Mode;
	OutputMode_t  OutputType;
	InputMode_t   InputType;
}GPIO_PinConfig_t;


/*******************************************************************************************************/
/*                                      01- GPIO_u8PinInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         01- GPIO_u8PinInit                                                                    */
/*   @brief      The function initializes the GPIO pin according to the input parameters                                        */
/*   @param[in]  PinConfig: the initialization values of the pin                                       */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig);


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
uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNum,PinVal_t PinVal);

/*******************************************************************************************************/
/*                                      03- GPIO_u8TogglePinValue                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         03- GPIO_u8TogglePinValue                                                                    */
/*   @brief      The function sets the pin using PinVal                                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  PinNum: The pin number, get options @pin_t enum                                      */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/
uint8_t GPIO_u8TogglePinValue(Port_t Port,Pin_t PinNum);


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
uint8_t GPIO_u8ReadPinValue(Port_t Port,Pin_t PinNum,PinVal_t *PinVal);

/*******************************************************************************************************/
/*                                      05- GPIO_u8SetPortValue                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         05- GPIO_u8SetPortValue                                                                    */
/*   @brief      The function sets the Port value                                                      */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  A_u8Value: The Value to set port the Port                                            */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/
uint8_t GPIO_u8SetPortValue(Port_t Port,uint8_t A_u8Value);

/*******************************************************************************************************/
/*                                      06- GPIO_u8SetResetPort                                              */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         04- GPIO_u8SetResetPort                                                                    */
/*   @brief      The function sets the pin using PinVal                                                 */
/*   @param[in]  Port: The port number, get options @Port_t enum                                       */
/*   @param[in]  Status: The port status you need to choose between{SET/RESET}                                    */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/
uint8_t GPIO_u8SetResetPort(Port_t Port,uint8_t Status);


#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
