/*
 * EventContinue.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventContinue.h"
#define COMMAND_CONTINUE 'c'

/**
 * Default Constructor
 */
EventContinue::EventContinue(int motorNum) {
	this->motor = motorNum;
}

/**
 * Default Destructor
 */
EventContinue::~EventContinue() {}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventContinue::getMessage(){
    return COMMAND_CONTINUE;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventContinue::getMotor(){
	return this->motor;
}
