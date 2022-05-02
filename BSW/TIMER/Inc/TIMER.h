/*
 * TIMER.h
 *
 *  Created on: Apr 10, 2022
 *      Author: Lenovo
 */

#ifndef BSW_TIMER_TIMER_H_
#define BSW_TIMER_TIMER_H_



#include "ECU_Init.h"
#define CHANEL_TIMER htim2


//typedef TIM_HandleTypeDef TIM_TypeDef;

void TIMER_Start();
void DELAY_uS(uint16_t uS);
void DELAY_1_mS ();
void DELAY_mS(uint16_t mS);
void DELAY_1S ();
void DELAY_S(uint16_t S);



#endif /* BSW_TIMER_TIMER_H_ */
