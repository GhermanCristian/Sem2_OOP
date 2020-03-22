#pragma once
#include "controller.h"
#include "inputValidator.h"

const int MAXIMUM_COMMAND_LENGTH = 200;
const int NUMBER_OF_COMMANDS = 4;
typedef std::smatch(*InputValidatorFunction)(std::string);

class UserInterface {
	private:
		Controller actionController;
		InputValidator inputValidator;
		InputValidatorFunction functionList[NUMBER_OF_COMMANDS];

		void processCommand(std::string command, char programMode);

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};