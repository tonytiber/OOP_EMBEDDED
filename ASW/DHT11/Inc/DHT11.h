#ifndef _INC_DHT11_H_
#define _INC_DHT11_H_

#define DHT11_STARTTIME 18000
#define DHT22_STARTTIME 12000
#define DHT11 0x01
#define DHT22 0x02

#include "ECU_Init.h"
#include "GPIO.h"

typedef struct DHT_Name
{
	uint8_t Respone;
	uint16_t Type;
	TIM_HandleTypeDef* Timer;
	uint16_t Pin;
	GPIO_TypeDef* Port;
	float Temp;
	float Humi;
}DHT_Name;

void DHT_DelayInit();
void DHT_DelayUs(uint16_t Time);

void DHT_SetPinOut();
void DHT_SetPinIn();

void DHT_WritePin( GPIO_PinState Value);
uint8_t DHT_ReadPin();

uint8_t DHT_Start();
uint8_t DHT_Read();

void DHT_Init(DHT_Name* DHT, uint8_t DHT_Type);
uint8_t DHT_ReadTempHum(DHT_Name* DHT);

#endif /*_INC_DHT11_H_*/
