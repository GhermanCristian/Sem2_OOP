#include "inputValidator.h"
#include <iostream>
#include <exception>

InputValidator::InputValidator(){
	;
}

std::smatch InputValidator::addVictimInputValidator(std::string userInput) {
	std::regex addVictimPattern("add +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");

	std::smatch stringMatch;
	if (std::regex_search(userInput, stringMatch, addVictimPattern) == true) {
		return stringMatch;
	}

	else {
		throw std::exception("Invalid input");
	}
}

std::smatch InputValidator::updateVictimInputValidator(std::string userInput) {
	std::regex updateVictimPattern("update +([a-zA-Z]+( *[a-zA-Z]*)*), +([a-zA-Z]+( *[a-zA-Z]*)*), +([0-9]+), +([a-zA-Z.0-9]+)");

	std::smatch stringMatch;
	if (std::regex_search(userInput, stringMatch, updateVictimPattern) == true) {
		return stringMatch;
	}

	else {
		throw std::exception("Invalid input");
	}
}

std::smatch InputValidator::deleteVictimInputValidator(std::string userInput) {
	std::regex deleteVictimPattern("delete +([a-zA-Z]+( *[a-zA-Z]*)*)");

	std::smatch stringMatch;
	if (std::regex_search(userInput, stringMatch, deleteVictimPattern) == true) {
		return stringMatch;
	}

	else {
		throw std::exception("Invalid input");
	}
}

std::smatch InputValidator::listAllInputValidator(std::string userInput) {
	std::regex listAllPattern("list");

	std::smatch stringMatch;
	if (std::regex_search(userInput, stringMatch, listAllPattern) == true) {
		return stringMatch;
	}

	else {
		throw std::exception("Invalid input");
	}
}

InputValidator::~InputValidator(){
	;
}
