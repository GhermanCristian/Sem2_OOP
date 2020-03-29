#pragma once

class VictimIterator {
	private:
		int currentPosition;
		int numberOfElements;

	public:
		VictimIterator();
		/*
			Creates a new VictimIterator, which is set on the first available position
			Input:
				- None
			Output:
				- A new object is created and is set of the first available position
			Throws:
				- None
		*/

		void setNumberOfElements(int numberOfElements);
		/*
			Sets the number of elements of the DynamicVector we iterate through
			Input:
				- An integer representing the length of the DynamicVector we iterate through
			Output:
				- The upper limit of the iterator is set
			Throws:
				- None
		*/

		bool isPositionValid();
		/*
			Checks if the current position of the iterator is valid
			Input:
				- None
			Output:
				- Returns true, if the position is valid
				- False, otherwise
			Throws:
				- None
		*/

		void setNextPosition();
		/*
			Advances the iterator to the next valid position
			Input:
				- None
			Output:
				- The iterator is advanced to the next available position
			Throws:
				- None
		*/

		int getCurrentPosition();
		/*
			Determines the current position of the iterator
			Input:
				- None
			Output:
				- Returns the current position of the iterator
			Throws:
				- None
		*/

};