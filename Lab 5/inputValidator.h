#pragma once
#include <string>
#include <regex>

class InputValidator {
	private:
		;
	public:
		InputValidator();
		std::smatch addVictimInputValidator(std::string userInput);
		std::smatch updateVictimInputValidator(std::string userInput);
		std::smatch deleteVictimInputValidator(std::string userInput);
		std::smatch listAllInputValidator(std::string userInput);
		~InputValidator();
};