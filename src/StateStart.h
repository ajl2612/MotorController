/*
 * StateStart.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef STATESTART_H_
#define STATESTART_H_

#include <iostream>
#include "State.h"

class StateStart : public State {
public:
	StateStart();
	virtual ~StateStart();

    void onEntry();
    void onReEntry();
    void onExit();
    int transition(char event_id);
};

#endif /* STATESTART_H_ */
