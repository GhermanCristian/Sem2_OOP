#pragma once
#include "controller.h"

typedef struct {
	Controller* commandController;
}UserInterface;

UserInterface* createUserInterface();
/*
	Creates a new, empty UserInterface
	Input:
		- None
	Output:
		- A pointer to an "object" of type UserInterface
*/

void startProgram(UserInterface* interface);
/*
	Starts the current program
	Input:
		- interface = a pointer to an "object" of type UserInterface
	Output:
		- None
*/

void destroyUserInterface(UserInterface* interface);
/*
	De-allocates the memory for a UserInterface
	Input:
		- interface = a pointer to an "object" of type UserInterface
	Output:
		- None
*/
