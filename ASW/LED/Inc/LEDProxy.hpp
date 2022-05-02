#ifndef ASW_LED_LEDPROXY_H_
#define ASW_LED_LEDPROXY_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include <main.hpp>

class LED_Proxy{
public:
	// attributes
	uint8_t state;
	void (*RTE_LED_SET_VALUE)(uint8_t state);

	// functions
	LED_Proxy();
	virtual ~LED_Proxy();

};



#ifdef __cplusplus
}
#endif
#endif /* ASW_LED_LEDPROXY_H_ */
