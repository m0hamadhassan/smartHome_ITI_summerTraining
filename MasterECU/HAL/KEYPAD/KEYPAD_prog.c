/*
 * KEYPAD_prog.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Mohamad Hassan
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"../LCD/LCD_int.h"

#include "KEYPAD_int.h"
#include "KEYPAD_prv.h"
#include "KEYPAD_cfg.h"

static u8 KEYPAD_u8ArrColsPins[KEYPAD_COLS_NUM] =
{ KEYPAD_COL_PIN0, KEYPAD_COL_PIN1, KEYPAD_COL_PIN2, KEYPAD_COL_PIN3 };

static u8 KEYPAD_u8ArrRowsPins[KEYPAD_ROWS_NUM] =
{ KEYPAD_ROW_PIN0, KEYPAD_ROW_PIN1, KEYPAD_ROW_PIN2, KEYPAD_ROW_PIN3 };

/* Name:			KEYPAD_vidInit
 * Description: Initialize MCU Pins for Keypad
 * Arguments: 	void
 * Return :	  	void
 * */
void KEYPAD_vidInit(void)
{
	DIO_vidInit();
}
/* Name:			KEYPAD_vidGetPressedKey
 * Description: Get value of pressed Key on keypad
 * Arguments: 	Address of variable to assign input in 
 * Return :	  	void
 * */
void KEYPAD_vidGetPressedKey(u8 *Add_pu8KeyValue)
{

	/*check arguments*/

	u8 Local_u8ColsIterator = 0;
	u8 Local_u8RowsIterator = 0;
	u8 Local_u8PinValue = 0;
	for (Local_u8ColsIterator = 0; Local_u8ColsIterator < KEYPAD_COLS_NUM; Local_u8ColsIterator++)
	{

		DIO_enuSetPinValue(KEYPAD_COL_PORT, KEYPAD_u8ArrColsPins[Local_u8ColsIterator], DIO_u8_LOW);
		for (Local_u8RowsIterator = 0; Local_u8RowsIterator < KEYPAD_ROWS_NUM;
				Local_u8RowsIterator++)
		{

			DIO_enuGetPinValue(KEYPAD_ROW_PORT, KEYPAD_u8ArrRowsPins[Local_u8RowsIterator],
					&Local_u8PinValue);

			if (Local_u8PinValue == 0)
			{

				*Add_pu8KeyValue = KEYPAD_u8KeysValue[Local_u8RowsIterator][Local_u8ColsIterator];
				while (Local_u8PinValue == DIO_u8_LOW)
				{
					DIO_enuGetPinValue(KEYPAD_ROW_PORT, KEYPAD_u8ArrRowsPins[Local_u8RowsIterator],
							&Local_u8PinValue);
				}
				return;
			}

		}

		DIO_enuSetPinValue(KEYPAD_COL_PORT, KEYPAD_u8ArrColsPins[Local_u8ColsIterator],
		DIO_u8_HIGH);
	}

	*Add_pu8KeyValue = KEYPAD_NOT_PRESSED;
}

