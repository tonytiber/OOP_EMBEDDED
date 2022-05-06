#ifndef ASW_ROBOTARMMANAGER_ACTION_H_
#define ASW_ROBOTARMMANAGER_ACTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

struct Action
{
	uint8_t rotatingArmJoint1;
	uint8_t rotatingArmJoint2;
	uint8_t rotatingArmJoint3;
	uint8_t manipulatorForce;
	uint8_t manipulatorOpen;
};

#ifdef __cplusplus
}
#endif

#endif /* ASW_ROBOTARMMANAGER_ACTION_H_ */
