#include "userInterface.h"
#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_ARGUMENTS 6
#define MAX_LENGTH_COMMAND 100

void addArchiveInterface(UserInterface* interface, char* catalogueNumber, char* stateOfDeterioration, char* fileType, char* yearOfCreation) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(yearOfCreation);
	if (integerCatalogueNumber == 0 || integerYearOfCreation == 0) {
		printf("Invalid parameters\n");
		return;
	}

	char* operationResult = addArchive(interface->commandController, integerCatalogueNumber, stateOfDeterioration, fileType, integerYearOfCreation);
	if (operationResult != NULL) {
		printf("%s", operationResult);
	}
}

void updateArchiveInterface(UserInterface* interface, char* catalogueNumber, char* newStateOfDeterioration, char* newFileType, char* newYearOfCreation) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	int integerYearOfCreation = atoi(newYearOfCreation);
	
	if (integerCatalogueNumber == 0 || integerYearOfCreation == 0) {
		printf("Invalid parameters\n");
		return;
	}
	
	char* operationResult = updateArchive(interface->commandController, integerCatalogueNumber, newStateOfDeterioration, newFileType, integerYearOfCreation);
	if (operationResult != NULL) {
		printf("%s", operationResult);
	}
}

void deleteArchiveInterface(UserInterface* interface, char* catalogueNumber) {
	int integerCatalogueNumber = atoi(catalogueNumber);
	
	if (integerCatalogueNumber == 0) {
		printf("Invalid parameters\n");
		return;
	}
	
	char* operationResult = deleteArchive(interface->commandController, integerCatalogueNumber);
	if (operationResult != NULL) {
		printf("%s", operationResult);
	}
}

void displayArchiveContent(Archive* currentArchive) {
	printf("%d %s %s %d\n", currentArchive->catalogueNumber, currentArchive->stateOfDeterioration, currentArchive->fileType, currentArchive->yearOfCreation);
}

void listAllArchives(UserInterface* interface) {
	Repository* archiveRepository = getAllRepositoryEntries(interface->commandController);
	for (int index = 0; index < archiveRepository->numberOfObjects; index++) {
		displayArchiveContent(&archiveRepository->archiveList[index]);
	}
}

void listFilteredArchives(UserInterface* interface, char* fileType) {
	Repository* filteredRepository = filterRepositoryEntries(interface->commandController, fileType);
	for (int index = 0; index < filteredRepository->numberOfObjects; index++) {
		displayArchiveContent(&filteredRepository->archiveList[index]);
	}
	//repositoryDestructor(filteredRepository);
}

void processCommand(UserInterface* interface, char* command) {
	int currentTokenIndex = 0;
	const char separators[3] = ", ";

	char** allTokens;
	allTokens = (char**)malloc(MAX_NUMBER_ARGUMENTS * sizeof(char*));

	if (allTokens == NULL) {
		printf("Could not process the command\n");
		return NULL;
	}

	allTokens[currentTokenIndex] = strtok(command, separators);
	while (allTokens[currentTokenIndex] != NULL) {
		//printf("token = %s\n", allTokens[currentTokenIndex]);
		allTokens[++currentTokenIndex] = strtok(NULL, separators);
	}

	if (allTokens[0] == NULL) {
		return NULL;
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

	else if (strcmp(allTokens[0], "list\n") == 0) {
		listAllArchives(interface);
	}

	else if (strcmp(allTokens[0], "list") == 0) {
		if (allTokens[1] == NULL) {
			return NULL;
		}
		allTokens[1][strlen(allTokens[1]) - 1] = '\0';
		listFilteredArchives(interface, allTokens[1]);
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
