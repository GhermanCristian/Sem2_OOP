#include "Tests/tests.h"
#include "Lab5.h"
#include <QtWidgets/QApplication>

#define _CRTDBG_MAP_ALLOC // used to check for memory leaks
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char** argv) {
	QApplication a(argc, argv);

	return a.exec();
	
	runAllTests();
	_CrtDumpMemoryLeaks();
	return 0;
	
}