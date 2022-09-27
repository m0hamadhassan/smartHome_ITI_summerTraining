/*
 * MENU_int.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Mohamad Hassan
 */

#ifndef APP_MENU_APP_MENU_INT_H_
#define APP_MENU_APP_MENU_INT_H_
void APP_voidInit(void);
void MENU_vidControlMenu(void);
u8 GetChioce(void);
void LaunchBuzzer(void);
void ReleaseBuzzer(void);
void MENU_vidSendInstruction(u8 Copy_pu8Instruction, u8 Copy_pu8SlaveSelect);

void MENU_vidWaitAndRecieve(u8 Copy_u8ValueToWaitFor, u8 Copy_u8ValueToSend);

#endif /* APP_MENU_APP_MENU_INT_H_ */
