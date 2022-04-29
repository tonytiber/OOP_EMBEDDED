
#ifndef ASW_CORE_INC_MAIN_H_
#define ASW_CORE_INC_MAIN_H_

#include "ECU_Init.h"
#include "LEDProxy.h"
#include "RTE.h"
#include "BUTTONProxy.h"
#include "TIMER.h"
#include "DHT11.h"
#include "PWM.h"


extern GPIO_PinState *RTE_LED1;
extern GPIO_PinState *RTE_LED2;

extern uint8_t *RTE_BUTTON1;


#endif /* ASW_CORE_INC_MAIN_H_ */
