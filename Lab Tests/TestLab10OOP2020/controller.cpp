#include "controller.h"
#include <fstream>

Controller::Controller(){
	;
}

void Controller::addNeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfBabies, double averageGrade){
	NeonatalUnit* newNeonatalUnit = new NeonatalUnit{ hospitalName, numberOfDoctors, numberOfMothers, numberOfBabies, averageGrade };
	this->elements.addDepartament(newNeonatalUnit);
}

void Controller::addSurgery(std::string hospitalName, int numberOfDoctors, int numberOfPatients){
	Surgery* newSurgery = new Surgery{ hospitalName, numberOfDoctors, numberOfPatients };
	this->elements.addDepartament(newSurgery);
}

std::vector<HospitalDepartament*> Controller::getAllDepartaments(){
	return this->elements.getAllEntries();
}

std::vector<HospitalDepartament*> Controller::getAllEfficientDepartaments(){
	std::vector<HospitalDepartament*> allData = this->elements.getAllEntries();
	std::vector<HospitalDepartament*> newData;

	for (auto departament : allData) {
		if (departament->isEfficient() == true) {
			newData.push_back(departament);
		}
	}

	return newData;
}

void Controller::writeToFile(std::string fileLocation){
	std::ofstream outputStream(fileLocation);
	std::vector<HospitalDepartament*> allDepartaments = this->elements.getAllEntries();

	for (auto departament : allDepartaments) {
		outputStream << departament->toString() << "\n";
	}

	outputStream.close();
}

Controller::~Controller(){
	;
}
