#include "dynamicVector.h"
#include <crtdbg.h>
#include <iostream>

int main() {
	{
		DynamicVector<int> v;
		v.addToVector(5, 0);
		v.addToVector(6, 1);
		v.addToVector(7, 2);

		for (DynamicVector<int>::Iterator it = v.begin(); it != v.end(); it++) {
			std::cout << *it << " ";
		}

		std::cout << "\n";

		for (auto& x : v) {
			std::cout << x << " ";
		}

		// pure virtual function <=> interface in java
	}
	
	{
		List<int> *l = new DynamicVector<int>;
		l->addToVector(6, 0);
	}

	_CrtDumpMemoryLeaks();
}