#include "tests.h"

void runAllTests() {
	TestVictim().runAllTests();
	TestMemoryRepository().runAllTests();
	TestCSVRepository().runAllTests();
	TestController().runAllTests();
	TestInputValidator().runAllTests();
	TestHTMLRepository().runAllTests();
}