#include "repository.h"
#include <string.h>

Repository* createRepository(){
	Repository* newRepository = (Repository*)malloc(sizeof(Repository));

	// ensure we don't de-reference a NULL pointer
	if (newRepository == NULL) {
		return NULL;
	}

	newRepository->numberOfObjects = 0;
	return newRepository;
}

int findInRepository(Repository* archiveRepository, int archiveCatalogueNumber) {
	// the objects in the repository are stored in increasing order of their catalogueNumber, hence
	// why we can search for them using binary search;
	// this finds the largest element <= given value
	int leftBound = 0;
	int rightBound = archiveRepository->numberOfObjects - 1;
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		if (archiveRepository->archiveList[middleIndex].catalogueNumber <= archiveCatalogueNumber) {
			leftBound = middleIndex + 1;
		}

		// we continue the search in the left half ot the current range
		else {
			rightBound = middleIndex - 1;
		}
	}
	return rightBound;
}

int isInRepository(Repository* archiveRepository, int archiveCatalogueNumber, int possiblePosition) {
	// ensure the position is, first of all, valid
	if (possiblePosition < 0) {
		return 0;
	}

	// check if the element at the given position is the one we actually look for
	return (archiveRepository->archiveList[possiblePosition].catalogueNumber == archiveCatalogueNumber);
}

int addToRepository(Repository* archiveRepository, Archive newArchive){
	// when the repository is empty, there is no need to search for the position on which to insert a new archive
	if (archiveRepository->numberOfObjects == 0) {
		archiveRepository->archiveList[archiveRepository->numberOfObjects++] = newArchive;
		return 1;
	}

	int possiblePosition = findInRepository(archiveRepository, newArchive.catalogueNumber);

	// element already is in the repository
	if (isInRepository(archiveRepository, newArchive.catalogueNumber, possiblePosition) == 1) {
		return 0;
	}

	// create a space in which to insert the new archive, by moving all elements on its right 1 position to the right
	for (int index = archiveRepository->numberOfObjects - 1; index > possiblePosition; index--) {
		archiveRepository->archiveList[index + 1] = archiveRepository->archiveList[index];
	}
	archiveRepository->numberOfObjects++;
	archiveRepository->archiveList[possiblePosition + 1] = newArchive;
	return 1;
}

int updateRepositoryEntry(Repository* archiveRepository, int catalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation){
	int possiblePosition = findInRepository(archiveRepository, catalogueNumber);

	// element does not exist
	if (isInRepository(archiveRepository, catalogueNumber, possiblePosition) == 0) {
		return 0;
	}
	strcpy(archiveRepository->archiveList[possiblePosition].fileType, newFileType);
	strcpy(archiveRepository->archiveList[possiblePosition].stateOfDeterioration, newStateOfDeterioration);
	archiveRepository->archiveList[possiblePosition].yearOfCreation = newYearOfCreation;
	return 1;
}

int deleteRepositoryEntry(Repository* archiveRepository, int catalogueNumber){
	int possiblePosition = findInRepository(archiveRepository, catalogueNumber);

	// element does not exist
	if (isInRepository(archiveRepository, catalogueNumber, possiblePosition) == 0) {
		return 0;
	}

	// overwrite the position we want to remove by moving all elements on its right by 1 position to the left
	for (int index = possiblePosition; index < archiveRepository->numberOfObjects - 1; index++) {
		archiveRepository->archiveList[index] = archiveRepository->archiveList[index + 1];
	}
	archiveRepository->numberOfObjects--;
	return 1;
}

void repositoryDestructor(Repository* archiveRepository) {
	free(archiveRepository);
}
