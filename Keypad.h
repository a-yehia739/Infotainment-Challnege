/*******************************************************************************************************************
 * Keypad.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia - Taha Gamal
 *******************************************************************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "Keypad_cfg.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
typedef enum
{
	BUTTON_STATE_RELEASED,
	BUTTON_STATE_PRESSED
}Keypad_enmButtonState_t;
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
extern void Keypad_vInit(void);
extern void Keypad_vCheckKeyState(void);
extern Keypad_enmButtonState_t Keypad_enmKeyState(Keypad_enmKeyName a_enmKeyName);
#endif /* KEYPAD_H_ */