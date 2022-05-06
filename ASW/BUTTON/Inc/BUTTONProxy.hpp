#ifndef BUTTONPROXY_H_
#define BUTTONPROXY_H_


#include <main.hpp>


class BUTTON_Proxy
{
public:
	uint8_t state;
	uint8_t (*RTE_BUTTON_READ_VALUE)();

	BUTTON_Proxy();
	virtual ~BUTTON_Proxy();
};




#endif /* BUTTONPROXY_H_ */
