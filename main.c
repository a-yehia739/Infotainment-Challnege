/*******************************************************************************************************************
 * SOS challenge
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "SOS.h"
#include "Keypad.h"
#include "Infotainment.h"
#include "LCD.h"

int main(void)
{
	DIO_Init();
	Info_vInit();
	SOS_enmInit();
	
	SOS_enmCreateTask(SOS_TASK0, 2, Keypad_vCheckKeyState);
	SOS_enmCreateTask(SOS_TASK1, 50, Info_vRun);
	
	SOS_enmRun();
}
