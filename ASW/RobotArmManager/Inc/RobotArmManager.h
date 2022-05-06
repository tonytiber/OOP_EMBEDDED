#ifndef ASW_ROBOTARMMANAGER_ROBOTARMMANAGER_H_
#define ASW_ROBOTARMMANAGER_ROBOTARMMANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "GraspingManipulator.h"
#include "RotatingArmJoint.h" //done
#include "Action.h"

class RobotArmManager //RAM
{
private:
	GraspingManipulator *RAM_GraspingManipulator;
	RotatingArmJoint *RAM_RotatingArmJoint[3];
	Action *RAM_Action[100];
	uint8_t RAM_nStep;
	uint8_t RAM_currentStep;
	uint8_t RAM_status;
	void RAM_Init();
	void RAM_Cleanup();
public:
	uint8_t RAM_graspAt( uint8_t x, uint8_t y, uint8_t z, uint8_t t);
	void RAM_computeTrajectory(uint8_t x, uint8_t y, uint8_t z, uint8_t t);
	uint8_t RAM_executeStep();
	uint8_t RAM_zero();
	RobotArmManager();
	virtual ~RobotArmManager();
};

#ifdef __cplusplus
}
#endif

#endif /* ASW_ROBOTARMMANAGER_ROBOTARMMANAGER_H_ */
