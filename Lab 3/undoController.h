#pragma once
#include "repository.h"

#define INITIAL_HISTORY_SIZE 10

typedef struct {
	Repository** repositoryHistory;
	int historySize;
	int currentAction;
	int upperBound;
	int maximumPosition;
}UndoController;

UndoController* createUndoController();
void performAction(UndoController* newUndoController, Repository* currentRepository);
int undo(UndoController* newUndoController);
int redo(UndoController* newUndoController);
Repository* getCurrentRepository(UndoController* newUndoController);
void undoControllerDestructor(UndoController* newUndoController);