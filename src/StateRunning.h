/*
 * StateRunning.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef STATERUNNING_H_
#define STATERUNNING_H_

#include "State.h"
class StateRunning : public State {
public:
	StateRunning();
	~StateRunning();
    int transition( char event_id );
    void onEntry();
    void onReEntry();
    void onExit();
};

#endif /* STATERUNNING_H_ */
