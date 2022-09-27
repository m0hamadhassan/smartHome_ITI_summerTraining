/*
 * ADC_int.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_
#include"../../LIB/STD_Types.h"
typedef enum
{
	ADC_OK=0,
	ADC_NOK=0
	
}ADC_tenuErrorStatus;
/*VREF Options*/
#define ADC_V_REFERENCE_AREF			0
#define ADC_V_REFERENCE_AVCC			1
#define ADC_V_REFERENCE_INTERNAL_2_56	2

/*PRESCALER options*/

#define ADC_PRESCALER_2					0
#define ADC_PRESCALER_4					1
#define ADC_PRESCALER_8					2
#define ADC_PRESCALER_16				3
#define ADC_PRESCALER_32				4
#define ADC_PRESCALER_64				5
#define ADC_PRESCALER_128				6

/*LEFT ADJUST options*/
#define ADC_RIGHT_ADJUST 				0
#define ADC_LEFT_ADJUST 				1

/*ADC INPUT Channel*/
#define ADC_PIN_ADC0					0
#define ADC_PIN_ADC1					1
#define ADC_PIN_ADC2					2
#define ADC_PIN_ADC3					3
#define ADC_PIN_ADC4					4
#define ADC_PIN_ADC5					5
#define ADC_PIN_ADC6					6
#define ADC_PIN_ADC7					7


/*Needed Functions*/


void ADC_vidInit(void);
ADC_tenuErrorStatus ADC_enuReadValuePolling(u16* Local_pu16DigitalValue);

#endif /* MCAL_ADC_ADC_INT_H_ */
