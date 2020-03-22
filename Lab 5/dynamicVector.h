#pragma once
#include "victim.h"

const int INITIAL_VECTOR_CAPACITY = 100;

class DynamicVector {
	private:
		int capacity;
		int numberOfElements;
		Victim* data;

		void resizeAndCopy(const DynamicVector& newDynamicVector);

	public:
		DynamicVector();
		DynamicVector(const DynamicVector& newDynamicVector);
		DynamicVector& operator = (const DynamicVector& newDynamicVector);
		~DynamicVector();
};