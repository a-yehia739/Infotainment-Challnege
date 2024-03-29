/*******************************************************************************************************************
 * SOS.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#ifndef SOS_H_
#define SOS_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "SOS_cfg.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
typedef enum
{
	SOS_OK,
	SOS_NOT_OK
}SOS_enmStatus_t;
typedef enum
{
    SOS_TASK_STATE_READY,
    SOS_TASK_STATE_RUN,
    SOS_TASK_STATE_WAIT,
    SOS_TASK_STATE_DELETE
}SOS_enmTaskState_t;
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/
typedef struct
{
	uint16_t m_u16Period;
	void (*m_vCallBackFunction_ptr)(void);
	SOS_enmTaskState_t m_enmState;
}SOS_strTask_t;
/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
extern SOS_enmStatus_t SOS_enmInit(void);
extern SOS_enmStatus_t SOS_enmCreateTask(SOS_enmTaskName_t a_enmName, uint16_t a_u16Period, void (*a_vCallBackFunction_ptr)(void));
extern SOS_enmStatus_t SOS_enmDeleteTask(SOS_enmTaskName_t a_enmName);
extern SOS_enmStatus_t SOS_enmRun(void);
#endif /* SOS_H_ */
