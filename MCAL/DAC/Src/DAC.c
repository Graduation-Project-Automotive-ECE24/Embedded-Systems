/*
 * DAC.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Mostafa Sayed
 */
#include "../Inc/DAC.h"

void 	 DAC_voidInit	( uint8_t Copy_u8ChannelNum )
{
	uint32_t DAC_CR_CH 	  = 0000;
	DAC_REG  *DAC_register = &DAC_BASE;

	DAC_CR_CH |= (DAC_DMA_CH1 << DMAEN1);
	DAC_CR_CH |= (DAC_MSK_AMP_CH1 << MAMP1_0);
	DAC_CR_CH |= (DAC_WAVE_CH1 << WAVE1_0);
	DAC_CR_CH |= (DAC_TRIG_EVE_CH1 << TSEL1_0);
	DAC_CR_CH |= (DAC_TRIG_SET_CH1 << TEN1);
	DAC_CR_CH |= (DAC_BUFF_SET_CH1 << BOFF1);
	DAC_CR_CH |= (DAC_EN << EN1);

	DAC_CR_CH |= (DAC_DMA_CH2 << DMAEN2);
	DAC_CR_CH |= (DAC_MSK_AMP_CH2 << MAMP2_0);
	DAC_CR_CH |= (DAC_WAVE_CH2 << WAVE2_0);
	DAC_CR_CH |= (DAC_TRIG_EVE_CH2 << TSEL2_0);
	DAC_CR_CH |= (DAC_TRIG_SET_CH2 << TEN2);
	DAC_CR_CH |= (DAC_BUFF_SET_CH2 << BOFF2);
	DAC_CR_CH |= (DAC_EN << EN2);

	if(Copy_u8ChannelNum == DAC_OUT_CH1 )
	{
		DAC_register-> DAC_CR	  |= 	DAC_CR_CH & ONLY_CH1;
	}
	else if (Copy_u8ChannelNum == DAC_OUT_CH2)
	{
		DAC_register-> DAC_CR	  |=    	DAC_CR_CH & ONLY_CH2;
	}
	else
	{
		DAC_register-> DAC_CR	  |=    	DAC_CR_CH;
	}


}
uint32_t DAC_u32Out 	(uint16_t Copy_u16DACValue , uint8_t Copy_u8ChannelNum )
{
	DAC_REG  *DAC_register = &DAC_BASE;
	static uint8_t counter = 0;
	uint16_t data = 0;
	if(Copy_u8ChannelNum == DAC_OUT_CH1)
	{
		#if DAC_REG_RES_CH1 == DAC_REG_RES_8BIT
			DAC_register->DAC_DHR8R1 &= 0;
			DAC_register->DAC_DHR8R1 |= (uint8_t)(0x000000FF & Copy_u16DACValue);
		#else
			#if DAC_DATA_ALIG_CH1	== DAC_RIGHT_ALIG
				DAC_register->DAC_DHR12R1 |= 0x00000FFF & Copy_u16DACValue;
			#else
				DAC_register->DAC_DHR12L1 = (0x00000FFF & Copy_u16DACValue << 4);
			#endif
		#endif
				DAC_register-> DAC_SWTRIGR |= (DAC_SWTRIG_CH1 << SWTIG1);
				while(GET_BIT(DAC_register-> DAC_SWTRIGR,SWTIG1));
				data = DAC_register->DAC_DOR1;
	}
	else if (Copy_u8ChannelNum == DAC_OUT_CH2)
	{
		#if DAC_REG_RES_CH2 == DAC_REG_RES_8BIT
			DAC_register->DAC_DHR8R2 = 0x000000FF & Copy_u16DACValue;
		#else
			#if DAC_DATA_ALIG_CH2	== DAC_RIGHT_ALIG
				DAC_register->DAC_DHR12R2 = 0x00000FFF & Copy_u16DACValue;
			#else
				DAC_register->DAC_DHR12L2 = (0x00000FFF & Copy_u16DACValue) << 4;
			#endif
		#endif
				DAC_register-> DAC_SWTRIGR = (DAC_SWTRIG_CH2 << SWTIG2);
				data = DAC_register->DAC_DOR2;
	}
	else
	{
		if(counter == 0)
		{
			#if DAC_REG_RES_CH1 == DAC_REG_RES_8BIT
				DAC_register->DAC_DHR8RD = 0x000000FF & Copy_u16DACValue;
			#else
				#if DAC_DATA_ALIG_CH1	== DAC_RIGHT_ALIG
					DAC_register->DAC_DHR12R1 = (0x00000FFF & Copy_u16DACValue);
				#else
					DAC_register->DAC_DHR12L1 = (0x00000FFF & Copy_u16DACValue) << 4;
				#endif
			#endif
					counter++;
		}
		else
		{
			#if DAC_REG_RES_CH2 == DAC_REG_RES_8BIT
				DAC_register->DAC_DHR8R2 = (0x000000FF &  Copy_u16DACValue) << 8;
			#else
				#if DAC_DATA_ALIG_CH2	== DAC_RIGHT_ALIG
					DAC_register->DAC_DHR12R2 = (0x00000FFF & Copy_u16DACValue);
				#else
					DAC_register->DAC_DHR12L2 = (0x00000FFF & Copy_u16DACValue) << 4;
				#endif
			#endif
					counter = 0;
		}
		DAC_register-> DAC_SWTRIGR |=	(DAC_SWTRIG_CH2 << SWTIG2) | (DAC_SWTRIG_CH1 << SWTIG1);
		data = (DAC_register->DAC_DOR2 << 16)| (DAC_register->DAC_DOR1);

	}
	return data;

}
void	 DAC_voidStop	( uint8_t Copy_u8ChannelNum )
{
	DAC_REG  *DAC_register = &DAC_BASE;
	if(Copy_u8ChannelNum == DAC_OUT_CH1)
	{
		DAC_register->DAC_CR &= ~(1 << EN1);
	}
	else if(Copy_u8ChannelNum == DAC_OUT_CH2)
	{
		DAC_register->DAC_CR &= ~(1 << EN2);
	}
	else{
		DAC_register->DAC_CR &= ~(1 << EN1);
		DAC_register->DAC_CR &= ~(1 << EN2);
	}
}
