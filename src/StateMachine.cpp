/*
 * StateMachine.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: ajl2612
 */

#include "StateMachine.h"
#include <unistd.h>




void* machineHelper(void* args){
	return static_cast<StateMachine*>(args)->runProcess();
}

void* StateMachine::runProcess(void){
	printf("Starting state machine\n");
    Event* e;
    int machine = 0;
    while (!done){
		if( !myQueue->empty() ){
            printf("In queue.......\n");

            //process first command in queue
            e = myQueue->frontCMD();
            myQueue->popCMD();
            machine = e->getMotor();
            printf("In queue........command = %c\n", e->getMessage());

            if( e->getMessage() == 'q'){
                printf("Termination signal received at State Machine\n");
                done = true;
            }else{
                last_state[machine] = current_state[machine];

                current_state[machine] = states[machine][current_state[machine]]->transition(e->getMessage());
                if(current_state[machine] == last_state[machine]){
                    //state has transitioned to itself
                    states[machine][current_state[machine]] -> onReEntry();
                }
                else{
                    states[machine][last_state[machine]] -> onExit();
                    states[machine][current_state[machine]] -> onEntry();
                }
                printf("System %d now in state #%d\n", machine, current_state[machine]);
            }
        }
        else{
            //wait for new commands
            sleep(1);
        }
	}
    printf("Terminating state machine\n");

	return NULL;
}


StateMachine::StateMachine(EventQueue* queue) {
    this -> done  = false;
    this -> myQueue = queue;
    
    //create states
    this->s00 = StateStart();
    this->s10 = StateStart();
    this->s01 = StateRunning();
    this->s11 = StateRunning();
    this->s02 = StatePaused();
    this->s12 = StatePaused();
    this->s03 = StateFinished();
    this->s13 = StateFinished();
    this->s04 = StateError();
    this->s14 = StateError();

    
    //assign states into state vector
    states[0][0] = &s00;
    states[0][1] = &s01;
    states[0][2] = &s02;
    states[0][3] = &s03;
    states[0][4] = &s04;

    states[1][0] = &s10;
    states[1][1] = &s11;
    states[1][2] = &s12;
    states[1][3] = &s13;
    states[1][4] = &s14;
    
    current_state[0] = 0;
    current_state[1] = 0;

    last_state[0] = 0;
    last_state[1] = 0;

    pthread_create(&io, NULL, &machineHelper, this);
}

StateMachine::~StateMachine() {
	// TODO Auto-generated destructor stub
}


