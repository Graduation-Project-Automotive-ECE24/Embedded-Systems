/*
 * RCC_Private.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_BASE_ADDRESS		0x40021000

/*RCC register map*/

typedef struct 
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
	
} RCCreg_t;

/*RCC.RCCreg_t*/
#define RCC  ((volatile RCCreg_t*)RCC_BASE_ADDRESS)   			/*Pointer to struct To use derefrencing * u have to use dot . operator istated of arrow -> in Program */





#endif /* RCC_PRIVATE_H_ */
