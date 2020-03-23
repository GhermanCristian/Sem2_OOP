#include "dynamicVector.h"
#include <iostream>

void DynamicVector::resizeAndCopy(const DynamicVector& newDynamicVector) {
	TElem* newData = new TElem[this->capacity];
	for (int i = 0; i < this->numberOfElements; i++) {
		newData[i] = newDynamicVector.elements[i];
	}
	delete[] this->elements;
	this->elements = newData;
}

int DynamicVector::findPositionInVector(std::string victimName){
	// the objects in the dynamic vector are stored in increasing order of their name, hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = this->numberOfElements - 1; // right margin of the current range
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		if (this->elements[middleIndex].getName() <= victimName) {
			leftBound = middleIndex + 1;
		}

		// we continue the search in the left half ot the current range
		else {
			rightBound = middleIndex - 1;
		}
	}
	return rightBound;
}

bool DynamicVector::isInVector(std::string victimName, int possiblePosition){
	if (possiblePosition == -1) {
		possiblePosition = findPositionInVector(victimName);
	}
	return this->elements[possiblePosition].getName() == victimName;
}

DynamicVector::DynamicVector(){
	this->capacity = INITIAL_VECTOR_CAPACITY;
	this->numberOfElements = 0;
	this->elements = new TElem[INITIAL_VECTOR_CAPACITY];
}

void DynamicVector::addToVector(const TElem& newVictim){
	if (this->numberOfElements == 0) {
		this->elements[0] = newVictim;
		this->numberOfElements = 1;
		return;
	}

	int possiblePosition = findPositionInVector(newVictim.getName());
	if (isInVector(newVictim.getName(), possiblePosition)) {
		throw std::exception("Element already exists");
	}

	this->numberOfElements++;
	if (this->numberOfElements == this->capacity) {
		this->capacity *= 2;
		resizeAndCopy(*this);
	}

	for (int index = this->numberOfElements - 1; index > possiblePosition; index--) {
		this->elements[index + 1] = this->elements[index];
	}
	this->elements[possiblePosition + 1] = newVictim;
}

void DynamicVector::updateInVector(const TElem& newVictim){
	int possiblePosition = findPositionInVector(newVictim.getName());
	if (isInVector(newVictim.getName(), possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	this->elements[possiblePosition] = newVictim;
}

void DynamicVector::deleteFromVector(std::string victimName){
	int possiblePosition = findPositionInVector(victimName);
	if (isInVector(victimName, possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}

	// overwrite the position we want to remove by moving all elements on its right by 1 position to the left
	for (int index = possiblePosition; index < this->numberOfElements - 1; index++) {
		this->elements[index] = this->elements[index + 1];
	}
	this->numberOfElements--;
}

int DynamicVector::getNumberOfElements(){
	return this->numberOfElements;
}

DynamicVector::DynamicVector(const DynamicVector& newDynamicVector){
	this->capacity = newDynamicVector.capacity;
	this->numberOfElements = newDynamicVector.numberOfElements;
	resizeAndCopy(newDynamicVector);
}

TElem& DynamicVector::operator[](int index) {
	if (index < 0 or index >= this->numberOfElements) {
		throw std::exception("Invalid index");
	}
	return this->elements[index];
}

DynamicVector& DynamicVector::operator = (const DynamicVector& newDynamicVector){
	if (this != &newDynamicVector) {
		this->capacity = newDynamicVector.capacity;
		this->numberOfElements = newDynamicVector.numberOfElements;
		resizeAndCopy(newDynamicVector);
	}
	return *this;
}

DynamicVector::~DynamicVector(){
	delete[] this->elements;
}
