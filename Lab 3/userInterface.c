#include "userInterface.h"
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH_COMMAND 100
#define MAX_NUMBER_COMMANDS 5

void addArchiveInterface(UserInterface* interface, char* catalogueNumber, char* stateOfDeterioration, char* fileType, char* yearOfCreation) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(yearOfCreation);
	addArchive(interface->commandController, integerCatalogueNumber, stateOfDeterioration, fileType, integerYearOfCreation);
}

void updateArchiveInterface(UserInterface* interface, char* catalogueNumber, char* newStateOfDeterioration, char* newFileType, char* newYearOfCreation) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(newYearOfCreation);
	updateArchive(interface->commandController, integerCatalogueNumber, newStateOfDeterioration, newFileType, integerYearOfCreation);
}

void deleteArchiveInterface(UserInterface* interface, char* catalogueNumber) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	deleteArchive(interface->commandController, integerCatalogueNumber);
}

void processCommand(UserInterface* interface, char* command) {
	int currentTokenIndex = 0;
	const char separators[3] = ", ";

	char* allTokens[MAX_LENGTH_COMMAND] = (char**)malloc(MAX_NUMBER_COMMANDS * sizeof(char*));
	for (int index = 0; index < MAX_NUMBER_COMMANDS; index++) {
		allTokens[index] = (char*)malloc(MAX_LENGTH_COMMAND * sizeof(char));
	}


	allTokens[currentTokenIndex] = strtok(command, separators);
	while (allTokens[currentTokenIndex] != NULL) {
		allTokens[++currentTokenIndex] = strtok(NULL, separators);
	}

	if (strcmp(allTokens[0], "add") == 0) {
		addArchiveInterface(interface, allTokens[1], allTokens[2], allTokens[3], allTokens[4]);
	}

	else if (strcmp(allTokens[0], "update") == 0) {
		updateArchiveInterface(interface, allTokens[1], allTokens[2], allTokens[3], allTokens[4]);
	}

	else if (strcmp(allTokens[0], "delete") == 0) {
		deleteArchiveInterface(interface, allTokens[1]);
	}

	else if (strcmp(allTokens[0], "list") == 0) {
		;
	}

	else {
		printf("Invalid command\n");
		return;
	}

	for (int index = 0; index < MAX_NUMBER_COMMANDS; index++) {
		free(allTokens[index]);
	}
	free(allTokens);
}

void startProgram(UserInterface* interface) {
	char command[MAX_LENGTH_COMMAND];

	while (1) {
		printf("Insert the command:\n");
		printf("exit\n");
		printf("add catalogueNumber, stateOfDeterioration, fileType, yearOfCreation\n");
		printf("update catalogueNumber, newStateOfDeterioration, newFileType, newYearOfCreation\n");
		printf("delete catalogueNumber\n");
		printf("list\n");
		printf("list fileType\n");

		if (fgets(command, MAX_LENGTH_COMMAND, stdin) == NULL) {
			printf("Cannot read the command\n");
			continue;
		}

		if (strcmp(command, "exit") == 0) {
			printf("The program has ended\n");
			return;
		}

		processCommand(interface, command);
	}
}

UserInterface* createUserInterface() {
	UserInterface* newUserInterface = (UserInterface*)malloc(sizeof(UserInterface));

	if (newUserInterface == NULL) {
		return NULL;
	}

	newUserInterface->commandController = createController();
	return newUserInterface;
}

void destroyUserInterface(UserInterface* interface) {
	controllerDestructor(interface->commandController);
	free(interface);
}
