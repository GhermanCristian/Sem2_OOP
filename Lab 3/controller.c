#include "controller.h"

Controller* createController() {
	Controller* newController = (Controller*)malloc(sizeof(Controller));

	if (newController == NULL) {
		return NULL;
	}

	newController->archiveRepository = createRepository();
	return newController;
}

char* addArchive(Controller* commandController, int catalogueNumber, char* stateOfDeterioration, char* archiveType, int yearOfCreation) {
	Archive newArchive = createArchive(catalogueNumber, stateOfDeterioration, archiveType, yearOfCreation);
	int successfulOperation = addToRepository(commandController->archiveRepository, newArchive);
	char* message = "Could not add a new archive\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation) {
	int successfulOperation = updateRepositoryEntry(commandController->archiveRepository, catalogueNumber, newStateOfDeterioration, newArchiveType, newYearOfCreation);
	char* message = "Could not update the archive\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* deleteArchive(Controller* commandController, int catalogueNumber) {
	int successfulOperation = deleteRepositoryEntry(commandController->archiveRepository, catalogueNumber);
	char* message = "Could not delete the archive\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

void controllerDestructor(Controller* commandController) {
	repositoryDestructor(commandController->archiveRepository);
	free(commandController);
}
