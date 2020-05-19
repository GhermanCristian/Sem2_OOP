#include "userInterface.h"
#include "tests.h"
#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	UserInterface().startProgram();
	_CrtDumpMemoryLeaks();
	return 0;
}