#include "dynamicVector.h"

void DynamicVector::resizeAndCopy(const DynamicVector& newDynamicVector) {
	Victim* newData = new Victim[this->capacity];
	for (int i = 0; i < this->numberOfElements; i++) {
		newData[i] = newDynamicVector.data[i];
	}
	delete[] this->data;
	this->data = newData;
}

DynamicVector::DynamicVector(){
	this->capacity = INITIAL_VECTOR_CAPACITY;
	this->numberOfElements = 0;
	this->data = new Victim[INITIAL_VECTOR_CAPACITY];
}

DynamicVector::DynamicVector(const DynamicVector& newDynamicVector){
	this->capacity = newDynamicVector.capacity;
	this->numberOfElements = newDynamicVector.numberOfElements;
	resizeAndCopy(newDynamicVector);
}

DynamicVector& DynamicVector::operator=(const DynamicVector& newDynamicVector){
	if (this != &newDynamicVector) {
		this->capacity = newDynamicVector.capacity;
		this->numberOfElements = newDynamicVector.numberOfElements;
		resizeAndCopy(newDynamicVector);
	}
	return *this;
}

DynamicVector::~DynamicVector(){
	delete[] this->data;
}
