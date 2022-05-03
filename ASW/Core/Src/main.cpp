#include <main.hpp>

int main(void)
{
	ECU_Init();
	PWM_Start(&htim2, TIM_CHANNEL_1);

	STEPProxy STEP1;
	STEP1.RTE_STEP_WRITE_VALUE = &RTE_PWMWrite_PWM_Val1;

	STEP1.value = 100;
	STEP1.RTE_STEP_WRITE_VALUE(STEP1.value);

	while (1)
	{

	}

	return 0;
}
