#include "inputValidator.h"
#include <iostream>
#include <exception>

InputValidator::InputValidator(){
	;
}

ArgumentList InputValidator::addVictimInputValidator(std::string userInput) {
	std::regex addVictimPattern("add +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");
	std::smatch stringMatch;
	ArgumentList addArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, addVictimPattern);

	if (validInput == false) {
		addArgumentList.list[0] = ERROR_CODE;
		return addArgumentList;
	}

	addArgumentList.list[0] = stringMatch.str(1);
	addArgumentList.list[1] = stringMatch.str(3);
	addArgumentList.list[2] = stringMatch.str(5);
	addArgumentList.list[3] = stringMatch.str(6);

	return addArgumentList;
}

ArgumentList InputValidator::updateVictimInputValidator(std::string userInput) {
	std::regex updateVictimPattern("update +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");
	std::smatch stringMatch;
	ArgumentList updateArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, updateVictimPattern);

	if (validInput == false) {
		updateArgumentList.list[0] = ERROR_CODE;
		return updateArgumentList;
	}

	updateArgumentList.list[0] = stringMatch.str(1);
	updateArgumentList.list[1] = stringMatch.str(3);
	updateArgumentList.list[2] = stringMatch.str(5);
	updateArgumentList.list[3] = stringMatch.str(6);

	return updateArgumentList;
}

ArgumentList InputValidator::deleteVictimInputValidator(std::string userInput) {
	std::regex deleteVictimPattern("delete +([a-zA-Z]+( *[a-zA-Z]*)*)");
	std::smatch stringMatch;
	ArgumentList deleteArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, deleteVictimPattern);

	if (validInput == false) {
		deleteArgumentList.list[0] = ERROR_CODE;
		return deleteArgumentList;
	}

	deleteArgumentList.list[0] = stringMatch.str(1);

	return deleteArgumentList;
}

ArgumentList InputValidator::listAllInputValidator(std::string userInput) {
	std::regex listAllPattern("list");
	std::smatch stringMatch;
	ArgumentList listAllArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, listAllPattern);

	if (validInput == false) {
		listAllArgumentList.list[0] = ERROR_CODE;
		return listAllArgumentList;
	}
	
	return listAllArgumentList;
}

char InputValidator::modeValidator(std::string userInput){
	std::regex modePattern("mode [AB]");
	std::smatch stringMatch;
	bool validInput = std::regex_search(userInput, stringMatch, modePattern);

	if (validInput == false) {
		throw std::exception("Invalid input");
	}

	return userInput.back();
}

InputValidator::~InputValidator(){
	;
}
