#ifndef ASW_ROBOTARMMANAGER_ROTATINGARMJOINT_H_
#define ASW_ROBOTARMMANAGER_ROTATINGARMJOINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "STEPProxy.h"



class RotatingArmJoint //RAJ
{
private:
	uint8_t RAJ_angle;
	uint8_t RAJ_deviceID;

public:
	STEPProxy *RAJ_STEP;
	uint8_t RAJ_getRotation();
	uint8_t RAJ_rotate(char angle);
	uint8_t RAJ_zero();
	RotatingArmJoint();
	virtual ~RotatingArmJoint();
};

#ifdef __cplusplus
}
#endif

#endif /* ASW_ROBOTARMMANAGER_ROTATINGARMJOINT_H_ */
