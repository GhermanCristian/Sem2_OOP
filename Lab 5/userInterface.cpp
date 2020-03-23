#include "userInterface.h"
#include <iostream>
#include <string.h>

const int LIST_ALL_COMMAND_INDEX = 3;
const char ADMINISTRATOR_MODE = 'A';
const char ASSISTANT_MODE = 'B';

UserInterface::UserInterface() {
	this->validatorFunctionList[0] = &InputValidator::addVictimInputValidator;
	this->validatorFunctionList[1] = &InputValidator::updateVictimInputValidator;
	this->validatorFunctionList[2] = &InputValidator::deleteVictimInputValidator;
	this->validatorFunctionList[3] = &InputValidator::listAllInputValidator;

	this->interfaceFunctionList[0] = &UserInterface::addVictimInterface;
	this->interfaceFunctionList[1] = &UserInterface::updateVictimInterface;
	this->interfaceFunctionList[2] = &UserInterface::deleteVictimInterface;
	this->interfaceFunctionList[3] = &UserInterface::listAllInterface;
}

void UserInterface::displayVictim(Victim currentVictim) {
	std::cout << currentVictim.getName() << " " << currentVictim.getPlaceOfOrigin() << " " << currentVictim.getAge() << " " << currentVictim.getPhotographLink() << "\n";
}

void UserInterface::addVictimInterface(ArgumentList argumentList) {
	std::string victimName = argumentList.list[0];
	std::string placeOfOrigin = argumentList.list[1];
	int age = stoi(argumentList.list[2]);
	std::string photographLink = argumentList.list[3];
	
	try {
		this->actionController.addVictim(victimName, placeOfOrigin, age, photographLink);
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::updateVictimInterface(ArgumentList argumentList){
	std::string newVictimName = argumentList.list[0];
	std::string newPlaceOfOrigin = argumentList.list[1];
	int newAge = stoi(argumentList.list[2]);
	std::string newPhotographLink = argumentList.list[3];

	try {
		this->actionController.updateVictim(newVictimName, newPlaceOfOrigin, newAge, newPhotographLink);
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::deleteVictimInterface(ArgumentList argumentList){
	std::string victimName = argumentList.list[0];

	try {
		this->actionController.deleteVictim(victimName);
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::listAllInterface(ArgumentList argumentList){
	DynamicVector* victimList;
	try {
		victimList = this->actionController.getAllVictims();
		for (int index = 0; index < victimList->getNumberOfElements(); index++) {
			displayVictim(victimList->getElementAtIndex(index));
		}
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::processCommand(std::string command, char programMode) {
	ArgumentList stringMatchResult;
	bool executedCommand = false;

	for (int i = 0; i < NUMBER_OF_COMMANDS && executedCommand == false; i++) {
		if (i == LIST_ALL_COMMAND_INDEX and programMode != ADMINISTRATOR_MODE) {
			executedCommand = true;
			continue;
		}

		try {
			stringMatchResult = (inputValidator.*validatorFunctionList[i])(command);
			executedCommand = true; // if we reach this point => the validation went well => we can perform the operation
			(this->*interfaceFunctionList[i])(stringMatchResult);
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
		std::cout << "Insert the mode ('mode A' = administrator, 'mode B' = assistant)\n";
		std::getline(std::cin, command);

		try {
			programMode = inputValidator.modeValidator(command);
			break;
		}
		catch (std::exception & operationException) {
			std::cout << operationException.what() << "\n";
		}
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