/*
 * SPI_prog.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamad Hassan
 */
#include"SPI_prv.h"
#include"SPI_int.h"
#include"SPI_cfg.h"
#include"../G_INT/G_INT_int.h"
#include"../../HAL/LCD/LCD_int.h"
#include<util/delay.h>
u8 Global_u8Value = 0;

void SPI_vidInit(SPI_tenuModeSelect Copy_enuSPIMode)
{

	/*1- choose wether master or slave*/
	ASSIGN_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR_PIN, Copy_enuSPIMode);

	/*2- enable SPI interrupt and global interrupt*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE_PIN);
	G_INT_vidEnable();
	/*3- choose data order  */

	ASSIGN_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORTD_PIN, SPI_u8_DATA_ORDER);
	/*4- choose data mode*/
	ASSIGN_REG(SPI_u8_SPCR_REG, (SPI_u8_DATA_MODE<<2));
	/*5- choose prescaler and speed bit*/
	ASSIGN_REG(SPI_u8_SPCR_REG, (SPI_u8_SCK_FREQUENCY&0x03));
	ASSIGN_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X_PIN, 0);
	/*6- activate SPI enable*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE_PIN);

}
SPI_tenuErrorStatus SPI_enuTranscieveAsynch(u8 *Copy_pu8Value)
{

	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE_PIN);
	SPI_u8_SPDR_REG = (*Copy_pu8Value);

}

u8 SPI_enuTranscieveSynch(u8 Copy_pu8Value)
{
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE_PIN);
	SPI_u8_SPDR_REG = Copy_pu8Value;
	while (GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPSR_SPIF_PIN) == 0)
		;
	return SPI_u8_SPDR_REG;
}

u8 SPI_u8RecievedValue(void)
{
	return Global_u8Value;
}
void SPI_vidStopConnection(void)
{
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE_PIN);
}

void __vector_12(void) __attribute((signal,used));
void __vector_12(void)
{

	Global_u8Value = SPI_u8_SPDR_REG;
}
