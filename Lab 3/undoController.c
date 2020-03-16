#include "undoController.h"
#include <stdio.h>
#include <string.h>

UndoController* createUndoController() {
	UndoController* newUndoController = (UndoController*)malloc(sizeof(UndoController));

	if (newUndoController == NULL) {
		return NULL;
	}

	newUndoController->currentAction = -1;
	newUndoController->upperBound = -1;
	newUndoController->maximumPosition = -1;
	newUndoController->historySize = INITIAL_HISTORY_SIZE; // I don't know if I'll ever use reallocating here, but still
	newUndoController->repositoryHistory = (Repository**)malloc(sizeof(Repository*) * INITIAL_HISTORY_SIZE);

	if (newUndoController->repositoryHistory == NULL) {
		return NULL;
	}

	return newUndoController;
}

void performAction(UndoController* newUndoController, Repository* currentRepository) {
	// if containerHistory is full, we would have to resize (won't do that right now)
	newUndoController->currentAction++;
	if (newUndoController->currentAction == newUndoController->historySize) {
		return;
	}

	// when adding a new version of the container to this list, everything that's above the current action
	// in containerHistory should be deleted
	newUndoController->upperBound = newUndoController->currentAction;
	if (newUndoController->maximumPosition < newUndoController->upperBound) {
		newUndoController->maximumPosition = newUndoController->upperBound;
	}

	if (newUndoController->repositoryHistory[newUndoController->currentAction] == NULL) {
		return;
	}

	newUndoController->repositoryHistory[newUndoController->currentAction] = createRepository();
	newUndoController->repositoryHistory[newUndoController->currentAction]->data.capacity = currentRepository->data.capacity;
	newUndoController->repositoryHistory[newUndoController->currentAction]->data.numberOfObjects = currentRepository->data.numberOfObjects;
	for (int index = 0; index < newUndoController->repositoryHistory[newUndoController->currentAction]->data.numberOfObjects; index++) {
		newUndoController->repositoryHistory[newUndoController->currentAction]->data.archiveList[index].catalogueNumber = currentRepository->data.archiveList[index].catalogueNumber;
		strcpy(newUndoController->repositoryHistory[newUndoController->currentAction]->data.archiveList[index].stateOfDeterioration, currentRepository->data.archiveList[index].stateOfDeterioration);
		strcpy(newUndoController->repositoryHistory[newUndoController->currentAction]->data.archiveList[index].fileType, currentRepository->data.archiveList[index].fileType);
		newUndoController->repositoryHistory[newUndoController->currentAction]->data.archiveList[index].yearOfCreation = currentRepository->data.archiveList[index].yearOfCreation;
	}
}

void undo(UndoController* newUndoController) {
	// cannot undo if there are no actions left to undo
	if (newUndoController->currentAction == 0) {
		return;
	}
	newUndoController->currentAction--;
}

void redo(UndoController* newUndoController) {
	if (newUndoController->currentAction == newUndoController->upperBound) {
		return;
	}
	newUndoController->currentAction++;
}

Repository* getCurrentRepository(UndoController* newUndoController) {
	return newUndoController->repositoryHistory[newUndoController->currentAction];
}

void undoControllerDestructor(UndoController* newUndoController) {
	for (int i = 0; i <= newUndoController->maximumPosition; i++) {
		// the first deallocation here (i = 0) deallocates the main container (i think, if not, this method as a 
		// whole does it)
		printf("undo: %p\n", &newUndoController->repositoryHistory[i]->data.archiveList);
		repositoryDestructor(newUndoController->repositoryHistory[i]);
	}
	free(newUndoController->repositoryHistory);
	free(newUndoController);
}