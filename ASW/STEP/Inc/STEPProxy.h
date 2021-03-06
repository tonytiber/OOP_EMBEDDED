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
		//attributes
		STEPData STEPData;
	public:
		//attributes
		void (*RTE_STEP_WRITE_VALUE)(uint8_t); // funtion pointer //attribute of this class
		void (*RTE_DIR_WRITE_VALUE)(uint8_t);
		//method
		STEPProxy();
		virtual ~STEPProxy();

//		void STEPProxy_Set_STEP_Port();
//		void STEPProxy_Set_DIR_Port();

		void STEPProxy_Init();
		void STEPProxy_Cleanup();

		//STEP_DIR STEPProxy_accessSTEPDirection();

		char STEPProxy_accessSTEPangle();
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

		/* update the angle and direction of the motor together */
		void STEPProxy_writeSTEPangle(char angle);
};


#ifdef __cplusplus
}
#endif

#endif /* ASW_STEP_STEP_H_ */
