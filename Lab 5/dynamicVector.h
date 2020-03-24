#pragma once
#include "victim.h"
#include <exception>

const int INITIAL_VECTOR_CAPACITY = 20;
const int MULTIPLICATION_FACTOR = 2; // used when resizing the vector
typedef Victim TElem;

class DynamicVector {
	private:
		int capacity; // the total capacity of the vector
		int numberOfElements; // the number of elements it currently contains
		TElem* elements; // the actual elements

		void resizeAndCopy(const DynamicVector& newDynamicVector);
		/*
			
			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		int findPositionInVector(std::string victimName);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		bool isInVector(std::string victimName, int possiblePosition = -1);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/


	public:
		DynamicVector();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void addToVector(const TElem& newVictim);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void updateInVector(const TElem& newVictim);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void deleteFromVector(std::string victimName);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		TElem& operator[] (int index);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		int getNumberOfElements();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		int getCapacity();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		DynamicVector(const DynamicVector& newDynamicVector);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		DynamicVector& operator = (const DynamicVector& newDynamicVector);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		~DynamicVector();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

};