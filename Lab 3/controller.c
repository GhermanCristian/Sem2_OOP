#include "controller.h"
#include <string.h>

Controller* createController() {
	Controller* newController = (Controller*)malloc(sizeof(Controller));

	// ensure we don't de-reference a NULL pointer
	if (newController == NULL) {
		return NULL;
	}

	// the repository associated to this set of commands
	newController->archiveRepository = createRepository();
	return newController;
}

char* addArchive(Controller* commandController, int catalogueNumber, char* stateOfDeterioration, char* archiveType, int yearOfCreation) {
	Archive *newArchive = createArchive(catalogueNumber, stateOfDeterioration, archiveType, yearOfCreation);
	int successfulOperation = addToRepository(commandController->archiveRepository, newArchive);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation) {
	int successfulOperation = updateRepositoryEntry(commandController->archiveRepository, catalogueNumber, newStateOfDeterioration, newArchiveType, newYearOfCreation);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* deleteArchive(Controller* commandController, int catalogueNumber) {
	int successfulOperation = deleteRepositoryEntry(commandController->archiveRepository, catalogueNumber);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

Container* getAllEntries(Controller* commandController) {
	return getAllData(commandController->archiveRepository);
}

Container* filterEntries(Controller* commandController, char* fileType) {
	Repository* filteredRepository = createRepository();
	Container* completeData = getAllData(commandController->archiveRepository);

	// we add to the filteredRepository only the elements which pass the filter
	// (whose fileType corresponds to the given one)
	for (int index = 0; index < getNumberOfObjects(completeData); index++) {
		if (strcmp(getArchiveAtIndex(completeData, index)->fileType, fileType) == 0) {
			addToRepository(filteredRepository, getArchiveAtIndex(completeData, index));
		}
	}
	return getAllData(filteredRepository);
}

void controllerDestructor(Controller* commandController) {
	repositoryDestructor(commandController->archiveRepository);
	free(commandController);
}
