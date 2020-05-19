#include "repository.h"

Repository::Repository(){
	;
}

void Repository::addDepartament(HospitalDepartament* newDepartament){
	this->departaments.push_back(newDepartament);
}

std::vector <HospitalDepartament*> Repository::getAllEntries(){
	return this->departaments;
}

Repository::~Repository(){
	for (auto departament : departaments) {
		delete departament;
	}
}
