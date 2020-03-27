#pragma once
#include "repository.h"

#define INITIAL_HISTORY_CAPACITY 10

typedef struct {
	Container** dataHistory;
	int historyCapacity;
	int currentAction; // index of the current state of the repository in the repositoryHistory
	int upperBound; // the largest index that has been reached since the last performed operation
	// for example, if we perform 4 operations then undo twice, upperBound = 4, because we need to be able to redo
	int maximumPosition; // the maximum position that is reached at any point during the execution of the program
	// (needed for the array destructor)
}UndoController;

UndoController* createUndoController();
/*
	Creates a new undoController
	Input:
		- None
	Output:
		- A pointer to a newly-created UndoController object
*/

void saveData(UndoController* newUndoController, Repository* currentRepository);
/*
	Saves the current state of the repository to a list of repositories
	Input:
		- newUndoController = pointer to an UndoController object
		- currentRepository = pointer to a Repository object, the Repository that we wish to save
	Output:
		- None
*/

int undo(UndoController* newUndoController);
/*
	Undoes the last performed operation
	Input:
		- newUndoController = pointer to an UndoController object
	Output:
		- 1, if the operation was successful
		- 0, otherwise
*/

int redo(UndoController* newUndoController);
/*
	Redoes the last operation that has been undone
	Input:
		- newUndoController = pointer to an UndoController object
	Output:
		- 1, if the operation was successful
		- 0, otherwise
*/

//Container* getPreviousContainer(UndoController* newUndoController);
/*
	Returns a 'deep' copy of the repository corresponding to the current index in repositoryHistory
	Input:
		- newUndoController = pointer to an UndoController object
	Output:
		- A pointer to a Repository object, which is a 'deep' copy of the repository at the current index in repositoryHistory
*/

void undoControllerDestructor(UndoController* newUndoController);
/*
	Deallocates the memory for the current UndoController
	Input:
		- newUndoController = pointer to an UndoController object
	Output:
		- None
*/

