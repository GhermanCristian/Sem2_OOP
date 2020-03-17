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
	// in containerHistory should be ignored
	newUndoController->upperBound = newUndoController->currentAction;
	if (newUndoController->maximumPosition < newUndoController->upperBound) {
		newUndoController->maximumPosition = newUndoController->upperBound;
	}
	else {
		repositoryDestructor(newUndoController->repositoryHistory[newUndoController->currentAction]);
	}
	newUndoController->repositoryHistory[newUndoController->currentAction] = copyRepository(currentRepository);
}

int undo(UndoController* newUndoController) {
	// there are no actions left to undo
	if (newUndoController->currentAction == 0) {
		return 0;
	}
	newUndoController->currentAction--;
	return 1;
}

int redo(UndoController* newUndoController) {
	// there are no actions left to redo
	if (newUndoController->currentAction == newUndoController->upperBound) {
		return 0;
	}
	newUndoController->currentAction++;
	return 1;
}

Repository* getCurrentRepository(UndoController* newUndoController) {
	// a 'deep' copy of the repository
	return copyRepository(newUndoController->repositoryHistory[newUndoController->currentAction]);
}

void undoControllerDestructor(UndoController* newUndoController) {
	for (int i = 0; i <= newUndoController->maximumPosition; i++) {
		repositoryDestructor(newUndoController->repositoryHistory[i]);
	}
	free(newUndoController->repositoryHistory);
	free(newUndoController);
}