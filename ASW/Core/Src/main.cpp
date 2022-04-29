#include "main.h"

int main(void)
{
	ECU_Init();

	PWM_Start(&htim2, TIM_CHANNEL_1);
	uint8_t x;


//	LED_Proxy LED1, LED2;
//
//	LED1.RTE_LED_SET_VALUE = RTE_LEDWrite_RTE_LED1;
//	LED2.RTE_LED_SET_VALUE = RTE_LEDWrite_RTE_LED2;
//
//
//	BUTTON_Proxy BUTTON1;
//	BUTTON1.RTE_BUTTON_READ_VALUE = RTE_BUTTONRead_RTE_BUTTON1;


	while (1)
	{
//			LED1.state = 1;
//			LED2.state = 1;
//
//			LED1.RTE_LED_SET_VALUE(LED1.state);
//			LED2.RTE_LED_SET_VALUE(LED2.state);
//
//			DELAY_1S();
//
//			LED1.state = 0;
//			LED2.state = 0;
//
//			LED1.RTE_LED_SET_VALUE(LED1.state);
//			LED2.RTE_LED_SET_VALUE(LED2.state);
//
//			DELAY_1S();

		for ( int i = 0; i < 100; i++)
		{
			PWM_WriteValue(&htim2, TIM_CHANNEL_1, i);
			DELAY_mS(100);
		}
	}
	return 0;
}
