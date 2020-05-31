#include "Tests/tests.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char** argv) {
	//runAllTests(); // for now DON'T run the tests, because the controller is loading the repo locations from a file
	// regargdless of it being a test controller or the actual controller used in the program exec
	// so the data is messed up

	QApplication a(argc, argv);
	GUI userInterface;
	userInterface.setWindowTitle("Mihai Traistariu");
	userInterface.show();
	return a.exec();
}