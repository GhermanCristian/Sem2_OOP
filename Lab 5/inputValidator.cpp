#include "inputValidator.h"
#include <iostream>
#include <exception>

InputValidator::InputValidator(){
	;
}

ArgumentList InputValidator::addVictimInputValidator(std::string userInput) {
	std::regex addVictimPattern("add +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");
	/*
		1 "add" word

		=== VICTIM NAME ===
		1 or more spaces
		1 or more uppercase/ lowercase letters
		0 or more times:
			0 or more spaces
			0 or more uppercase/ lowercase letters
		1 "," symbol

		=== VICTIM PLACE OF ORIGIN ===
		1 or more spaces
		1 or more uppercase/ lowercase letters
		0 or more times:
			0 or more spaces
			0 or more uppercase/ lowercase letters
		1 "," symbol

		=== VICTIM AGE ===
		1 or more digits
		1 "," symbol

		=== VICTIM PHOTOGRAPH LINK ===
		1 or more spaces
		1 or more uppercase/ lowercase letters, digits or the dot "." symbol
	*/
	
	std::smatch stringMatch;
	ArgumentList addArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, addVictimPattern);

	if (validInput == false) {
		addArgumentList.list[ERROR_POSITION] = ERROR_CODE;
		return addArgumentList;
	}

	addArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
	addArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
	addArgumentList.list[AGE_POSITION] = stringMatch.str(THIRD_ARGUMENT_REGEX_POSITION);
	addArgumentList.list[PHOTOGRAPH_POSITION] = stringMatch.str(FOURTH_ARGUMENT_REGEX_POSITION);

	return addArgumentList;
}

ArgumentList InputValidator::updateVictimInputValidator(std::string userInput) {
	std::regex updateVictimPattern("update +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");
	/*
		1 "update" word

		=== VICTIM NAME ===
		1 or more spaces
		1 or more uppercase/ lowercase letters
		0 or more times:
			0 or more spaces
			0 or more uppercase/ lowercase letters
		1 "," symbol

		=== NEW VICTIM PLACE OF ORIGIN ===
		1 or more spaces
		1 or more uppercase/ lowercase letters
		0 or more times:
			0 or more spaces
			0 or more uppercase/ lowercase letters
		1 "," symbol

		=== NEW VICTIM AGE ===
		1 or more digits
		1 "," symbol

		=== NEW VICTIM PHOTOGRAPH LINK ===
		1 or more spaces
		1 or more uppercase/ lowercase letters, digits or the dot "." symbol
	*/
	
	std::smatch stringMatch;
	ArgumentList updateArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, updateVictimPattern);

	if (validInput == false) {
		updateArgumentList.list[ERROR_POSITION] = ERROR_CODE;
		return updateArgumentList;
	}

	updateArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
	updateArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
	updateArgumentList.list[AGE_POSITION] = stringMatch.str(THIRD_ARGUMENT_REGEX_POSITION);
	updateArgumentList.list[PHOTOGRAPH_POSITION] = stringMatch.str(FOURTH_ARGUMENT_REGEX_POSITION);

	return updateArgumentList;
}

ArgumentList InputValidator::deleteVictimInputValidator(std::string userInput) {
	std::regex deleteVictimPattern("delete +([a-zA-Z]+( *[a-zA-Z]*)*)");
	/*
		1 "delete" word

		=== VICTIM NAME ===
		1 or more spaces
		1 or more uppercase/ lowercase letters
		0 or more times:
			0 or more spaces
			0 or more uppercase/ lowercase letters
	*/

	std::smatch stringMatch;
	ArgumentList deleteArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, deleteVictimPattern);

	if (validInput == false) {
		deleteArgumentList.list[ERROR_POSITION] = ERROR_CODE;
		return deleteArgumentList;
	}

	deleteArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);

	return deleteArgumentList;
}

ArgumentList InputValidator::listAllInputValidator(std::string userInput) {
	std::regex listAllPattern("list");
	/*
		1 "list" word
	*/

	std::smatch stringMatch;
	ArgumentList listAllArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, listAllPattern);

	if (validInput == false) {
		listAllArgumentList.list[ERROR_POSITION] = ERROR_CODE;
		return listAllArgumentList;
	}
	
	return listAllArgumentList;
}

char InputValidator::modeValidator(std::string userInput){
	std::regex modePattern("mode [AB]");
	/*
		1 "mode" word
		either of the letters A or B, exactly once
	*/

	std::smatch stringMatch;
	bool validInput = std::regex_search(userInput, stringMatch, modePattern);

	if (validInput == false) {
		throw std::exception("Invalid mode");
	}

	return userInput.back();
}

InputValidator::~InputValidator(){
	;
}
