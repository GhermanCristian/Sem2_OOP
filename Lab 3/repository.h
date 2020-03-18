#pragma once
#include "archive.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 100

typedef struct {
	int numberOfObjects;
	int capacity;
	Archive *archiveList;
}Container;

typedef struct {
	Container data;
}Repository;

Repository* createRepository(int repositoryCapacity);
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

int addToRepository(Repository* archiveRepository, Archive newArchive);
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

Archive getArchiveAtIndex(Container* data, int archiveIndex);
/*
	Determines the archive at a given index
	Input:
		- archiveRepository = pointer to an "object" of type Repository
		- archiveIndex = integer; the (valid) position of the archive in the repository
	Output:
		- An Archive object
*/

int getNumberOfObjects(Container* data);
/*
	Determines the number of objects from a given Container
	Input:
		- data = pointer to an "object" of type Container
	Output:
		- The number of elements in the Container = integer
*/

Container* getPointerToData(Repository* currentRepo);
/*
	Returns a pointer to the data of the current Repository
	Input:
		- currentRepo = pointer to an "object" of type Repository
	Output:
		- A pointer to the data of the current Repository, of type Container
*/

Container getData(Repository* currentRepo);
/*
	Returns a 'deep' copy of the data from current Repository
	Input:
		- currentRepo = pointer to an "object" of type Repository
	Output:
		- A Container object = 'deep' copy of all the data from the given Repository
*/

void sortIncreasingByStateOfDeterioration(Repository* archiveRepository);
/*
	Sorts the entries in a given Repository based on their stateOfDeterioration (in increasing order)
	Input:
		- archiveRepository = pointer to an "object" of type Repository
	Output:
		- None
*/

Repository* copyRepository(Repository* originalRepository);
/*
	Creates a 'deep' copy of the given Repository
	Input:
		- originalRepository = pointer to an "object" of type Repository, whose content will be assigned to the new Repository
	Output:
		- A new Repository, with the exact content as the original one, but with newly-allocated memory areas
*/

void containerDestructor(Container* currentContainer);
/*
	Deallocates the memory for the given Container
	Input:
		- currentContainer = pointer to an "object" of type Container
	Output:
		- None
*/

void repositoryDestructor(Repository* archiveRepository);
/*
	De-allocates the memory for a Repository
	Input:
		- archiveRepository = pointer to an "object" of type Repository
	Output:
		- None
*/