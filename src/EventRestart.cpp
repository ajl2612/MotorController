/*
 * EventRestart.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventRestart.h"
#define COMMAND_RESTART 'b'

/**
 * Default Constructor
 */
EventRestart::EventRestart(int motorNum) {
	this->motor = motorNum;
}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventRestart::getMessage(){
    return COMMAND_RESTART;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventRestart::getMotor(){
	return this->motor;
}
