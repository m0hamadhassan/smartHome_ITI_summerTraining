/*
 * SECURITY_APP_int.h
 *
 *  Created on: Sep 27, 2022
 *      Author: moham
 */
#ifndef APP_SECURITY_APP_SECURITY_APP_INT_H_
#define APP_SECURITY_APP_SECURITY_APP_INT_H_
#include"../../LIB/STD_Types.h"
#include"SECURITY_APP_prv.h"
void SECURITY_APP_vidStartCheck(void);
void GetPassword(u8 Local_u8Indicator);
u8 SECURITY_u8CheckForSetPassword(void);
void SECURITY_vidSetNewPassword(void);
void SECURITY_vidWritePassword(void);
u8 SECURITY_vidCheckEnterdPassword(void);
u8 SECURITY_u8CheckForViolation(void);
void CallEmergancy(void);
void SECURITY_vidMarkViolated(void);

#endif /* APP_SECURITY_APP_SECURITY_APP_INT_H_ */
