/*
 * BUTTONProxy.h
 *
 *  Created on: Apr 10, 2022
 *      Author: Lenovo
 */

#ifndef BUTTONPROXY_H_
#define BUTTONPROXY_H_

#include "main.h"

class BUTTON_Proxy
{
public:
	uint8_t state;
	uint8_t (*RTE_BUTTON_READ_VALUE)();

	BUTTON_Proxy();
	virtual ~BUTTON_Proxy();
};



#endif /* BUTTONPROXY_H_ */
