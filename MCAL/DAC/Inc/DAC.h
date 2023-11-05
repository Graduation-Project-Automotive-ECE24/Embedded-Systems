/*
 * DAC.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Mostafa Sayed
 */

#ifndef SRC_MCAL_DAC_DAC_H_
#define SRC_MCAL_DAC_DAC_H_

#include <stdint.h>
#include "../../../BIT_Math.h"
#include "DAC_Config.h"
#include "DAC_Private.h"


/*
 * Copy_u8ChannelNum : DAC_OUT_CH1	DAC_OUT_CH2 	DAC_OUT_DUAL
 * Copy_u16DACValue	 :
 * 0 - 255 	for 8 -bit resolution
 * 0 - 4095	for 12-bit resolution
 */

/*			APIs 	*/
void 	 DAC_voidInit	( uint8_t Copy_u8ChannelNum );
uint32_t DAC_u32Out 	(uint16_t Copy_u16DACValue , uint8_t Copy_u8ChannelNum );
void	 DAC_voidStop	( uint8_t Copy_u8ChannelNum );

/*
 * Important Notes:
 * In dual DAC channel mode, conversions could be done independently or simultaneously
 *
 * The DAC integrates two output buffers that can be used to reduce the output impedance,
 * and to drive external loads directly without having to add an external operational amplifier.
 *
 * DACoutput =  V_REF * DOR / 4095
 * TSELx[2:0] bit cannot be changed when the ENx bit is set.
 * Noise Generation : to generate a variable-amplitude pseudonoise, a Linear Feedback Shift Register is available
 * Triangle-wave generation :  to add a small-amplitude triangular waveform on a DC or slowly varying signal.
 * */


#endif /* SRC_MCAL_DAC_DAC_H_ */
