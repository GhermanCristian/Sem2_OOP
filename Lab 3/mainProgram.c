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

	return 0;
}