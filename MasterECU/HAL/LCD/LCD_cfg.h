/*
 * LCD_cfg.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamad Hassan
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/********************************************************************/
/*****************LCD Ports and Pins configuration*******************/
/********************************************************************/
/*PORT options :DIO_u8_PORTA	DIO_u8_PORTB	DIO_u8_PORTC	DIO_u8_PORTD
 * 
 * 
 * PIN options : DIO_u8_PIN0	DIO_u8_PIN1		DIO_u8_PIN2		DIO_u8_PIN3
 * 
 * 				 DIO_u8_PIN4	DIO_u8_PIN5		DIO_u8_PIN6		DIO_u8_PIN7	
 *
 *			For 4-Bits mode configure only:		LCD_u8_D4_PIN 	LCD_u8_D5_PIN 
 *												LCD_u8_D6_PIN 	LCD_u8_D7_PIN 
 * */
/***************D0*****************/
#define LCD_u8_D0_PORT DIO_u8_PORTC
#define LCD_u8_D0_PIN DIO_u8_PIN0
/***************D1*****************/
#define LCD_u8_D1_PORT DIO_u8_PORTC
#define LCD_u8_D1_PIN DIO_u8_PIN1
/***************D2*****************/
#define LCD_u8_D2_PORT DIO_u8_PORTC
#define LCD_u8_D2_PIN DIO_u8_PIN2
/***************D3*****************/
#define LCD_u8_D3_PORT DIO_u8_PORTC
#define LCD_u8_D3_PIN DIO_u8_PIN3
/***************D4*****************/
#define LCD_u8_D4_PORT DIO_u8_PORTC
#define LCD_u8_D4_PIN DIO_u8_PIN4
/***************D5*****************/
#define LCD_u8_D5_PORT DIO_u8_PORTC
#define LCD_u8_D5_PIN DIO_u8_PIN5
/***************D6*****************/
#define LCD_u8_D6_PORT DIO_u8_PORTC
#define LCD_u8_D6_PIN DIO_u8_PIN6
/***************D7*****************/
#define LCD_u8_D7_PORT DIO_u8_PORTC
#define LCD_u8_D7_PIN DIO_u8_PIN7
/*********************RS, RW, E Pins Configuration *******************/
/***************RS*****************/
#define LCD_u8_RS_PORT DIO_u8_PORTC
#define LCD_u8_RS_PIN DIO_u8_PIN1
/***************RW*****************/
#define LCD_u8_RW_PORT DIO_u8_PORTC
#define LCD_u8_RW_PIN DIO_u8_PIN2
/****************E*****************/
#define LCD_u8_E_PORT DIO_u8_PORTC
#define LCD_u8_E_PIN DIO_u8_PIN3

/********************************************************************/
/*****************LCD Ports Display Configuration********************/
/********************************************************************/

/*
 * Display Control options :	
 * 							LCD_u8_DISPLAY_ON_CURSOR_OFF 		
 LCD_u8_DISPLAY_ON_CURSOR_ON 		
 LCD_u8_DISPLAY_ON_CURSOR_BLINK_ON	 			 		
 * */
#define LCD_u8_DISPLAY_CONTROL	LCD_u8_DISPLAY_ON_CURSOR_OFF
/********************************************************************/
/*
 * DISPLAY Directions options :	
 * 							LCD_u8_RIGHT_TO_LEFT_DISPLY
 * 							LCD_u8_LEFT_TO_RIGHT_DISPLY 		
 * */
#define LCD_u8_ENTRY_MODE_SET	LCD_u8_LEFT_TO_RIGHT_DISPLY

/********************************************************************/
/*
 * DATA LENGTH options :	
 * 							LCD_u8_8_BIT_MODE
 * 							LCD_u8_4_BIT_MODE
 * */
#define LCD_u8_DATA_LENGTH	LCD_u8_4_BIT_MODE

/********************************************************************/
/*
 * NUMBER OF LINES options :	
 * 							   LCD_u8_1_LINE_MODE
 * 							   LCD_u8_2_LINE_MODE
 * */
#define LCD_u8_NUMBER_OF_LINES LCD_u8_2_LINE_MODE

/********************************************************************/
/*
 * CHARACTER FONT options:	
 * 						 LCD_u8_FONT_5_7
 * 						 LCD_u8_FONT_5_10
 * */
#define LCD_u8_FONT_SIZE LCD_u8_FONT_5_7

#endif /* HAL_LCD_LCD_CFG_H_ */
