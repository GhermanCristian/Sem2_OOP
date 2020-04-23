#include "controller.h"
#include <iostream>

Controller::Controller() {
	this->victimRepository = new MemoryRepository();
}

void Controller::setRepositoryFileLocation(std::string repositoryFileLocation){
	delete this->victimRepository;
	this->victimRepository = new CSVRepository(repositoryFileLocation);
}

void Controller::addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink){
	Victim newVictim{ victimName, placeOfOrigin, age, photographLink };
	this->victimRepository->add(newVictim);
}

void Controller::updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink){
	Victim newVictim{ victimName, newPlaceOfOrigin, newAge, newPhotographLink };
	this->victimRepository->update(newVictim);
}

void Controller::deleteVictim(std::string victimName){
	this->victimRepository->erase(victimName);
}

std::vector <Victim> Controller::getAllVictims(){
	return this->victimRepository->getAllEntries();
}

std::vector <Victim> Controller::getFilteredVictims(std::string placeOfOrigin, int age) {
	FilterPlaceOfOriginAndYoungerThan currentFilter{ placeOfOrigin, age };
	return this->victimRepository->getFilteredEntries(currentFilter);
}

Victim Controller::getNextVictim(){
	Victim nextVictim;
	std::vector <Victim> currentData = this->victimRepository->getAllEntries();
	int numberOfElements = currentData.size();

	if (numberOfElements <= 0) {
		throw RepositoryException("No elements available");
	}

	this->victimIterator.setNumberOfElements(numberOfElements);
	nextVictim = this->victimIterator.getCurrentElement(currentData);
	this->victimIterator.setNextPosition();

	return nextVictim;
}

void Controller::saveVictim(std::string victimName){
	this->victimRepository->saveVictim(victimName);
}

std::vector <Victim>* Controller::getSavedVictims(){
	return this->victimRepository->getSavedVictimList();
}

Controller::~Controller() {
	delete this->victimRepository;
}