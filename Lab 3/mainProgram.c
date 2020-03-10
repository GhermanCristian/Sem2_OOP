#include <stdio.h>
#define _CRTDBG_MAP_ALLOC  // used to check for memory leaks
#include <crtdbg.h> 
#include "userInterface.h"

int main() {
	UserInterface* currentInterface = createUserInterface();
	startProgram(currentInterface);
	userInterfaceDestructor(currentInterface);

	return 0;
}