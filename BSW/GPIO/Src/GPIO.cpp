#include "GPIO.h"
#include "stdbool.h"
#include "TIMER.h"

uint8_t GPIO_Read_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_PinState State_Button = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
	if (State_Button == PIN_SET)
		return 1;
	else
		return 0;
}

void GPIO_Write_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin,GPIO_PinState status)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin,status);
}

//ham toggle
void GPIO_Toggle_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOx,GPIO_Pin);
}

// ham read pin in, pin out
uint8_t GPIO_SetPinIn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

	return 1;
}

uint8_t GPIO_SetPinOut(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = 	GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

	return 0;
}



