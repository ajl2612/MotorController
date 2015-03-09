/*
 * EventError.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventError.h"
#define COMMAND_ERROR 'e'

/**
 * Default Constructor
 */
EventError::EventError(int motorNum) {
	this->motor = motorNum;
}

/**
 * Default Destructor
 */
EventError::~EventError() {}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventError::getMessage(){
    return COMMAND_ERROR;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventError::getMotor(){
	return this->motor;
}
