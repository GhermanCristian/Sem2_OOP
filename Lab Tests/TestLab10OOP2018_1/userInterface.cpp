#include "userInterface.h"
#include <iostream>

UserInterface::UserInterface() {
	;
}

void UserInterface::addBMIAnalysisInterface(std::string analysisDate){
	double BMIValue;
	std::cout << "BMI analysis (BMIvalue)\n";
	std::cin >> BMIValue;
	this->actionController.addBMIAnalysis(analysisDate, BMIValue);
}

void UserInterface::addBPAnalysisInterface(std::string analysisDate){
	int systolicValue;
	int diastolicValue;
	std::cout << "analysis (systolicValue diastolicValue)\n";
	std::cin >> systolicValue >> diastolicValue;
	this->actionController.addBPAnalysis(analysisDate, systolicValue, diastolicValue);
}

void UserInterface::addAnalysisInterface(){
	std::string analysisType;
	std::string analysisDate;
	const std::string BMI_ANALYSIS_NAME = "BMI";
	const std::string BP_ANALYSIS_NAME = "BP";
	std::cin >> analysisType >> analysisDate;

	if (analysisType == BMI_ANALYSIS_NAME) {
		this->addBMIAnalysisInterface(analysisDate);
	}
	else if (analysisType == BP_ANALYSIS_NAME) {
		this->addBPAnalysisInterface(analysisDate);
	}
}

void UserInterface::getAllAnalysesInterface(){
	std::vector <MedicalAnalysis*> allAnalysis = this->actionController.getAllAnalysis();
	for (auto currentAnalysis : allAnalysis) {
		std::cout << currentAnalysis->toString() << "\n";
	}
}

void UserInterface::isPersonIllInterface(){
	std::string analysisMonth;
	std::cin >> analysisMonth;
	if (this->actionController.isPersonIll(analysisMonth) == true) {
		std::cout << "Person is ill\n";
	}
	else {
		std::cout << "Person is not ill\n";
	}
}

void UserInterface::writeToFileTheAnalysesBetweenDatesInterface(){
	std::string firstDate; // has to be <= secondDate
	std::string secondDate;
	std::string fileName;
	std::cout << "filename firstDate secondDate\n";
	std::cin >> fileName >> firstDate >> secondDate;
	this->actionController.writeAnalysesToFile(fileName, firstDate, secondDate);
}

void UserInterface::startProgram(){
	int command;

	while (true) {
		std::cout << "0. Exit\n";
		std::cout << "1. Add analysis (type yyyy.mm.dd)\n";
		std::cout << "2. Get all analysis\n";
		std::cout << "3. Check if person is ill (month)\n";
		std::cout << "4. Write to file the analyses between two dates (yyyy.mm.dd yyyy.mm.dd)\n";
		std::cout << "\n";
		std::cin >> command;

		if (command == 0) {
			std::cout << "Program has ended\n";
			return;
		}
		else if (command == 1) {
			this->addAnalysisInterface();
		}
		else if (command == 2) {
			this->getAllAnalysesInterface();
		}
		else if (command == 3) {
			this->isPersonIllInterface();
		}
		else if (command == 4) {
			this->writeToFileTheAnalysesBetweenDatesInterface();
		}
	}
}

UserInterface::~UserInterface(){
	;
}
