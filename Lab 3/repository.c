#include "repository.h"
#include <string.h>

#define INITIAL_LENGTH 101

Repository* createRepository(){
	Repository* newRepository = (Repository*)malloc(sizeof(Repository));

	// ensure we don't de-reference a NULL pointer
	if (newRepository == NULL) {
		return NULL;
	}

	newRepository->data.archiveList = (Archive*)malloc((INITIAL_LENGTH + 1) * sizeof(Archive));
	// ensure we don't de-reference a NULL pointer
	if (newRepository->data.archiveList == NULL) {
		return NULL;
	}

	newRepository->data.numberOfObjects = 0;
	return newRepository;
}

int findInRepository(Repository* archiveRepository, int archiveCatalogueNumber) {
	// the objects in the repository are stored in increasing order of their catalogueNumber, hence
	// why we can search for them using binary search;
	// this function finds the largest element <= given value
	int leftBound = 0; // left margin of the current range
	int rightBound = archiveRepository->data.numberOfObjects - 1; // right margin of the current range
	int middleIndex; // the index of the middle of the current range
	while (leftBound <= rightBound) {
		middleIndex = (leftBound + rightBound) / 2;

		// we continue the search in the right half ot the current range
		if (archiveRepository->data.archiveList[middleIndex].catalogueNumber <= archiveCatalogueNumber) {
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
	return (archiveRepository->data.archiveList[possiblePosition].catalogueNumber == archiveCatalogueNumber);
}

int addToRepository(Repository* archiveRepository, Archive newArchive){
	// when the repository is empty, there is no need to search for the position on which to insert a new archive
	if (archiveRepository->data.numberOfObjects == 0) {
		archiveRepository->data.archiveList[archiveRepository->data.numberOfObjects++] = newArchive;
		return 1;
	}

	// check for the position on which the archive should be added, so that we preserve the condition that
	// the catalogue numbers are in (strictly) increasing order
	int possiblePosition = findInRepository(archiveRepository, newArchive.catalogueNumber);

	// element already is in the repository
	if (isInRepository(archiveRepository, newArchive.catalogueNumber, possiblePosition) == 1) {
		return 0;
	}

	// create a space in which to insert the new archive, by moving all elements on its right 1 position to the right
	for (int index = archiveRepository->data.numberOfObjects - 1; index > possiblePosition; index--) {
		archiveRepository->data.archiveList[index + 1] = archiveRepository->data.archiveList[index];
	}
	archiveRepository->data.numberOfObjects++;
	archiveRepository->data.archiveList[possiblePosition + 1] = newArchive;
	return 1;
}

int updateRepositoryEntry(Repository* archiveRepository, int catalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation){
	int possiblePosition = findInRepository(archiveRepository, catalogueNumber);

	// element does not exist
	if (isInRepository(archiveRepository, catalogueNumber, possiblePosition) == 0) {
		return 0;
	}

	// update the content of the archive
	strcpy(archiveRepository->data.archiveList[possiblePosition].fileType, newFileType);
	strcpy(archiveRepository->data.archiveList[possiblePosition].stateOfDeterioration, newStateOfDeterioration);
	archiveRepository->data.archiveList[possiblePosition].yearOfCreation = newYearOfCreation;
	return 1;
}

int deleteRepositoryEntry(Repository* archiveRepository, int catalogueNumber){
	int possiblePosition = findInRepository(archiveRepository, catalogueNumber);

	// element does not exist
	if (isInRepository(archiveRepository, catalogueNumber, possiblePosition) == 0) {
		return 0;
	}

	// overwrite the position we want to remove by moving all elements on its right by 1 position to the left
	for (int index = possiblePosition; index < archiveRepository->data.numberOfObjects - 1; index++) {
		archiveRepository->data.archiveList[index] = archiveRepository->data.archiveList[index + 1];
	}
	archiveRepository->data.numberOfObjects--;
	return 1;
}

Archive getArchiveAtIndex(Container* data, int archiveIndex) {
	// assume the index is valid
	return data->archiveList[archiveIndex];
}

int getNumberOfObjects(Container* data) {
	return data->numberOfObjects;
}

Container* getPointerToData(Repository* currentRepo) {
	return &currentRepo->data;
}

Container getData(Repository* currentRepo) {
	return currentRepo->data;
}

void repositoryDestructor(Repository* archiveRepository) {
	free(archiveRepository->data.archiveList);
	free(archiveRepository);
}

