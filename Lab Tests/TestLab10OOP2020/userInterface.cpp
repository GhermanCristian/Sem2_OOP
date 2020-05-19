#include "userInterface.h"
#include <iostream>

void UserInterface::addNeonatalInterface(std::string command){
	int pos = 4;
	int length = command.length();
	int currentArgumentPosition = 0;
	int lastArgumentStart = 4;
	const int ARGUMENT_COUNT = 6;
	std::string arguments[ARGUMENT_COUNT];
	while (pos + 1 < length) {
		if (command[pos] == ',' and command[pos + 1] == ' ') {
			arguments[currentArgumentPosition] = command.substr(lastArgumentStart, pos - lastArgumentStart);
			currentArgumentPosition++;
			lastArgumentStart = pos + 2;
		}
		pos++;
	}
	arguments[currentArgumentPosition] = command.substr(lastArgumentStart, length - lastArgumentStart);
	this->actionController.addNeonatalUnit(arguments[0], stoi(arguments[2]), stoi(arguments[3]), stoi(arguments[4]), stod(arguments[5]));
}

void UserInterface::addSurgeryInterface(std::string command){
	int pos = 4;
	int length = command.length();
	int currentArgumentPosition = 0;
	int lastArgumentStart = 4;
	const int ARGUMENT_COUNT = 4;
	std::string arguments[ARGUMENT_COUNT];
	while (pos + 1 < length) {
		if (command[pos] == ',' and command[pos + 1] == ' ') {
			arguments[currentArgumentPosition] = command.substr(lastArgumentStart, pos - lastArgumentStart);
			currentArgumentPosition++;
			lastArgumentStart = pos + 2;
		}
		pos++;
	}

	arguments[currentArgumentPosition] = command.substr(lastArgumentStart, length - lastArgumentStart);
	this->actionController.addSurgery(arguments[0], stoi(arguments[2]), stoi(arguments[3]));
}

UserInterface::UserInterface(){
	;
}

void UserInterface::startProgram(){
	std::string command;

	while (true) {
		std::cout << "0. Exit\n";
		std::cout << "1. add hospitalName, departmentType, numberOfDoctors, numberOfPatients\n";
		std::cout << "2. add hospitalName, departmentType, numberOfDoctors, numberOfMothers, numberOfBabies, averageGrade\n";
		std::cout << "3. list\n";
		std::cout << "4. filelocation\n";
		std::cout << "\n";
		std::getline(std::cin, command);

		if (command == "exit") {
			std::cout << "Program has ended\n";
			return;
		}

		if (command == "list") {
			std::vector<HospitalDepartament*> allDepartaments = this->actionController.getAllDepartaments();
			for (auto departament : allDepartaments) {
				std::cout << departament->toString() << "\n";
			}
		}

		else if (command == "list efficient") {
			std::vector<HospitalDepartament*> allEfficientDepartaments = this->actionController.getAllEfficientDepartaments();
			for (auto departament : allEfficientDepartaments) {
				std::cout << departament->toString() << "\n";
			}
		}

		else if (command.find("Neonatal Unit") != std::string::npos) {
			addNeonatalInterface(command);
		}

		else if (command.find("Surgery") != std::string::npos) {
			addSurgeryInterface(command);
		}

		else if (command.find("fileLocation") != std::string::npos) {
			int commandLength = command.length();
			const int FILE_PATH_FIRST_POSITION = 12;
			std::string fileLocation = command.substr(FILE_PATH_FIRST_POSITION, commandLength - FILE_PATH_FIRST_POSITION);
			this->actionController.writeToFile(fileLocation);
		}
		
	}
}

UserInterface::~UserInterface(){
	;
}
