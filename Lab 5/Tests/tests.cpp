#include "tests.h"

void runAllTests() {
	testVictim();
	testRepository();
	testController();
	TestInputValidator().runAllTests();
}