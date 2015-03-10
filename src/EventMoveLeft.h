/*
 * EventMoveLeft.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef EVENTMOVELEFT_H_
#define EVENTMOVELEFT_H_

#include "Event.h"
class EventMoveLeft : public Event{
public:
	EventMoveLeft(int);
	char getMessage();
	int getMotor();
};

#endif /* EVENTMOVELEFT_H_ */
