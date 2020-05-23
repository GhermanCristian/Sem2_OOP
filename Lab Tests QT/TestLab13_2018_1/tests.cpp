#include "tests.h"
#include "controller.h"
#include "repository.h"
#include <assert.h>

void RemoveAtIndex_EmptyList_ThrowsException(){
	Repository currentRepository;
	currentRepository.loadFromFile("testData1.txt");
	try {
		currentRepository.removeAtIndex(0);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void RemoveAtIndex_FilledList_CorrectNumberOfItems(){
	Repository currentRepository;
	currentRepository.loadFromFile("testData2.txt");

	int originalSize = currentRepository.getNumberOfItems();
	currentRepository.removeAtIndex(0);
	currentRepository.removeAtIndex(0);
	currentRepository.removeAtIndex(0);
	assert(currentRepository.getNumberOfItems() == originalSize - 3);
}
