#include "controller.h"
#include <iostream>

Controller::Controller() {
	this->loadRepositoryType();

	this->TXT_FILE_EXTENSION = ".txt";
	this->CSV_FILE_EXTENSION = ".csv";
	this->HTML_FILE_EXTENSION = ".html";
}

void Controller::loadRepositoryType(){
	const std::string CONFIGURATION_FILE_LOCATION = "settings.properties";
	const std::string DEFAULT_REPOSITORY_CSV_LOCATION = "data.txt";
	const std::string DEFAULT_MYLIST_CSV_LOCATION = "mylist.txt";
	const std::string DEFAULT_REPOSITORY_HTML_LOCATION = "data.html";
	const std::string DEFAULT_MYLIST_HTML_LOCATION = "mylist.html";
	std::fstream inputStream(CONFIGURATION_FILE_LOCATION);
	std::string currentLine;

	this->isMemoryRepository = false;

	// we skip over the comment lines <=> those which begin with ';'
	while (std::getline(inputStream, currentLine)) {
		if (currentLine.front() != ';') {
			break; 
		}
	}

	if (currentLine.find("html") != std::string::npos) {
		this->victimRepository = new HTMLRepository(DEFAULT_REPOSITORY_HTML_LOCATION);
		this->savedVictims = new HTMLRepository(DEFAULT_MYLIST_HTML_LOCATION);
	}

	else if (currentLine.find("csv") != std::string::npos) {
		this->victimRepository = new CSVRepository(DEFAULT_REPOSITORY_CSV_LOCATION);
		this->savedVictims = new CSVRepository(DEFAULT_MYLIST_CSV_LOCATION);
	}

	// in_memory, or if the configuration file is corrupted
	else {
		this->isMemoryRepository = true;
		this->victimRepository = new MemoryRepository();
		this->savedVictims = new MemoryRepository();
	}

	inputStream.close();
}

std::string Controller::getFileExtension(const std::string& fileLocation){
	int locationLength = fileLocation.length();
	const int TXT_EXTENSION_LENGTH = 4;
	const int HTML_EXTENSION_LENGTH = 5;

	std::string lastFourCharacters = fileLocation.substr(locationLength - TXT_EXTENSION_LENGTH, TXT_EXTENSION_LENGTH);
	if (lastFourCharacters == TXT_FILE_EXTENSION || lastFourCharacters == CSV_FILE_EXTENSION) {
		return lastFourCharacters;
	}

	std::string lastFiveCharacters = fileLocation.substr(locationLength - HTML_EXTENSION_LENGTH, HTML_EXTENSION_LENGTH);
	if (lastFiveCharacters == HTML_FILE_EXTENSION) {
		return lastFiveCharacters;
	}

	throw ValidationException("Invalid file type");
}

void Controller::setRepositoryFileLocation(std::string repositoryFileLocation){
	std::string fileExtension = getFileExtension(repositoryFileLocation);

	// if we reach this point => the validation went well => the type is valid
	delete this->victimRepository;

	if (fileExtension == TXT_FILE_EXTENSION || fileExtension == CSV_FILE_EXTENSION) {
		this->victimRepository = new CSVRepository(repositoryFileLocation);
	}

	else if (fileExtension == HTML_FILE_EXTENSION) {
		this->victimRepository = new HTMLRepository(repositoryFileLocation);
	}
}

void Controller::setSavedVictimsFileLocation(std::string myListLocation){
	std::string fileExtension = getFileExtension(myListLocation);

	// if we reach this point => the validation went well => the type is valid
	this->mylistFilePath = myListLocation;
	delete this->savedVictims;

	if (fileExtension == TXT_FILE_EXTENSION || fileExtension == CSV_FILE_EXTENSION) {
		this->savedVictims = new CSVRepository(myListLocation);
	}

	else if (fileExtension == HTML_FILE_EXTENSION) {
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

std::string Controller::getMylistPath(){
	return this->mylistFilePath;
}

std::map<std::string, int> Controller::getVictimCountByPlaceOfOrigin(){
	std::map<std::string, int> victimsByPlaceOfOrigin;
	std::vector<Victim> allVictims = this->victimRepository->getAllEntries();

	for (auto currentVictim : allVictims) {
		if (victimsByPlaceOfOrigin.count(currentVictim.getPlaceOfOrigin()) > 0) {
			victimsByPlaceOfOrigin[currentVictim.getPlaceOfOrigin()]++;
		}
		else {
			victimsByPlaceOfOrigin[currentVictim.getPlaceOfOrigin()] = 1;
		}
	}

	return victimsByPlaceOfOrigin;
}

bool Controller::isInMemoryRepository(){
	return this->isMemoryRepository;
}

Controller::~Controller() {
	delete this->victimRepository;
	delete this->savedVictims;
}