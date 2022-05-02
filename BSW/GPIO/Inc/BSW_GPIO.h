#ifndef GPIO_INC_GPIO_DRIVER_H_
#define GPIO_INC_GPIO_DRIVER_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "ECU_Init.h"

#define PIN_SET 	1
#define PIN_RESET	0

typedef GPIO_TypeDef	GPIO_Type;

uint8_t GPIO_Read_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_Write_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin,GPIO_PinState status);
void GPIO_Toggle_Pin(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
uint8_t GPIO_SetPinIn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t GPIO_SetPinOut(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_INC_GPIO_DRIVER_H_ */
