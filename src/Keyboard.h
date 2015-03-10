//
//  Keyboard.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__Keyboard__
#define __StateMachine__Keyboard__

#include <iostream>
#include "EventGenerator.h"
#include "EventPause.h"
#include "EventContinue.h"
#include "EventMoveLeft.h"
#include "EventMoveRight.h"
#include "EventNoop.h"
#include "EventRestart.h"
#include "EventError.h"
#include "EventExit.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include "mutex.h"
#include <queue>

class Keyboard: public EventGenerator{
    
private:
    
    EventQueue* myQueue;
	char commandOne;
	char commandTwo;
	bool newCmds;
	bool alreadyRead;
	bool done;

	PThreads::Mutex mtx;
	pthread_t keyboard;
	pthread_t monitor;

    void sendCMD(char cmd, int machine);
    
public:
    Keyboard( EventQueue* queue);
    void* runProcess (void* args);
    void* monitorBlocking (void* args);
    void shutDown();

};

#endif /* defined(__StateMachine__Keyboard__) */
