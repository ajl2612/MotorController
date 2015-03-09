/*
 * StateRunning.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "StateRunning.h"
#define STATENAME_PAUSED "PAUSED"

/**
 * Default Constructor
 * Sets local variable for stateID to defined constant in State.h
 */
StateRunning::StateRunning() {
	this->stateID = STATE_RUNNING;
}

/**
 * Default Destructor
 */
StateRunning::~StateRunning() {}

/**
 * On entry function for state. State specific behavior located here.
 */
void StateRunning::onEntry(){
    printf("Entering Running State\n");
    NOP();
}

/**
 * Not used in this project.
 */
void StateRunning::onReEntry(){
    NOP();
}
/**
 * Not used in this project.
 */
void StateRunning::onExit(){
    NOP();
}

/**
 * Transition function. Handles logic of switching from state to state.
 *
 * Parameter event_id : character for event acting upon this state.
 * Return : Number representing resulting state from transition.
 */
char StateRunning::transition(char event_id){

	switch( event_id ){

	case EVENT_PAUSE:
		std::printf("Pausing motor.\n");
		return STATE_PAUSED;
		break;
	case EVENT_CONTINUE:
		std::printf("No transition for CONTINUE event in RUNNING state.\n");
		return STATE_RUNNING;
		break;
	case EVENT_MOVELEFT:
	case EVENT_MOVERIGHT:
		std::printf("ERROR:Cannot manually move motors while recipe running.\n");
		return STATE_ERROR;
		break;
	case EVENT_NOOP:
		std::printf("No Operation : RUNNING state\n");
		return STATE_RUNNING;
		break;
	case EVENT_RESTART:
		//TODO motor reset code here
		std::printf("Starting motor recipe from beginning.\n");
		return STATE_RUNNING;
		break;
	case EVENT_ERROR:
		std::printf("Error Encountered : RUNNING state\n");
		return STATE_ERROR;
		break;
	case EVENT_EXIT:
		std::printf("RUNNING state received EXIT command. Error in StateMachine event handling.\n");
		return STATE_ERROR;
		break;
	default:
		std::printf( "ERROR: no event definition for StateRunning code:%d\n", event_id);
		return STATE_ERROR;
	}
	//If code reaches this line an error has occurred.
	return -1;
}
