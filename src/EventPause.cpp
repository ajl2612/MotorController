/*
 * EventPause.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventPause.h"
#define COMMAND_PAUSE 'p'

/**
 * Default Constructor
 */
EventPause::EventPause(int motorNum) {
	this->motor = motorNum;
}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventPause::getMessage(){
    return COMMAND_PAUSE;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventPause::getMotor(){
	return this->motor;
}
