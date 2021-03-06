#pragma once
#include "repository.h"
#include "undoController.h"

typedef struct {
	Repository* archiveRepository;
	UndoController* undoController;
}Controller;

Controller* createController();
/*
	Creates a new, empty Controller
	Input:
		- None
	Output:
		- A pointer to an "object" of type Controller
*/

char* addArchive(Controller* commandController, int catalogueNumber, char* stateOfDeterioration, char* archiveType, int yearOfCreation);
/*
	Service for adding an Archive
	Input:
		- commandController = pointer to an "object" of type Controller
		- catalogueNumber = integer
		- stateOfDeterioration = array of characters
		- fileType = array of characters
		- yearOfCreation = integer
	Output:
		- An error message, if the operation was unsuccessfull = array of characters
		- NULL, otherwise
*/

char* updateArchive(Controller* commandController, int catalogueNumber, char* newStateOfDeterioration, char* newArchiveType, int newYearOfCreation);
/*
	Service for updating an Archive
	Input:
		- commandController = pointer to an "object" of type Controller
		- catalogueNumber = integer
		- newStateOfDeterioration = array of characters
		- newFileType = array of characters
		- newYearOfCreation = integer
	Output:
		- An error message, if the operation was unsuccessfull = array of characters
		- NULL, otherwise
*/

char* deleteArchive(Controller* commandController, int catalogueNumber);
/*
	Service for deleting an Archive
	Input:
		- commandController = pointer to an "object" of type Controller
		- catalogueNumber = integer
	Output:
		- An error message, if the operation was unsuccessfull = array of characters
		- NULL, otherwise
*/

Container* getAllEntries(Controller* commandController);
/*
	Provides access to all the entries in a repository
	Input:
		- commandController = pointer to an "object" of type Controller
	Output:
		- A pointer to an "object" of type Repository
*/

Container filterEntriesByType(Controller* commandController, char* fileType);
/*
	Provides access to some particular entries in a repository, based on a filter
	(fileType correspondes to a given one)
	Input:
		- commandController = pointer to an "object" of type Controller
		- fileType = array of characters
	Output:
		- A Container object which contains only the Archives that have passed the filter
*/

Container filterEntriesByYear(Controller* commandController, int yearOfCreation);
/*
	Provides access to some particular entries in a repository, based on a filter
	(yearOfCreation < a given one, and the entries are sorted in ascending order of their stateOfDeterioration)
	Input:
		- commandController = pointer to an "object" of type Controller
		- yearOfCreation = integer
	Output:
		- A Container object which contains only the Archives that have passed the filter
*/

void undoLastOperation(Controller* commandController);
/*
	Undoes the last performed operation
	Input:
		- commandController = pointer to an "object" of type Controller
	Output:
		- None
*/

void redoLastOperation(Controller* commandController);
/*
	Redoes the last operation that has been undone
	Input:
		- commandController = pointer to an "object" of type Controller
	Output:
		- None
*/

void controllerDestructor(Controller* commandController);
/*
	De-allocates the memory for a Controller
	Input:
		- commandController = pointer to an "object" of type Controller
	Output:
		- None
*/
