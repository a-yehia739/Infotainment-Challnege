/*******************************************************************************************************************
 * Infotainment.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia - Taha Gamal
 *******************************************************************************************************************/
#ifndef INFOTAINMENT_H_
#define INFOTAINMENT_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CommonHeaders.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
#define INFO_NUMBER_OF_QUESTIONS	(5u)
#define INFO_MAX_NUMBER_OF_LETTERS	(20u)

typedef enum
{
	INFO_STATE_QUESTION,
	INFO_STATE_CORRECT_ANSWER,
	INFO_STATE_WRONG_ANSWER,
	INFO_STATE_SCORE,
}Info_enmState_t;
typedef enum
{
	INFO_ANSWER_NOTHING,
	INFO_ANSWER_NO,
	INFO_ANSWER_YES
}Info_enmAnswer_t;
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
extern void Info_vInit(void);
extern void Info_vRun(void);
#endif /* INFOTAINMENT_H_ */