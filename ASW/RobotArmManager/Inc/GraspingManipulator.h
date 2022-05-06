#ifndef ASW_ROBOTARMMANAGER_GRASPINGMANIPULATOR_H_
#define ASW_ROBOTARMMANAGER_GRASPINGMANIPULATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

class GraspingManipulator //GM
{
private:
	uint8_t GM_deviceID;
	uint8_t GM_maxForce = 0;
public:
	uint8_t GM_open();
	uint8_t GM_close();
	uint8_t GM_setMaxForce(uint8_t );
	uint8_t GM_getClosure();
	GraspingManipulator();
	virtual ~GraspingManipulator();
};

#ifdef __cplusplus
}
#endif

#endif /* ASW_ROBOTARMMANAGER_GRASPINGMANIPULATOR_H_ */
