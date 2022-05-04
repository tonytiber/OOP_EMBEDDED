#ifndef RTE_INC_RTE_H_
#define RTE_INC_RTE_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <BSW_GPIO.h>
#include <PWM.h>


extern GPIO_PinState *RTE_LED1;

extern GPIO_PinState *RTE_DIR1;

extern uint8_t *RTE_BUTTON1;

extern uint8_t *PWM_Val1;

void RTE_HW_Init();

void RTE_LEDWrite_RTE_LED1(uint8_t value);

void RTE_LEDWrite_RTE_DIR1(uint8_t value);

void RTE_PWMWrite_PWM_Val1(uint8_t value);

uint8_t RTE_BUTTONRead_RTE_BUTTON1();

#ifdef __cplusplus
}
#endif

#endif /* RTE_INC_RTE_H_ */
