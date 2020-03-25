#include "userInterface.h"
#include <iostream>
#include <string.h>

UserInterface::UserInterface() {
	this->validatorFunctionListAdministrator[ADD_FUNCTION_POSITION] = &InputValidator::addVictimInputValidator;
	this->validatorFunctionListAdministrator[UPDATE_FUNCTION_POSITION] = &InputValidator::updateVictimInputValidator;
	this->validatorFunctionListAdministrator[DELETE_FUNCTION_POSITION] = &InputValidator::deleteVictimInputValidator;
	this->validatorFunctionListAdministrator[LIST_FUNCTION_POSITION] = &InputValidator::listAllInputValidator;

	this->interfaceFunctionListAdministrator[ADD_FUNCTION_POSITION] = &UserInterface::addVictimInterface;
	this->interfaceFunctionListAdministrator[UPDATE_FUNCTION_POSITION] = &UserInterface::updateVictimInterface;
	this->interfaceFunctionListAdministrator[DELETE_FUNCTION_POSITION] = &UserInterface::deleteVictimInterface;
	this->interfaceFunctionListAdministrator[LIST_FUNCTION_POSITION] = &UserInterface::listAllInterface;

	this->commandInfoAdministrator = "Insert command:\n";
	this->commandInfoAdministrator += "exit\n";
	this->commandInfoAdministrator += "add name, placeOfOrigin, age, photograph\n";
	this->commandInfoAdministrator += "update name, newPlaceOfOrigin, newAge, newPhotograph\n";
	this->commandInfoAdministrator += "delete name\n";
	this->commandInfoAdministrator += "list\n\n";


	this->validatorFunctionListAssistant[ADD_FUNCTION_POSITION] = &InputValidator::addVictimInputValidator;
	this->validatorFunctionListAssistant[UPDATE_FUNCTION_POSITION] = &InputValidator::updateVictimInputValidator;
	this->validatorFunctionListAssistant[DELETE_FUNCTION_POSITION] = &InputValidator::deleteVictimInputValidator;

	this->interfaceFunctionListAssistant[ADD_FUNCTION_POSITION] = &UserInterface::addVictimInterface;
	this->interfaceFunctionListAssistant[UPDATE_FUNCTION_POSITION] = &UserInterface::updateVictimInterface;
	this->interfaceFunctionListAssistant[DELETE_FUNCTION_POSITION] = &UserInterface::deleteVictimInterface;

	this->commandInfoAssistant = "Insert command:\n";
	this->commandInfoAssistant += "exit\n";
	this->commandInfoAssistant += "add name, placeOfOrigin, age, photograph\n";
	this->commandInfoAssistant += "update name, newPlaceOfOrigin, newAge, newPhotograph\n";
	this->commandInfoAssistant += "delete name\n\n";
}

void UserInterface::displayVictim(const Victim& currentVictim) {
	std::cout << currentVictim.getName() << " - " << currentVictim.getPlaceOfOrigin() << " - " << currentVictim.getAge() << " - " << currentVictim.getPhotographLink() << "\n";
}

void UserInterface::addVictimInterface(ArgumentList argumentList) {
	std::string victimName = argumentList.list[NAME_POSITION];
	std::string placeOfOrigin = argumentList.list[PLACE_OF_ORIGIN_POSITION];
	int age = stoi(argumentList.list[AGE_POSITION]);
	std::string photographLink = argumentList.list[PHOTOGRAPH_POSITION];
	
	try {
		this->actionController.addVictim(victimName, placeOfOrigin, age, photographLink);
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::updateVictimInterface(ArgumentList argumentList){
	std::string newVictimName = argumentList.list[NAME_POSITION];
	std::string newPlaceOfOrigin = argumentList.list[PLACE_OF_ORIGIN_POSITION];
	int newAge = stoi(argumentList.list[AGE_POSITION]);
	std::string newPhotographLink = argumentList.list[PHOTOGRAPH_POSITION];

	try {
		this->actionController.updateVictim(newVictimName, newPlaceOfOrigin, newAge, newPhotographLink);
	}
	catch (std::exception & operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::deleteVictimInterface(ArgumentList argumentList){
	std::string victimName = argumentList.list[NAME_POSITION];

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
			displayVictim((*victimList)[index]);
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
	else { // assistant mode
		validatorFunctionList = this->validatorFunctionListAssistant;
		interfaceFunctionList = this->interfaceFunctionListAssistant;
		numberOfCommands = NUMBER_OF_COMMANDS_ASSISTANT;
	}

	for (int currentCommand = 0; currentCommand < numberOfCommands && executedCommand == false; currentCommand++) {
		stringMatchResult = (inputValidator.*validatorFunctionList[currentCommand])(command);

		if (stringMatchResult.list[ERROR_POSITION] == ERROR_CODE) {
			continue;
		}

		executedCommand = true; // if we reach this point => the validation went well => we can perform the operation
		(this->*interfaceFunctionList[currentCommand])(stringMatchResult);
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