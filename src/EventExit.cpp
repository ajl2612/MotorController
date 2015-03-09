/*
 * EventExit.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventExit.h"
#define COMMAND_EXIT 'q'

/**
 * Default Constructor
 */
EventExit::EventExit(int motorNum) {
	this->motor = motorNum;
}

/**
 * Default Destructor
 */
EventExit::~EventExit() {}

/**
 * Function for returning the command associated with
 * this event.
 */
char EventExit::getMessage(){
    return COMMAND_EXIT;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventExit::getMotor(){
	return this->motor;
}
