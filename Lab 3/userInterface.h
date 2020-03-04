#pragma once
#include "controller.h"

typedef struct {
	Controller* commandController;
}UserInterface;

void startProgram(UserInterface* interface);
UserInterface* createUserInterface();
void destroyUserInterface(UserInterface* interface);