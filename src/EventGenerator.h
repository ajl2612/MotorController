//
//  EventGenerator.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__EventGenerator__
#define __StateMachine__EventGenerator__

#include <iostream>
#include "EventQueue.h"
#include "Event.h"

#define EVENT_PAUSE 'p'
#define EVENT_CONTINUE 'c'
#define EVENT_MOVELEFT 'l'
#define EVENT_MOVERIGHT 'r'
#define EVENT_NOOP 'n'
#define EVENT_RESTART 'b'
#define EVENT_ERROR 'e'
#define EVENT_EXIT 'q'

class EventGenerator{

protected:
    EventQueue *myQueue;
    virtual void sendCMD(char cmd, int machine) = 0;

public:
        //virtual void* runProcess (void* arg) = 0;
};
#endif /* defined(__StateMachine__EventGenerator__) */       
