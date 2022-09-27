/*
 * LCD_prog.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamad Hassan
 */

#include"../../LIB/BIT_Utils.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"LCD_int.h"
#include<util/delay.h>

/*Function to send enable signal for instructions */
static void LCD_vidSendEnable(void)
{
	DIO_enuSetPinValue(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8_LOW);
}
/**************************************************************/
/*Name:			LCD_vidInit
 * Description: Initialize LCD
 * Arguments: 	vid
 * Return :	  	vid
 * */
void LCD_vidInit(void)
{
#if LCD_u8_DATA_LENGTH ==LCD_u8_8_BIT_MODE
	/*init the pins*/
	DIO_vidInit();
	_delay_ms(32);
	
	/*function set init*/
	
	LCD_enuSendInstruction(LCD_u8_FUNCTION_SET);
	_delay_ms(1);
	
	/*display control init*/
	LCD_enuSendInstruction(LCD_u8_DISPLAY_CONTROL);
	_delay_ms(1);
	
	/*clear display*/
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	_delay_ms(2);
	
	/*entry mode set init */
	LCD_enuSendInstruction(LCD_u8_ENTRY_MODE_SET);
#elif LCD_u8_DATA_LENGTH ==LCD_u8_4_BIT_MODE
	/*init the pins*/
	DIO_vidInit();
	_delay_ms(32);

	/*function set init*/

	DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, DIO_u8_LOW);
	DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, DIO_u8_HIGH);
	DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, DIO_u8_LOW);
	DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, DIO_u8_LOW);
	_delay_ms(2);
	LCD_vidSendEnable();

	DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, DIO_u8_LOW);
	DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, DIO_u8_HIGH);
	DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, DIO_u8_LOW);
	DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, DIO_u8_LOW);
	_delay_ms(2);
	LCD_vidSendEnable();

	DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(LCD_u8_FONT_SIZE, DIO_u8_PIN2));
	DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(LCD_u8_NUMBER_OF_LINES, DIO_u8_PIN3));
	_delay_ms(2);
	LCD_vidSendEnable();

	/*display control init*/
	LCD_enuSendInstruction(LCD_u8_DISPLAY_CONTROL);
	_delay_ms(2);

	/*clear display*/
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	_delay_ms(2);

	/*entry mode set init */
	LCD_enuSendInstruction(LCD_u8_ENTRY_MODE_SET);
	_delay_ms(2);
#endif
}
/**************************************************************/
/*Name:			LCD_enuSendCharacter
 * Description: Send character to be displayed on LCD
 * Arguments: 	First Argument : Copy_u8Character, options(any character on ASCII table)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendCharacter(u8 Copy_u8Character)
{
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;

	if (Copy_u8Character > 127)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
#if LCD_u8_DATA_LENGTH ==LCD_u8_8_BIT_MODE
		/*RS pin ---> High*/
		DIO_enuSetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);

		/*RW pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
		/*Send instruction*/
		DIO_enuSetPinValue(LCD_u8_D0_PORT, LCD_u8_D0_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN0));
		DIO_enuSetPinValue(LCD_u8_D1_PORT, LCD_u8_D1_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN1));
		DIO_enuSetPinValue(LCD_u8_D2_PORT, LCD_u8_D2_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN2));
		DIO_enuSetPinValue(LCD_u8_D3_PORT, LCD_u8_D3_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN3));
		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN4));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN5));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN6));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Character,DIO_u8_PIN7));
	
		/*Send Enable*/
		LCD_vidSendEnable();
#elif LCD_u8_DATA_LENGTH ==LCD_u8_4_BIT_MODE

		/*RS pin ---> High*/
		DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

		/*RW pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
		/*Send instruction*/

		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN4));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN5));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN6));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN7));
		LCD_vidSendEnable();
		_delay_ms(2);

		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN0));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN1));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN2));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Character, DIO_u8_PIN3));
		/*Send Enable*/
		LCD_vidSendEnable();
#endif
	}
	return Local_enuErrorStatus;
}
/**************************************************************/
/*Name:			LCD_enuSendInstruction
 * Description: Send instruction LCD controller
 * Arguments: 	First Argument : Copy_u8Instruction, options(any Instruction deriven from datasheet)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction)
{
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;

	if (0)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
#if LCD_u8_DATA_LENGTH ==LCD_u8_8_BIT_MODE
		/*RS pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
		/*RW pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
		/*Send instruction*/
		DIO_enuSetPinValue(LCD_u8_D0_PORT, LCD_u8_D0_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN0));
		DIO_enuSetPinValue(LCD_u8_D1_PORT, LCD_u8_D1_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN1));
		DIO_enuSetPinValue(LCD_u8_D2_PORT, LCD_u8_D2_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN2));
		DIO_enuSetPinValue(LCD_u8_D3_PORT, LCD_u8_D3_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN3));
		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN4));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN5));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN6));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Instruction,DIO_u8_PIN7));
		
		/*Send Enable*/
		LCD_vidSendEnable();
#elif LCD_u8_DATA_LENGTH ==LCD_u8_4_BIT_MODE
		/*RS pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

		/*RW pin ---> low*/
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
		/*Send instruction*/

		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN4));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN5));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN6));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN7));
		LCD_vidSendEnable();
		_delay_ms(2);
		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN0));
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN1));
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN2));
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Instruction, DIO_u8_PIN3));

		/*Send Enable*/
		LCD_vidSendEnable();
#endif
	}
	return Local_enuErrorStatus;
}
/**************************************************************/
/*Name:			LCD_enuSendString
 * Description: Send string to be displayed on LCD
 * Arguments: 	First Argument : Add_pu8String, options(Any non NULL pointer to string)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendString(u8 *Add_pu8String)
{
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;

	if (Add_pu8String == NULL)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		while (*Add_pu8String != '\0')
		{
			LCD_enuSendCharacter(*Add_pu8String);

			Add_pu8String++;
		}

	}
	return Local_enuErrorStatus;
}
/*Name:			LCD_enuChangePosition
 * Description: change Cursor position
 * Arguments: 	First Argument : Copy_u8Row,     options (LCD_u8_ROW0 , LCD_u8_ROW1)
 * 				Second Argument : Copy_u8Column, options(LCD_u8_Column0 to LCD_u8_Column15)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuChangePosition(u8 Copy_u8Row, u8 Copy_u8Column)
{
	_delay_ms(40);
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;

	if (Copy_u8Row > LCD_u8_ROW1 || Copy_u8Column > LCD_u8_Column15)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		switch (Copy_u8Row)
		{
		case LCD_u8_ROW0:
			LCD_enuSendInstruction(LCD_u8_FIRST_DDRAM_ADDRESS + Copy_u8Column);
			break;
		case LCD_u8_ROW1:
			LCD_enuSendInstruction((LCD_u8_FIRST_DDRAM_ADDRESS + LCD_u8_SECOND_LINE_INIT) | (Copy_u8Column));
			break;
		}
	}

	return Local_enuErrorStatus;
}
/**************************************************************/
/*Name:			LCD_enuSendCustomCharacter
 * Description: pass custom character to CGRAM then display it on LCD
 * Arguments: 	First Argument : Add_pu8Pattern,     options (Address of array of special character)
 * 				Second Argument : Copy_BlockNumberu8, options(0:80 , "locations of CGRAM")
 * 				Third  Argument : Copy_u8Row,    options (LCD_u8_ROW0 , LCD_u8_ROW1)
 * 				Fourth Argument : Copy_u8Column, options(LCD_u8_Column0 to LCD_u8_Column15)
 * 				
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_BlockNumberu8, u8 Copy_u8Row, u8 Copy_u8Column)
{
	u8 Local_u8Iterator;
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;

	if (Add_pu8Pattern == NULL || Copy_u8Row > LCD_u8_ROW1 || Copy_u8Column > LCD_u8_Column15 || Copy_BlockNumberu8 > 80)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		LCD_enuSendInstruction(LCD_u8_FIRST_CGRAM_ADDRESS + (Copy_BlockNumberu8 * 8));
		for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
		{
			LCD_enuSendCharacter(Add_pu8Pattern[Local_u8Iterator]);
			_delay_ms(1);
		}
		LCD_enuChangePosition(Copy_u8Row, Copy_u8Column);
		LCD_enuSendCharacter(Copy_BlockNumberu8);
	}

	return Local_enuErrorStatus;
}
/**************************************************************/
/*Name:			LCD_enuSendNumber
 * Description: Display number on LCD "number not string"
 * Arguments: 	First Argument : Copy_u16Number,     options (any integer number from 0 to 65535)
 * Return :	  	LCD_tenu_ErrorStatus
 * */

LCD_tenu_ErrorStatus LCD_enuSendNumber(u32 Copy_u32Number)
{
	u8 Local_u8Arr[10];
	s8 Local_s8Iterator = 0;
	LCD_tenu_ErrorStatus Local_enuErrorStatus = LCD_OK;
	if (0)
	{

	}
	else
	{
		if (Copy_u32Number == 0)
		{
			LCD_enuSendCharacter('0');
		}
		else
		{
			while (Copy_u32Number > 0)
			{
				Local_u8Arr[Local_s8Iterator++] = ((Copy_u32Number % 10) == 0) ? (48) : ((Copy_u32Number % 10) + 48);
				Copy_u32Number /= 10;
			}

			Local_s8Iterator--;

			while (Local_s8Iterator >= 0)
			{
				LCD_enuSendCharacter(Local_u8Arr[Local_s8Iterator]);
				Local_s8Iterator--;
			}
		}

	}
	return Local_enuErrorStatus;
}

/**************************************************************/
/*Name:			LCD_Clear_Display
 * Description: Clear any data on LCD display
 * Arguments: 	vid
 * Return :	  	vid
 * */
void LCD_Clear_Display(void)
{
	_delay_ms(40);
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	_delay_ms(40);
}
