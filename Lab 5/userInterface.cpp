#include "userInterface.h"
#include <iostream>
#include <string.h>

UserInterface::UserInterface() {
	loadAdministratorModeContent();
	loadAssistantModeContent();
}

void UserInterface::loadAdministratorModeContent() {
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
}

void UserInterface::loadAssistantModeContent() {
	this->validatorFunctionListAssistant[NEXT_FUNCTION_POSITION] = &InputValidator::nextVictimInputValidator;
	this->validatorFunctionListAssistant[SAVE_FUNCTION_POSITION] = &InputValidator::saveVictimInputValidator;
	this->validatorFunctionListAssistant[LIST_FILTERED_FUNCTION_POSITION] = &InputValidator::listFilteredInputValidator;
	this->validatorFunctionListAssistant[MYLIST_FUNCTION_POSITION] = &InputValidator::myListInputValidator;

	this->interfaceFunctionListAssistant[NEXT_FUNCTION_POSITION] = &UserInterface::nextVictimInterface;
	this->interfaceFunctionListAssistant[SAVE_FUNCTION_POSITION] = &UserInterface::saveVictimInterface;
	this->interfaceFunctionListAssistant[LIST_FILTERED_FUNCTION_POSITION] = &UserInterface::listFilteredInterface;
	this->interfaceFunctionListAssistant[MYLIST_FUNCTION_POSITION] = &UserInterface::myListInterface;

	this->commandInfoAssistant = "Insert command:\n";
	this->commandInfoAssistant += "exit\n";
	this->commandInfoAssistant += "next\n";
	this->commandInfoAssistant += "save name\n";
	this->commandInfoAssistant += "list placeOfOrigin, age\n";
	this->commandInfoAssistant += "mylist\n\n";
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
	DynamicVector<TElem>* victimList;

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

void UserInterface::nextVictimInterface(ArgumentList argumentList){
	try {
		Victim nextVictim = this->actionController.getNextVictim();
		displayVictim(nextVictim);
	}
	catch (std::exception& operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::saveVictimInterface(ArgumentList argumentList){
	std::string victimName = argumentList.list[NAME_POSITION];

	try {
		this->actionController.saveVictim(victimName);
	}
	catch (std::exception& operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::listFilteredInterface(ArgumentList argumentList){
	DynamicVector<TElem> filteredVictimList;

	std::string placeOfOrigin = argumentList.list[NAME_POSITION];
	int age = stoi(argumentList.list[PLACE_OF_ORIGIN_POSITION]);

	try {
		filteredVictimList = this->actionController.getFilteredVictims(placeOfOrigin, age);
		for (int index = 0; index < filteredVictimList.getNumberOfElements(); index++) {
			displayVictim(filteredVictimList[index]);
		}
	}
	catch (std::exception& operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::myListInterface(ArgumentList argumentList){
	DynamicVector<TElem>* savedVictimList;

	try {
		savedVictimList = this->actionController.getSavedVictims();
		for (int index = 0; index < savedVictimList->getNumberOfElements(); index++) {
			displayVictim((*savedVictimList)[index]);
		}
	}
	catch (std::exception& operationException) {
		std::cout << operationException.what() << "\n";
	}
}

void UserInterface::processCommand(std::string command, char &programMode) {
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

	// apparently the mode may now be changed anywhere in the program
	try {
		programMode = inputValidator.modeValidator(command);
		executedCommand = true;
	}
	catch (...) {
		;
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

		if (command == "exit") {
			std::cout << "Program has ended\n";
			return;
		}

		try {
			programMode = inputValidator.modeValidator(command);
			break;
		}
		catch (std::exception& operationException) {
			std::cout << operationException.what() << "\n";
		}
	}
	
	while (1) {
		if (programMode == ADMINISTRATOR_MODE) {
			commandInfo = this->commandInfoAdministrator;
		}
		else {
			commandInfo = this->commandInfoAssistant;
		}

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