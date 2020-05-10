#include "Tests/tests.h"
#include "Lab5.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char** argv) {
	runAllTests();

	QApplication a(argc, argv);
	GUI userInterface;
	userInterface.show();
	return a.exec();
}