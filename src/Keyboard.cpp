//
//  Keyboard.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include "Keyboard.h"

void* keyBoardHelper(void* args);
void* monitorHelper(void* args);

Keyboard::Keyboard( EventQueue *queue ){
    this->myQueue = queue;
    this-> done = false;
    this -> alreadyRead = true;
    this-> newCmds = false;

    pthread_create(&keyboard, NULL, &keyBoardHelper, this);
    pthread_create(&monitor, NULL, &monitorHelper, this);
}

void Keyboard::sendCMD(char cmd, int machine){
	printf("SENDING NEW COMMAND\n");
	switch(cmd){
		case EVENT_PAUSE:
		    this->myQueue->enterCMD(new EventPause(machine));
	        break;
	    case EVENT_CONTINUE:
	    	this->myQueue->enterCMD(new EventContinue(machine));
	    	break;
	    case EVENT_MOVELEFT:
	    	this->myQueue->enterCMD(new EventMoveLeft(machine));
	    	break;
	    case EVENT_MOVERIGHT:
	    	this->myQueue->enterCMD(new EventMoveRight(machine));
	    	break;
	    case EVENT_NOOP:
	    	this->myQueue->enterCMD(new EventNoop(machine));
	    	break;
	    case EVENT_RESTART:
	    	this->myQueue->enterCMD(new EventRestart(machine));
	    	break;
	    case EVENT_ERROR:
	    	this->myQueue->enterCMD(new EventError(machine));
	    	break;
	    case EVENT_EXIT:
	    	this->myQueue->enterCMD(new EventExit(machine));
	    	break;
	    default:
	    	printf("Command not recognized command : %c\n",cmd);
	    	break;
		}
}

void* keyBoardHelper(void* args){
	return static_cast<Keyboard*>(args)->runProcess(NULL);
}

void* monitorHelper(void* args){
	return static_cast<Keyboard*>(args)->monitorBlocking(NULL);
}

void* Keyboard::runProcess(void* args){
	printf("Begin processing for user input\n");

	    std::string input = "";
	    while(!done){
	        printf("In loop....\n");
	        sleep(2);
	        if(newCmds){
	            mtx.lock();
	            printf( "NEW COMMANDS !!!!\n");
	            sendCMD(commandOne, 0);
	            sendCMD(commandTwo, 1);
	            newCmds = false;
	            mtx.unlock();
	        }
	    }
	    printf("Terminating processing for user input\n");

	    return EXIT_SUCCESS;

}

void* Keyboard::monitorBlocking(void* args){

		printf("Begin scanning for user input\n");

	    std::string input = "";
	    while( !done ){
	       printf("waiting...\n");
	        getline(std::cin, input);
	        printf( "got something...%s\n", input.c_str());
            char first = input[0];
            char second = input[1];
            mtx.lock();
            switch(first){
            	case EVENT_PAUSE:
            		commandOne = EVENT_PAUSE;
            		break;
            	case EVENT_CONTINUE:
            		commandOne = EVENT_CONTINUE;
            		break;
            	case EVENT_MOVELEFT:
            		commandOne = EVENT_MOVELEFT;
            		break;
            	case EVENT_MOVERIGHT:
            		commandOne = EVENT_MOVERIGHT;
            		break;
            	case EVENT_NOOP:
            		commandOne = EVENT_NOOP;
            		break;
            	case EVENT_RESTART:
            		commandOne = EVENT_RESTART;
            		break;
            	case EVENT_ERROR:
            		commandOne = EVENT_ERROR;
            		break;
            	case EVENT_EXIT:
            		commandOne = EVENT_EXIT;
            		break;
            	default:
            		printf("Invalid first command : %c\n",first);
            		commandOne = EVENT_ERROR;
            		break;
            }
            switch(second){
            	case EVENT_PAUSE:
            		commandTwo = EVENT_PAUSE;
            		break;
            	case EVENT_CONTINUE:
            		commandTwo = EVENT_CONTINUE;
            		break;
            	case EVENT_MOVELEFT:
            		commandTwo = EVENT_MOVELEFT;
            		break;
            	case EVENT_MOVERIGHT:
            		commandTwo = EVENT_MOVERIGHT;
            		break;
            	case EVENT_NOOP:
            		commandTwo = EVENT_NOOP;
            		break;
            	case EVENT_RESTART:
            		commandTwo = EVENT_RESTART;
            		break;
            	case EVENT_ERROR:
            		commandTwo = EVENT_ERROR;
            		break;
            	case EVENT_EXIT:
            		commandTwo = EVENT_EXIT;
            		break;
            	default:
            		printf("Invalid second command : %c\n",second);
            		commandTwo = EVENT_ERROR;
            		break;
            }
            newCmds = true;
            mtx.unlock();
            if(first == 'q' || second == 'q') {
            	done = true;
            }
	    }

	    //printf("Terminating scanning for user input\n");

	    return NULL;
}

void Keyboard::shutDown(){
	done = true;
}



