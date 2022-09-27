/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */
//=====================================================[MasterUnit]=============================================
#include"SECURITY_APP/SECURITY_APP_int.h"
#include"MENU_APP/MENU_int.h"
void main()
{
	APP_voidInit();
	// super loop
	while (TRUE)
	{
		SECURITY_APP_vidStartCheck();
		MENU_vidControlMenu();
	}
}
