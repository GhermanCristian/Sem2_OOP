#pragma once
#include <string>
#include <regex>

const int NUMBER_OF_ARGUMENTS = 4;
const std::string ERROR_CODE = "ERROR";

struct ArgumentList {
	std::string list[NUMBER_OF_ARGUMENTS];
};

class InputValidator {
	private:
		;
	public:
		InputValidator();
		ArgumentList addVictimInputValidator(std::string userInput);
		ArgumentList updateVictimInputValidator(std::string userInput);
		ArgumentList deleteVictimInputValidator(std::string userInput);
		ArgumentList listAllInputValidator(std::string userInput);
		char modeValidator(std::string userInput);
		~InputValidator();
};