#include "repository.h"

Repository::~Repository(){
	;
}

int Repository::findPosition(const std::vector <Victim>& currentData, std::string victimName) {
	// the objects in the dynamic vector are stored in increasing order of their name (which is unique), hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = currentData.size() - 1; // right margin of the current range
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		// don't forget that lowercase letters > uppercase letters
		if (currentData[middleIndex].getName() <= victimName) {
			leftBound = middleIndex + 1;
		}

		// we continue the search in the left half ot the current range
		else {
			rightBound = middleIndex - 1;
		}
	}

	return rightBound;
}
