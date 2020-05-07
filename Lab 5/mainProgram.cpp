#include <iostream>
#include "userInterface.h"
#include "Tests/tests.h"

#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	{
		//runAllTests();
		UserInterface currentUserInterface = UserInterface();
		currentUserInterface.startProgram();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}