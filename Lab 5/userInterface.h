#pragma once
/*#include "controller.h"
#include "inputValidator.h"

typedef ArgumentList(InputValidator::* InputValidatorFunction)(std::string);
const int MAXIMUM_COMMAND_LENGTH = 200;
const int NUMBER_OF_COMMANDS_ADMINISTRATOR = 4;
const int NUMBER_OF_COMMANDS_ASSISTANT = 4;

const int ADD_FUNCTION_POSITION = 0;
const int UPDATE_FUNCTION_POSITION = 1;
const int DELETE_FUNCTION_POSITION = 2;
const int LIST_FUNCTION_POSITION = 3;

const int NEXT_FUNCTION_POSITION = 0;
const int SAVE_FUNCTION_POSITION = 1;
const int LIST_FILTERED_FUNCTION_POSITION = 2;
const int MYLIST_FUNCTION_POSITION = 3;

const char ADMINISTRATOR_MODE = 'A';
const char ASSISTANT_MODE = 'B';

class UserInterface {
	typedef void (UserInterface::* InterfaceFunction)(ArgumentList);

	private:
		Controller actionController;
		InputValidator inputValidator;

		// the administrator/ assistant modes have different sets of commands (so different sets of input validators
		// and different command information)
		InputValidatorFunction validatorFunctionListAdministrator[NUMBER_OF_COMMANDS_ADMINISTRATOR];
		InterfaceFunction interfaceFunctionListAdministrator[NUMBER_OF_COMMANDS_ADMINISTRATOR];
		std::string commandInfoAdministrator;

		InputValidatorFunction validatorFunctionListAssistant[NUMBER_OF_COMMANDS_ASSISTANT];
		InterfaceFunction interfaceFunctionListAssistant[NUMBER_OF_COMMANDS_ASSISTANT];
		std::string commandInfoAssistant;

		void loadAdministratorModeContent();
		void loadAssistantModeContent();
		void displayVictim(const Victim& currentVictim);
		void addVictimInterface(ArgumentList argumentList);
		void updateVictimInterface(ArgumentList argumentList);
		void deleteVictimInterface(ArgumentList argumentList);
		void listAllInterface(ArgumentList argumentList);
		void nextVictimInterface(ArgumentList argumentList);
		void saveVictimInterface(ArgumentList argumentList);
		void listFilteredInterface(ArgumentList argumentList);
		void myListInterface(ArgumentList argumentList);
		void processCommand(std::string command, char& programMode);

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};*/