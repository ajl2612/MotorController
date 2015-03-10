/*
 * StateFinished.h
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#ifndef STATEFINISHED_H_
#define STATEFINISHED_H_

#include "State.h"
class StateFinished : public State{
public:
	StateFinished();
	~StateFinished();
    int transition( char event_id );
    void onEntry();
    void onReEntry();
    void onExit();
};

#endif /* STATEFINISHED_H_ */
