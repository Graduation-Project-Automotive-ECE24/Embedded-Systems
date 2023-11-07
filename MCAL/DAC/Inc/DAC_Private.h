/*
 * DAC_Private.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Mostafa Sayed
 */

#ifndef DAC_PRIVATE_H_
#define DAC_PRIVATE_H_

typedef struct {
	volatile uint32_t DAC_CR;
	volatile uint32_t DAC_SWTRIGR;

	volatile uint32_t DAC_DHR12R1;	/* These bits are written by software which specify 12-bit data for DAC channel1 */
	volatile uint32_t DAC_DHR12L1;	// These bits are written by software which specify 12-bit data for DAC channel1
	volatile uint32_t DAC_DHR8R1;	// These bits are written by software which specify 8-bit data for DAC channel1

	volatile uint32_t DAC_DHR12R2;  // These bits are written by software which specify 12-bit data for DAC channel2
	volatile uint32_t DAC_DHR12L2;	// These bits are written by software which specify 12-bit data for DAC channel2
	volatile uint32_t DAC_DHR8R2;	// These bits are written by software which specify 8-bit data for DAC channel1

	volatile uint32_t DAC_DHR12RD;	// These bits are written by software which specify 12-bit data for DAC Dual Mode
	volatile uint32_t DAC_DHR12LD;  // These bits are written by software which specify 12-bit data for DAC Dual Mode
	volatile uint32_t DAC_DHR8RD;  // These bits are written by software which specify 8-bit data for DAC Dual Mode

	volatile uint32_t DAC_DOR1;		// These bits are read only, they contain data output for DAC channel1
	volatile uint32_t DAC_DOR2;		// These bits are read only, they contain data output for DAC channel2


} DAC_REG;

#define DAC_BASE	(*(volatile DAC_REG*) (0x40007400))

// 	DAC_CR			0x00
#define DMAEN2		28   // DAC channel2 DMA enable (SET,CLR by SW)
#define MAMP2_3		27	 // select mask in wave generation mode or amplitude in triangle generation mode.
#define MAMP2_2		26
#define MAMP2_1		25
#define MAMP2_0		24
#define WAVE2_1		23	// Select Noise wave or Triangular wave or disable wave generation
#define WAVE2_0		22
#define TSEL2_2		21	// select the external event used to trigger DAC channel2
#define TSEL2_1		20
#define TSEL2_0		19
#define TEN2		18	// Enable Channel 2 Trigger
#define BOFF2		17	// enable/disable DAC channel2 output buffer.
#define EN2			16	// enable/disable DAC channel2.
#define DMAEN1		12	// DMA Enable/Disable
#define MAMP1_3		11	 // select mask in wave generation mode or amplitude in triangle generation mode.
#define MAMP1_2		10
#define MAMP1_1		9
#define MAMP1_0		8
#define WAVE1_1		7	// Select Noise wave or Triangular wave or disable wave generation
#define WAVE1_0		6
#define TSEL1_2		5	// select the external event used to trigger DAC channel1
#define TSEL1_1		4
#define TSEL1_0		3
#define TEN1		2	// Enable Channel 1 Trigger
#define BOFF1		1	// enable/disable DAC channel1 output buffer.
#define EN1			0	// enable/disable DAC channel1.

// 	DAC_SWTRIG		0x04
#define SWTIG2		1	// to enable/disable the software trigger for channel 2
#define SWTIG1		0	// to enable/disable the software trigger for channel 1

/* Trigger Event */
#define DAC_TIM6_TRIGO	0
#define DAC_TIM3_TRIGO	1
#define DAC_TIM7_TRIGO	2
#define DAC_TIM5_TRIGO	3
#define DAC_TIM2_TRIGO	4
#define DAC_TIM4_TRIGO	5
#define DAC_EXTY_TRIGO	6
#define DAC_SWTRIG		7

/*			DAC	Noise waveform or triangular waveform properties			*/
#define DAC_LFSR0_AMP1		0
#define DAC_LFSR1_AMP3		1
#define DAC_LFSR2_AMP7		2
#define DAC_LFSR3_AMP15		3
#define DAC_LFSR4_AMP31		4
#define DAC_LFSR5_AMP63		5
#define DAC_LFSR6_AMP127	6
#define DAC_LFSR7_AMP255	7
#define DAC_LFSR8_AMP511	8
#define DAC_LFSR9_AMP1023	9
#define DAC_LFSR10_AMP2047	10
#define DAC_LFSR11_AMP4095	11

/*		DAC Waveform 			*/
#define DAC_WAVE_DIS		0
#define DAC_WAVE_NO			1
#define DAC_WAVE_TRI		2

/*	DAC Triggering event */
#define DAC_TRIG_TIM6		0
#define DAC_TRIG_TIM3		1
#define DAC_TRIG_TIM7		2
#define DAC_TRIG_TIM5		3
#define DAC_TRIG_TIM2		4
#define DAC_TRIG_TIM4		5
#define DAC_TRIG_EXT		6
#define DAC_SWTRIG			7

/*	DAC Resolution  */
#define DAC_REG_RES_8BIT	0
#define DAC_REG_RES_12BIT	1

/*	DAC Alignment	*/
#define DAC_RIGHT_ALIG		0
#define DAC_LEFT_ALIG		1

/*	DAC Output Channel		*/
#define DAC_OUT_CH1			0
#define DAC_OUT_CH2			1
#define DAC_OUT_DUAL		2

/*	DAC Setting				*/
#define	DAC_DIS				0
#define	DAC_EN				1

/* Auxiliary Macros			*/
#define ONLY_CH1	0x0000FFFF
#define ONLY_CH2	0xFFFF0000

#endif /* DAC_PRIVATE_H_ */
