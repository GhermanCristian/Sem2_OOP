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

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		ArgumentList addVictimInputValidator(std::string userInput);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		ArgumentList updateVictimInputValidator(std::string userInput);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		ArgumentList deleteVictimInputValidator(std::string userInput);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		ArgumentList listAllInputValidator(std::string userInput);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		char modeValidator(std::string userInput);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		~InputValidator();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

};