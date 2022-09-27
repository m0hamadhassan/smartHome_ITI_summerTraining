/*
 * KEYPAD_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Mohamad Hassan
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_
#include "../../MCAL/DIO/DIO_int.h"
#define KEYPAD_NOT_PRESSED 0

/* Name:			KEYPAD_vidInit
 * Description: Initialize MCU Pins for Keypad
 * Arguments: 	void
 * Return :	  	void
 * */
void KEYPAD_vidInit(void);
/* Name:			KEYPAD_vidGetPressedKey
 * Description: Get value of pressed Key on keypad
 * Arguments: 	Address of variable to assign input in 
 * Return :	  	void
 * */
void KEYPAD_vidGetPressedKey(u8 *Add_pu8KeyValue);

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
