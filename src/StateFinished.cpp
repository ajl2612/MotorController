/*
 * StateFinished.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: ajl2612
 */

#include "StateFinished.h"
#define STATENAME_FINISHED "FINISHED"

/**
 * Default Constructor
 * Sets local variable for stateID to defined constant in State.h
 */
StateFinished::StateFinished() {
	this->stateID = STATE_FINISHED;
}

/**
 * Default Destructor
 */
StateFinished::~StateFinished() {}

/**
 * On entry function for state. State specific behavior located here.
 */
void StateFinished::onEntry(){
    printf("Entering Finished State\n");
    NOP();
}

/**
 * Not used in this project.
 */
void StateFinished::onReEntry(){
    NOP();
}
/**
 * Not used in this project.
 */
void StateFinished::onExit(){
    NOP();
}

/**
 * Transition function. Handles logic of switching from state to state.
 *
 * Parameter event_id : character for event acting upon this state.
 * Return : Number representing resulting state from transition.
 */
char StateFinished::transition(char event_id){

	switch( event_id ){

	case EVENT_PAUSE:
		std::printf("No transition for PAUSE event in FINISHED state.\n");
		return STATE_FINISHED;
		break;
	case EVENT_CONTINUE:
	case EVENT_RESTART:
		//TODO motor reset code here
		std::printf("Resuming motor recipe from beginning.\n");
		return STATE_RUNNING;
		break;
	case EVENT_MOVELEFT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		std::printf("Motor moving one position to the left if possible.\n");
		return STATE_FINISHED;
		break;
	case EVENT_MOVERIGHT:
		//TODO ADD MOTOR MOVEMENT CODE HERE
		std::printf("Motor moving one position to the right if possible.\n");
		return STATE_FINISHED;
		break;
	case EVENT_NOOP:
		std::printf("No Operation : FINISHED state\n");
		return STATE_FINISHED;
		break;
	case EVENT_ERROR:
		std::printf("Error Encountered : FINISHED state\n");
		return STATE_ERROR;
		break;
	case EVENT_EXIT:
		std::printf("FINISHED state received EXIT command. Error in StateMachine event handling.\n");
		return STATE_ERROR;
		break;
	default:
		std::printf( "ERROR: no event definition for StateFinished code:%d\n", event_id);
		return STATE_ERROR;
	}
	//If code reaches this line an error has occurred.
	return -1;
}

