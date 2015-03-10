/*
 * EventError.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef EVENTERROR_H_
#define EVENTERROR_H_

#include "Event.h"
class EventError : public Event{
public:
	EventError(int);
	char getMessage();
	int getMotor();
};

#endif /* EVENTERROR_H_ */
