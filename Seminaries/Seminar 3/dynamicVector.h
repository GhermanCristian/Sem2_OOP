#pragma once
#include <exception>
#include "list.h"

const int INITIAL_VECTOR_CAPACITY = 20;
const int MULTIPLICATION_FACTOR = 2; // used when resizing the vector
const int INEXISTENT_POSITION = -1111;

template <typename TElem>
class DynamicVector : public List<TElem> {
	private:
		int capacity; // the total capacity of the vector
		int numberOfElements; // the number of elements it currently contains
		TElem* elements; // the actual elements

		void resizeAndCopy(const DynamicVector& originalDynamicVector);
		/*
			Copies the list of elements from another DynamicVector to the current one, which is resized in the process
			Input:
				- A reference to another DynamicVector object
			Output:
				- The list of elements from the given DynamicVector is copied to the one of the current object
			Throws:
				- None
		*/


	public:
		DynamicVector();
		/*
			Constructor for DynamicVector
			Input:
				- Creates a new, empty, DynamicVector, with a default number of elements
			Output:
				- An object of type DynamicVector is created
			Throws:
				- None
		*/

		void addToVector(const TElem& newVictim, int possiblePosition);
		/*
			Adds a victim to the list
			Input:
				- The Victim which is to be added
			Output:
				- A victim is added to the list
			Throws:
				- Exception, if the victim already was in the list
		*/

		void updateInVector(const TElem& newVictim, int possiblePosition);
		/*
			Updates a victim from the list
			Input:
				- The Victim which is to be updated (with its new properties, but with the same name)
			Output:
				- A victim from the list is updated
			Throws:
				- Exception, if the victim wasn't in the list
		*/

		void deleteFromVector(int possiblePosition);
		/*
			Deletes a victim from the list
			Input:
				- The name of the victim which we want to delete
			Output:
				- A victim is deleted from the list
			Throws:
				- Exception, if the victim wasn't in the list
		*/

		TElem& operator[] (int index);
		/*
			Overloaded [] operator
			Input:
				- The index we want to access
			Output:
				- The element at the given index
			Throws:
				- Exception, if the index is invalid
		*/

		int getNumberOfElements();
		/*
			Determines the number of elements from the current DynamicVector
			Input:
				- None
			Output:
				- Returns the current number of elements
			Throws:
				- None
		*/

		int getCapacity();
		/*
			Determines the capacity of the current DynamicVector
			Input:
				- None
			Output:
				- Returns the current capacity
			Throws:
				- None
		*/

		DynamicVector(const DynamicVector& originalDynamicVector);
		/*
			Copy constructor for the DynamicVector type
			Input:
				- A original DynamicVector, whose content will be copied to the current one
			Output:
				- The content of the original DynamicVector is copied to the current one
			Throws:
				- None
		*/

		DynamicVector& operator = (const DynamicVector& originalDynamicVector);
		/*
			Overloaded assignment operator
			Input:
				- A original DynamicVector, whose content will be copied to a new object
			Output:
				- Returns a reference to a new object with the same properties as the original Dynamic Vector
			Throws:
				- None
		*/

		bool operator==(const DynamicVector<TElem>& newDynamicVector);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		~DynamicVector();
		/*
			Destructor for the DynamicVector type
			Input:
				- None
			Output:
				- Destroys the current object
			Throws:
				- None
		*/

		class Iterator {
			private:
				TElem* currentElementPointer;

			public:
				Iterator(TElem* elementPointer);
				bool operator != (const Iterator& newIterator);
				Iterator operator ++ (int); // post
				Iterator operator ++ (); // pre
				TElem& operator * ();
		};

		typename Iterator begin();
		typename Iterator end();
};

template <typename TElem>
void DynamicVector<TElem>::resizeAndCopy(const DynamicVector<TElem>& originalDynamicVector) {
	TElem* newData = new TElem[this->capacity];
	for (int i = 0; i < this->numberOfElements; i++) {
		newData[i] = originalDynamicVector.elements[i];
	}
	delete[] this->elements;
	this->elements = newData;
}

template <typename TElem>
DynamicVector <TElem>::DynamicVector() {
	this->capacity = INITIAL_VECTOR_CAPACITY;
	this->numberOfElements = 0;
	this->elements = new TElem[INITIAL_VECTOR_CAPACITY];
}

template <typename TElem>
void DynamicVector<TElem>::addToVector(const TElem& newVictim, int possiblePosition) {
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

	for (int index = this->numberOfElements - 1; index >= possiblePosition; index--) {
		this->elements[index + 1] = this->elements[index];
	}
	this->elements[possiblePosition] = newVictim;
}

template <typename TElem>
void DynamicVector<TElem>::updateInVector(const TElem& newVictim, int possiblePosition) {
	this->elements[possiblePosition] = newVictim;
}

template <typename TElem>
void DynamicVector<TElem>::deleteFromVector(int possiblePosition) {
	// overwrite the position we want to remove by moving all elements on its right by 1 position to the left
	for (int index = possiblePosition; index < this->numberOfElements - 1; index++) {
		this->elements[index] = this->elements[index + 1];
	}
	this->numberOfElements--;
}

template <typename TElem>
int DynamicVector <TElem>::getNumberOfElements() {
	return this->numberOfElements;
}

template <typename TElem>
int DynamicVector <TElem>::getCapacity() {
	return this->capacity;
}

template <typename TElem>
DynamicVector <TElem>::DynamicVector(const DynamicVector& originalDynamicVector) {
	this->capacity = originalDynamicVector.capacity;
	this->numberOfElements = originalDynamicVector.numberOfElements;
	this->elements = new TElem[this->capacity];
	resizeAndCopy(originalDynamicVector);
}

template <typename TElem>
TElem& DynamicVector<TElem>::operator[](int index) {
	if (index < 0 or index >= this->numberOfElements) {
		throw std::exception("Invalid index");
	}
	return this->elements[index];
}

template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator = (const DynamicVector<TElem>& originalDynamicVector) {
	if (this != &originalDynamicVector) {
		this->capacity = originalDynamicVector.capacity;
		this->numberOfElements = originalDynamicVector.numberOfElements;
		resizeAndCopy(originalDynamicVector);
	}
	return *this;
}

template <typename TElem>
bool DynamicVector<TElem>::operator == (const DynamicVector<TElem>& newDynamicVector) {
	if (this->numberOfElements != newDynamicVector.numberOfElements or this->capacity != newDynamicVector.capacity) {
		return false;
	}

	for (int i = 0; i < this->numberOfElements; i++) {
		if (this->elements[i] == newDynamicVector.elements[i]) {
			continue; // I do this bc I don't want to also write an overloaded != operator
		}
		else {
			return false;
		}
	}

	return true;
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector() {
	delete[] this->elements;
}

template<typename TElem>
DynamicVector<TElem>::Iterator::Iterator(TElem* elementPointer){
	this->currentElementPointer = elementPointer;
}

template<typename TElem>
inline bool DynamicVector<TElem>::Iterator::operator!=(const Iterator& newIterator)
{
	return this->currentElementPointer != newIterator.currentElementPointer;
}

template<typename TElem>
inline typename DynamicVector<TElem>::Iterator DynamicVector<TElem>::Iterator::operator++(int)
{
	Iterator aux = *this;
	this->currentElementPointer++;
	return aux;
}

template<typename TElem>
inline typename DynamicVector<TElem>::Iterator DynamicVector<TElem>::Iterator::operator++()
{
	this->currentElementPointer++;
	return *this;
}

template<typename TElem>
inline TElem& DynamicVector<TElem>::Iterator::operator*(){
	return *(this->currentElementPointer);
}

template<typename TElem>
inline typename DynamicVector<TElem>::Iterator DynamicVector<TElem>::begin() {
	return Iterator(this->elements);
}

template<typename TElem>
inline typename DynamicVector<TElem>::Iterator DynamicVector<TElem>::end() {
	return Iterator(this->elements + this->numberOfElements);
}
