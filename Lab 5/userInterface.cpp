#include "userInterface.h"
#include <iostream>

UserInterface::UserInterface() {
	this->actionController = Controller();
}

void UserInterface::startProgram() {
	char programMode;
	char command[MAXIMUM_COMMAND_LENGTH];

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
		std::cin.getline(command, MAXIMUM_COMMAND_LENGTH, '\n');
		std::cout << "\n" << command << "\n";

		// validate input, but for now we'll consider that it's valid
		break;
	}
}

UserInterface::~UserInterface() {
	;
}