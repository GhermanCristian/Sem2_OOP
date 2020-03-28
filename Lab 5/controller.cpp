#include "controller.h"
#include <iostream>
#include <exception>

Controller::Controller() {
	positionInAllList = -1;
	positionInSavedList = 0;
}

void Controller::addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink){
	Victim newVictim{ victimName, placeOfOrigin, age, photographLink };
	this->victimRepository.addToRepository(newVictim);
}

void Controller::updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink){
	Victim newVictim{ victimName, newPlaceOfOrigin, newAge, newPhotographLink };
	this->victimRepository.updateInRepository(newVictim);
}

void Controller::deleteVictim(std::string victimName){
	this->victimRepository.deleteFromRepository(victimName);
}

DynamicVector<TElem>* Controller::getAllVictims(){
	return this->victimRepository.getAllEntries();
}

DynamicVector<TElem> Controller::getFilteredVictims(std::string placeOfOrigin, int age) {
	return this->victimRepository.getFilteredEntries(placeOfOrigin, age);
}

void Controller::saveVictim(std::string victimName){
	// TO-DO: ensure no victim is saved twice
	int possiblePositionOfVictim = this->victimRepository.findPosition(victimName);
	if (this->victimRepository.isInVector(victimName, possiblePositionOfVictim) == false) {
		throw std::exception("Element doesn't exist");
	}
	savedVictimList.addToVector((*this->victimRepository.getAllEntries())[possiblePositionOfVictim], positionInSavedList++);
}

DynamicVector<TElem>* Controller::getSavedVictims(){
	return &savedVictimList;
}

Controller::~Controller() {
	;
}