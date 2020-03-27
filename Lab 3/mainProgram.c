#include <stdio.h>
#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>
#include "userInterface.h"
#include "tests.h"

int main() {
	//performTests();

	UserInterface* currentInterface = createUserInterface();
	startProgram(currentInterface);
	userInterfaceDestructor(currentInterface);

	_CrtDumpMemoryLeaks();
	if (_CrtDumpMemoryLeaks()) {
		printf("leak found\n");
	}
	else {
		printf("no leak found\n");
	}

	return 0;
}