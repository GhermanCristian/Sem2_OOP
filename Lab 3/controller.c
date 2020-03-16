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
	newController->undoController = createUndoController();
	// add an empty repository to the list of previous repositories (the initial state of the program is an empty repository)
	performAction(newController->undoController, newController->archiveRepository);
	return newController;
}

char* addArchive(Controller* commandController, int catalogueNumber, char* stateOfDeterioration, char* archiveType, int yearOfCreation) {
	Archive newArchive = createArchive(catalogueNumber, stateOfDeterioration, archiveType, yearOfCreation);
	int successfulOperation = addToRepository(commandController->archiveRepository, newArchive);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	performAction(commandController->undoController, commandController->archiveRepository);
	return NULL;
}

char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation) {
	int successfulOperation = updateRepositoryEntry(commandController->archiveRepository, catalogueNumber, newStateOfDeterioration, newArchiveType, newYearOfCreation);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	performAction(commandController->undoController, commandController->archiveRepository);
	return NULL;
}

char* deleteArchive(Controller* commandController, int catalogueNumber) {
	int successfulOperation = deleteRepositoryEntry(commandController->archiveRepository, catalogueNumber);
	char* message = "No!";
	if (successfulOperation == 0) {
		return message;
	}
	performAction(commandController->undoController, commandController->archiveRepository);
	return NULL;
}

Container* getAllEntries(Controller* commandController) {
	return getPointerToData(commandController->archiveRepository);
}

Container filterEntriesByType(Controller* commandController, char* fileType) {
	Repository* filteredRepository = createRepository();
	Container* completeDataPointer = getPointerToData(commandController->archiveRepository);
	Container completeData;

	// we add to the filteredRepository only the elements which pass the filter
	// (whose fileType corresponds to the given one)
	for (int index = 0; index < getNumberOfObjects(completeDataPointer); index++) {
		if (strcmp(getArchiveAtIndex(completeDataPointer, index).fileType, fileType) == 0) {
			addToRepository(filteredRepository, getArchiveAtIndex(completeDataPointer, index));
		}
	}
	
	// why I am using to different getters here is because before I would return a pointer to this
	// temporary repository (filtered); if I tried to free it, then the result would have also dissapeared
	// otherwise, there would've been a memory leak
	// now I return the actual data, but just where it is needed

	completeData = getData(filteredRepository);
	repositoryDestructor(filteredRepository);
	return completeData;
}

Container filterEntriesByYear(Controller* commandController, int yearOfCreation) {
	Repository* filteredRepository = createRepository();
	Container* completeDataPointer = getPointerToData(commandController->archiveRepository);
	Container completeData;

	// we add to the filteredRepository only the elements which pass the filter
	for (int index = 0; index < getNumberOfObjects(completeDataPointer); index++) {
		if (yearOfCreation > getArchiveAtIndex(completeDataPointer, index).yearOfCreation) {
			addToRepository(filteredRepository, getArchiveAtIndex(completeDataPointer, index));
		}
	}
	
	sortIncreasingByStateOfDeterioration(filteredRepository);
	completeData = getData(filteredRepository);
	repositoryDestructor(filteredRepository);
	return completeData;
}

void undoLastOperation(Controller* commandController) {
	undo(commandController->undoController);
	commandController->archiveRepository = getCurrentRepository(commandController->undoController);
}

void redoLastOperation(Controller* commandController) {
	redo(commandController->undoController);
	commandController->archiveRepository = getCurrentRepository(commandController->undoController);
}

void controllerDestructor(Controller* commandController) {
	undoControllerDestructor(commandController->undoController);
	repositoryDestructor(commandController->archiveRepository);
	free(commandController);
}
