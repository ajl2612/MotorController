/*
 * StatePaused.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef STATEPAUSED_H_
#define STATEPAUSED_H_

#include "State.h"
class StatePaused : public State{
public:
	StatePaused();
	~StatePaused();
    int transition( char event_id );
    void onEntry();
    void onReEntry();
    void onExit();
};

#endif /* STATEPAUSED_H_ */
