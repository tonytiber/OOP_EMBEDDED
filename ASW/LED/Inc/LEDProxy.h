#ifndef ASW_LED_LEDPROXY_H_
#define ASW_LED_LEDPROXY_H_

#include <ECU_Init.h>

class LED_Proxy
{
public:
	// attributes
	uint8_t state;
	void (*RTE_LED_SET_VALUE)(uint8_t state);

	// functions
	LED_Proxy();
	virtual ~LED_Proxy();

};

#endif /* ASW_LED_LEDPROXY_H_ */
