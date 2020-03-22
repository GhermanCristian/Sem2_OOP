#include "userInterface.h"
#include <iostream>
#include <string.h>

UserInterface::UserInterface() {
	this->actionController = Controller();
	this->inputValidator = InputValidator();

	this->functionList[0] = inputValidator.addVictimInputValidator;
	this->functionList[1] = inputValidator.updateVictimInputValidator;
	this->functionList[2] = inputValidator.deleteVictimInputValidator;
	this->functionList[3] = inputValidator.listAllInputValidator;
}

void UserInterface::processCommand(std::string command, char programMode) {
	std::smatch stringMatchResult;

	for (int i = 0; i < NUMBER_OF_COMMANDS; i++) {
		try {
			stringMatchResult = this->functionList[i](command);
			break;
		}

		catch (std::exception & errorMessage) {
			std::cout << errorMessage.what() << "\n";
			return;
		}
	}
}

void UserInterface::startProgram() {
	char programMode;
	std::string command;

	while (1) {
		std::cout << "Insert the mode (A = administrator, B = assistant)\n";
		std::cin >> programMode;
		std::cin.get(); // read the '\n' after the input

		// validate input, but for now we'll consider that it's valid
		break;
	}

	while (1) {
		std::cout << "Insert command:\n";
		std::cout << "exit\n";
		std::cout << "add name, placeOfOrigin, age, photograph\n";
		std::cout << "update name, newPlaceOfOrigin, newAge, newPhotograph\n";
		std::cout << "delete name\n";
		std::cout << "list\n\n";
		std::getline(std::cin, command);
		// validate input, but for now we'll consider that it's valid
		
		if (command == "exit") {
			std::cout << "Program has ended\n";
			return;
		}

		processCommand(command, programMode);
	}
}

UserInterface::~UserInterface() {
	;
}