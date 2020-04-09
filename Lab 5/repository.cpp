#include "repository.h"

int Repository::findPosition(std::vector<Victim> currentVector, std::string victimName){
	// the objects in the dynamic vector are stored in increasing order of their name (which is unique), hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = currentVector.size() - 1; // right margin of the current range
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		if (currentVector[middleIndex].getName() <= victimName) {
			leftBound = middleIndex + 1;
		}

		// we continue the search in the left half ot the current range
		else {
			rightBound = middleIndex - 1;
		}
	}

	return rightBound;
}

bool Repository::isInRepository(std::vector<Victim> currentVector, std::string victimName, int possiblePosition){
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentVector, victimName);
	}
	return possiblePosition >= 0 and possiblePosition < currentVector.size() and currentVector[possiblePosition].getName() == victimName;

}

void Repository::saveVictim(std::string victimName){
	Victim currentVictim = getVictimByName(victimName);
	savedVictimList.push_back(currentVictim);
}

std::vector<Victim>* Repository::getSavedVictimList(){
	return &savedVictimList;
}

Repository::~Repository(){
	;
}
