#include <main.hpp>

int main(void)
{
	RTE_HW_Init(); // khoi tao MCU

	STEPProxy STEP1,STEP2,STEP3; //tao 1 object

	STEP1.RTE_STEP_WRITE_VALUE = &RTE_PWMWrite_PWM_Val1; // assign real port to vitural port

	//STEP1.STEPProxy_writeSTEPSpeed(STEP_DIR_STOP, 50);

	RotatingArmJoint Joint1;
	Joint1.RAJ_STEP = &STEP1;
	Joint1.RAJ_rotate(100);
	HAL_Delay(2000);
	//Joint1.RAJ_zero();
	Joint1.RAJ_rotate(50);

	while (1)
	{

	}

	return 0;
}
