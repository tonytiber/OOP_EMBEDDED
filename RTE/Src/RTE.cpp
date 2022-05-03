#include "RTE.h"

GPIO_PinState *RTE_LED1;
GPIO_PinState *RTE_LED2;

uint8_t *RTE_BUTTON1;
uint8_t *PWM_Val1;

void RTE_LEDWrite_RTE_LED1(uint8_t value)
{

	GPIO_PinState temp;
	RTE_LED1 = &temp;
	if (value == 0)
	{
		temp = GPIO_PIN_RESET;
	}
	else
	{
		temp = GPIO_PIN_SET;
	}

	GPIO_Write_Pin(GPIOA, GPIO_PIN_9, *RTE_LED1);
}

void RTE_LEDWrite_RTE_LED2(uint8_t value)
{

	GPIO_PinState temp;
	RTE_LED2 = &temp;
	if (value == 0)
	{
		temp = GPIO_PIN_RESET;
	}
	else
	{
		temp = GPIO_PIN_SET;
	}

	GPIO_Write_Pin(GPIOA, GPIO_PIN_10, *RTE_LED2);
}

uint8_t RTE_BUTTONRead_RTE_BUTTON1()
{
	uint8_t temp;
	RTE_BUTTON1 = &temp;
	temp = GPIO_Read_Pin(GPIOC, GPIO_PIN_9);
	return *RTE_BUTTON1;
}


void RTE_PWMWrite_PWM_Val1(uint8_t value)
{
	uint8_t temp = value;
	PWM_Val1 = &temp;
	PWM_WriteValue(&htim2, TIM_CHANNEL_1,*PWM_Val1);
}
