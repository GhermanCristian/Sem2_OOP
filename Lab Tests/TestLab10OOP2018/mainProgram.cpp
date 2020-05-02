#include "userInterface.h"
#include "tests.h"
#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	UserInterface().startProgram();

	//AddRefrigerator_NewRefrigerator_RefrigeratorAdded();
	//AddRefrigerator_ExistingRefrigerator_ThrowsException();
	//GetAppliancesSortedByWeight_CorrectInput_AppliancesSorted();

	_CrtDumpMemoryLeaks();
	return 0;
}