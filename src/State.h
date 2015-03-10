//
//  State.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__State__
#define __StateMachine__State__

#define STATE_START 0
#define STATE_RUNNING 1
#define STATE_PAUSED 2
#define STATE_FINISHED 3
#define STATE_ERROR 4

#define EVENT_PAUSE 'p'
#define EVENT_CONTINUE 'c'
#define EVENT_MOVELEFT 'l'
#define EVENT_MOVERIGHT 'r'
#define EVENT_NOOP 'n'
#define EVENT_RESTART 'b'
#define EVENT_ERROR 'e'
#define EVENT_EXIT 'q'

#include <iostream>

class State{
protected:
    int stateID;
    
public:
    int NOP();

    int getID();

    virtual int transition( char event_id ) = 0;
    virtual void onEntry() = 0;
    virtual void onReEntry() = 0;
    virtual void onExit() = 0;
};

#endif /* defined(__StateMachine__State__) */
