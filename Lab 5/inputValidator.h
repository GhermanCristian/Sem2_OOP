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
		/*
			Constructor for the InputValidator class
			Input:
				- None
			Output:
				- Creates a new object of this type
			Throws:
				- None
		*/

		ArgumentList addVictimInputValidator(std::string userInput);
		/*
			Validates the input for "addVictim"
			Input:
				- The user's input
			Output:
				- The arguments of the command, split in an ArgumentList (array of strings), if the command is valid
				- An error code, if the command is invalid
			Throws:
				- None
		*/

		ArgumentList updateVictimInputValidator(std::string userInput);
		/*
			Validates the input for "updateVictim"
			Input:
				- The user's input
			Output:
				- The arguments of the command, split in an ArgumentList (array of strings), if the command is valid
				- An error code, if the command is invalid
			Throws:
				- None
		*/

		ArgumentList deleteVictimInputValidator(std::string userInput);
		/*
			Validates the input for "deleteVictim"
			Input:
				- The user's input
			Output:
				- The arguments of the command, split in an ArgumentList (array of strings), if the command is valid
				- An error code, if the command is invalid
			Throws:
				- None
		*/

		ArgumentList listAllInputValidator(std::string userInput);
		/*
			Validates the input for "listAllVictims"
			Input:
				- The user's input
			Output:
				- The arguments of the command, split in an ArgumentList (array of strings), if the command is valid
				- An error code, if the command is invalid
			Throws:
				- None
		*/

		char modeValidator(std::string userInput);
		/*
			Validates the input for choosing the program mode
			Input:
				- The user's input
			Output:
				- The symbol corresponding to the chosen mode
			Throws:
				- Exception, if the input is invalid
		*/

		~InputValidator();
		/*
			Destructor for the InputValidator type
			Input:
				- None
			Output:
				- Destroys the current object
			Throws:
				- None
		*/

};