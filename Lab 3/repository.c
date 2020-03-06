#include "repository.h"
#include <string.h>

Repository* createRepository(){
	Repository* newRepository = (Repository*)malloc(sizeof(Repository));

	if (newRepository == NULL) {
		return NULL;
	}

	newRepository->numberOfObjects = 0;
	return newRepository;
}

int findInRepository(Repository* archiveRepository, int archiveCatalogueNumber) {
	int leftBound = 0, rightBound = archiveRepository->numberOfObjects - 1, middle;
	while (leftBound <= rightBound) {
		middle = (leftBound + rightBound) / 2;
		if (archiveRepository->archiveList[middle].catalogueNumber <= archiveCatalogueNumber) {
			leftBound = middle + 1;
		}
		else {
			rightBound = middle - 1;
		}
	}
	return rightBound;
}

int isInRepository(Repository* archiveRepository, int archiveCatalogueNumber, int possiblePosition) {
	if (possiblePosition < 0) {
		return 0;
	}
	return (archiveRepository->archiveList[possiblePosition].catalogueNumber == archiveCatalogueNumber);
}

int addToRepository(Repository* archiveRepository, Archive newArchive){
	if (archiveRepository->numberOfObjects == 0) {
		archiveRepository->archiveList[archiveRepository->numberOfObjects++] = newArchive;
		return 1;
	}

	int possiblePosition = findInRepository(archiveRepository, newArchive.catalogueNumber);
	if (isInRepository(archiveRepository, newArchive.catalogueNumber, possiblePosition) == 1) {
		return 0;
	}

	for (int index = archiveRepository->numberOfObjects - 1; index > possiblePosition; index--) {
		archiveRepository->archiveList[index + 1] = archiveRepository->archiveList[index];
	}
	archiveRepository->numberOfObjects++;
	archiveRepository->archiveList[possiblePosition + 1] = newArchive;
	return 1;
}

int updateRepositoryEntry(Repository* archiveRepository, int catalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation){
	int possiblePosition = findInRepository(archiveRepository, catalogueNumber);
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
	if (isInRepository(archiveRepository, catalogueNumber, possiblePosition) == 0) {
		return 0;
	}

	for (int index = possiblePosition; index < archiveRepository->numberOfObjects - 1; index++) {
		archiveRepository->archiveList[index] = archiveRepository->archiveList[index + 1];
	}
	archiveRepository->numberOfObjects--;
	return 1;
}

void repositoryDestructor(Repository* archiveRepository) {
	free(archiveRepository);
}
