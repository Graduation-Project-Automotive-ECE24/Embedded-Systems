/*
 * ADC_Private.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Mostafa Sayed
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

// struct data type to prevent repeating in code
typedef struct {					// offset
	volatile uint32_t ADC_SR;		// 0x00
	volatile uint32_t ADC_CR1;		// 0x04
	volatile uint32_t ADC_CR2;		// 0x08
	volatile uint32_t ADC_SMPR1;	// 0x0C

	volatile uint32_t ADC_SMPR2;	// 0x10
	volatile uint32_t ADC_JOFR1;	// 0x14
	volatile uint32_t ADC_JOFR2;	// 0x18
	volatile uint32_t ADC_JOFR3;	// 0x1C

	volatile uint32_t ADC_JOFR4;	// 0x20
	volatile uint32_t ADC_HTR;		// 0x24
	volatile uint32_t ADC_LTR;		// 0x28
	volatile uint32_t ADC_SQR1;		// 0x2C

	volatile uint32_t ADC_SQR2;		// 0x30
	volatile uint32_t ADC_SQR3;		// 0x34
	volatile uint32_t ADC_JSQR;		// 0x38
	volatile uint32_t ADC_JDR1;		// 0x3C

	volatile uint32_t ADC_JDR2;		// 0x40
	volatile uint32_t ADC_JDR3;		// 0x44
	volatile uint32_t ADC_JDR4;		// 0x48
	volatile uint32_t ADC_DR;		// 0x4C
}ADC_REG;

// Macros for base address of registers
#define	ADC1_BASE	 ((volatile ADC_REG*)(0x40012400))
#define	ADC2_BASE	 ((volatile ADC_REG*)(0x40012800))
#define	ADC3_BASE	 ((volatile ADC_REG*)(0x40013C00))
#define NULL		 (void*) 0LL

// Enum used to select Certain ADC
typedef enum{
	ADC1_enum,
	ADC2_enum,
	ADC3_enum,
}ADC_REG_NUM;

// Selecting Group of ADC Channels
typedef enum{
	REGULAR,
	INJECTED,
	WDT_ADC,
}ADC_TYPE;

// typedef of pointer to function to increase readability
typedef void(*ptr2fun)(void);

//		 ADC_SR		 0x00
#define STRT 		 4			// Regular Channel Start Flag (CLR by SW , SET by HW)
#define JSTRT		 3			// Injected Channel Start Flag (CLR by SW , SET by HW)
#define JEOC		 2			// Injected Channel End Of Conversion flag (CLR by SW , SET by HW)
#define EOC	    	 1			// Regular Channel End Of Conversion flag (CLR by SW , SET by HW)
#define AWD		 	 0			// Analog Watchdog flag (SET by HW when Voltage cross ADC_LTR & ADC_HTR , CLR by SW)

// 		ADC_CR1	 	 0x04
#define AWDEN		 23			// Enable Watchdog on regular channels
#define JAWDEN		 22			// Enable Watchdog on injected channels
#define DUALMOD3	 19			// Dual Mode Selection
#define DUALMOD2	 18
#define DUALMOD1	 17
#define DUALMOD0	 16
#define DISCNUM2	 15			// Define the number of regular channels to be converted in discontinuous mode
#define DISCNUM1	 14
#define DISCNUM0	 13
#define JDISCEN		 12			// Enable/Disable Discontinous mode on injected group
#define DISCEN		 11			// Enable/Disable Discontinous mode on regular group
#define JAUTO		 10         // Enable/Disable automatic injected group conversion after regular group conversion.
#define AWDSGL		 9		    // Enable/Disable the analog watchdog on the channel identified by the AWDCH[4:0] bits.
#define SCAN		 8			// Enable/Disable Scan mode. In Scan mode
#define JEOCIE 		 7			// Enable/Disable the end of conversion interrupt for injected channels.
#define AWDIE		 6			// Enable/Disable the analog watchdog interrupt. in scan mode , scan is aborted if threshold is crossed
#define EOCIE		 5			// Enable/Disable the End of Conversion interrupt.
#define AWDCH4		 4 			// select the input channel to be guarded by the Analog watchdog.
#define AWDCH3		 3
#define AWDCH2		 2
#define AWDCH1		 1
#define AWDCH0		 0

//	   	ADC_CR2	 	 0x08
#define TSVREFE		 23 		//  enable/disable the temperature sensor and VREFINT channel (in dual ADCs, ADC1 only)
#define SWSTART		 22 		//  start conversion of regular channels (SET by SW , CLR by HW)
#define JSWSTART	 21 		//  start conversion of injected channels (SET by SW , CLR by HW)
#define EXITRIG		 20 		//  enable/disable the external trigger used to start conversion of a regular channel group
#define EXTSEL2		 19  		//  select trigger the start of conversion of a regular group
#define EXTSEL1		 18
#define EXTSEL0		 17
#define JEXTTRIG	 15			// 	 enable/disable the external trigger used to start conversion of an injected channel group
#define JEXTSEL2	 14 		//   Select trigger the start of conversion of an injected
#define JEXTSEL1	 13
#define JEXTSEL0	 12
#define ALIGN		 11			// 0 -> Right Alignment , 1 -> Left Alignment
#define DMA			 8			// Enable/Disable DMA mode
#define RSTCAL		 3			// Cleared after CAL register are initialized (1 -> to init REG CAL)
#define CAL			 2			// Reset by HW after CAL and enable CAL when SET
#define CONT		 1			// Enable/Disable Continous Conversion
#define ADON		 0			// Wake ADC from Power down when SET while it was CLR, CLR this bit make PW DN mode active

//		ADC_SMPR1	 0x0C
#define ADC_SMP17	 21
#define ADC_SMP16	 18
#define ADC_SMP15	 15
#define ADC_SMP14	 12
#define ADC_SMP13	 9
#define ADC_SMP12	 6
#define ADC_SMP11	 3
#define ADC_SMP10	 0

//		ADC_SMPR2	 0x10
#define ADC_SMP9	 27
#define ADC_SMP8	 24
#define ADC_SMP7	 21
#define ADC_SMP6	 18
#define ADC_SMP5	 15
#define ADC_SMP4	 12
#define ADC_SMP3	 9
#define ADC_SMP2	 6
#define ADC_SMP1	 3
#define ADC_SMP0	 0

// 		ADC_JOFR1	 0x14		 // define the offset to be subtracted from the raw converted data when converting injected channels
// 		ADC_JOFR2	 0x18
// 		ADC_JOFR3	 0x1C
//		ADC_JOFR4	 0x20

//		ADC_HTR		 0x24 		// Define the high threshold for the analog watchdog.
//		ADC_LTR		 0x28 		// Define the low threshold for the analog watchdog.

// 		ADC_SQR1	 0x2C
#define ADC_L		 20 		// Define Number of conversions from 1 to 16
#define SQ16		 15			// These bits are written by software with the channel number (0..17) assigned as 16th in conversion sequence
#define SQ15		 10			// These bits are written by software with the channel number (0..17) assigned as 15th in conversion sequence
#define SQ14		 5			// These bits are written by software with the channel number (0..17) assigned as 14th in conversion sequence
#define SQ13		 0			// These bits are written by software with the channel number (0..17) assigned as 13th in conversion sequence

// 		ADC_SQR2	 0x30
#define SQ12		 25			// These bits are written by software with the channel number (0..17) assigned as 12th in conversion sequence
#define SQ11		 20			// These bits are written by software with the channel number (0..17) assigned as 11th in conversion sequence
#define SQ10		 15			// These bits are written by software with the channel number (0..17) assigned as 10th in conversion sequence
#define SQ9			 10			// These bits are written by software with the channel number (0..17) assigned as 9th in conversion sequence
#define SQ8			 5			// These bits are written by software with the channel number (0..17) assigned as 8th in conversion sequence
#define SQ7			 00			// These bits are written by software with the channel number (0..17) assigned as 7th in conversion sequence

//		ADC_SQR3	 0x34
#define SQ6			 25			// These bits are written by software with the channel number (0..17) assigned as 6th in conversion sequence
#define SQ5			 20			// These bits are written by software with the channel number (0..17) assigned as 5th in conversion sequence
#define SQ4			 15			// These bits are written by software with the channel number (0..17) assigned as 4th in conversion sequence
#define SQ3			 10			// These bits are written by software with the channel number (0..17) assigned as 3rd in conversion sequence
#define SQ2			 5			// These bits are written by software with the channel number (0..17) assigned as 2nd in conversion sequence
#define SQ1			 0			// These bits are written by software with the channel number (0..17) assigned as 1st in conversion sequence

//		ADC_JSQR	 0x38
#define ADC_JL1		 21    		// define the total number of conversions in the injected channel conversion sequence.
#define ADC_JL0		 20
#define JSQ4		 15			// These bits are written by software with the channel number (0..17) assigned as 4th in conversion sequence
#define JSQ4		 10			// These bits are written by software with the channel number (0..17) assigned as 3rd in conversion sequence
#define JSQ4		 5			// These bits are written by software with the channel number (0..17) assigned as 2nd in conversion sequence
#define JSQ4		 0			// These bits are written by software with the channel number (0..17) assigned as 1st in conversion sequence

// 		ADC_JDR1	 0x3C		// Contain the conversion result from injected channel
// 		ADC_JDR2	 0x40
// 		ADC_JDR3	 0x44
// 		ADC_JDR4	 0x48


//		ADC_DR		 0x4C
#define	ADC2DATA	 16 	// Contain regular data of ADC2 in Dual mode (Not used in ADC2 & ADC3)
#define DATA		 0		// Contain Conversion Result


/*			Macros				*/

/*			Dual Mode			(DUALMOD[3:0] - ADC_CR1)*/
#define INDEP_MOD			0
#define COMB_REG_INJ		1
#define COMB_REG_ALT		2
#define COMB_INJ_FAST		3
#define COMB_INJ_SLOW		4
#define INJ_SIM				5
#define REG_SIM				6
#define FAST_INTER			7
#define SLOW_INTER			8
#define ALT_TRIG			9


/*			Discontinous Mode	(DISCNUM[2:0] - ADC_CR1)*/
#define ADC_DIS_CHANNEL1		0
#define ADC_DIS_CHANNEL2		1
#define ADC_DIS_CHANNEL3		2
#define ADC_DIS_CHANNEL4		3
#define ADC_DIS_CHANNEL5		4
#define ADC_DIS_CHANNEL6		5
#define ADC_DIS_CHANNEL7		6
#define ADC_DIS_CHANNEL8		7


/*			WDT Guarded Channel	(AWDCH[4:0] - ADC_CR1)*/
#define	ADC_WDT_CHANNEL0	0
#define	ADC_WDT_CHANNEL1	1
#define	ADC_WDT_CHANNEL2	2
#define	ADC_WDT_CHANNEL3	3
#define	ADC_WDT_CHANNEL4	4
#define	ADC_WDT_CHANNEL5	5
#define	ADC_WDT_CHANNEL6	6
#define	ADC_WDT_CHANNEL7	7
#define	ADC_WDT_CHANNEL8	8
#define	ADC_WDT_CHANNEL9	9
#define	ADC_WDT_CHANNEL10	10
#define	ADC_WDT_CHANNEL11	11
#define	ADC_WDT_CHANNEL12	12
#define	ADC_WDT_CHANNEL13	13
#define	ADC_WDT_CHANNEL14	14
#define	ADC_WDT_CHANNEL15	15
#define	ADC_WDT_CHANNEL16	16
#define	ADC_WDT_CHANNEL17	17

/*	Note :
 * 	ADC1	Channel 16 and Channel 17 are connected to temperature sensor and Vrefint repectively
 * 	ADC2	Channel 16 and Channel 17 are connected to Vss
 * 	ADC3	Channel 9, Channel 14, Channel 15, Channel 16 and Channel 17 are connected to VSS
 *
 * */

/* 		External Event Trigger Regular Channel		(EXTSEL[3:0] - ADC_CR2)*/
/*		for ADC1 and ADC2						     */
#define	TIM1_CC1_EVE		0
#define	TIM1_CC2_EVE		1
#define	TIM1_CC3_EVE		2
#define	TIM2_CC2_EVE		3
#define	TIM3_TRI_EVE		4
#define	TIM4_CC4_EVE		5
#define	EXTI_TIM8_TRI		6
#define	SWSTART				7
/*		for ADC3									*/
#define	TIM3_CC1_EVE		0
#define	TIM2_CC3_EVE		1
#define	TIM1_CC3_EVE		2
#define	TIM8_CC1_EVE		3
#define	TIM8_TRI_EVE		4
#define	TIM5_CC1_EVE		5
#define	TIM5_CC3_EVE		6
#define	SWSTART				7

/* 		External Event Trigger Injected Channel		(JEXTSEL[3:0] - ADC_CR2)*/
/*		for ADC1 and ADC2				 		     */
#define	TIM1_TRI_EVE		0
#define	TIM1_CC4_EVE		1
#define	TIM2_TRI_EVE		2
#define	TIM2_CC1_EVE		3
#define	TIM3_CC4_EVE		4
#define	TIM4_TRI_EVE		5
#define	EXTI_TIM8_CC4		6
#define	JSWSTART			7
/*		for ADC3									*/
#define	TIM1_TRI_EVE		0
#define	TIM1_CC4_EVE		1
#define	TIM4_CC3_EVE		2
#define	TIM8_CC4_EVE		3
#define	TIM8_TRI_EVE		4
#define	TIM5_TRI_EVE		5
#define	TIM5_CC4_EVE		6
#define	JSWSTART			7

/*		Sampling Time    (SMPx[2:0] - ADC_SMPRx)	*/
#define CYC_1_5			0
#define CYC_7_5			1
#define CYC_13_5		2
#define CYC_28_5		3
#define CYC_41_5		4
#define CYC_55_5		5
#define CYC_71_5		6
#define CYC_239_5		7

/*		Injected Channel Conversion Length			*/
#define INJ_ONE_CONV	0
#define INJ_TWO_CONV	1
#define INJ_THR_CONV	2
#define INJ_FOU_CONV	3

/* 		ADC Channel									*/
#define ADC_CHANNEL0		0
#define ADC_CHANNEL1		1
#define ADC_CHANNEL2		2
#define ADC_CHANNEL3		3
#define ADC_CHANNEL4		4
#define ADC_CHANNEL5		5
#define ADC_CHANNEL6		6
#define ADC_CHANNEL7		7
#define ADC_CHANNEL8		8
#define ADC_CHANNEL9		9
#define ADC_CHANNEL10		10
#define ADC_CHANNEL11		11
#define ADC_CHANNEL12		12
#define ADC_CHANNEL13		13
#define ADC_CHANNEL14		14
#define ADC_CHANNEL15		15
#define ADC_CHANNEL16		16
#define ADC_CHANNEL17		17

/*		ADC Setting (Enable and Disable)	*/
#define	ADC_DIS				0
#define ADC_EN				1

/*		ADC Alignment						*/
#define RIGHT_ALIGN		0
#define LEFT_ALIGN		1
/*		ADC Mode							*/
#define	SINGLE_CONV		0
#define	CONT_CONV		1
#define	SCAN_MODE		2

/*	ADC  Injected Channel Numbers			*/
#define 	ADC_INJ_CH1		0
#define		ADC_INJ_CH2		1
#define		ADC_INJ_CH3		2
#define		ADC_INJ_CH4     3


#endif /* ADC_PRIVATE_H_ */
