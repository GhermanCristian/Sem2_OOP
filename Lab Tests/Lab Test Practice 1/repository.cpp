#include "repository.h"

Repository::Repository(){
	this->currentID = 0;
}

int Repository::getCurrentID(){
	return this->currentID;
}

void Repository::add(Aircraft* newAircraft){
	this->aircrafts.push_back(newAircraft);
	this->currentID++;
}

std::vector<Aircraft*> Repository::getAllAircrafts(){
	return this->aircrafts;
}

Repository::~Repository(){
	for (auto currentAircraft : this->aircrafts) {
		delete currentAircraft;
	}
}
