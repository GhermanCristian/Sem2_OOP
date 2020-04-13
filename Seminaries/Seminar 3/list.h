#pragma once

template <typename TElem>
class List {
public:
	//virtual void addToVector(const TElem& newElement);
	// we use virtual so that it can be overwritten (polymorphism)
	// we might use override in the declaration of the function from dynvec
	virtual void addToVector(const TElem& newElement) = 0; // this is a "pure virtual", so this will not have an implementation
	// in this case, the class becomes abstract
	TElem& operator[](int position) = 0;
	int getSize() const;
	virtual ~List(); // we cannot make it = 0
};