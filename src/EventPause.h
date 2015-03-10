/*
 * EventPause.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef EVENTPAUSE_H_
#define EVENTPAUSE_H_

#include "Event.h"
class EventPause : public Event{
public:
    EventPause(int);
	char getMessage();
	int getMotor();
};

#endif /* EVENTPAUSE_H_ */
