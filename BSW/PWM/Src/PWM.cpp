#include "PWM.h"

void PWM_Start(TIM_TYPE *htim, uint32_t Channel)
{
	HAL_TIM_PWM_Start(htim, Channel);
}

void PWM_WriteValue(TIM_TYPE *htim, uint32_t Channel, uint8_t Value)
{
	__HAL_TIM_SET_COMPARE(htim, Channel, Value);
}

