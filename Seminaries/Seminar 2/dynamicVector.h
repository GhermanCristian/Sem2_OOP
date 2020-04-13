#pragma once
#include "song.h"

typedef Song TElem; // check out templates

// this is not the repository, but the container
class DynamicVector {
	private:
		int capacity;
		int size;
		TElem* elems;

	public:
		DynamicVector(int capacity = 10);
		DynamicVector(const DynamicVector& newVector);
		DynamicVector& operator = (const DynamicVector& newVector);
		~DynamicVector();
		void resize();
		void add(TElem newSong);
};
