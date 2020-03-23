#pragma once
#include "controller.h"
#include "inputValidator.h"

typedef ArgumentList(InputValidator::* InputValidatorFunction)(std::string);

class UserInterface {
	typedef void (UserInterface::* InterfaceFunction)(ArgumentList);

	private:
		Controller actionController;
		InputValidator inputValidator;
		InputValidatorFunction validatorFunctionList[NUMBER_OF_COMMANDS];
		InterfaceFunction interfaceFunctionList[NUMBER_OF_COMMANDS];

		void displayVictim(Victim currentVictim);
		void addVictimInterface(ArgumentList argumentList);
		void updateVictimInterface(ArgumentList argumentList);
		void deleteVictimInterface(ArgumentList argumentList);
		void listAllInterface(ArgumentList argumentList);
		void processCommand(std::string command, char programMode);

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};