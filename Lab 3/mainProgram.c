#include <stdio.h>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include "userInterface.h"

int main() {
	UserInterface* interface = createUserInterface();
	startProgram(interface);
	destroyUserInterface(interface);

	return 0;
}