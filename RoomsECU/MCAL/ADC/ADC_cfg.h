/*
 * ADC_cfg.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_
/*
 * options: 
 * 			ADC_V_REFERENCE_AREF
 * 			ADC_V_REFERENCE_AVCC
 * 			ADC_V_REFERENCE_INTERNAL_2_56
 */
#define ADC_V_REFERENCE_SELECTION ADC_V_REFERENCE_AREF
/*************************************************************/
/*
 * options: 
 * 			ADC_PRESCALER_2
 * 			ADC_PRESCALER_4
 * 			ADC_PRESCALER_8
 * 			ADC_PRESCALER_16
 * 			ADC_PRESCALER_32
 * 			ADC_PRESCALER_64
 * 			ADC_PRESCALER_128
 * 
 */
#define ADC_PRESCALER_SELECTION	ADC_PRESCALER_128
/*
 * options: 
 * 			ADC_RIGHT_ADJUST
 * 			ADC_LEFT_ADJUST
 */
#define ADC_LEFT_ADJUST_SELECTION ADC_RIGHT_ADJUST
/*
 * options:	
 * 			ADC_PIN_ADC0
 * 			ADC_PIN_ADC1
 * 			ADC_PIN_ADC2
 * 			ADC_PIN_ADC3
 * 			ADC_PIN_ADC4
 * 			ADC_PIN_ADC5
 * 			ADC_PIN_ADC6
 * 			ADC_PIN_ADC7
 * Note : must configure At DIO_cfg as INPUT FLOATING 
 */
#define ADC_INPUT_CHANNEL	ADC_PIN_ADC0



#endif /* MCAL_ADC_ADC_CFG_H_ */
