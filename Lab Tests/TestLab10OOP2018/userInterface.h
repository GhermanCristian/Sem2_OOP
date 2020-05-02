#pragma once
#include "controller.h"

class UserInterface{
	private:
		Controller actionController;

		void addRefrigeratorInterface();
		void addDishWashingMachineInterface();

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};

