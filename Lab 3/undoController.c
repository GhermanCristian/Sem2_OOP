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
	newUndoController->dataHistory = (Container**)malloc(sizeof(Container*) * INITIAL_HISTORY_CAPACITY);

	// ensure we don't dereference a null pointer
	if (newUndoController->dataHistory == NULL) {
		return NULL;
	}

	Repository* fillerRepository = createRepository(INITIAL_CAPACITY);
	for (int i = 0; i < newUndoController->historyCapacity; i++) {
		Container fillerContainer = getData(fillerRepository);
		newUndoController->dataHistory[i] = &fillerContainer;
	}
	repositoryDestructor(fillerRepository);

	return newUndoController;
}

void saveData(UndoController* newUndoController, Repository* currentRepository) {
	newUndoController->currentAction++;
	if (newUndoController->currentAction == newUndoController->historyCapacity) {
		// when containerHistory is full, we normally would have to resize
		return;
	}

	// when adding a new version of the repository to this list, everything that's above the current action
	// in containerHistory should be ignored
	newUndoController->upperBound = newUndoController->currentAction;

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

void undoControllerDestructor(UndoController* newUndoController) {

}