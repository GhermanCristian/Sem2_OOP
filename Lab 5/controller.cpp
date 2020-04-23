#include "controller.h"
#include <iostream>

Controller::Controller() {
	this->victimRepository = new MemoryRepository();
	this->savedVictims = new MemoryRepository();
}

void Controller::setRepositoryFileLocation(std::string repositoryFileLocation){
	delete this->victimRepository;
	// right now the main repo is only CSV, so we assume by default that the file location is a csv file
	// we might have to do sth like in set saved victims
	this->victimRepository = new CSVRepository(repositoryFileLocation);
}

void Controller::setSavedVictimsFileLocation(std::string myListLocation){
	int locationLength = myListLocation.length();

	std::string lastFourCharacters = myListLocation.substr(locationLength - 4, 4);
	if (lastFourCharacters == ".txt" or lastFourCharacters == ".csv") {
		delete this->savedVictims;
		this->savedVictims = new CSVRepository(myListLocation);
	}

	std::string lastFiveCharacters = myListLocation.substr(locationLength - 5, 5);
	if (lastFiveCharacters == ".html") {
		delete this->savedVictims;
		this->savedVictims = new HTMLRepository(myListLocation);
	}
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
	Victim savedVictim = victimRepository->getVictimByName(victimName);
	savedVictims->add(savedVictim);
}

std::vector <Victim> Controller::getSavedVictims(){
	std::vector <Victim> allVictims = savedVictims->getAllEntries();
	return allVictims;
}

Controller::~Controller() {
	delete this->victimRepository;
	delete this->savedVictims;
}