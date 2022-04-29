

#ifndef RTE_INC_RTE_H_
#define RTE_INC_RTE_H_

#include "GPIO.h"

extern GPIO_PinState *RTE_LED1;
extern uint8_t *RTE_BUTTON1;


void RTE_LEDWrite_RTE_LED1(uint8_t value);
void RTE_LEDWrite_RTE_LED2(uint8_t value);

uint8_t RTE_BUTTONRead_RTE_BUTTON1();



#endif /* RTE_INC_RTE_H_ */
