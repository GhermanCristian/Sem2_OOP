#include "inputValidator.h"
#include <iostream>
#include <exception>

InputValidator::InputValidator(){
	;
}

ArgumentList InputValidator::addVictimInputValidator(std::string userInput) {
	std::regex addVictimPattern("add +(([a-zA-Z0-9]+ *)+), +(([a-zA-Z0-9]+ *)+), +([0-9]+), +([a-zA-Z.0-9]+)");
	/*
		1 "add" word
		1 or more spaces

		=== VICTIM NAME ===
		1 or more times: (name can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces

		1 "," symbol
		1 or more spaces

		=== VICTIM PLACE OF ORIGIN ===
		1 or more times: (place of origin can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces

		1 "," symbol
		1 or more spaces

		=== VICTIM AGE ===
		1 or more digits

		1 "," symbol
		1 or more spaces

		=== VICTIM PHOTOGRAPH LINK ===
		1 or more uppercase/ lowercase letters, digits or the dot "." symbol
	*/
	
	std::smatch stringMatch;
	ArgumentList addArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, addVictimPattern);

	if (validInput == false) {
		addArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		addArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
		addArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
		addArgumentList.list[AGE_POSITION] = stringMatch.str(THIRD_ARGUMENT_REGEX_POSITION);
		addArgumentList.list[PHOTOGRAPH_POSITION] = stringMatch.str(FOURTH_ARGUMENT_REGEX_POSITION);
	}

	return addArgumentList;
}

ArgumentList InputValidator::updateVictimInputValidator(std::string userInput) {
	std::regex updateVictimPattern("update +(([a-zA-Z0-9]+ *)+), +(([a-zA-Z0-9]+ *)+), +([0-9]+), +([a-zA-Z.0-9]+)");
	/*
		1 "update" word
		1 or more spaces

		=== VICTIM NAME ===
		1 or more times: (name can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces

		1 "," symbol
		1 or more spaces

		=== NEW VICTIM PLACE OF ORIGIN ===
		1 or more times: (place of origin can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces

		1 "," symbol
		1 or more spaces

		=== NEW VICTIM AGE ===
		1 or more digits

		1 "," symbol
		1 or more spaces

		=== NEW VICTIM PHOTOGRAPH LINK ===
		1 or more uppercase/ lowercase letters, digits or the dot "." symbol
	*/
	
	std::smatch stringMatch;
	ArgumentList updateArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, updateVictimPattern);

	if (validInput == false) {
		updateArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		updateArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
		updateArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
		updateArgumentList.list[AGE_POSITION] = stringMatch.str(THIRD_ARGUMENT_REGEX_POSITION);
		updateArgumentList.list[PHOTOGRAPH_POSITION] = stringMatch.str(FOURTH_ARGUMENT_REGEX_POSITION);
	}

	return updateArgumentList;
}

ArgumentList InputValidator::deleteVictimInputValidator(std::string userInput) {
	std::regex deleteVictimPattern("delete +(([a-zA-Z0-9]+ *)+)");
	/*
		1 "delete" word
		1 or more spaces

		=== VICTIM NAME ===
		1 or more times: (name can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces
	*/

	std::smatch stringMatch;
	ArgumentList deleteArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, deleteVictimPattern);

	if (validInput == false) {
		deleteArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		deleteArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
	}

	return deleteArgumentList;
}

ArgumentList InputValidator::listAllInputValidator(std::string userInput) {
	std::regex listAllPattern("^list$");
	/*
		1 "list" word
	*/

	std::smatch stringMatch;
	ArgumentList listAllArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, listAllPattern);

	if (validInput == false) {
		listAllArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		;
	}
	
	return listAllArgumentList;
}

ArgumentList InputValidator::nextVictimInputValidator(std::string userInput)
{
	std::regex nextVictimPattern("^next$");
	/*
		1 "next" word
	*/

	std::smatch stringMatch;
	ArgumentList nextVictimArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, nextVictimPattern);

	if (validInput == false) {
		nextVictimArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		;
	}

	return nextVictimArgumentList;
}

ArgumentList InputValidator::saveVictimInputValidator(std::string userInput)
{
	std::regex saveVictimPattern("save +(([a-zA-Z0-9]+ *)+)");
	/*
		1 "save" word
		1 or more spaces

		=== VICTIM NAME ===
		1 or more times: (name can be composed of more than 1 word)
			1 or more uppercase/ lowercase letters or digits
			0 or more spaces
	*/

	std::smatch stringMatch;
	ArgumentList saveVictimArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, saveVictimPattern);

	if (validInput == false) {
		saveVictimArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		saveVictimArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
	}

	return saveVictimArgumentList;
}

ArgumentList InputValidator::listFilteredInputValidator(std::string userInput)
{
	std::regex listFilteredPattern("list +(([a-zA-Z0-9]+ *)+)?, +([0-9]+)");
	/*
		1 "list" word
		1 or more spaces

		=== VICTIM PLACE OF ORIGIN ===
		0 or 1 time(s): (because the place of origin might be left empty)
			1 or more times: (name can be composed of more than 1 word)
				1 or more uppercase/ lowercase letters or digits
				0 or more spaces

		1 or more spaces
		1 "," symbol

		=== VICTIM AGE ===
		1 or more digits
	*/

	std::smatch stringMatch;
	ArgumentList listFilteredArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, listFilteredPattern);

	if (validInput == false) {
		listFilteredArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		listFilteredArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
		listFilteredArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
	}

	return listFilteredArgumentList;
}

ArgumentList InputValidator::myListInputValidator(std::string userInput)
{
	std::regex myListPattern("^mylist$");
	/*
		1 "mylist" word
	*/

	std::smatch stringMatch;
	ArgumentList myListArgumentList;
	bool validInput = std::regex_search(userInput, stringMatch, myListPattern);

	if (validInput == false) {
		myListArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		;
	}

	return myListArgumentList;
}

char InputValidator::modeValidator(std::string userInput){
	std::regex modePattern("mode [AB]");
	/*
		1 "mode" word
		1 space
		either of the letters A or B, exactly once
	*/

	std::smatch stringMatch;
	bool validInput = std::regex_search(userInput, stringMatch, modePattern);

	if (validInput == false) {
		throw std::exception("Invalid mode");
	}

	return userInput.back();
}

ArgumentList InputValidator::CSVFileVictimValidator(std::string victimLine){
	std::regex CSVFileVictimPattern("(([a-zA-Z0-9]+ *)+), +(([a-zA-Z0-9]+ *)+), +([0-9]+), +([a-zA-Z.0-9]+)");
	std::smatch stringMatch;
	bool validInput = std::regex_search(victimLine, stringMatch, CSVFileVictimPattern);
	ArgumentList victimPropertiesArgumentList;

	if (validInput == false) {
		victimPropertiesArgumentList.list[ERROR_POSITION] = ERROR_CODE;
	}
	else {
		victimPropertiesArgumentList.list[NAME_POSITION] = stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
		victimPropertiesArgumentList.list[PLACE_OF_ORIGIN_POSITION] = stringMatch.str(SECOND_ARGUMENT_REGEX_POSITION);
		victimPropertiesArgumentList.list[AGE_POSITION] = stringMatch.str(THIRD_ARGUMENT_REGEX_POSITION);
		victimPropertiesArgumentList.list[PHOTOGRAPH_POSITION] = stringMatch.str(FOURTH_ARGUMENT_REGEX_POSITION);
	}

	return victimPropertiesArgumentList;
}

std::string InputValidator::fileLocationValidator(std::string userInput){
	std::regex fileLocationPattern("([a-zA-Z]:(\\([a-zA-Z0-9.]+ *)+))");
	std::smatch stringMatch;
	bool validInput = std::regex_search(userInput, stringMatch, fileLocationPattern);

	if (validInput == false) {
		throw std::exception("Invalid file location");
	}
	else {
		return stringMatch.str(FIRST_ARGUMENT_REGEX_POSITION);
	}
}

InputValidator::~InputValidator(){
	;
}
