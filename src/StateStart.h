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
	~StateStart();
    int transition( char event_id );
    void onEntry();
    void onReEntry();
    void onExit();
};

#endif /* STATESTART_H_ */
