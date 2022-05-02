
#ifndef ASW_CORE_INC_MAIN_HPP_
#define ASW_CORE_INC_MAIN_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "ECU_Init.h"
#include <LEDProxy.hpp>
#include "RTE.h"
#include <BUTTONProxy.hpp>
#include "TIMER.h"
#include "DHT11.h"
#include "PWM.h"
#include "BSW_GPIO.h"


extern GPIO_PinState *RTE_LED1;
extern GPIO_PinState *RTE_LED2;


extern uint8_t *RTE_BUTTON1;

#ifdef __cplusplus
}
#endif


#endif /* ASW_CORE_INC_MAIN_HPP_ */
