#include "dynamicVector.h"

DynamicVector::DynamicVector(int capacity = 10) {
	this->capacity = capacity;
	this->size = 0;
	this->elems = new TElem[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector& newVector) {
	this->capacity = newVector.capacity;
	this->size = newVector.size;
	this->elems = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->elems[i] = newVector.elems[i];
	}
}

DynamicVector& DynamicVector::operator = (const DynamicVector& newVector) {
	if (this == &newVector) {
		return *this;
	}

	this->capacity = newVector.capacity;
	this->size = newVector.size;

	delete[] this->elems;
	this->elems = new TElem[newVector.capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->elems[i] = newVector.elems[i];
	}

	return *this;
}

DynamicVector::~DynamicVector() {
	delete[] this->elems;
}

void DynamicVector::resize() {
	this->capacity *= 2;
	TElem* tempArray = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		tempArray[i] = this->capacity[i];
	}
	delete[] this->elems;
	this->elems = tempArray;
}

void DynamicVector::add(TElem newSong) {
	if (this->capacity == this->size) {
		this->resize();
	}
	this->elems[this->capacity++] = newSong;
}