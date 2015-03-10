/*
 * EventMoveLeft.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "EventMoveLeft.h"
#define COMMAND_MOVELEFT 'l'

/**
 * Default Constructor
 */
EventMoveLeft::EventMoveLeft(int motorNum) {
	this->motor = motorNum;
}

/**
 * Function for returning the command associated with
 * this event.
 */

char EventMoveLeft::getMessage(){
    return COMMAND_MOVELEFT;
}

/**
 * Function for returning the motor number associated with
 * this event.
 * Values 0 for left motor and 1 for right motor.
 */
int EventMoveLeft::getMotor(){
	return this->motor;
}
