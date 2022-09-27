/*
 * G_INT_prog.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamad Hassan
 */

#include"G_INT_prv.h"

void G_INT_vidEnable(void)
{
	SET_BIT(G_INT_u8_SREG_REG, G_INT_u8_SREG_I_PIN);
}
void G_INT_vidDisable(void)
{
	CLR_BIT(G_INT_u8_SREG_REG, G_INT_u8_SREG_I_PIN);
}
