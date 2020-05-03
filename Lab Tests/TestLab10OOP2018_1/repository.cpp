#include "repository.h"

Repository::Repository(){
	;
}

void Repository::addAnalysis(MedicalAnalysis* newAnalysis){
	this->analysisList.push_back(newAnalysis);
}

std::vector <MedicalAnalysis*> Repository::getAllEntries(){
	return this->analysisList;
}

Repository::~Repository(){
	for (auto currentAnalysis : this->analysisList) {
		delete currentAnalysis;
	}
}
