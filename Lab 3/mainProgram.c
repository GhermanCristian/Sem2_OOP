#include <stdio.h>
#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>
#include "userInterface.h"

int main() {
	UserInterface* currentInterface = createUserInterface();
	startProgram(currentInterface);
	userInterfaceDestructor(currentInterface);

	_CrtDumpMemoryLeaks();
	if (_CrtDumpMemoryLeaks()) {
		printf("leak\n");
	}
	else {
		printf("no leak\n");
	}

	return 0;
}