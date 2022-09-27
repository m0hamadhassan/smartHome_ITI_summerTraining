/*
 * SPI_int.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamad Hassan
 */
#include"../../LIB/BIT_Utils.h"
#include"../../LIB/STD_Types.h"

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

typedef enum
{
	SPI_OK=0,
	SPI_NOK
}SPI_tenuErrorStatus;

typedef enum
{
	SPI_Slave=0,
	SPI_Master
	
	
}SPI_tenuModeSelect;

void SPI_vidInit(SPI_tenuModeSelect Copy_enuSPIMode);
SPI_tenuErrorStatus SPI_enuTranscieveAsynch(u8* Copy_pu8Value);
u8 SPI_enuTranscieveSynch(u8 Copy_pu8Value);
void SPI_vidStopConnection(void);
u8 SPI_u8RecievedValue(void);

#endif /* MCAL_SPI_SPI_INT_H_ */
