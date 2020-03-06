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
	char* message = "No!\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation) {
	int successfulOperation = updateRepositoryEntry(commandController->archiveRepository, catalogueNumber, newStateOfDeterioration, newArchiveType, newYearOfCreation);
	char* message = "No!\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

char* deleteArchive(Controller* commandController, int catalogueNumber) {
	int successfulOperation = deleteRepositoryEntry(commandController->archiveRepository, catalogueNumber);
	char* message = "No!\n";
	if (successfulOperation == 0) {
		return message;
	}
	return NULL;
}

Repository* getAllRepositoryEntries(Controller* commandController) {
	return commandController->archiveRepository;
}

Repository* filterRepositoryEntries(Controller* commandController, char* fileType) {
	Repository* filteredRepository = createRepository();
	Repository* completeRepository = commandController->archiveRepository;

	for (int index = 0; index < completeRepository->numberOfObjects; index++) {
		if (strcmp(completeRepository->archiveList[index].fileType, fileType) == 0) {
			addToRepository(filteredRepository, completeRepository->archiveList[index]);
		}
	}

	return filteredRepository;
}

void controllerDestructor(Controller* commandController) {
	repositoryDestructor(commandController->archiveRepository);
	free(commandController);
}
