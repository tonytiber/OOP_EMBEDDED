#ifndef PWM_PWM_H_
#define PWM_PWM_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "ECU_Init.h"

 typedef TIM_HandleTypeDef TIM_TYPE;

 void PWM_Start(TIM_TYPE *htim, uint32_t Channel);
 void PWM_WriteValue(TIM_TYPE *htim, uint32_t Channel, uint8_t Value);

#ifdef __cplusplus
}
#endif

#endif /* PWM_PWM_H_ */
