//
//  EventQueue.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__EventQueue__
#define __StateMachine__EventQueue__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "mutex.h"
#include "Event.h"

class EventQueue{
    
private:
    std::queue<Event*> eventQueue;
    PThreads::Mutex mtx;
    
public:
    //EventQueue();
    //~EventQueue();
    void enterCMD(Event* e);
    Event* frontCMD();
    void popCMD();
    bool empty();

};

#endif /* defined(__StateMachine__EventQueue__) */
