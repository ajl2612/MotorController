/*
 * StatePaused.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "StatePaused.h"
#define STATENAME_PAUSED "PAUSED"

/**
 * Default Constructor
 * Sets local variable for stateID to defined constant in State.h
 */
StatePaused::StatePaused() {
	this->stateID = STATE_PAUSED;
}

/**
 * Default Destructor
 */
StatePaused::~StatePaused() {}

/**
 * On entry function for state. State specific behavior located here.
 */
void StatePaused::onEntry(){
    printf("Entering Paused State\n");
    NOP();
}

/**
 * Not used in this project.
 */
void StatePaused::onReEntry(){
    NOP();
}
/**
 * Not used in this project.
 */
void StatePaused::onExit(){
    NOP();
}

/**
 * Transition function. Handles logic of switching from state to state.
 *
 * Parameter event_id : character for event acting upon this state.
 * Return : Number representing resulting state from transition.
 */
int StatePaused::transition(char event_id){

	switch( event_id ){

	case EVENT_PAUSE:
		printf("Motor already in PAUSED state.\n");
		return STATE_PAUSED;
		break;
	case EVENT_CONTINUE:
		printf("Resuming motor recipe.\n");
		return STATE_RUNNING;
		break;
	case EVENT_MOVELEFT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		printf("Motor moving one position to the left if possible.\n");
		return STATE_PAUSED;
		break;
	case EVENT_MOVERIGHT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		printf("Motor moving one position to the right if possible.\n");
		return STATE_PAUSED;
		break;
	case EVENT_NOOP:
		printf("No Operation : PAUSED state\n");
		return STATE_PAUSED;
		break;
	case EVENT_RESTART:
		//TODO motor reset code here
		printf("Starting motor recipe from beginning.\n");
		return STATE_RUNNING;
		break;
	case EVENT_ERROR:
		printf("Error Encountered : PAUSED state\n");
		return STATE_ERROR;
		break;
	case EVENT_EXIT:
		printf("PAUSED state received EXIT command. Error in StateMachine event handling.\n");
		return STATE_ERROR;
		break;
	default:
		printf( "ERROR: no event definition for StatePaused code:%d\n", event_id);
		return STATE_ERROR;
	}
	//If code reaches this line an error has occurred.
	return -1;
}
