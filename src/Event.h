//
//  Event.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__Event__
#define __StateMachine__Event__

#include <iostream>
#include <string>


class Event{
    
protected:
	// represents the command type of this event.
    char command;
    // Represents the motor associated with this command.
    // Valid values are 0 for left motor and 1 for right motor.
    int motor;
    
public:
    virtual char getMessage() = 0;
    virtual int getMotor() = 0;
};

#endif /* defined(__StateMachine__Event__) */
