#include "../Inc/ADC.h"

void 	 ADC_voidInit(ADC_REG_NUM local_u8ADC)
{
	ADC_REG* local_ptr2ADC = NULL;

	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	}

	local_ptr2ADC->ADC_CR1 |= (WDT_ON_REG << AWDEN);
	local_ptr2ADC->ADC_CR1 |= (WDT_ON_INJ << JAWDEN);
	local_ptr2ADC->ADC_CR1 |= (DUAL_MODE  << DUALMOD0);
	local_ptr2ADC->ADC_CR1 |= (ADC_REG_DISCONT<< DISCNUM0);

	local_ptr2ADC->ADC_CR1 |= (DISCONT_ON_REG << DISCEN);
	local_ptr2ADC->ADC_CR1 |= (DISCONT_ON_INJ << JDISCEN);
	local_ptr2ADC->ADC_CR1 |= (AUTO_INJ << JAUTO);
	local_ptr2ADC->ADC_CR1 |= (ANALOG_WDT_SET << AWDSGL);

	local_ptr2ADC->ADC_CR1 |= (SCAN_SET << SCAN);
	local_ptr2ADC->ADC_CR1 |= (INJ_EOC_INT << JEOCIE);
	local_ptr2ADC->ADC_CR1 |= (WDT_INT << AWDIE);
	local_ptr2ADC->ADC_CR1 |= (EOC_INT_SET << EOCIE);

	local_ptr2ADC->ADC_CR1 |= (SCAN_SET << AWDCH0);

	local_ptr2ADC->ADC_CR2 |= (EXT_TRIG_REG_EN	<< EXITRIG);
	local_ptr2ADC->ADC_CR2 |= (ADC_REG_EXT_TRIG_EVE << EXTSEL0);
	local_ptr2ADC->ADC_CR2 |= (EXT_TRIG_INJ_EN	<< JEXTTRIG);
	local_ptr2ADC->ADC_CR2 |= (ADC_INJ_EXT_TRIG_EVE << JEXTSEL0);

	local_ptr2ADC->ADC_CR2 |= (ADC_ALIGN << ALIGN);
	local_ptr2ADC->ADC_CR2 |= (ADC_DMA_SET << DMA);
	local_ptr2ADC->ADC_CR2 |= (CONT_ON << CONT);
	/* Power on ADC 		*/
	SET_BIT(local_ptr2ADC->ADC_CR2,ADON);


}

void 	 ADC_voidSampleTime	 (ADC_REG_NUM local_u8ADC,uint8_t Copy_u8SampleTime , uint8_t Copy_u8ChannelNum)
{
	ADC_REG* local_ptr2ADC = NULL;

	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	}
	switch(Copy_u8SampleTime)
	{
		case	ADC_CHANNEL0 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP0);
					break;
		case	ADC_CHANNEL1 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP1);
					break;
		case	ADC_CHANNEL2 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP2);
					break;
		case	ADC_CHANNEL3 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP3);
					break;
		case	ADC_CHANNEL4 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP4);
					break;
		case	ADC_CHANNEL5 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP5);
					break;
		case	ADC_CHANNEL6 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP6);
					break;
		case	ADC_CHANNEL7 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP7);
					break;
		case	ADC_CHANNEL8 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP8);
					break;
		case	ADC_CHANNEL9 :
			local_ptr2ADC->ADC_SMPR2 |= (Copy_u8SampleTime << ADC_SMP9);
					break;
		case	ADC_CHANNEL10 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP10);
					break;
		case	ADC_CHANNEL11 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP11);
					break;
		case	ADC_CHANNEL12 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP12);
					break;
		case	ADC_CHANNEL13 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP13);
					break;
		case	ADC_CHANNEL14 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP14);
					break;
		case	ADC_CHANNEL15 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP15);
					break;
		case	ADC_CHANNEL16 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP16);
					break;
		case	ADC_CHANNEL17 :
			local_ptr2ADC->ADC_SMPR1 |= (Copy_u8SampleTime << ADC_SMP17);
					break;
	}

}

void 	 ADC_voidInjectedOffset	(ADC_REG_NUM local_u8ADC,uint8_t Copy_u8InjectedOffset, uint8_t Copy_u8ChannelNum)
{
	ADC_REG* local_ptr2ADC = NULL;
	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	}

	switch (Copy_u8ChannelNum)
	{
		case	ADC_INJ_CH1	:
			local_ptr2ADC->ADC_JOFR1 |= Copy_u8InjectedOffset;
				break;
		case	ADC_INJ_CH2	:
			local_ptr2ADC->ADC_JOFR2 |= Copy_u8InjectedOffset;
				break;
		case	ADC_INJ_CH3	:
			local_ptr2ADC->ADC_JOFR3 |= Copy_u8InjectedOffset;
				break;
		case	ADC_INJ_CH4	:
			local_ptr2ADC->ADC_JOFR4 |= Copy_u8InjectedOffset;
				break;
	}
}

void 	 ADC_voidSequence(ADC_REG_NUM local_u8ADC,ADC_TYPE local_u8ADC_Type,uint8_t* local_u8SeqArray , uint8_t ConvNum)
{
	uint8_t counter = 0;
	ADC_REG* local_ptr2ADC = NULL;
	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	}

	switch(local_u8ADC_Type)
	{
	case REGULAR:
		local_ptr2ADC->ADC_SQR1 |= (ConvNum << ADC_L ) ;
		for(counter = 0 ;counter < 15 ; counter++ )
		{
			if(counter >= 13)
			{
				local_ptr2ADC->ADC_SQR1 = ( local_u8SeqArray[counter] << (5*(counter - 12)) );
			}
			else if(counter >= 7)
			{
				local_ptr2ADC->ADC_SQR2 = ( local_u8SeqArray[counter] << (5*(counter - 6)) );
			}
			else
			{
				local_ptr2ADC->ADC_SQR3 = ( local_u8SeqArray[counter] << (5*(counter )) );
			}
		}
	break;
	case INJECTED:
		local_ptr2ADC->ADC_JSQR |= (ConvNum << ADC_JL0 ) ;
		for(counter = 0 ;counter < 3 ; counter++ )
		{
				local_ptr2ADC->ADC_JSQR = ( local_u8SeqArray[counter] << (5*(counter )) );
		}
	break;
	}

}

void	 ADC_voidWathdogThreshold(ADC_REG_NUM local_u8ADC,uint8_t Copy_u8Upper, uint8_t Copy_u8Lower)
{
	ADC_REG* local_ptr2ADC = NULL;
	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	}
	local_ptr2ADC ->ADC_HTR &=  0b00000000000;
	local_ptr2ADC ->ADC_HTR |=  Copy_u8Upper;
	local_ptr2ADC ->ADC_LTR &=  0b00000000000;
	local_ptr2ADC ->ADC_LTR |=  Copy_u8Lower;
}

uint32_t ADC_u32Read(ADC_REG_NUM local_u8ADC,ADC_TYPE local_u8ADC_Type , uint8_t channel_num)
{
	ADC_REG* local_ptr2ADC = NULL;
	uint32_t local_u32data = 0;
	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	default:
	}

	switch(local_u8ADC_Type)
	{
	case REGULAR:
		/*		Regular Channel				*/
		/*		Start Conversion		    */
		SET_BIT(local_ptr2ADC->ADC_CR2,ADON);
		SET_BIT(local_ptr2ADC->ADC_CR2,SWSTART);
		/*		Polling till flag is set	*/
		while(GET_BIT(local_ptr2ADC->ADC_SR,EOC) == 0);
		/*		Read data in ADC_DR			*/
		local_u32data = local_ptr2ADC->ADC_DR;
		CLR_BIT(local_ptr2ADC->ADC_SR,EOC);
	break;
	/* 			Injected Channel		*/
	case INJECTED:
		/*		Start Conversion		    */
		SET_BIT(local_ptr2ADC->ADC_CR2,ADON);
		CLR_BIT(local_ptr2ADC->ADC_CR2,CONT);
		/*		Polling till flag is set	*/
		while(GET_BIT(local_ptr2ADC->ADC_SR,JEOC) == 0);
		/*		Read data in ADC_DR			*/
		local_u32data = local_ptr2ADC->ADC_JDR1;
		CLR_BIT(local_ptr2ADC->ADC_SR,EOC);
	break;
	default:
	}
	return local_u32data;
}
void 	 ADC_voidSetCallbackFun(ptr2fun);
void     ADC_voidStop(ADC_REG_NUM local_u8ADC)
{
	ADC_REG* local_ptr2ADC = NULL;
	switch(local_u8ADC)
	{
	case ADC1_enum:
		local_ptr2ADC = ADC1_BASE;
		break;
	case ADC2_enum:
		local_ptr2ADC = ADC2_BASE;
		break;
	case ADC3_enum:
		local_ptr2ADC = ADC3_BASE;
		break;
	default:
	}
	local_ptr2ADC->ADC_CR1   &= 0;
	local_ptr2ADC->ADC_CR2   &= 0;
	local_ptr2ADC->ADC_JSQR  &= 0;
	local_ptr2ADC->ADC_SMPR1 &= 0;
	local_ptr2ADC->ADC_SMPR2 &= 0;
	local_ptr2ADC->ADC_SQR1  &= 0;
	local_ptr2ADC->ADC_SQR2  &= 0;
	local_ptr2ADC->ADC_SQR3  &= 0;
}
