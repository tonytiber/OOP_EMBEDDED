#ifndef ASW_STEP_STEP_H_
#define ASW_STEP_STEP_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "RTE.h"
#include "STEPData.h"

class STEPProxy
{
	private:
		STEPData STEPData;
	public:
	//attributes
		void (*RTE_STEP_WRITE_VALUE)(uint8_t); // funtion pointer //attribute of this class

	//method
		STEPProxy();
		virtual ~STEPProxy();

		void STEPProxy_Init();
		void STEPProxy_Cleanup();

		uint8_t STEPProxy_accessSTEPDirection();
		uint8_t STEPProxy_accessSTEPSpeed();
		uint8_t STEPProxy_aceessSTEPState();

		/* keep all settings the same but clear error bits */
		void STEPProxy_clearErrorStatus();

		/* Configure must be called first, since it sets up the */

		/* address of the device. */
		void STEPProxy_configure(uint8_t length, uint8_t*location);

		/* turn motor off but keep original settings */
		void STEPProxy_disable( );

		/* Start up the hardware but leave all other settings of the */
		/* hardware alone */
		void STEPProxy_enable();

		/* precondition: must be called AFTER configure() function. */
		/* turn on the hardware to a known default state. */
		void STEPProxy_initialize();

		/* update the speed and direction of the motor together */
		void STEPProxy_writeSTEPSpeed(const uint8_t direction, uint8_t speed);
};


#ifdef __cplusplus
}
#endif

#endif /* ASW_STEP_STEP_H_ */
