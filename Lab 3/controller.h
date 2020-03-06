#pragma once
#include "repository.h"

typedef struct {
	Repository* archiveRepository;
}Controller;

Controller* createController();
char* addArchive(Controller* commandController, int catalogueNumber, char* stateOfDeterioration, char* archiveType, int yearOfCreation);
char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation);
char* deleteArchive(Controller* commandController, int catalogueNumber);
Repository* getAllRepositoryEntries(Controller* commandController);
Repository* filterRepositoryEntries(Controller* commandController, char* fileType);
void controllerDestructor(Controller* commandController);