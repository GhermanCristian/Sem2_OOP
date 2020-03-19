#pragma once
#include "controller.h"

const int MAXIMUM_COMMAND_LENGTH = 200;

class UserInterface {
	private:
		Controller actionController;
		;// maybe an object of type InputValidator
	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};