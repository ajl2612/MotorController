/*
 * EventNoop.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventNoop.h"
#define COMMAND_NOOP 'n'

/**
 * Default Constructor
 */
EventNoop::EventNoop(int motorNum) {
	this->motor = motorNum;
}

/**
 * Default Destructor
 */
EventNoop::~EventNoop() {}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventNoop::getMessage(){
    return COMMAND_NOOP;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventNoop::getMotor(){
	return this->motor;
}
