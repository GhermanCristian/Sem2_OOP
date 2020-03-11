#pragma once
#include "archive.h"
#include <stdlib.h>

#define MAX_LENGTH 10001

typedef struct {
	int numberOfObjects;
	Archive* archiveList[MAX_LENGTH];
}Container;

typedef struct {
	Container data;
}Repository;

Repository* createRepository();
/*
	Creates a new, empty Repository
	Input:
		- None
	Output:
		- A pointer to an "object" of type Repository
*/

int findInRepository(Repository* archiveRepository, int archiveCatalogueNumber);
/*
	Finds an archive in a repository, based on its catalogue number
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- archiveCatalogueNumber = integer
	Output:
		- The largest position whose value is smaller than or equal to the catalogue number = integer
*/

int isInRepository(Repository* archiveRepository, int archiveCatalogueNumber, int possiblePosition);
/*
	Checks if the archive at a given position corresponds to the given catalogue number
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- archiveCatalogueNumber = integer
		- possiblePosition = integer
	Output:
		- The truth value of the condition = integer
*/

int addToRepository(Repository* archiveRepository, Archive *newArchive);
/*
	Adds an archive to the repository
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- newArchive = "object" of type Archive
	Output:
		- 1, if the operation was successfull
		- 0, otherwise
*/

int updateRepositoryEntry(Repository* archiveRepository, int catalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation);
/*
	Updates an entry in the repository
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- catalogueNumber = integer
		- newStateOfDeterioration = array of characters
		- newFileType = array of characters
		- newYearOfCreation = integer
	Output:
		- 1, if the operation was successfull
		- 0, otherwise
*/

int deleteRepositoryEntry(Repository* archiveRepository, int catalogueNumber);
/*
	Deletes an entry from the repository
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- catalogueNumber = integer
	Output:
		- 1, if the operation was successfull
		- 0, otherwise
*/

Archive* getArchiveAtIndex(Container* data, int archiveIndex);
/*
	Determines the archive at a given index
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- archiveIndex = integer; the (valid) position of the archive in the repository
	Output:
		- A pointer to an "object" of type Archive
*/

int getNumberOfObjects(Container* data);

Container* getAllData(Repository* currentRepo);

void repositoryDestructor(Repository* archiveRepository);
/*
	De-allocates the memory for a Repository
	Input:
		- archiveRepository = pointer to an "object" of type Repository
	Output:
		- None
*/