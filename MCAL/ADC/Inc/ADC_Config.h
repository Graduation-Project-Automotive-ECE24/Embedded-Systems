/*
 * ADC_Config.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Mostafa Sayed
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* 	WDT_ON_REG	:	ADC_EN	ADC_DIS*/
#define WDT_ON_REG	 ADC_DIS

/* 	WDT_ON_INJ	:	ADC_EN	ADC_DIS*/
#define WDT_ON_INJ	 ADC_DIS

/* 	DISCONT_ON_REG	:	ADC_EN	ADC_DIS*/
#define DISCONT_ON_REG	 ADC_DIS

/* 	DISCONT_ON_INJ	:	ADC_EN	ADC_DIS*/
#define DISCONT_ON_INJ	 ADC_DIS

/* 	AUTO_INJ	:	ADC_EN	ADC_DIS*/
#define AUTO_INJ	 ADC_DIS

/* 	ANALOG_WDT_SET	:	ADC_EN	ADC_DIS*/
#define ANALOG_WDT_SET	 ADC_DIS

/* 	SCAN_SET	:	ADC_EN	ADC_DIS*/
#define SCAN_SET	 ADC_DIS

/* 	INJ_EOC_INT	:	ADC_EN	ADC_DIS*/
#define INJ_EOC_INT	 ADC_DIS

/* 	WDT_INT	:	ADC_EN	ADC_DIS*/
#define WDT_INT	 ADC_DIS

/* 	EOC_INT_SET	:	ADC_EN	ADC_DIS*/
#define EOC_INT_SET	 ADC_DIS

/*	EXT_TRIG_REG_EN : ADC_EN	ADC_DIS*/
#define EXT_TRIG_REG_EN	 ADC_DIS

/*	EXT_TRIG_INJ_EN : ADC_EN	ADC_DIS*/
#define EXT_TRIG_INJ_EN	 ADC_DIS

/* 	CONT_ON	:	ADC_EN	ADC_DIS*/
#define CONT_ON	 ADC_DIS

/*	Dual Mode	:
 * INDEP_MOD		COMB_REG_INJ	COMB_REG_ALT	COMB_INJ_FAST
 * COMB_INJ_SLOW	INJ_SIM			REG_SIM			FAST_INTER
 * SLOW_INTER		ALT_TRIG
 * */
#define DUAL_MODE			INDEP_MOD

/*	Discontinuous Channel Number
 * 	ADC_DIS_CHANNEL1	ADC_DIS_CHANNEL2	ADC_DIS_CHANNEL3
 * 	ADC_DIS_CHANNEL4	ADC_DIS_CHANNEL5	ADC_DIS_CHANNEL6
 * 	ADC_DIS_CHANNEL7	ADC_DIS_CHANNEL8
 * 	*/
#define ADC_REG_DISCONT	ADC_DIS_CHANNEL1
/*	Watch-dog Guard Channel Number
 * 	ADC_WDT_CHANNEL0	ADC_WDT_CHANNEL1	ADC_WDT_CHANNEL2	ADC_WDT_CHANNEL3
 * 	ADC_WDT_CHANNEL4	ADC_WDT_CHANNEL5	ADC_WDT_CHANNEL6	ADC_WDT_CHANNEL7
 * 	ADC_WDT_CHANNEL8	ADC_WDT_CHANNEL9	ADC_WDT_CHANNEL10	ADC_WDT_CHANNEL11
 * 	ADC_WDT_CHANNEL12	ADC_WDT_CHANNEL13	ADC_WDT_CHANNEL14	ADC_WDT_CHANNEL15
 * 	ADC_WDT_CHANNEL16	ADC_WDT_CHANNEL17
 * 	*/

/*	External Event Trigger Regular Channel ADC1 or ADC2 (ADC3) :
 * 	TIM1_CC1_EVE 	(TIM3_CC1_EVE)	TIM1_CC2_EVE (TIM2_CC3_EVE)	TIM1_CC3_EVE (TIM1_CC3_EVE)
 * 	TIM2_CC2_EVE 	(TIM8_CC1_EVE)	TIM3_TRI_EVE (TIM8_TRI_EVE)	TIM4_CC4_EVE (TIM5_CC1_EVE)
 * 	EXTI_TIM8_TRI	(TIM5_CC3_EVE)	SWSTART	(SWSTART)
 */
#define ADC_REG_EXT_TRIG_EVE	SWSTART

/*	External Event Trigger Injected Channel ADC1 or ADC2 (ADC3) :
 * 	TIM1_TRI_EVE 	(TIM1_TRI_EVE)	TIM1_CC4_EVE (TIM1_CC4_EVE)	TIM2_TRI_EVE (TIM4_CC3_EVE)
 * 	TIM2_CC1_EVE 	(TIM8_CC2_EVE)	TIM3_CC4_EVE (TIM8_CC4_EVE)	TIM4_TRI_EVE (TIM5_TRI_EVE)
 * 	EXTI_TIM8_CC4	(TIM5_CC4_EVE)	JSWSTART	 (JSWSTART)
 */
#define ADC_INJ_EXT_TRIG_EVE	SWSTART

/*	Sampling Time
 * 	CYC_1_5		CYC_7_5		CYC_13_5	CYC_28_5
 * 	CYC_41_5	CYC_55_5	CYC_71_5	CYC_239_5
 */
#define ADC_SAMP_TIM	CYC_1_5


/*	ADC_ALIGN
 *  RIGHT_ALIGN		LEFT_ALIGN
 */
#define ADC_ALIGN		RIGHT_ALIGN

/*	ADC_DMA_SET	: ADC_EN	ADC_DIS*/
#define 	ADC_DMA_SET	ADC_DIS

/*	Injection Channel Conversion length :
 * 	INJ_ONE_CONV	INJ_TWO_CONV	INJ_THR_CONV	INJ_FOU_CONV
 */
#define INJ_CONV_L		INJ_ONE_CONV

/*	ADC Channel Numbers
 * 	ADC_CHANNEL0	ADC_CHANNEL1	ADC_CHANNEL2	ADC_CHANNEL3
 * 	ADC_CHANNEL4	ADC_CHANNEL5	ADC_CHANNEL6	ADC_CHANNEL7
 * 	ADC_CHANNEL8	ADC_CHANNEL9	ADC_CHANNEL10	ADC_CHANNEL11
 * 	ADC_CHANNEL12	ADC_CHANNEL13	ADC_CHANNEL14	ADC_CHANNEL15
 * 	ADC_CHANNEL16	ADC_CHANNEL17
 */

/*	ADC  Injected Channel Numbers
 * 	ADC_INJ_CH1		ADC_INJ_CH2		ADC_INJ_CH3		ADC_INJ_CH4
 */

/*	ADC_MODE :
 * 	SINGLE_CONV 	CONT_CONV	SCAN_MODE
 */

#define ADC_MODE		SINGLE_CONV

#endif /* ADC_CONFIG_H_ */
