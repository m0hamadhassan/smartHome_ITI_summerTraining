/*
 * LCD_int.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamad Hassan
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_
#include"LCD_cfg.h"
/*******************************************************************/
/****error status****/
typedef enum
{
	LCD_OK, LCD_NOK
} LCD_tenu_ErrorStatus;

/*************************** Macros ******************************/
/*********************macros for instructions*********************/

/*ON Demand Instructions (Use it when you need) */
#define LCD_u8_CLEAR_DISPLAY 				0x01
#define LCD_u8_RETURN_HOME	 				0x02
/*Cursor and display shift instructions */
#define LCD_u8_SHIFT_CURSOR_LEFT		 	0x10
#define LCD_u8_SHIFT_CURSOR_RIGHT		 	0x14
#define LCD_u8_SHIFT_DISPLAY_LEFT		 	0x18
#define LCD_u8_SHIFT_DISPLAY_RIGHT		 	0x1C
/*****Configuration Instructions (Used in configuration)***********/
#define LCD_u8_CURSOR_INC_SHIFT_OFF 		0x06
#define LCD_u8_CURSOR_DEC_SHIFT_OFF 		0x04
#define LCD_u8_CURSOR_INC_SHIFT_ON	 		0x07
#define LCD_u8_CURSOR_DEC_SHIFT_ON	 		0x05

#define LCD_u8_LEFT_TO_RIGHT_DISPLY LCD_u8_CURSOR_INC_SHIFT_OFF 	
#define LCD_u8_RIGHT_TO_LEFT_DISPLY LCD_u8_CURSOR_DEC_SHIFT_OFF
/*******************************************************************/
#define LCD_u8_DISPLAY_ON_CURSOR_OFF 		0x0C
#define LCD_u8_DISPLAY_ON_CURSOR_ON 		0x0E
#define LCD_u8_DISPLAY_ON_CURSOR_BLINK_ON 	0x0F
/*******************************************************************/
#define LCD_u8_8_BIT_MODE					0x10 
#define LCD_u8_4_BIT_MODE					0x00 
/*******************************************************************/
#define LCD_u8_1_LINE_MODE					0x00
#define LCD_u8_2_LINE_MODE					0x08
/*******************************************************************/
#define LCD_u8_FONT_5_7   					0x00
#define LCD_u8_FONT_5_10  					0x04
/*******************************************************************/
#define FUNCTION_SET_DB5 					0x20
/*******************************************************************/
/*Please configure this from configuration file */
#define LCD_u8_FUNCTION_SET 	FUNCTION_SET_DB5 | LCD_u8_DATA_LENGTH | LCD_u8_NUMBER_OF_LINES | LCD_u8_FONT_SIZE
/*******************************************************************/

/******Important addresses*********************/
#define LCD_u8_FIRST_CGRAM_ADDRESS			0x40
#define LCD_u8_FIRST_DDRAM_ADDRESS			0x80

#define LCD_u8_SECOND_LINE_INIT       0x40
/*macros for row and column*/

#define LCD_u8_ROW0 		0x00
#define LCD_u8_ROW1  		0x01

#define LCD_u8_Column0 		0x00
#define LCD_u8_Column1 		0x01
#define LCD_u8_Column2 		0x02
#define LCD_u8_Column3 		0x03
#define LCD_u8_Column4 		0x04
#define LCD_u8_Column5 		0x05
#define LCD_u8_Column6 		0x06
#define LCD_u8_Column7 		0x07
#define LCD_u8_Column8 		0x08
#define LCD_u8_Column9 		0x09
#define LCD_u8_Column10 	0x0A
#define LCD_u8_Column11 	0x0B
#define LCD_u8_Column12 	0x0C
#define LCD_u8_Column13 	0x0D
#define LCD_u8_Column14 	0x0E
#define LCD_u8_Column15 	0x0F

/**************************************************************/
/*Needed Functions*/

/*Name:			LCD_vidInit
 * Description: Initialize LCD
 * Arguments: 	vid
 * Return :	  	vid
 * */
void LCD_vidInit(void);
/**************************************************************/
/*Name:			LCD_enuSendCharacter
 * Description: Send character to be displayed on LCD
 * Arguments: 	First Argument : Copy_u8Character, options(any character on ASCII table)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendCharacter(u8 Copy_u8Character);
/**************************************************************/
/*Name:			LCD_enuSendInstruction
 * Description: Send instruction LCD controller
 * Arguments: 	First Argument : Copy_u8Instruction, options(any Instruction deriven from datasheet)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction);
/**************************************************************/
/*Name:			LCD_enuSendString
 * Description: Send string to be displayed on LCD
 * Arguments: 	First Argument : Add_pu8String, options(Any non NULL pointer to string)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendString(u8 *Add_pu8String);
/**************************************************************/
/*Name:			LCD_enuChangePosition
 * Description: change Cursor position
 * Arguments: 	First Argument : Copy_u8Row,     options (LCD_u8_ROW0 , LCD_u8_ROW1)
 * 				Second Argument : Copy_u8Column, options(LCD_u8_Column0 to LCD_u8_Column15)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuChangePosition(u8 Copy_u8Row, u8 Copy_u8Column);
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
LCD_tenu_ErrorStatus LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_BlockNumberu8, u8 Copy_u8Row, u8 Copy_u8Column);
/**************************************************************/
/*Name:			LCD_enuSendNumber
 * Description: Display number on LCD "number not string"
 * Arguments: 	First Argument : Copy_u16Number,     options (any integer number from 0 to 65535)
 * Return :	  	LCD_tenu_ErrorStatus
 * */
LCD_tenu_ErrorStatus LCD_enuSendNumber(u32 Copy_u32Number);
/**************************************************************/
/*Name:			LCD_Clear_Display
 * Description: Clear any data on LCD display
 * Arguments: 	vid
 * Return :	  	vid
 * */
void LCD_Clear_Display(void);

#endif /* HAL_LCD_LCD_INT_H_ */
