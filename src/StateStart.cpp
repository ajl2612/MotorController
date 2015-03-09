/*
 * StateStart.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "StateStart.h"
#define STATENAME_START "START"

/**
 * Default Constructor
 * Sets local variable for stateID to defined constant in State.h
 */
StateStart::StateStart() {
	this->stateID = STATE_START;
}

/**
 * Default Destructor
 */
StateStart::~StateStart() {}

/**
 * On entry function for state. State specific behavior located here.
 */
void StateStart::onEntry(){
    printf("Entering Start State\n");
    NOP();
}

/**
 * Not used in this project.
 */
void StateStart::onReEntry(){
    NOP();
}
/**
 * Not used in this project.
 */
void StateStart::onExit(){
    NOP();
}

/**
 * Transition function. Handles logic of switching from state to state.
 *
 * Parameter event_id : character for event acting upon this state.
 * Return : Number representing resulting state from transition.
 */
char StateStart::transition(char event_id){

	switch( event_id ){

	case EVENT_PAUSE:
		std::printf("No transition for PAUSE event in START state.\n");
		return STATE_START;
		break;
	case EVENT_CONTINUE:
		std::printf("Starting motor recipe.\n");
		return STATE_RUNNING;
		break;
	case EVENT_MOVELEFT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		std::printf("Motor moving one position to the left if possible.\n");
		return STATE_START;
		break;
	case EVENT_MOVERIGHT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		std::printf("Motor moving one position to the right if possible.\n");
		return STATE_START;
		break;
	case EVENT_NOOP:
		std::printf("No Operation : START state\n");
		return STATE_START;
		break;
	case EVENT_RESTART:
		//TODO motor reset code here
		std::printf("Starting motor recipe.\n");
		return STATE_RUNNING;
		break;
	case EVENT_ERROR:
		std::printf("Error Encountered : START state\n");
		return STATE_ERROR;
		break;
	case EVENT_EXIT:
		std::printf("START state received EXIT command. Error in StateMachine event handling.\n");
		return STATE_ERROR;
		break;
	default:
		std::printf( "ERROR: no event definition for StateStart code:%d\n", event_id);
		return STATE_ERROR;
	}
	//If code reaches this line an error has occurred.
	return -1;
}
