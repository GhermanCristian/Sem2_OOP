#include "repository.h"
#include <iostream>

Repository::Repository(){
	;
}

int Repository::findPosition(std::string victimName) {
	// the objects in the dynamic vector are stored in increasing order of their name (which is unique), hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = this->data.getNumberOfElements() - 1; // right margin of the current range
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		if (this->data[middleIndex].getName() <= victimName) {
			leftBound = middleIndex + 1;
		}

		// we continue the search in the left half ot the current range
		else {
			rightBound = middleIndex - 1;
		}
	}

	return rightBound;
}

bool Repository::isInVector(std::string victimName, int possiblePosition) {
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(victimName);
	}
	return possiblePosition >= 0 and this->data[possiblePosition].getName() == victimName;
}

void Repository::addToRepository(const TElem& newVictim){
	if (this->data.getNumberOfElements() == 0) {
		this->data.addToVector(newVictim, 0);
		return;
	}

	int possiblePosition = findPosition(newVictim.getName());
	if (isInVector(newVictim.getName(), possiblePosition)) {
		throw std::exception("Element already exists");
	}

	this->data.addToVector(newVictim, possiblePosition);
}

void Repository::updateInRepository(const TElem& newVictim){
	int possiblePosition = findPosition(newVictim.getName());
	if (isInVector(newVictim.getName(), possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data.updateInVector(newVictim, possiblePosition);
}

void Repository::deleteFromRepository(std::string victimName){
	int possiblePosition = findPosition(victimName);
	if (isInVector(victimName, possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data.deleteFromVector(possiblePosition);
}

DynamicVector* Repository::getAllEntries(){
	return &this->data;
}

Repository::Repository(const Repository& originalRepository){
	this->data = originalRepository.data;
}

Repository& Repository::operator=(const Repository& originalRepository){
	if (this != &originalRepository) {
		this->data = originalRepository.data;
	}
	return *this;
}

Repository::~Repository(){
	;
}
