#include "../Inc/STEPProxy.h"

void STEPProxy::STEPProxy_Init()
{
	this->RTE_STEP_WRITE_VALUE = nullptr;
}

void STEPProxy::STEPProxy_Cleanup()
{

}

STEP_DIR STEPProxy::STEPProxy_accessSTEPDirection()
{
	return STEPData.STEP_direction;
}

uint8_t STEPProxy::STEPProxy_accessSTEPSpeed()
{
	return STEPData.STEP_speed;
}

uint8_t STEPProxy::STEPProxy_aceessSTEPState()
{
	return STEPData.STEP_errorStatus;
}

/* keep all settings the same but clear error bits */
void STEPProxy::STEPProxy_clearErrorStatus()
{
	STEPData.STEP_errorStatus = 0;
}

/* Configure must be called first, since it sets up the */

/* address of the device. */
void STEPProxy::STEPProxy_configure(uint8_t length, uint8_t*location)
{

}

/* turn STEP off but keep original settings */
void STEPProxy::STEPProxy_disable()
{
	STEPData.STEP_on_off = STEP_OFF;
}

/* Start up the hardware but leave all other settings of the */
/* hardware alone */
void STEPProxy::STEPProxy_enable()
{
	STEPData.STEP_on_off = STEP_ON;
}

/* precondition: must be called AFTER configure() function. */
/* turn on the hardware to a known default state. */
void STEPProxy::STEPProxy_initialize()
{

}

/* update the speed and direction of the STEP together */
void STEPProxy::STEPProxy_writeSTEPSpeed(const uint8_t direction, uint8_t speed)
{

}

STEPProxy::STEPProxy()
{

}

STEPProxy::~STEPProxy()
{

}


