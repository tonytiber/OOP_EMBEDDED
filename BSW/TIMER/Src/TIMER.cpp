#include "TIMER.h"

void DELAY_uS(uint16_t uS)
{
	htim2.Instance->CNT = 0;
	while (htim2.Instance->CNT < uS);	// wait for the counter to reach he us input in the parameter
}

void DELAY_1_mS()
{
	htim2.Instance->CNT = 0;
	while (htim2.Instance->CNT < 1000 );
}

void DELAY_mS(uint16_t mS)
{
	for ( int i = 0 ; i < mS ; i--)
	{
		DELAY_1_mS();
	}
}


void DELAY_1S ()
{
	int i = 0;
	while (i < 1000)
	{
		DELAY_1_mS();
		i++;
	}
}

void DELAY_S(uint16_t S)
{
	int i = 0;
	do
	{
		DELAY_1S();
		i++;
	}while (i < 1000);
}

