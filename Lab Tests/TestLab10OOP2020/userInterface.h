#pragma once
#include "controller.h"

class UserInterface{
	private:
		Controller actionController;
		void addNeonatalInterface(std::string command);
		void addSurgeryInterface(std::string command);

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};

