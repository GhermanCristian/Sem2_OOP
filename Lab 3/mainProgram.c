#include <stdio.h>
#define _CRTDBG_MAP_ALLOC  // used to check for memory leaks
#include <crtdbg.h> 
#include "userInterface.h"

int main() {
	UserInterface* interface = createUserInterface();
	startProgram(interface);
	destroyUserInterface(interface);

	return 0;
}