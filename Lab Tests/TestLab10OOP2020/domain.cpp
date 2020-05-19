#include "domain.h"

NeonatalUnit::NeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade){
	this->hospitalName = hospitalName;
	this->numberOfDoctors = numberOfDoctors;
	this->numberOfMothers = numberOfMothers;
	this->numberOfNewborns = numberOfNewborns;
	this->averageGrade = averageGrade;
}

bool NeonatalUnit::isEfficient(){
	const double LOWEST_OK_GRADE = 8.5;
	return (averageGrade > LOWEST_OK_GRADE and numberOfNewborns >= numberOfMothers);
}

std::string NeonatalUnit::toString(){
	std::string representation = "";
	representation += (hospitalName + ", ");
	representation += ("Neonatal Unit, ");
	representation += (std::to_string(numberOfDoctors) + ", ");
	representation += (std::to_string(numberOfMothers) + ", ");
	representation += (std::to_string(numberOfNewborns) + ", ");
	representation += (std::to_string(averageGrade) + ", ");
	if (isEfficient() == true)
		representation += ("efficient, ");
	else
		representation += ("not efficient, ");

	return representation;
}

Surgery::Surgery(std::string hospitalName, int numberOfDoctors, int numberOfPatients){
	this->hospitalName = hospitalName;
	this->numberOfDoctors = numberOfDoctors;
	this->numberOfPatients = numberOfPatients;
}

bool Surgery::isEfficient(){
	const double PATIENT_TO_DOCTOR_MINIMUM_RATIO = 2.0;
	return (numberOfPatients >= numberOfDoctors * PATIENT_TO_DOCTOR_MINIMUM_RATIO);
}

std::string Surgery::toString(){
	std::string representation = "";
	representation += (hospitalName + ", ");
	representation += ("Surgery, ");
	representation += (std::to_string(numberOfDoctors) + ", ");
	representation += (std::to_string(numberOfPatients) + ", ");
	if (isEfficient() == true)
		representation += ("efficient, ");
	else
		representation += ("not efficient, ");

	return representation;
}
