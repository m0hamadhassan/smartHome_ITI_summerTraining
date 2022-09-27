/*
 d * DIO_prog.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */

#include"Dio_prv.h"
#include"Dio_int.h"
#include"Dio_cfg.h"

/*Name:			DIO_vidInit
 * Description: Initialize all MCU Pins
 * Arguments: 	vid
 * Return :	  	vid
 * */
void DIO_vidInit(void)
{

	/*Old Value
	 * DIO_u8_OUTPUT_LOW		-->0
	 * DIO_u8_OUTPUT_HIGH		-->1
	 * DIO_u8_INPUT_FLOATING	-->2
	 * DIO_u8_INPUT_PULLUP		-->3
	 * 
	 * */

	//Undefine old values
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP

	//Define new values
#define DIO_u8_OUTPUT_LOW		1
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	0
#define DIO_u8_INPUT_PULLUP		0

	/*our beautiful way :) */
	//Set DDR Values
	DIO_u8_DDRA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5, DIO_u8_PORTA_PIN4, DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2,
			DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);

	DIO_u8_DDRB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5, DIO_u8_PORTB_PIN4, DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2,
			DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

	DIO_u8_DDRC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5, DIO_u8_PORTC_PIN4, DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2,
			DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

	DIO_u8_DDRD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5, DIO_u8_PORTD_PIN4, DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2,
			DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);

	/*Old Value
	 * DIO_u8_OUTPUT_LOW		-->1
	 * DIO_u8_OUTPUT_HIGH		-->1
	 * DIO_u8_INPUT_FLOATING	-->0
	 * DIO_u8_INPUT_PULLUP		-->0
	 * 
	 * */
	//Undefine old values
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP

	//Define new values
#define DIO_u8_OUTPUT_LOW		0
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	0
#define DIO_u8_INPUT_PULLUP		1

	DIO_u8_PORTA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5, DIO_u8_PORTA_PIN4, DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2,
			DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);

	DIO_u8_PORTB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5, DIO_u8_PORTB_PIN4, DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2,
			DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

	DIO_u8_PORTC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5, DIO_u8_PORTC_PIN4, DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2,
			DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

	DIO_u8_PORTD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5, DIO_u8_PORTD_PIN4, DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2,
			DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);
	//Undefine values
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP

	//REDefine old values
#define DIO_u8_OUTPUT_LOW		0
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	2
#define DIO_u8_INPUT_PULLUP		3

}
/* Name:		DIO_enuSetPinValue
 * Description: assign the desired value to the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Copy_u8Value,   options()
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	/*Check Args*/

	if ((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Pin > DIO_u8_PIN7) || (Copy_u8Value > DIO_u8_HIGH))
	{
		Local_enuErrorStatus = DIO_NOK;
	}
	else
	{
		/*Implementation*/

		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA:
			(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTA_REG |= (1 << Copy_u8Pin)) : (DIO_u8_PORTA_REG &= ~(1 << Copy_u8Pin));
			break;

		case DIO_u8_PORTB:
			(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTB_REG |= (1 << Copy_u8Pin)) : (DIO_u8_PORTB_REG &= ~(1 << Copy_u8Pin));

			break;

		case DIO_u8_PORTC:
			(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTC_REG |= (1 << Copy_u8Pin)) : (DIO_u8_PORTC_REG &= ~(1 << Copy_u8Pin));

			break;

		case DIO_u8_PORTD:
			(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTD_REG |= (1 << Copy_u8Pin)) : (DIO_u8_PORTD_REG &= ~(1 << Copy_u8Pin));

			break;
		}

		/*empty*/
		//asm("NOP");
	}
	return Local_enuErrorStatus;

}
/* Name:		DIO_enuGetPinValue
 * Description: get the value of the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Add_pu8PinValue,   Variable Address to store pin value
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	/*Check Args*/

	if ((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Pin > DIO_u8_PIN7) || (Add_pu8PinValue == NULL))
	{
		Local_enuErrorStatus = DIO_NOK;
	}
	else
	{
		/*Implementation*/

		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA:
			*Add_pu8PinValue = (DIO_u8_PINA_REG >> Copy_u8Pin) & 0x01;
			break;

		case DIO_u8_PORTB:
			*Add_pu8PinValue = (DIO_u8_PINB_REG >> Copy_u8Pin) & 0x01;
			break;

		case DIO_u8_PORTC:
			*Add_pu8PinValue = (DIO_u8_PINC_REG >> Copy_u8Pin) & 0x01;
			break;

		case DIO_u8_PORTD:
			*Add_pu8PinValue = (DIO_u8_PIND_REG >> Copy_u8Pin) & 0x01;
			break;
		}

		/*empty*/
		//asm("NOP");
	}
	return Local_enuErrorStatus;
}

/* Name:		DIO_enuGetPortValue
 * Description: Get Desired Port Value
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Add_pu8PortValue	Variable Address to store port value
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */

DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Add_pu8PortValue)
{

	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	/*Check Args*/
	if ((Copy_u8Port > DIO_u8_PORTD) || (Add_pu8PortValue == NULL))
	{
		Local_enuErrorStatus = DIO_NOK;
	}
	else
	{
		/*Implementation*/

		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA:
			*Add_pu8PortValue = DIO_u8_PINA_REG;
			break;

		case DIO_u8_PORTB:
			*Add_pu8PortValue = DIO_u8_PINB_REG;
			break;

		case DIO_u8_PORTC:
			*Add_pu8PortValue = DIO_u8_PINC_REG;
			break;

		case DIO_u8_PORTD:
			*Add_pu8PortValue = DIO_u8_PIND_REG;
			break;
		}

		/*empty*/
		//asm("NOP");
	}
	return Local_enuErrorStatus;

}
/* Name:		DIO_enuSetPortValue
 * Description: assign the desired value to the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Value,     variable to the value to be se to port
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */

DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{

	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	/*Check Args*/

	if ((Copy_u8Port > DIO_u8_PORTD))
	{
		Local_enuErrorStatus = DIO_NOK;
	}
	else
	{
		/*Implementation*/

		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA:
			DIO_u8_PORTA_REG = Copy_u8Value;
			break;

		case DIO_u8_PORTB:
			DIO_u8_PORTB_REG = Copy_u8Value;

			break;

		case DIO_u8_PORTC:
			DIO_u8_PORTC_REG = Copy_u8Value;

			break;

		case DIO_u8_PORTD:
			DIO_u8_PORTD_REG = Copy_u8Value;

			break;
		}

		/*empty*/
		//asm("NOP");
	}
	return Local_enuErrorStatus;

}

