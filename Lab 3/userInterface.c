#include "userInterface.h"
#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_ARGUMENTS 6 // the maximum number of arguments for each command (including the command's name)
#define MAX_LENGTH_COMMAND 100 // the maximum length of a command
#define COMMAND_NAME 0 
#define ARCHIVE_NUMBER 1
#define ARCHIVE_STATE_OF_DETERIORATION 2
#define ARCHIVE_FILE_TYPE 3
#define ARCHIVE_YEAR_OF_CREATION 4


UserInterface* createUserInterface() {
	UserInterface* newUserInterface = (UserInterface*)malloc(sizeof(UserInterface));

	// ensure we don't de-reference a NULL pointer
	if (newUserInterface == NULL) {
		return NULL;
	}

	// the set of commands associated to this user interface
	newUserInterface->commandController = createController();
	return newUserInterface;
}

void addArchiveInterface(UserInterface* interface, char* catalogueNumber, char* stateOfDeterioration, char* fileType, char* yearOfCreation) {
	// convert the catalogueNumber and the yearOfCreation to integers (because the command was an array of characters)
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(yearOfCreation);

	// cannot convert these parameters, hence atoi returns 0
	if (integerCatalogueNumber == 0 || integerYearOfCreation == 0) {
		printf("Invalid parameters\n");
		return;
	}

	char* operationResult = addArchive(interface->commandController, integerCatalogueNumber, stateOfDeterioration, fileType, integerYearOfCreation);
	// print the error message, if required
	if (operationResult != NULL) {
		printf("%s\n", operationResult);
	}
}

void updateArchiveInterface(UserInterface* interface, char* catalogueNumber, char* newStateOfDeterioration, char* newFileType, char* newYearOfCreation) {
	// convert the catalogueNumber and the yearOfCreation to integers (because the command was an array of characters)
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(newYearOfCreation);
	
	// cannot convert these parameters, hence atoi returns 0
	if (integerCatalogueNumber == 0 || integerYearOfCreation == 0) {
		printf("Invalid parameters\n");
		return;
	}
	
	char* operationResult = updateArchive(interface->commandController, integerCatalogueNumber, newStateOfDeterioration, newFileType, integerYearOfCreation);
	// print the error message, if required
	if (operationResult != NULL) {
		printf("%s\n", operationResult);
	}
}

void deleteArchiveInterface(UserInterface* interface, char* catalogueNumber) {
	// convert the catalogueNumber to integer (because the command was an array of characters)
	int integerCatalogueNumber = atoi(catalogueNumber);
	
	// cannot convert this parameter, hence atoi returns 0
	if (integerCatalogueNumber == 0) {
		printf("Invalid parameters\n");
		return;
	}
	
	char* operationResult = deleteArchive(interface->commandController, integerCatalogueNumber);
	// print the error message, if required
	if (operationResult != NULL) {
		printf("%s\n", operationResult);
	}
}

// 'private' method
void displayArchiveContent(Archive* currentArchive) {
	// displays the content of an archive
	printf("%d %s %s %d\n", currentArchive->catalogueNumber, currentArchive->stateOfDeterioration, currentArchive->fileType, currentArchive->yearOfCreation);
}

void listAllArchives(UserInterface* interface) {
	Container* data = getAllEntries(interface->commandController);
	for (int index = 0; index < getNumberOfObjects(data); index++) {
		displayArchiveContent(getArchiveAtIndex(data, index));
	}
}

void listFilteredArchives(UserInterface* interface, char* fileType) {
	Container* data = filterEntries(interface->commandController, fileType);
	for (int index = 0; index < getNumberOfObjects(data); index++) {
		displayArchiveContent(getArchiveAtIndex(data, index));
	}
	// the filteredRepository is a newly allocated Repository, and we don't use it from here on,
	// so we have to destroy it
}

void processCommand(UserInterface* interface, char* command) {
	int currentTokenIndex = 0;
	const char separators[3] = ", ";

	// allTokens[0] will the command's name; the following entries are the command's arguments
	char** allTokens;
	allTokens = (char**)malloc(MAX_NUMBER_ARGUMENTS * sizeof(char*));

	// ensure we don't de-reference a null pointer
	if (allTokens == NULL) {
		printf("Could not process the command\n");
		return;
	}

	allTokens[currentTokenIndex] = strtok(command, separators);
	while (allTokens[currentTokenIndex] != NULL) {
		allTokens[++currentTokenIndex] = strtok(NULL, separators);
	}

	// ensure we don't de-reference a null pointer
	if (allTokens[COMMAND_NAME] == NULL) {
		return;
	}

	if (strcmp(allTokens[COMMAND_NAME], "add") == 0) {
		addArchiveInterface(interface, allTokens[ARCHIVE_NUMBER], allTokens[ARCHIVE_STATE_OF_DETERIORATION], allTokens[ARCHIVE_FILE_TYPE], allTokens[ARCHIVE_YEAR_OF_CREATION]);
	}

	else if (strcmp(allTokens[COMMAND_NAME], "update") == 0) {
		updateArchiveInterface(interface, allTokens[ARCHIVE_NUMBER], allTokens[ARCHIVE_STATE_OF_DETERIORATION], allTokens[ARCHIVE_FILE_TYPE], allTokens[ARCHIVE_YEAR_OF_CREATION]);
	}

	else if (strcmp(allTokens[COMMAND_NAME], "delete") == 0) {
		deleteArchiveInterface(interface, allTokens[ARCHIVE_NUMBER]);
	}

	else if (strcmp(allTokens[COMMAND_NAME], "list\n") == 0) {
		listAllArchives(interface);
	}

	else if (strcmp(allTokens[COMMAND_NAME], "list") == 0) {
		// ensure we don't de-reference a null pointer
		if (allTokens[ARCHIVE_NUMBER] == NULL) {
			return;
		}

		// remove the trailing "\0" so that we can properly compare the strings
		allTokens[ARCHIVE_NUMBER][strlen(allTokens[ARCHIVE_NUMBER]) - 1] = '\0';
		listFilteredArchives(interface, allTokens[ARCHIVE_NUMBER]);
	}

	else {
		printf("Invalid command\n");
		return;
	}

	free(allTokens);
}

void startProgram(UserInterface* interface) {
	char command[MAX_LENGTH_COMMAND];

	while (1) {
		printf("Insert the command:\n\n");
		printf("exit\n");
		printf("add catalogueNumber, stateOfDeterioration, fileType, yearOfCreation\n");
		printf("update catalogueNumber, newStateOfDeterioration, newFileType, newYearOfCreation\n");
		printf("delete catalogueNumber\n");
		printf("list\n");
		printf("list fileType\n\n");

		if (fgets(command, MAX_LENGTH_COMMAND, stdin) == NULL) {
			printf("Cannot read the command\n");
			continue;
		}

		if (strcmp(command, "exit\n") == 0) {
			printf("The program has ended\n");
			return;
		}

		processCommand(interface, command);
	}
}

void userInterfaceDestructor(UserInterface* interface) {
	controllerDestructor(interface->commandController);
	free(interface);
}
