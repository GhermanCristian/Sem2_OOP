#include "controller.h"
#include <iostream>
#include <exception>

Controller::Controller() {
	;
}

void Controller::addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink){
	Victim newVictim{ victimName, placeOfOrigin, age, photographLink };
	this->victimRepository.add(newVictim);
}

void Controller::updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink){
	Victim newVictim{ victimName, newPlaceOfOrigin, newAge, newPhotographLink };
	this->victimRepository.update(newVictim);
}

void Controller::deleteVictim(std::string victimName){
	this->victimRepository.deleteFromRepository(victimName);
}

std::vector <Victim>* Controller::getAllVictims(){
	return this->victimRepository.getAllEntries();
}

std::vector <Victim> Controller::getFilteredVictims(std::string placeOfOrigin, int age) {
	return this->victimRepository.getFilteredEntries(placeOfOrigin, age);
}

Victim Controller::getNextVictim(){
	Victim nextVictim;
	int numberOfElements = this->victimRepository.getAllEntries()->size();

	if (numberOfElements <= 0) {
		throw std::exception("No elements available");
	}

	// we set the number of elements in this call and not in the constructor because at that point, the
	// DynamicVector is empty
	this->victimIterator.setNumberOfElements(numberOfElements);
	nextVictim = this->victimIterator.getCurrentElement(this->victimRepository.getAllEntries());
	this->victimIterator.setNextPosition();

	return nextVictim;
}

void Controller::saveVictim(std::string victimName){
	this->victimRepository.saveVictim(victimName);
}

std::vector <Victim>* Controller::getSavedVictims(){
	return this->victimRepository.getSavedVictimList();
}

Controller::~Controller() {
	;
}