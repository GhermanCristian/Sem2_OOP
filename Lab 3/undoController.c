#include "undoController.h"
#include <stdio.h>
#include <string.h>

UndoController* createUndoController() {
	UndoController* newUndoController = (UndoController*)malloc(sizeof(UndoController));

	// ensure we don't dereference a null pointer
	if (newUndoController == NULL) {
		return NULL;
	}

	newUndoController->currentAction = -1;
	newUndoController->upperBound = -1;
	newUndoController->maximumPosition = -1;
	newUndoController->historyCapacity = INITIAL_HISTORY_CAPACITY; // I don't know if I'll use reallocating here, so I don't know if the word 'initial' is relevant or not
	newUndoController->repositoryHistory = (Repository**)malloc(sizeof(Repository*) * INITIAL_HISTORY_CAPACITY);

	// ensure we don't dereference a null pointer
	if (newUndoController->repositoryHistory == NULL) {
		return NULL;
	}

	return newUndoController;
}

void saveRepository(UndoController* newUndoController, Repository* currentRepository) {
	newUndoController->currentAction++;
	if (newUndoController->currentAction == newUndoController->historyCapacity) {
		// when containerHistory is full, we normally would have to resize
		return;
	}

	// when adding a new version of the repository to this list, everything that's above the current action
	// in containerHistory should be ignored
	newUndoController->upperBound = newUndoController->currentAction;

	// update the maximum position reached by the currentAction
	if (newUndoController->maximumPosition < newUndoController->currentAction) {
		newUndoController->maximumPosition = newUndoController->currentAction;
	}
	else {
		// if it's not a new maximum value, it means that this position contains a residual repository
		// which has to be destroyed (the destructor is not called for a new maximum because that position is empty
		// , thus it doesn't have a container to destroy)
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

Repository* getPreviousRepository(UndoController* newUndoController) {
	// a 'deep' copy of the repository
	return copyRepository(newUndoController->repositoryHistory[newUndoController->currentAction]);
}

void undoControllerDestructor(UndoController* newUndoController) {
	// destroy only the repositories on the positions which have actually been accessed (because trying to 
	// deallocate the container of an undefined repository causes errors)
	for (int i = 0; i <= newUndoController->maximumPosition; i++) {
		repositoryDestructor(newUndoController->repositoryHistory[i]);
	}
	free(newUndoController->repositoryHistory);
	free(newUndoController);
}