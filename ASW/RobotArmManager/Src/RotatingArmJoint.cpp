#include "RotatingArmJoint.h"

uint8_t RotatingArmJoint::RAJ_getRotation()
{
	return this->RAJ_angle;
}

uint8_t RotatingArmJoint::RAJ_rotate(char angle)
{
	RAJ_STEP->STEPProxy_writeSTEPangle(angle);
	return 0;
}

uint8_t RotatingArmJoint::RAJ_zero()
{
	RAJ_STEP = nullptr;
}

RotatingArmJoint::RotatingArmJoint()
{

}

RotatingArmJoint::~RotatingArmJoint()
{

}

