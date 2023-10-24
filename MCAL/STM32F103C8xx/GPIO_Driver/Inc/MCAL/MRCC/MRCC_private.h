/*
 * MRCC_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: pc castle
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_


typedef enum
{
	HSION,
	HSIRDY,
	HSITRIM0,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSEON=16,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON=24,
	PLLRDY,
	PLL2ON,
	PLL2RDY,
	PLL3ON,
	PLL3RDY
}CR_t;

#define SW0 0
#define SW1 1
#define HSE_IS_READY 1
#define HSI_IS_READY 1
#define PLL_IS_READY 1


#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
