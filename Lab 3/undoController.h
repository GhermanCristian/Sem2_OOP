#pragma once
#include "repository.h"

#define INITIAL_HISTORY_CAPACITY 10

typedef struct {
	Repository** repositoryHistory;
	int historyCapacity;
	int currentAction; // index of the current state of the repository in the repositoryHistory
	int upperBound; // the largest index that has been reached since the last performed operation
	// for example, if we perform 4 operations then undo twice, upperBound = 4, because we need to be able to redo
	int maximumPosition; // the maximum position that is reached at any point during the execution of the program
	// (needed for the array destructor)
}UndoController;

UndoController* createUndoController();
/*
	
	Input:
		-
	Output:
		-
*/

void saveRepository(UndoController* newUndoController, Repository* currentRepository);
/*

	Input:
		-
	Output:
		-
*/

int undo(UndoController* newUndoController);
/*

	Input:
		-
	Output:
		-
*/


int redo(UndoController* newUndoController);
/*

	Input:
		-
	Output:
		-
*/


Repository* getPreviousRepository(UndoController* newUndoController);
/*

	Input:
		-
	Output:
		-
*/


void undoControllerDestructor(UndoController* newUndoController);
/*

	Input:
		-
	Output:
		-
*/

