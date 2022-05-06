#ifndef ASW_INC_STEPData_H_
#define ASW_INC_STEPData_H_

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum
{
	 STEP_OFF = 0,
	 STEP_ON = 1
}STEP_STATUS;

//typedef enum
//{
//	STEP_DIR_STOP = 0,
//	STEP_DIR_FW = 1,
//	STEP_DIR_BW = 2
//}STEP_DIR;

struct STEPData
{
	STEP_STATUS STEP_on_off;
	//STEP_DIR STEP_direction;
	char STEP_angle;
	uint8_t STEP_errorStatus;
	uint8_t STEP_noPowerError;
	uint8_t STEP_noTorqueError;
	uint8_t STEP_BITError;
	uint8_t STEP_overTempError;
	uint8_t STEP_UnknownError;
};

#ifdef __cplusplus
}
#endif

#endif /* ASW_INC_STEPData_H_ */
