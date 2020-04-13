#include "dynamicVector.h"
#include <iostream>

using namespace std;

void testDynamicVector() {
	DynamicVector vector1{};
	DynamicVector vector2{ vector1 };
	DynamicVector vector3{ 3 };
	vector3 = vector1;
}

int main() {
	
}
/*
	int a = 10;
	int &b = a; // this has to be initialised with sth (maybe null)
	b = 8;
	now a = 8;
*/