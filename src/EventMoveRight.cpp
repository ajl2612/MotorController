/*
 * EventMoveRight.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventMoveRight.h"
#define COMMAND_MOVERIGHT 'r'

/**
 * Default Constructor
 */
EventMoveRight::EventMoveRight(int motorNum) {
	this->motor = motorNum;
}

/**
 * Default Destructor
 */
EventMoveRight::~EventMoveRight() {}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventMoveRight::getMessage(){
    return COMMAND_MOVERIGHT;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventMoveRight::getMotor(){
	return this->motor;
}
