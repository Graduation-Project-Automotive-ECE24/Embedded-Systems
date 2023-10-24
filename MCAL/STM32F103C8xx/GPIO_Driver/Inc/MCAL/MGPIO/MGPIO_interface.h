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
 * @AltFunc_t enum
 */
typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}AltFunc_t;

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
	I2C,
	USART1,
	USART2,
	USART3=4,
	TIM1=6,
	TIM2=8,
	TIM3=10,
	TIM4,
	CAN=13,
	PD01,
	TIM5CH4,
	ADC1_ETRGINJ,
	ADC2_ETRGINJ,
	ADC2_ETRGREG,
	SWJ_CFG,
}MAPR_t;


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
}PinConfig_t;


uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig);

uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNum,PinVal_t PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t Port,Pin_t PinNum);

uint8_t GPIO_u8ReadPinValue(Port_t Port,Pin_t PinNum,PinVal_t* PinVal);

uint8_t AFIO_u8SetAltFun(Port_t Port,Pin_t PinNum);

uint8_t AFIO_U8SetEXTIPort(Port_t Port,EXTI_t EXTI_Line);
#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
