#include "dynamicVector.h"
#include <iostream>

void DynamicVector::resizeAndCopy(const DynamicVector& originalDynamicVector) {
	TElem* newData = new TElem[this->capacity];
	for (int i = 0; i < this->numberOfElements; i++) {
		newData[i] = originalDynamicVector.elements[i];
	}
	delete[] this->elements;
	this->elements = newData;
}

DynamicVector::DynamicVector(){
	this->capacity = INITIAL_VECTOR_CAPACITY;
	this->numberOfElements = 0;
	this->elements = new TElem[INITIAL_VECTOR_CAPACITY];
}

void DynamicVector::addToVector(const TElem& newVictim, int possiblePosition){
	// if the vector is empty, there is no need to check on which position to add the element
	if (this->numberOfElements == 0) {
		this->elements[0] = newVictim;
		this->numberOfElements = 1;
		return;
	}

	this->numberOfElements++;

	// if the vector is full, we need to resize
	if (this->numberOfElements == this->capacity) {
		this->capacity *= MULTIPLICATION_FACTOR;
		resizeAndCopy(*this);
	}

	for (int index = this->numberOfElements - 1; index > possiblePosition; index--) {
		this->elements[index + 1] = this->elements[index];
	}
	this->elements[possiblePosition + 1] = newVictim;
}

void DynamicVector::updateInVector(const TElem& newVictim, int possiblePosition){
	this->elements[possiblePosition] = newVictim;
}

void DynamicVector::deleteFromVector(int possiblePosition){
	// overwrite the position we want to remove by moving all elements on its right by 1 position to the left
	for (int index = possiblePosition; index < this->numberOfElements - 1; index++) {
		this->elements[index] = this->elements[index + 1];
	}
	this->numberOfElements--;
}

int DynamicVector::getNumberOfElements(){
	return this->numberOfElements;
}

int DynamicVector::getCapacity() {
	return this->capacity;
}

DynamicVector::DynamicVector(const DynamicVector& originalDynamicVector){
	this->capacity = originalDynamicVector.capacity;
	this->numberOfElements = originalDynamicVector.numberOfElements;
	this->elements = new TElem[this->capacity];
	resizeAndCopy(originalDynamicVector);
}

TElem& DynamicVector::operator[](int index) {
	if (index < 0 or index >= this->numberOfElements) {
		throw std::exception("Invalid index");
	}
	return this->elements[index];
}

DynamicVector& DynamicVector::operator = (const DynamicVector& originalDynamicVector){
	if (this != &originalDynamicVector) {
		this->capacity = originalDynamicVector.capacity;
		this->numberOfElements = originalDynamicVector.numberOfElements;
		resizeAndCopy(originalDynamicVector);
	}
	return *this;
}

DynamicVector::~DynamicVector(){
	delete[] this->elements;
}
