/*******************************************************************************************************************
 * Keypad_Lcfg.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia - Taha Gamal
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Keypad.h"
#include "ATmega32Pins.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/
const uint8_t Keypad_u8RowPins[KEYPAD_NUMBER_OF_ROWS] =
{
	/*......................................................................................*/
	/* state the row pins connections below */
	SPRINTS_ROW_1,
	SPRINTS_ROW_2,
	SPRINTS_ROW_3
	/*......................................................................................*/
};
const uint8_t Keypad_u8ColumnPins[KEYPAD_NUMBER_OF_COLUMNS] =
{
	/*......................................................................................*/
	/* state the column pins connections below */
	SPRINTS_COLUMN_1,
	SPRINTS_COLUMN_2,
	SPRINTS_COLUMN_3
	/*......................................................................................*/
};
/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/