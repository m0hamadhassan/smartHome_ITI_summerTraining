/*
 * DIO_int.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
#include"DIO_cfg.h"
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Utils.h"
/**************************************************************/

/*Error Status*/
typedef enum
{
	DIO_OK, DIO_NOK
} DIO_tenuErrorStatus;

/*************************** Macros ****************************/
/*Macros For Ports */
#define DIO_u8_PORTA 	0
#define DIO_u8_PORTB 	1
#define DIO_u8_PORTC 	2
#define DIO_u8_PORTD 	3

/*Macros For Pins */
#define DIO_u8_PIN0 	0
#define DIO_u8_PIN1 	1
#define DIO_u8_PIN2 	2
#define DIO_u8_PIN3 	3
#define DIO_u8_PIN4 	4
#define DIO_u8_PIN5 	5
#define DIO_u8_PIN6 	6
#define DIO_u8_PIN7 	7
/*Macros For Pins */
#define DIO_u8_LOW		0
#define DIO_u8_HIGH		1

/**************************************************************/
/*Needed Functions*/

/*Name:			DIO_vidInit
 * Description: Initialize all MCU Pins
 * Arguments: 	vid
 * Return :	  	vid
 * */
void DIO_vidInit(void);
/**************************************************************/
/* Name:		DIO_enuSetPinValue
 * Description: assign the desired value to the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options:(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options:(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Copy_u8Value,   options()
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
/**************************************************************/
/* Name:		DIO_enuGetPinValue
 * Description: get the value of the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options:(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options:(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Add_pu8PinValue,   Variable Address to store pin value
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue);
/**************************************************************/
/* Name:		DIO_enuGetPortValue
 * Description: Get Desired Port Value
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options:(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Pin,     options:(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 			    Third  Argument : Add_pu8PortValue	Variable Address to store port value
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */

DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Add_pu8PortValue);
/**************************************************************/
/* Name:		DIO_enuSetPortValue
 * Description: assign the desired value to the desired pin
 * Arguments:
 * 		    	First  Argument : Copy_u8Port,    options:(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 * 			    Second Argument : Copy_u8Value,     variable to the value to be se to port
 * Return :		Error Status --> DIO_OK , DIO_NOK
 * */

DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
/**************************************************************/
#endif /* MCAL_DIO_DIO_INT_H_ */
