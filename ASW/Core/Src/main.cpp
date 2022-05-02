#include <main.hpp>

int main(void)
{
	ECU_Init();
	PWM_Start(&htim2, TIM_CHANNEL_1);

	while (1)
	{
		for(int i = 0; i < 100 ; i++){
			RTE_PWMWrite_PWM_Val1(i);
			HAL_Delay(5);
		}
	}
	return 0;
}
