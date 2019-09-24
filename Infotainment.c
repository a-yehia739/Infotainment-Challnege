/*******************************************************************************************************************
 * Infotainment.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia - Taha Gamal
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Infotainment.h"
#include "Keypad.h"
#include "LCD.h"
//
#include "DIO.h"
#include "ATmega32Pins.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static const uint8_t Info_g_u8Questions_arr[][INFO_MAX_NUMBER_OF_LETTERS] =
{
	"  1 - Answer is 9",
	"  2 - Answer is 9",
	"  3 - Answer is 7",
	"  4 - Answer is 9",
	"  5 - Answer is 7"
};
static const Info_enmAnswer_t Info_g_enmAnswers_arr[] = 
{
	INFO_ANSWER_NO,
	INFO_ANSWER_NO,
	INFO_ANSWER_YES,
	INFO_ANSWER_NO,
	INFO_ANSWER_YES
};
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                Info_vInit
 * description:         initialize keypad and LCD
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
void Info_vInit(void)
{
	LCD_init();
	Keypad_vInit();
}
/*......................................................................................
 * name:                Info_vRun
 * description:         execute the infotainment state machine
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
extern void Info_vRun(void)
{
	static Info_enmState_t Run_l_enmState = INFO_STATE_QUESTION;
	static uint8_t Run_l_u8QuestionNumber = 0;
	static uint8_t Run_l_u8Score = 0;
	switch(Run_l_enmState)
	{
	case INFO_STATE_QUESTION:
		/* output */
		LCD_clear();
		LCD_gotoRowColumn(0,0);
		LCD_displayString(Info_g_u8Questions_arr[Run_l_u8QuestionNumber]);
		/* next state */
		if((Keypad_enmKeyState(KEYPAD_KEY_YES) == BUTTON_STATE_PRESSED) && (Keypad_enmKeyState(KEYPAD_KEY_NO) == BUTTON_STATE_PRESSED))
		{
			Run_l_enmState = INFO_STATE_SCORE;
		}
		else if(Keypad_enmKeyState(KEYPAD_KEY_YES) == BUTTON_STATE_PRESSED)
		{
			if(Info_g_enmAnswers_arr[Run_l_u8QuestionNumber] == INFO_ANSWER_YES)
			{
				Run_l_enmState = INFO_STATE_CORRECT_ANSWER;
			}
			else
			{
				Run_l_enmState = INFO_STATE_WRONG_ANSWER;
			}
		}
		else if(Keypad_enmKeyState(KEYPAD_KEY_NO) == BUTTON_STATE_PRESSED)
		{
			if(Info_g_enmAnswers_arr[Run_l_u8QuestionNumber] == INFO_ANSWER_NO)
			{
				Run_l_enmState = INFO_STATE_CORRECT_ANSWER;
			}
			else
			{
				Run_l_enmState = INFO_STATE_WRONG_ANSWER;
			}
		}
		break;
	case INFO_STATE_CORRECT_ANSWER:
		/* output */
		LCD_clear();
		LCD_gotoRowColumn(0,0);
		LCD_displayString("  :)");
		/* next state */
		if(Keypad_enmKeyState(KEYPAD_KEY_NEXT) == BUTTON_STATE_PRESSED)
		{
			Run_l_u8QuestionNumber++;
			if(Run_l_u8QuestionNumber >= INFO_NUMBER_OF_QUESTIONS)
			{
				Run_l_enmState = INFO_STATE_SCORE;
				Run_l_u8Score++;
			}
			else
			{
				Run_l_enmState = INFO_STATE_QUESTION;
			}
		}
		break;
	case INFO_STATE_WRONG_ANSWER:
		/* output */
		LCD_clear();
		LCD_gotoRowColumn(0,0);
		LCD_displayString("  :(");
		/* next state */
		if(Keypad_enmKeyState(KEYPAD_KEY_NEXT) == BUTTON_STATE_PRESSED)
		{
			Run_l_u8QuestionNumber++;
			if(Run_l_u8QuestionNumber >= INFO_NUMBER_OF_QUESTIONS)
			{
				Run_l_enmState = INFO_STATE_SCORE;
			}
			else
			{
				Run_l_enmState = INFO_STATE_QUESTION;
			}
		}
		break;
	case INFO_STATE_SCORE:
		/* output */
		LCD_clear();
		LCD_gotoRowColumn(0,0);
		LCD_displayString("  score = ");
		LCD_Write_Integer_Number(Run_l_u8Score);
		/* next state */
		if(Keypad_enmKeyState(KEYPAD_KEY_RESTART) == BUTTON_STATE_PRESSED)
		{
			Run_l_enmState = INFO_STATE_QUESTION;
			Run_l_u8QuestionNumber = 0;
			Run_l_u8Score = 0;
		}
		break;
	default :
		break;
	}
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/