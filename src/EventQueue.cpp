//
//  EventQueue.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include "EventQueue.h"

void EventQueue::enterCMD(Event* e){
    printf("EventQueue received new event ... %c.\n", e->getMessage());
    //this->mtx.lock();
    this -> eventQueue.push(e);
    //this->mtx.unlock();
    
}

Event* EventQueue::frontCMD(){
    //this->mtx.lock();
    return this->eventQueue.front();
    //this->mtx.unlock();
}

void EventQueue::popCMD(){
    //this->mtx.lock();
    this->eventQueue.pop();
    //this->mtx.unlock();
}

bool EventQueue::empty(){
    return eventQueue.empty();
}
