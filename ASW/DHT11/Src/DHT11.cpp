#include "DHT11.h"
//************************** Low Level Layer ********************************************************//

void microDelay (uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim2, 0);
  while (__HAL_TIM_GET_COUNTER(&htim2) < delay);
}

 void DHT_DelayInit()
{
	HAL_TIM_Base_Start(&htim2);
}

 void DHT_DelayUs(uint16_t Time)
{

	 	htim2.Instance->CNT = 0;
	 	while (htim2.Instance->CNT < Time);	// wait for the counter to reach he us input in the parameter
}

void DHT_SetPinOut()
{
	GPIO_SetPinOut(GPIOB, GPIO_PIN_9);
}

void DHT_SetPinIn()
{
	GPIO_SetPinIn(GPIOB, GPIO_PIN_9);
}

void DHT_WritePin(GPIO_PinState Value)
{
	GPIO_Write_Pin(GPIOB, GPIO_PIN_9, Value);
}

uint8_t DHT_ReadPin()
{
	uint8_t Value;
	Value =  GPIO_Read_Pin(GPIOB, GPIO_PIN_9);
	return Value;
}
//********************************* Middle level Layer ****************************************************//
uint8_t DHT_Start()
{
	  uint8_t Response = 0;
	  DHT_SetPinOut();// set the pin as output

	  DHT_WritePin(GPIO_PIN_RESET);   // pull the pin low
	  microDelay(30000);   // wait for 20ms

	  DHT_WritePin(GPIO_PIN_SET);    // pull the pin high
	  microDelay (30);   // wait for 30us

	  DHT_SetPinIn(); // set the pin as input
	  microDelay (40);

	  if ( !DHT_ReadPin() )
	  {
	    microDelay (80);
	    if (DHT_ReadPin()) Response = 1;
	  }

	  while ( DHT_ReadPin() )
	  {

	  }
	  return Response;
}

uint8_t DHT_Read()
{
	  uint8_t a,b;
	  for (a=0;a<8;a++)
	  {
	    while (!(DHT_ReadPin()))
	    {
	    }
	    microDelay (40);   // wait for 40 us
	    if (!DHT_ReadPin())   // if the pin is low
	      b&= ~(1<<(7-a));
	    else
	      b|= (1<<(7-a));
	    while ((DHT_ReadPin()) )
	    {
	    }
	  }
	  return b;
}

//************************** High Level Layer ********************************************************//
void DHT_Init(DHT_Name* DHT, uint8_t DHT_Type)
{
	if(DHT_Type == DHT11)
	{
		DHT->Type = DHT11_STARTTIME;
	}
	else if(DHT_Type == DHT22)
	{
		DHT->Type = DHT22_STARTTIME;
	}
	DHT->Port = GPIOB;
	DHT->Pin = GPIO_PIN_9;
	DHT->Timer = &htim2;
	DHT_DelayInit();
}

uint8_t DHT_ReadTempHum(DHT_Name* DHT)
{
	DHT->Respone =0;
	uint8_t Temp1, Temp2, RH1, RH2;
	uint16_t Temp, Humi, SUM = 0;
	DHT->Respone = DHT_Start();
	RH1 = DHT_Read();
	RH2 = DHT_Read();
	Temp1 = DHT_Read();
	Temp2 = DHT_Read();
	SUM = DHT_Read();
	Temp = (Temp1<<8)|Temp2;
	Humi = (RH1<<8)|RH2;
	DHT->Temp = (float)(Temp1);
	DHT->Humi = (float)(RH1);
	return SUM;
}
