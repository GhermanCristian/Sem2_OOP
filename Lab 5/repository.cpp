#include "repository.h"
#include <iostream>

Repository::Repository(){
	positionInSavedList = 0;
}

bool Repository::victimPassesFilter(const Victim& currentVictim, std::string placeOfOrigin, int age) {
	return (placeOfOrigin.length() == 0 or (currentVictim.getAge() < age and currentVictim.getPlaceOfOrigin() == placeOfOrigin));
}

int Repository::findPosition(std::string victimName) {
	// the objects in the dynamic vector are stored in increasing order of their name (which is unique), hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = this->data.size() - 1; // right margin of the current range
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

bool Repository::isInRepository(std::string victimName, int possiblePosition) {
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(victimName);
	}
	return possiblePosition >= 0 and possiblePosition < this->data.size() and this->data[possiblePosition].getName() == victimName;
}

void Repository::add(const Victim& newVictim){
	if (this->data.size() == 0) {
		this->data.push_back(newVictim);
		return;
	}

	int possiblePosition = findPosition(newVictim.getName());
	if (isInRepository(newVictim.getName(), possiblePosition)) {
		throw std::exception("Element already exists");
	}

	possiblePosition++; // I am doing this because when possiblePosition is -1, doing .. + 1 will cause an error, 
						// because we cannot subtract from the begin() iterator
	this->data.insert(this->data.begin() + possiblePosition, newVictim);
}

void Repository::update(const Victim& newVictim){
	int possiblePosition = findPosition(newVictim.getName());
	if (isInRepository(newVictim.getName(), possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data[possiblePosition] = newVictim;
}

void Repository::deleteFromRepository(std::string victimName){
	int possiblePosition = findPosition(victimName);
	if (isInRepository(victimName, possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data.erase(this->data.begin() + possiblePosition);
}

std::vector <Victim>* Repository::getAllEntries(){
	return &this->data;
}

std::vector <Victim> Repository::getFilteredEntries(std::string placeOfOrigin, int age) {
	std::vector <Victim> tempVector;

	for (auto victim : this->data) {
		if (victimPassesFilter(victim, placeOfOrigin, age)) {
			tempVector.push_back(victim);
		}
	}

	return tempVector;
}

void Repository::saveVictim(std::string victimName){
	int possiblePositionOfVictim = this->findPosition(victimName);

	if (this->isInRepository(victimName, possiblePositionOfVictim) == false) {
		throw std::exception("Element doesn't exist");
	}

	savedVictimList.push_back(this->data[possiblePositionOfVictim]);
}

std::vector <Victim>* Repository::getSavedVictimList(){
	return &savedVictimList;
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
