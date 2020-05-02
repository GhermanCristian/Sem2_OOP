#include "controller.h"
#include <algorithm>

Controller::Controller(){
	;
}

void Controller::addRefrigerator(int uniqueID, int weight, std::string usageClass, bool hasFreezer){
	Refrigerator* newRefrigerator = new Refrigerator{ uniqueID, weight, usageClass, hasFreezer };
	this->elements.addAppliance(newRefrigerator);
}

void Controller::addDishWashingMachine(int uniqueID, int weight, int washingCycleLength, int electricityPerHour){
	DishWashingMachine* newDishWashingMachine = new DishWashingMachine{ uniqueID, weight, washingCycleLength, electricityPerHour };
	this->elements.addAppliance(newDishWashingMachine);
}

std::vector<Appliance*> Controller::getAllAppliances(){
	return elements.getAllEntries();
}

std::vector<Appliance*> Controller::getAppliancesSortedByWeight(){
	std::vector<Appliance*> sortedAppliances = this->getAllAppliances();
	std::sort(sortedAppliances.begin(), sortedAppliances.end(), [this](Appliance* first, Appliance* second) {return first->getWeight() < second->getWeight(); });
	return sortedAppliances;
}

std::vector<Appliance*> Controller::getFilteredAppliances(int maximumElectricity){
	std::vector <Appliance*> filteredAppliances;
	std::vector <Appliance*> allAppliances = this->elements.getAllEntries();
	for (auto currentAppliance : allAppliances) {
		if (currentAppliance->getMonthlyElectricityQuantity() < maximumElectricity) {
			filteredAppliances.push_back(currentAppliance);
		}
	}
	return filteredAppliances;
}

Controller::~Controller(){
	;
}
