/*
 * MTIM_Private.h
 *
 *  Created on: Nov 4, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef MTIM_PRIVATE_H_
#define MTIM_PRIVATE_H_



/*Timer register map*/

typedef struct {
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RCR;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 BDTR;
	u32 DCR;
	u32 DMAR;
}MACT_t;

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 DCR;
	u32 DMAR;
}MGPT_t;


/*Advanced timers*/
#define TIM1 ((volatile MACT_t*) 0x40012C00)
#define TIM1 ((volatile MACT_t*) 0x40012C00)


/*General purpose timers*/
#define TIM2 ((volatile MGPT_t*) 0x40000000)
#define TIM3 ((volatile MGPT_t*) 0x40000400)
#define TIM4 ((volatile MGPT_t*) 0x40000800)



#endif /* MTIM_PRIVATE_H_ */
