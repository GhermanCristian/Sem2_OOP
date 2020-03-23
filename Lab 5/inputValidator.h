#pragma once
#include <string>
#include <regex>

const int MAXIMUM_COMMAND_LENGTH = 200;
const int NUMBER_OF_COMMANDS = 4;

struct ArgumentList {
	std::string list[NUMBER_OF_COMMANDS];
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