#include "../Inc/STEPProxy.h"

void STEPProxy::STEPProxy_Init()
{
	this->RTE_STEP_WRITE_VALUE = nullptr;
	this->RTE_DIR_WRITE_VALUE = nullptr;
}

void STEPProxy::STEPProxy_Cleanup()
{
	this->STEPProxy_writeSTEPSpeed(STEP_DIR_STOP, 0);
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
void STEPProxy::STEPProxy_configure(uint8_t length, uint8_t *location)
{

}

/* turn STEP off but keep original settings */
void STEPProxy::STEPProxy_disable()
{
	STEPData.STEP_on_off = STEP_OFF;
	STEPData.STEP_direction = STEP_DIR_STOP;
	STEPData.STEP_speed = 0;
	this->STEPProxy_writeSTEPSpeed(STEP_DIR_STOP, STEPData.STEP_speed);
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
void STEPProxy::STEPProxy_writeSTEPSpeed(const STEP_DIR direction, uint8_t speed)
{
	this->RTE_DIR_WRITE_VALUE(direction);
	this->RTE_STEP_WRITE_VALUE(speed);
}

STEPProxy::STEPProxy()
{
	this->STEPProxy_Init();
}

STEPProxy::~STEPProxy()
{
	this->STEPProxy_Cleanup();
}


