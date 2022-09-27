/*
 * ADC_prog.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamad Hassan
 */
#include"ADC_int.h"
#include"ADC_prv.h"
#include"ADC_cfg.h"
#include"../../LIB/BIT_Utils.h"
#include<util/delay.h>
void ADC_vidInit(void)
{
	
	/*1- choose  Vref and selected channel and whether adjust right or left*/
	ASSIGN_REG(ADC_u8_ADMUX_REG,ADC_INPUT_CHANNEL);
	ASSIGN_REG(ADC_u8_ADMUX_REG,(ADC_V_REFERENCE_SELECTION<<ADC_u8_ADMUX_REFS0_BIT));
	ASSIGN_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_ADLAR_BIT,ADC_LEFT_ADJUST_SELECTION);
	
	/*2-choose prescaler */
	ASSIGN_REG(ADC_u8_ADCSRA_REG,ADC_PRESCALER_SELECTION);
	/*3- enable ADC*/
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADEN_BIT);
	


}
ADC_tenuErrorStatus ADC_enuReadValuePolling(u16* Local_pu16DigitalValue)
{
	ADC_tenuErrorStatus Local_enuErrorStatus=ADC_OK;
	if(0)
	{
		
	}
	else
	{
		if(*Local_pu16DigitalValue==0)
		{
//			_delay_ms(500);
		}
		/*1-start conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADSC_BIT);
		/*2- polling on ADSC bit*/
		while(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADSC_BIT));
		/*3- assign digital value value */
		*Local_pu16DigitalValue=(u16) (ADC_u8_ADCL_REG)|(ADC_u8_ADCH_REG<<8);
	}
	return Local_enuErrorStatus;
}
