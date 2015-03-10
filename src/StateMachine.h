/*
 * StateMachine.h
 *
 *  Created on: Mar 19, 2014
 *      Author: ajl2612
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "EventQueue.h"
#include "StateStart.h"
#include "StateRunning.h"
#include "StatePaused.h"
#include "StateFinished.h"
#include "StateError.h"
#include <pthread.h>


#define NUM_STATES 5
#define NUM_MACHINES 2


class StateMachine {
private:
    pthread_t io;
    bool done;
    int current_state[NUM_MACHINES];
    int last_state[NUM_MACHINES];
    EventQueue* myQueue;
    
    StateStart s00;
    StateStart s10;

    StateRunning s01;
    StateRunning s11;

    StatePaused s02;
    StatePaused s12;

    StateFinished s03;
    StateFinished s13;

    StateError s04;
    StateError s14;

    State *states[NUM_MACHINES][NUM_STATES];

    

public:
    void* runProcess(void);
	StateMachine(EventQueue* queue);
	virtual ~StateMachine();
};

#endif /* STATEMACHINE_H_ */
