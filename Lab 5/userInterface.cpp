#include "userInterface.h"
#include <iostream>
#include <string.h>

UserInterface::UserInterface() {
	this->validatorFunctionListAdministrator[0] = &InputValidator::addVictimInputValidator;
	this->validatorFunctionListAdministrator[1] = &InputValidator::updateVictimInputValidator;
	this->validatorFunctionListAdministrator[2] = &InputValidator::deleteVictimInputValidator;
	this->validatorFunctionListAdministrator[3] = &InputValidator::listAllInputValidator;

	this->interfaceFunctionListAdministrator[0] = &UserInterface::addVictimInterface;
	this->interfaceFunctionListAdministrator[1] = &UserInterface::updateVictimInterface;
	this->interfaceFunctionListAdministrator[2] = &UserInterface::deleteVictimInterface;
	this->interfaceFunctionListAdministrator[3] = &UserInterface::listAllInterface;

	this->commandInfoAdministrator = "Insert command:\n";
	this->commandInfoAdministrator += "exit\n";
	this->commandInfoAdministrator += "add name, placeOfOrigin, age, photograph\n";
	this->commandInfoAdministrator += "update name, newPlaceOfOrigin, newAge, newPhotograph\n";
	this->commandInfoAdministrator += "delete name\n";
	this->commandInfoAdministrator += "list\n\n";


	this->validatorFunctionListAssistant[0] = &InputValidator::addVictimInputValidator;
	this->validatorFunctionListAssistant[1] = &InputValidator::updateVictimInputValidator;
	this->validatorFunctionListAssistant[2] = &InputValidator::deleteVictimInputValidator;

	this->interfaceFunctionListAssistant[0] = &UserInterface::addVictimInterface;
	this->interfaceFunctionListAssistant[1] = &UserInterface::updateVictimInterface;
	this->interfaceFunctionListAssistant[2] = &UserInterface::deleteVictimInterface;

	this->commandInfoAssistant = "Insert command:\n";
	this->commandInfoAssistant += "exit\n";
	this->commandInfoAssistant += "add name, placeOfOrigin, age, photograph\n";
	this->commandInfoAssistant += "update name, newPlaceOfOrigin, newAge, newPhotograph\n";
	this->commandInfoAssistant += "delete name\n\n";
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
	InputValidatorFunction* validatorFunctionList;
	InterfaceFunction* interfaceFunctionList;
	int numberOfCommands;
	bool executedCommand = false;

	if (programMode == ADMINISTRATOR_MODE) {
		validatorFunctionList = this->validatorFunctionListAdministrator;
		interfaceFunctionList = this->interfaceFunctionListAdministrator;
		numberOfCommands = NUMBER_OF_COMMANDS_ADMINISTRATOR;
	}
	else {
		validatorFunctionList = this->validatorFunctionListAssistant;
		interfaceFunctionList = this->interfaceFunctionListAssistant;
		numberOfCommands = NUMBER_OF_COMMANDS_ASSISTANT;
	}

	for (int i = 0; i < numberOfCommands && executedCommand == false; i++) {
		stringMatchResult = (inputValidator.*validatorFunctionList[i])(command);

		if (stringMatchResult.list[0] == ERROR_CODE) {
			continue;
		}

		executedCommand = true; // if we reach this point => the validation went well => we can perform the operation
		(this->*interfaceFunctionList[i])(stringMatchResult);
	}

	if (executedCommand == false) {
		std::cout << "Invalid input\n";
		return;
	}
}

void UserInterface::startProgram() {
	char programMode;
	std::string command;
	std::string commandInfo;

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

	if (programMode == ADMINISTRATOR_MODE) {
		commandInfo = this->commandInfoAdministrator;
	}
	else {
		commandInfo = this->commandInfoAssistant;
	}

	while (1) {
		std::cout << commandInfo;
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