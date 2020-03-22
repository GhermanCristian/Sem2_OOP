#include "userInterface.h"
#include <iostream>
#include <string.h>

UserInterface::UserInterface() {
	this->functionList[0] = &InputValidator::addVictimInputValidator;
	this->functionList[1] = &InputValidator::updateVictimInputValidator;
	this->functionList[2] = &InputValidator::deleteVictimInputValidator;
	this->functionList[3] = &InputValidator::listAllInputValidator;
}

void UserInterface::processCommand(std::string command, char programMode) {
	std::smatch stringMatchResult;
	bool executedCommand = false;

	for (int i = 0; i < NUMBER_OF_COMMANDS && executedCommand == false; i++) {
		try {
			stringMatchResult = (inputValidator.*functionList[i])(command);
			executedCommand = true; // if we reach this point => the operation went well
		}

		catch (...) {
			;
		}
	}

	if (executedCommand == false) {
		std::cout << "Invalid input\n";
		return;
	}
}

void UserInterface::startProgram() {
	char programMode;
	std::string command;

	while (1) {
		std::cout << "Insert the mode (A = administrator, B = assistant)\n";
		std::cin >> programMode;
		std::cin.get(); // read the '\n' after this input

		// validate this input, but for now we'll consider that it's valid
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