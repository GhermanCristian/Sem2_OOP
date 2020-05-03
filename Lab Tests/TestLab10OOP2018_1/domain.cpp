#include "domain.h"

BMIAnalysis::BMIAnalysis(std::string analysisDate, double value){
	this->analysisDate = analysisDate;
	this->value = value;
}

bool BMIAnalysis::isResultOK(){
	const double LOWEST_OK_VALUE = 18.5;
	const double HIGHEST_OK_VALUE = 25;
	return (LOWEST_OK_VALUE <= this->value and this->value <= HIGHEST_OK_VALUE);
}

std::string BMIAnalysis::toString(){
	std::string representation = "";
	representation += ("Date: " + analysisDate + ", ");
	representation += ("BMIValue: " + std::to_string(this->value) + ", ");
	representation += ("ResultOK? " + std::to_string(this->isResultOK()));
	return representation;
}

BPAnalysis::BPAnalysis(std::string analysisDate, int systolicValue, int diastolicValue){
	this->analysisDate = analysisDate;
	this->systolicValue = systolicValue;
	this->diastolicValue = diastolicValue;
}

bool BPAnalysis::isResultOK(){
	const int LOWEST_OK_SYSTOLIC_VALUE = 90;
	const int HIGHEST_OK_SYSTOLIC_VALUE = 119;
	const int LOWEST_OK_DIASTOLIC_VALUE = 60;
	const int HIGHEST_OK_DIASTOLIC_VALUE = 79;

	return (LOWEST_OK_SYSTOLIC_VALUE <= systolicValue and systolicValue <= HIGHEST_OK_SYSTOLIC_VALUE and LOWEST_OK_DIASTOLIC_VALUE <= diastolicValue and diastolicValue <= HIGHEST_OK_DIASTOLIC_VALUE);
}

std::string BPAnalysis::toString(){
	std::string representation = "";
	representation += ("Date: " + analysisDate + ", ");
	representation += ("SystolicValue: " + std::to_string(this->systolicValue) + ", ");
	representation += ("DiastolicValue: " + std::to_string(this->diastolicValue) + ", ");
	representation += ("ResultOK? " + std::to_string(this->isResultOK()));
	return representation;
}

bool MedicalAnalysis::sameMonth(std::string analysisMonth){
	const int CURRENT_MONTH_STRING_STARTING_POSITION = 5;
	const int CURRENT_MONTH_STRING_LENGTH = 2;
	std::string currentMonth = analysisDate.substr(CURRENT_MONTH_STRING_STARTING_POSITION, CURRENT_MONTH_STRING_LENGTH);
	return currentMonth == analysisMonth;
}

std::string MedicalAnalysis::getDate(){
	return this->analysisDate;
}
