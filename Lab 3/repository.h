#pragma once
#include "archive.h"
#include <stdlib.h>

#define MAX_LENGTH 10001

typedef struct {
	int numberOfObjects;
	Archive archiveList[MAX_LENGTH];

}Repository;

Repository* createRepository();
int findInRepository(Repository* archiveRepository, int archiveCatalogueNumber);
int isInRepository(Repository* archiveRepository, int archiveCatalogueNumber, int possiblePosition);
int addToRepository(Repository* archiveRepository, Archive newArchive);
int updateRepositoryEntry(Repository* archiveRepository, int catalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation);
int deleteRepositoryEntry(Repository* archiveRepository, int catalogueNumber);
void repositoryDestructor(Repository* archiveRepository);