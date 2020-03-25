#pragma once
#include "victim.h"
#include <exception>

const int INITIAL_VECTOR_CAPACITY = 20;
const int MULTIPLICATION_FACTOR = 2; // used when resizing the vector
const int INEXISTENT_POSITION = -1;
typedef Victim TElem;

class DynamicVector {
	private:
		int capacity; // the total capacity of the vector
		int numberOfElements; // the number of elements it currently contains
		TElem* elements; // the actual elements

		void resizeAndCopy(const DynamicVector& originalDynamicVector);
		/*
			Copies the list of elements from another DynamicVector to the current one, which is resized in the process
			Input:
				- A reference to another DynamicVector object
			Output:
				- The list of elements from the given DynamicVector is copied to the one of the current object
			Throws:
				- None
		*/

		int findPositionInVector(std::string victimName);
		/*
			Finds the position of the largest name <= victimName in the current list (which is sorted in increasing 
			order of the names of the victims)
			Input:
				- A Victim's name
			Output:
				- Largest position on which the name <= victimName
			Throws:
				- None
		*/

		bool isInVector(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
		/*
			Checks if the victim on the given position is the same as the one that we look for
			Input:
				- A Victim's name
				- The position on which the Victim is supossed to be (-1 by default, in which case we determine it ourselves)
			Output:
				- True, if the two Victims correspond
				- False, otherwise
			Throws:
				- None
		*/


	public:
		DynamicVector();
		/*
			Constructor for DynamicVector
			Input:
				- Creates a new, empty, DynamicVector, with a default number of elements
			Output:
				- An object of type DynamicVector is created
			Throws:
				- None
		*/

		void addToVector(const TElem& newVictim);
		/*
			Adds a victim to the list
			Input:
				- The Victim which is to be added
			Output:
				- A victim is added to the list
			Throws:
				- Exception, if the victim already was in the list
		*/

		void updateInVector(const TElem& newVictim);
		/*
			Updates a victim from the list
			Input:
				- The Victim which is to be updated (with its new properties, but with the same name)
			Output:
				- A victim from the list is updated
			Throws:
				- Exception, if the victim wasn't in the list
		*/

		void deleteFromVector(std::string victimName);
		/*
			Deletes a victim from the list
			Input:
				- The name of the victim which we want to delete
			Output:
				- A victim is deleted from the list
			Throws:
				- Exception, if the victim wasn't in the list
		*/

		TElem& operator[] (int index);
		/*
			Overloaded [] operator
			Input:
				- The index we want to access
			Output:
				- The element at the given index
			Throws:
				- Exception, if the index is invalid
		*/

		int getNumberOfElements();
		/*
			Determines the number of elements from the current DynamicVector
			Input:
				- None
			Output:
				- Returns the current number of elements
			Throws:
				- None
		*/

		int getCapacity();
		/*
			Determines the capacity of the current DynamicVector
			Input:
				- None
			Output:
				- Returns the current capacity
			Throws:
				- None
		*/

		DynamicVector(const DynamicVector& originalDynamicVector);
		/*
			Copy constructor for the DynamicVector type
			Input:
				- A original DynamicVector, whose content will be copied to the current one
			Output:
				- The content of the original DynamicVector is copied to the current one
			Throws:
				- None
		*/

		DynamicVector& operator = (const DynamicVector& originalDynamicVector);
		/*
			Overloaded assignment operator
			Input:
				- A original DynamicVector, whose content will be copied to a new object
			Output:
				- Returns a reference to a new object with the same properties as the original Dynamic Vector
			Throws:
				- None
		*/

		~DynamicVector();
		/*
			Destructor for the DynamicVector type
			Input:
				- None
			Output:
				- Destroys the current object
			Throws:
				- None
		*/

};