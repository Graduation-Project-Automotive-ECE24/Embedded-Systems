/*
 * ADC.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mostafa Sayed
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "../../../BIT_Math.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/*				Enums								*/

/* ADC_TYPE
 * REGULAR 	INJECTED	WDT_ADC
 * */

/* ADC_REG_NUM
 * ADC1_enum 	ADC2_enum	ADC3_enum
 * */

/*				APIs								*/
void 	 ADC_voidInit	 	 	(ADC_REG_NUM local_u8ADC);
void 	 ADC_voidSampleTime	 	(ADC_REG_NUM local_u8ADC,uint8_t Copy_u8SampleTime , uint8_t Copy_u8ChannelNum);
void 	 ADC_voidInjectedOffset	(ADC_REG_NUM local_u8ADC,uint8_t Copy_u8InjectedOffset, uint8_t Copy_u8ChannelNum);
void	 ADC_voidWathdogThreshold(ADC_REG_NUM local_u8ADC,uint8_t Copy_u8Upper, uint8_t Copy_u8Lower);
void 	 ADC_voidSequence		(ADC_REG_NUM local_u8ADC,ADC_TYPE local_u8ADC_Type,uint8_t* local_u8SeqArray , uint8_t ConvNum);
uint32_t ADC_u32Read	 	 	(ADC_REG_NUM local_u8ADC,ADC_TYPE local_u8ADC_Type , uint8_t channel_num);
void 	 ADC_voidSetCallbackFun (ptr2fun);
void     ADC_voidStop	 		(ADC_REG_NUM local_u8ADC);



/*
 * Important Documentation:
 * 	STM32f103 is eiher medium density or High Density device
 * 	Analog Watch-dog feature : allows the application to detect if the input voltage goes outside the user-defined high or low thresholds.
 * 	The ADC input clock is generated from the PCLK2 clock divided by a prescaler and it must not exceed 14 MHz
 *
 *	If normal group conversion is going on and injected conversion is triggered, then normal conversion is halted,
 *	then injected conversion is performed, then normal conversion is resumed. Injected conversion channels have their result registers and offset registers.
 *	The offset can store a value that will be deducted from the ADC result automatically.
 *	The injected group channels converted data value is decreased by the user-defined offset so the result can be a negative value.
 *	for regular group channels no offset is subtracted so only twelve bits are significant.
 *
 *	Internal Temperature sensor connected to channel 16
 *
 *	The ADCCLK clock provided by the Clock Controller is synchronous with the PCLK2 (APB2 clock).
 *	The RCC controller has a dedicated programmable prescaler for the ADC clock.
 *
 *	Modes of Operation:
 *		Single Mode 		: ADC does one Conversion and halt.
 *		Continuous Mode 	: ADC starts another conversion as soon as it finishes one
 *		Scan Mode			: ADC scans all the channels selected in the ADC_SQRx registers (for regular channels) or in the ADC_JSQR (for injected channels).
 *							  A single conversion is performed for each channel of the group. stop at the last selected group channel
 *		Discontinuous Mode 	: convert a short sequence of n conversions (n <=8) which is a part of the sequence of conversions selected in the ADC_SQRx registers.
 *
 *	Analog Watch-Dog		:
 *		The AWD analog watchdog status bit is set if the analog voltage converted by the ADC is
 *		below a low threshold or above a high threshold.
 *
 *
 *	Injection Management	:
 *		Triggered Injection : External Trigger causing interrupting of current regular conversion until end of injected conversion then resume regular conversion
 *		Auto Injection		: the injected group channels are automatically converted after the regular group channels. (used to perform up to 20 conversions)
 *
 *	Calibration		    :
 *		reduce accuracy error due to internal capacitor by calculating error correction code for each capacitor to remove error introduced by them
 *		recommended to calibrate the ADC once at power-on
 *
 *	Sampling Time		:
 *		Each channel can be sampled with a different sample time.
 *		The total conversion time is calculated as follows:
 *		Tconv = Sampling time + 12.5 cycles
 *
 *	DMA Request			:
 *		it is necessary to use DMA for conversion of more than one regular channel.
 *		Only the end of conversion of a regular channel generates a DMA request, which allows the
 *		transfer of its converted data from the ADC_DR register to the destination location selected by the user.
 *
 *	Dual ADC mode		:
 *		the start of conversion is triggered alternately or simultaneously by the ADC1 master to the ADC2 slave
 *
 *		Injected simultaneous mode:
 *			This mode converts an injected channel group. The source of external trigger comes from the injected group mux of ADC1
 *			A simultaneous trigger is provided to ADC2.
 *
 *		Regular simultaneous mode:
 *			This mode converts a regular channel group. The source of external trigger comes from the injected group mux of ADC1
 *			A simultaneous trigger is provided to ADC2.
 *
 *		Fast interleaved mode:
 *			 After an external trigger occurs:
 *				● ADC2 starts immediately and
 *				● ADC1 starts after a delay of 7 ADC clock cycles.
 *
 *		 Slow interleaved mode:
 *			 After an external trigger occurs:
 *				● ADC2 starts immediately and
 *				● ADC1 starts after a delay of 14 ADC clock cycles.
 *				● ADC2 starts after a second delay of 14 ADC cycles, and so on.
 *
 *		Alternate trigger mode:
 *			 started only on an injected channel group. The source of external trigger comes from the injected group mux of ADC1.
 *				● When the 1st trigger occurs, all injected group channels in ADC1 are converted.
 *				● When the 2nd trigger arrives, all injected group channels in ADC2 are converted
 *				● and so on.
 *
 *		Independent mode:
 *		In this mode the dual ADC synchronization is bypassed and each ADC interfaces works independently
 *
 *		Combined regular/injected simultaneous mode:
 *			It is possible to interrupt simultaneous conversion of a regular group to start simultaneous conversion of an injected group.
 *
 *		Combined regular simultaneous + alternate trigger mode:
 *			It is possible to interrupt regular group simultaneous conversion to start alternate trigger conversion of an injected group.
 *
 *		Combined injected simultaneous + interleaved
 *			It is possible to interrupt an interleaved conversion with an injected event. In this case the interleaved conversion is interrupted
 *			and the injected conversion starts, at the end of the injected sequence the interleaved conversion is resumed.
 *
 *		Temperature sensor
 *		The temperature sensor can be used to measure the ambient temperature (TA) of the device.
 *
 * */

#endif /* ADC_H_ */
