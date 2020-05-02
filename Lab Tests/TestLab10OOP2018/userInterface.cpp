#include "userInterface.h"
#include <iostream>
#include <fstream>

void UserInterface::addRefrigeratorInterface(){
	int uniqueID;
	int weight;
	std::string usageClass;
	bool hasFreezer;

	std::cin >> uniqueID >> weight >> usageClass >> hasFreezer;
	this->actionController.addRefrigerator(uniqueID, weight, usageClass, hasFreezer);
}

void UserInterface::addDishWashingMachineInterface(){
	int uniqueID;
	int weight;
	int washingCycleLength;
	int electricityPerHour;

	std::cin >> uniqueID >> weight >> washingCycleLength >> electricityPerHour;
	this->actionController.addDishWashingMachine(uniqueID, weight, washingCycleLength, electricityPerHour);
}

UserInterface::UserInterface(){
	;
}

void UserInterface::startProgram(){
	int command;

	while (true) {
		std::cout << "0. Exit\n";
		std::cout << "1. Add refrigerator (id weight usageClass hasFreezer)\n";
		std::cout << "2. Add dish washing machine (id weight washingCycleLength electricityPerHour\n";
		std::cout << "3. Show all appliances\n";
		std::cout << "4. Show sorted appliances\n";
		std::cout << "5. Save to file electricity < than\n";
		std::cout << "\n";
		std::cin >> command;

		if (command == 0) {
			std::cout << "Program has ended\n";
			return;
		}

		else if(command == 1) {
			try {
				this->addRefrigeratorInterface();
			}
			catch (std::exception& currentException) {
				std::cout << currentException.what() << "\n";
			}
		}

		else if (command == 2) {
			try {
				this->addDishWashingMachineInterface();
			}
			catch (std::exception& currentException) {
				std::cout << currentException.what() << "\n";
			}
		}

		else if (command == 3) {
			std::vector<Appliance*> allAppliances = this->actionController.getAllAppliances();
			for (auto currentAppliance : allAppliances) {
				std::cout << currentAppliance->toString() << "\n";
			}
		}

		else if (command == 4) {
			std::vector<Appliance*> sortedAppliances = this->actionController.getAppliancesSortedByWeight();
			for (auto currentAppliance : sortedAppliances) {
				std::cout << currentAppliance->toString() << "\n";
			}
		}

		else if (command == 5) {
			int maximumElectricity;
			std::cin >> maximumElectricity;
			std::ofstream outputStream("savedAppliances.txt");
			std::vector <Appliance*> filteredAppliances = this->actionController.getFilteredAppliances(maximumElectricity);
			for (auto currentAppliance : filteredAppliances) {
				outputStream << currentAppliance->toString() << "\n";
			}
			outputStream.close();
		}
	}
}

UserInterface::~UserInterface(){
	;
}
