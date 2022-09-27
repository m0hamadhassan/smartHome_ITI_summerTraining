/*
 * ADC_prv.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

/*ADC Registers*/
#define ADC_u8_ADMUX_REG  	 *((volatile u8*)  0x27)    
#define ADC_u8_ADCSRA_REG    *((volatile u8*)  0x26)     
#define ADC_u8_ADCH_REG  	 *((volatile u8*)  0x25)     
#define ADC_u8_ADCL_REG  	 *((volatile u8*)  0x24)     
#define ADC_u8_SFIOR_REG	 *((volatile u8*)  0x50) 


/*ADMUX Register bits*/
#define ADC_u8_ADMUX_MUX0_BIT			0
#define ADC_u8_ADMUX_MUX1_BIT			1	
#define ADC_u8_ADMUX_MUX2_BIT			2	
#define ADC_u8_ADMUX_MUX3_BIT			3	
#define ADC_u8_ADMUX_MUX4_BIT			4
#define ADC_u8_ADMUX_ADLAR_BIT			5		
#define ADC_u8_ADMUX_REFS0_BIT			6		
#define ADC_u8_ADMUX_REFS1_BIT			7		
/*ADCSRA Register bits*/
#define ADC_u8_ADCSRA_ADPS0_BIT 		0
#define ADC_u8_ADCSRA_ADPS1_BIT 		1
#define ADC_u8_ADCSRA_ADPS2_BIT			2
#define ADC_u8_ADCSRA_ADIE_BIT			3
#define ADC_u8_ADCSRA_ADIF_BIT 			4
#define ADC_u8_ADCSRA_ADATE_BIT			5
#define ADC_u8_ADCSRA_ADSC_BIT 			6	
#define ADC_u8_ADCSRA_ADEN_BIT 			7
/*SFIOR Register bits*/
#define ADC_u8_SFIOR_ADTS0_BIT			5
#define ADC_u8_SFIOR_ADTS1_BIT			6
#define ADC_u8_SFIOR_ADTS2_BIT			7

#endif /* MCAL_ADC_ADC_PRV_H_ */
