/*
 * StateError.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef STATEERROR_H_
#define STATEERROR_H_

#include "State.h"
class StateError : public State{
public:
	StateError();
	~StateError();
    int transition( char event_id );
    void onEntry();
    void onReEntry();
    void onExit();
};

#endif /* STATEERROR_H_ */
