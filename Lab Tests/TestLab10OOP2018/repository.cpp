#include "repository.h"

Repository::Repository() {
	;
}

bool Repository::isInRepository(Appliance* newAppliance){
	for (auto currentAppliance : this->appliances) {
		if (*currentAppliance == *newAppliance) {
			return true;
		}
	}
	return false;
}

void Repository::addAppliance(Appliance* newAppliance){
	if (isInRepository(newAppliance) == true) {
		throw std::exception("Appliance already exists");
	}
	this->appliances.push_back(newAppliance);
}

std::vector <Appliance*> Repository::getAllEntries(){
	return this->appliances;
}

Repository::~Repository(){
	for (auto currentAppliance : this->appliances) {
		delete currentAppliance;
	}
}
