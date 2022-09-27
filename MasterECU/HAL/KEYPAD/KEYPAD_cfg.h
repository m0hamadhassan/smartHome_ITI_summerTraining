/*
 * KEYPAD_cfg.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamad Hassan
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#include "../../LIB/STD_Types.h"
#include "KEYPAD_int.h"
#include "../../MCAL/DIO/DIO_int.h"

#define KEYPAD_ROWS_NUM 4
#define KEYPAD_COLS_NUM 4

u8 KEYPAD_u8KeysValue[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM] =
{
{ '7', '8', '9', '/' },
{ '4', '5', '6', '*' },
{ '1', '2', '3', '-' },
{ '#', '0', '=', '+' } };

/*Column output - Row input */
/********************************************************************/
/*PORT options :DIO_u8_PORTA	DIO_u8_PORTB	DIO_u8_PORTC	DIO_u8_PORTD
 * 
 * 
 * PIN options : DIO_u8_PIN0	DIO_u8_PIN1		DIO_u8_PIN2		DIO_u8_PIN3
 * 
 * 				 DIO_u8_PIN4	DIO_u8_PIN5		DIO_u8_PIN6		DIO_u8_PIN7	
 *
 * */

#define KEYPAD_COL_PORT DIO_u8_PORTA
#define KEYPAD_ROW_PORT DIO_u8_PORTA

#define KEYPAD_COL_PIN0	DIO_u8_PIN0
#define KEYPAD_COL_PIN1 DIO_u8_PIN1
#define KEYPAD_COL_PIN2 DIO_u8_PIN2
#define KEYPAD_COL_PIN3 DIO_u8_PIN3

#define KEYPAD_ROW_PIN0 DIO_u8_PIN4
#define KEYPAD_ROW_PIN1 DIO_u8_PIN5
#define KEYPAD_ROW_PIN2 DIO_u8_PIN6
#define KEYPAD_ROW_PIN3 DIO_u8_PIN7

#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
