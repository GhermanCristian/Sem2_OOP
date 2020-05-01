#include "userInterface.h"
#include <iostream>
#include <fstream>
#include <string>

void UserInterface::addHelicopterInterface(){
	bool isPrivate;
	std::cout << "isPrivate\n";
	std::cin >> isPrivate;
	std::cin.get();
	this->actionController.addHelicopter(isPrivate);
}

void UserInterface::addPlaneInterface(){
	bool isPrivate;
	std::string wingType;
	std::cout << "isPrivate wingType\n";
	std::cin >> isPrivate >> wingType;
	std::cin.get();
	this->actionController.addPlane(isPrivate, wingType);
}

void UserInterface::addHotAirBalloonInterface(){
	int weightLimit;
	std::cout << "weightLimit\n";
	std::cin >> weightLimit;
	std::cin.get();
	this->actionController.addHotAirBalloon(weightLimit);
}

void UserInterface::displayAircraftByActivity(){
	std::string activity;
	std::string filePath;
	std::cout << "activity\n";
	std::cin >> activity;
	filePath = activity + ".txt";
	std::cin.get();
	std::vector <Aircraft*> filteredData = this->actionController.filterByActivity(activity);
	for (auto currentAircraft : filteredData) {
		std::cout << currentAircraft->getAircraftRepresentation();
	}
	this->displayToFile(filePath, filteredData);
}

void UserInterface::displayAircraftByAltitude(){
	int altitude;
	std::cout << "altitude\n";
	std::cin >> altitude;
	std::cin.get();
	std::vector <Aircraft*> filteredData = this->actionController.filterByAltitude(altitude);
	for (auto currentAircraft : filteredData) {
		std::cout << currentAircraft->getAircraftRepresentation();
	}
}

void UserInterface::displayToFile(std::string filePath, std::vector<Aircraft*> filteredAircrafts){
	std::ofstream fileOutput(filePath);
	for (auto currentAircraft : filteredAircrafts) {
		fileOutput << currentAircraft->getAircraftRepresentation();
	}
	fileOutput.close();
}

void UserInterface::startProgram(){
	std::string command;

	while (true) {
		std::cout << "0. Exit\n";
		std::cout << "1. Add helicopter\n";
		std::cout << "2. Add plane\n";
		std::cout << "3. Add hot air baloon\n";
		std::cout << "4. Display by activity\n";
		std::cout << "5. Display by altitude\n\n";
		std::getline(std::cin, command);

		if (command == "0") {
			std::cout << "program has ended\n";
			return;
		}

		if (command == "1") {
			this->addHelicopterInterface();
		}

		else if (command == "2") {
			this->addPlaneInterface();
		}

		else if (command == "3") {
			this->addHotAirBalloonInterface();
		}

		else if (command == "4") {
			this->displayAircraftByActivity();
		}

		else if (command == "5") {
			this->displayAircraftByAltitude();
		}
	}
}
