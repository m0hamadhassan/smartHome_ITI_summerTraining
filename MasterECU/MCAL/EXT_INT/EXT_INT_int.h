/*
 * EXT_INT_int.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_
#include"../../LIB/STD_Types.h"
typedef enum
{
	EXT_INT_OK, EXT_INT_NOK
} EXT_INT_tenuErrorStatus;

#define EXT_INT0					0
#define EXT_INT1					1
#define EXT_INT2					2

#define EXT_INT_u8_LOW_LEVEL		0
#define EXT_INT_u8_ANY_CHANGE		1
#define EXT_INT_u8_RISING_EDGE		2
#define EXT_INT_u8_FALLING_EDGE		3

EXT_INT_tenuErrorStatus EXT_INT_vidEnable(u8 Copy_u8Interrupt, u8 Copy_u8SenseControl);

EXT_INT_tenuErrorStatus EXT_INT_vidDisable(u8 Copy_u8Interrupt);

void EXT_INT_vidRegisterCBF(u8 Copy_u8Interrupt, func_ptr Add_pfunCBF);

#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
