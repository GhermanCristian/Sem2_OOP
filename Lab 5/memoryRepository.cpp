#include "memoryRepository.h"
#include <iostream>

MemoryRepository::MemoryRepository() {
	;
}

int MemoryRepository::findPosition(std::string victimName) {
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

bool MemoryRepository::isInRepository(std::string victimName, int possiblePosition) {
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(victimName);
	}
	return possiblePosition >= 0 and possiblePosition < this->data.size() and this->data[possiblePosition].getName() == victimName;
}

Victim MemoryRepository::getVictimByName(std::string victimName, int possiblePosition) {
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(victimName);
	}

	if (isInRepository(victimName, possiblePosition) == false) {
		throw std::exception("Inexistent victim");
	}

	return this->data[possiblePosition];
}

void MemoryRepository::add(const Victim& newVictim) {
	if (this->data.size() == 0) {
		this->data.push_back(newVictim);
		return;
	}

	int possiblePosition = findPosition(newVictim.getName());
	if (isInRepository(newVictim.getName(), possiblePosition)) {
		throw std::exception("Element already exists");
	}

	possiblePosition++; // btw, we cannot do sth like begin + pos + 1 when pos is -1
	this->data.insert(this->data.begin() + possiblePosition, newVictim);
}

void MemoryRepository::update(const Victim& newVictim) {
	int possiblePosition = findPosition(newVictim.getName());
	if (isInRepository(newVictim.getName(), possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data[possiblePosition] = newVictim;
}

void MemoryRepository::erase(std::string victimName) {
	int possiblePosition = findPosition(victimName);
	if (isInRepository(victimName, possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->data.erase(this->data.begin() + possiblePosition);
}

std::vector <Victim>* MemoryRepository::getAllEntries() {
	return &this->data;
}

std::vector <Victim> MemoryRepository::getFilteredEntries(const Filter& currentFilter) {
	std::vector <Victim> temporaryVector;

	for (auto victim : this->data) {
		if (currentFilter.isPassed(victim) == true) {
			temporaryVector.push_back(victim);
		}
	}

	/*
	// this is not working bc currentFilter is of the abstract type Filter
	auto copyCondition = [currentFilter](const Victim& currentVictim) {
		return currentFilter.isPassed(currentVictim);
	};
	auto copyVictims = std::copy_if(this->data.begin(), this->data.end(), temporaryVector.begin(), copyCondition);
	*/

	return temporaryVector;
}

MemoryRepository::MemoryRepository(const MemoryRepository& originalRepository) {
	this->data = originalRepository.data;
}

MemoryRepository& MemoryRepository::operator=(const MemoryRepository& originalRepository) {
	if (this != &originalRepository) {
		this->data = originalRepository.data;
	}
	return *this;
}

MemoryRepository::~MemoryRepository() {
	;
}
