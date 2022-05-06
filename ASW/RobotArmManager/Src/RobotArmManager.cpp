#include "RobotArmManager.h"

void RobotArmManager::RAM_Init()
{

}

void RobotArmManager::RAM_Cleanup()
{
	int pos;

	for(pos = 0; pos < 100; ++pos)
	{
		RAM_Action[pos] = NULL;
	}

	RAM_GraspingManipulator = NULL;

	for(pos = 0; pos < 3; ++pos)
	{
		RAM_RotatingArmJoint[pos] = NULL;
	}
}

uint8_t RobotArmManager::RAM_graspAt( uint8_t x, uint8_t y, uint8_t z, uint8_t t)
{
	RAM_currentStep = -1;
	RAM_nSteps = 0;

	RAM_zero();
	RAM_computeTrajectory(x,y,z,t);

	if ( RAM_nSteps == 0 )
	{
	RAM_status = -1;
	}
	else
	{
		do
		{
			RAM_currentStep++;
			RAM_status = RAM_executeStep();
		}
		while (RAM_status ==0 && RAM_currentStep < RAM_nSteps);
	}
	return RAM_status;
}

void RobotArmManager::RAM_computeTrajectory(uint8_t x, uint8_t y, uint8_t z, uint8_t t)
{

}

uint8_t RobotArmManager::RAM_executeStep()
{
	int actionValue = 0;
	int step = RAM_currentStep;
	int RAM_status = 0;
	if (RAM_Action[step])
	{
		actionValue = RAM_Action[step]->rotatingArmJoint1;
		RAM_status = RAM_RotatingArmJoint[0]->RAJ_rotate(actionValue);
		if (RAM_status) return RAM_status;

		actionValue = RAM_Action[step]->rotatingArmJoint2;
		RAM_status = RAM_RotatingArmJoint[1]->RAJ_rotate(actionValue);
		if (RAM_status) return RAM_status;

		actionValue = RAM_Action[step]->rotatingArmJoint3;
		RAM_status = RAM_RotatingArmJoint[2]->RAJ_rotate(actionValue);
		if (RAM_status) return RAM_status;

		actionValue = RAM_Action[step]->manipulatorForce;
		RAM_status = RAM_GraspingManipulator->GM_setMaxForce(actionValue);
		if (RAM_status) return RAM_status;

		if (RAM_Action[step]->manipulatorOpen)
			RAM_status = RAM_GraspingManipulator->GM_open();
		else
			RAM_status = RAM_GraspingManipulator->GM_close();
	};
	return RAM_status;
}

uint8_t RobotArmManager::RAM_zero()
{
	/* zero all devices */
	int j;
	for (j=0; j<3; j++)
	{
		if (RAM_RotatingArmJoint[j] == NULL) return -1;
		if (RAM_RotatingArmJoint[j]->RAJ_zero()) return -1;
	}

	if (RAM_GraspingManipulator == NULL) return -1;
	if (RAM_GraspingManipulator->GM_open()) return -1;

	return 0;
}

RobotArmManager::RobotArmManager()
{
	RAM_Init();
}

RobotArmManager::~RobotArmManager()
{
	RAM_Cleanup();
}

