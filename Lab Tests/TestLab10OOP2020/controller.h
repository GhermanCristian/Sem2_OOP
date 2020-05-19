#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		void addNeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfBabies, double averageGrade);
		void addSurgery(std::string hospitalName, int numberOfDoctors, int numberOfPatients);
		std::vector<HospitalDepartament*> getAllDepartaments();
		std::vector<HospitalDepartament*> getAllEfficientDepartaments();
		void writeToFile(std::string fileLocation);
		~Controller();
};

