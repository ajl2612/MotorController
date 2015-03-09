/*
 * StateError.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "StateError.h"
#define STATENAME_ERROR "ERROR"

/**
 * Default Constructor
 * Sets local variable for stateID to defined constant in State.h
 */
StateError::StateError() {
	this->stateID = STATE_ERROR;
}

/**
 * Default Destructor
 */
StateError::~StateError() {}

/**
 * On entry function for state. State specific behavior located here.
 */
void StateError::onEntry(){
    printf("Entering Error State\n");
    NOP();
}

/**
 * Not used in this project.
 */
void StateError::onReEntry(){
    NOP();
}
/**
 * Not used in this project.
 */
void StateError::onExit(){
    NOP();
}

/**
 * Transition function. Handles logic of switching from state to state.
 *
 * Parameter event_id : character for event acting upon this state.
 * Return : Number representing resulting state from transition.
 */
char StateError::transition(char event_id){

	switch( event_id ){

	case EVENT_PAUSE:
		std::printf("No transition for PAUSE event in ERROR state.\n");
		return STATE_ERROR;
		break;
	case EVENT_CONTINUE:
		std::printf("No transition for CONTINUE event in ERROR state.\n");
		return STATE_ERROR;
		break;
	case EVENT_RESTART:
		//TODO motor reset code here
		std::printf("Resuming motor recipe from beginning.\n");
		return STATE_RUNNING;
		break;
	case EVENT_MOVELEFT:
		std::printf("No transition for MOVELEFT event in ERROR state.\n");
		return STATE_ERROR;
		break;
	case EVENT_MOVERIGHT:
		std::printf("No transition for MOVERIGHT event in ERROR state.\n");
		return STATE_ERROR;
		break;
	case EVENT_NOOP:
		std::printf("No Operation : ERROR state\n");
		return STATE_ERROR;
		break;
	case EVENT_ERROR:
		std::printf("Error Encountered : ERROR state\n");
		return STATE_ERROR;
		break;
	case EVENT_EXIT:
		std::printf("ERROR state received EXIT command. Error in StateMachine event handling.\n");
		return STATE_ERROR;
		break;
	default:
		std::printf( "ERROR: no event definition for StateError code:%d\n", event_id);
		return STATE_ERROR;
	}
	//If code reaches this line an error has occurred.
	return -1;
}

