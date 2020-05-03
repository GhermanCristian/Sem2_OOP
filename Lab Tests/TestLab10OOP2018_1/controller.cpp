#include "controller.h"
#include <fstream>

Controller::Controller(){
	;
}

void Controller::addBMIAnalysis(std::string analysisDate, double BMIValue){
	BMIAnalysis* newAnalysis = new BMIAnalysis{ analysisDate, BMIValue };
	this->elements.addAnalysis(newAnalysis);
}

void Controller::addBPAnalysis(std::string analysisDate, int systolicValue, int diastolicValue){
	BPAnalysis* newAnalysis = new BPAnalysis{ analysisDate, systolicValue, diastolicValue };
	this->elements.addAnalysis(newAnalysis);
}

std::vector<MedicalAnalysis*> Controller::getAllAnalysis(){
	return this->elements.getAllEntries();
}

std::vector<MedicalAnalysis*> Controller::getAnalysesBetweenTwoDates(std::string firstDate, std::string secondDate){
	std::vector <MedicalAnalysis*> allAnalyses = this->elements.getAllEntries();
	std::vector <MedicalAnalysis*> analysesBetweenDates;

	for (auto currentAnalysis : allAnalyses) {
		if (firstDate <= currentAnalysis->getDate() and currentAnalysis->getDate() <= secondDate) {
			analysesBetweenDates.push_back(currentAnalysis);
		}
	}

	return analysesBetweenDates;
}

std::vector<MedicalAnalysis*> Controller::getAnalysesFromMonth(std::string analysisMonth){
	std::vector <MedicalAnalysis*> allAnalyses = this->elements.getAllEntries();
	std::vector <MedicalAnalysis*> analysesFromMonth;

	for (auto currentAnalysis : allAnalyses) {
		if (currentAnalysis->sameMonth(analysisMonth) == true) {
			analysesFromMonth.push_back(currentAnalysis);
		}
	}

	return analysesFromMonth;
}

void Controller::writeAnalysesToFile(std::string fileName, std::string firstDate, std::string secondDate){
	std::vector<MedicalAnalysis*> analysisBetweenDates = this->getAnalysesBetweenTwoDates(firstDate, secondDate);

	std::ofstream outputStream(fileName);
	for (auto currentAnalysis : analysisBetweenDates) {
		outputStream << currentAnalysis->toString() << "\n";
	}
	outputStream.close();
}

bool Controller::isPersonIll(std::string analysisMonth){
	std::vector <MedicalAnalysis*> allAnalyses = this->elements.getAllEntries();
	std::vector <MedicalAnalysis*> analysesFromMonth = getAnalysesFromMonth(analysisMonth);

	if (analysesFromMonth.size() == 0) {
		return false;
	}

	for (auto currentAnalysis : analysesFromMonth) {
		if (currentAnalysis->isResultOK() == true) {
			return false;
		}
	}

	return true;
}

Controller::~Controller(){
	;
}
