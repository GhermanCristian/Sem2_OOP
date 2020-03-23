#pragma once
#include "victim.h"
#include <exception>

const int INITIAL_VECTOR_CAPACITY = 100;
typedef Victim TElem;

class DynamicVector {
	private:
		int capacity;
		int numberOfElements;
		TElem* elements;

		void resizeAndCopy(const DynamicVector& newDynamicVector);
		int findPositionInVector(std::string victimName);
		bool isInVector(std::string victimName, int possiblePosition = -1);

	public:
		DynamicVector();
		void addToVector(TElem newVictim);
		void updateInVector(TElem newVictim);
		void deleteFromVector(std::string victimName);
		TElem getElementAtIndex(int index);
		int getNumberOfElements();
		DynamicVector(const DynamicVector& newDynamicVector);
		DynamicVector& operator = (const DynamicVector& newDynamicVector);
		~DynamicVector();
};