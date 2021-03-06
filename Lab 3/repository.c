#include "repository.h"
#include <string.h>
#include <stdio.h>

Repository* createRepository(int repositoryCapacity){
	Repository* newRepository = (Repository*)malloc(sizeof(Repository));

	// ensure we don't de-reference a NULL pointer
	if (newRepository == NULL) {
		return NULL;
	}
	newRepository->data.archiveList = (Archive*)malloc(repositoryCapacity * sizeof(Archive));
	// ensure we don't de-reference a NULL pointer
	if (newRepository->data.archiveList == NULL) {
		return NULL;
	}

	newRepository->data.capacity = repositoryCapacity;
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

	// the array is full, need to re-allocate it
	if (archiveRepository->data.numberOfObjects + 1 == archiveRepository->data.capacity) {
		Archive* newArray = (Archive*)malloc(sizeof(Archive) * archiveRepository->data.capacity * 2);
		
		// ensure we don't dereference a null pointer
		if (newArray == NULL) {
			return 0;
		}
		
		for (int i = 0; i < archiveRepository->data.capacity; i++) {
			newArray[i] = archiveRepository->data.archiveList[i];
		}

		archiveRepository->data.capacity *= 2;
		free(archiveRepository->data.archiveList);
		archiveRepository->data.archiveList = newArray;
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
	Container newContainer;
	newContainer.numberOfObjects = currentRepo->data.numberOfObjects;
	newContainer.capacity = currentRepo->data.capacity; // not really required, but it's better to not leave it uninitialised
	newContainer.archiveList = (Archive*)malloc(sizeof(Archive) * newContainer.numberOfObjects);
	
	// ensure we don't dereference a null pointer
	if (newContainer.archiveList == NULL) {
		return;
	}

	for (int i = 0; i < newContainer.numberOfObjects; i++) {
		newContainer.archiveList[i] = currentRepo->data.archiveList[i];
	}
	
	return newContainer;
}

void swapArchives(Archive* archive1, Archive* archive2) {
	Archive temporaryArchive;
	temporaryArchive = *archive1;
	*archive1 = *archive2;
	*archive2 = temporaryArchive;
}

void sortIncreasingByStateOfDeterioration(Repository* archiveRepository) {
	// bubble sort
	int sorted = 0;
	while (sorted == 0) {
		sorted = 1;
		for (int index = 0; index < archiveRepository->data.numberOfObjects - 1; index++) {
			if (strcmp(archiveRepository->data.archiveList[index].stateOfDeterioration, archiveRepository->data.archiveList[index + 1].stateOfDeterioration) > 0) {
				swapArchives(&archiveRepository->data.archiveList[index], &archiveRepository->data.archiveList[index + 1]);
				sorted = 0;
			}
		}
	}
}

Repository* copyRepository(Repository* originalRepository) {
	Repository* newRepository;
	newRepository = createRepository(originalRepository->data.capacity);
	newRepository->data.numberOfObjects = originalRepository->data.numberOfObjects;
	newRepository->data.capacity = originalRepository->data.capacity; // this is pointless, but I still use it to show that we are copying everything
	for (int i = 0; i < newRepository->data.capacity; i++) {
		newRepository->data.archiveList[i] = originalRepository->data.archiveList[i];
	}
	return newRepository;
}

Container* copyContainer(Container* originalContainer) {
	Container newContainer;
	newContainer.capacity = originalContainer->capacity;
	newContainer.numberOfObjects = originalContainer->numberOfObjects;
	newContainer.archiveList = (Archive*)malloc(sizeof(Archive) * newContainer.capacity);

	if (newContainer.archiveList == NULL) {
		return NULL;
	}

	for (int i = 0; i < newContainer.numberOfObjects; i++) {
		newContainer.archiveList[i] = originalContainer->archiveList[i];
	}

	return &newContainer;
}

void loadDataIntoRepository(Repository* currentRepository, Container* newContainer) {
	containerDestructor(&currentRepository->data);
	currentRepository->data.capacity = newContainer->capacity;
	currentRepository->data.numberOfObjects = newContainer->numberOfObjects;
	currentRepository->data.archiveList = (Archive*)malloc(sizeof(Archive) * newContainer->capacity);

	if (currentRepository->data.archiveList == NULL) {
		return;
	}

	for (int i = 0; i < newContainer->numberOfObjects; i++) {
		currentRepository->data.archiveList[i] = newContainer->archiveList[i];
	}
}

void containerDestructor(Container* currentContainer) {
	free(currentContainer->archiveList);
}

void repositoryDestructor(Repository* archiveRepository) {
	containerDestructor(&(archiveRepository->data));
	free(archiveRepository);
}

