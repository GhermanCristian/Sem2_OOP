#include "CSVRepository.h"
#include "inputValidator.h"
#include <fstream>
#include <stdio.h>

CSVRepository::CSVRepository() : FileRepository(){
	this->filePath = TEMPORARY_CSV_FILE_NAME;
	bool successfulCreation = createFile(TEMPORARY_CSV_FILE_NAME);
	/*if (successfulCreation == false) {
		throw std::exception("Cannot create temporary file for CSVRepository");
	}*/
}

CSVRepository::CSVRepository(std::string filePath) : FileRepository(filePath){
	bool successfulCreation = createFile(filePath);
	/*if (successfulCreation == false) {
		throw std::exception("Cannot create file for CSVRepository");
	}*/
}

bool CSVRepository::isInRepository(std::vector<Victim>& currentVector, std::string victimName, int possiblePosition){
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentVector, victimName);
	}
	return possiblePosition >= 0 and possiblePosition < currentVector.size() and currentVector[possiblePosition].getName() == victimName;
}

bool CSVRepository::createFile(std::string filePath){
	FILE* currentFile;
	errno_t functionReturnValue = fopen_s(&currentFile, filePath.c_str(), "a");
	if (functionReturnValue == 0) { // the file has been opened/created successfully
		fclose(currentFile);
		return true;
	}
	return false;
}

Victim CSVRepository::getOneVictimFromFile(std::string lineContent) {
	InputValidator inputValidator;
	ArgumentList victimProperties;

	victimProperties = inputValidator.CSVFileVictimValidator(lineContent);
	if (victimProperties.list[ERROR_POSITION] == ERROR_CODE) {
		throw std::exception("Invalid victim line");
	}

	std::string victimName = victimProperties.list[NAME_POSITION];
	std::string placeOfOrigin = victimProperties.list[PLACE_OF_ORIGIN_POSITION];
	int age = stoi(victimProperties.list[AGE_POSITION]);
	std::string photographLink = victimProperties.list[PHOTOGRAPH_POSITION];

	return Victim{ victimName, placeOfOrigin, age, photographLink };
}

std::vector <Victim> CSVRepository::loadFromFile() {
	std::vector <Victim> allData;
	std::string currentLine;
	std::fstream fileStream(this->filePath, std::fstream::in);

	// in the case in which the file is empty, loadVictim will not throw an exception bc the program won't even
	// reach that point (it doesn't enter the while loop)
	while (getline(fileStream, currentLine)) {
		try {
			allData.push_back(getOneVictimFromFile(currentLine));
		}
		catch (...) {
			fileStream.close();
			throw std::exception("Invalid victim line");
		}
	}

	fileStream.close();
	return allData;
}

std::string CSVRepository::getVictimFileRepresentation(const Victim& currentVictim) {
	std::string victimRepresentation = "";

	victimRepresentation += currentVictim.getName();
	victimRepresentation += ", ";
	victimRepresentation += currentVictim.getPlaceOfOrigin();
	victimRepresentation += ", ";
	victimRepresentation += std::to_string(currentVictim.getAge());
	victimRepresentation += ", ";
	victimRepresentation += currentVictim.getPhotographLink();

	return victimRepresentation;
}

void CSVRepository::saveToFile(const std::vector<Victim>& currentData) {
	std::string currentLine;
	std::ofstream out(this->filePath);

	for (auto currentVictim : currentData) {
		out << currentVictim << "\n";
		//out << getVictimFileRepresentation(currentVictim) << "\n";
	}

	out.close();
}

Victim CSVRepository::getVictimByName(std::string victimName, int possiblePosition){
	std::vector <Victim> currentData = this->loadFromFile();

	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentData, victimName);
	}

	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw std::exception("Inexistent victim");
	}

	return currentData[possiblePosition];
}

void CSVRepository::add(const Victim& newVictim){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition)) {
		throw std::exception("Element already exists");
	}
	
	possiblePosition++; // btw, we cannot do sth like begin + pos + 1 when pos is -1
	currentData.insert(currentData.begin() + possiblePosition, newVictim);

	this->saveToFile(currentData);
}

void CSVRepository::update(const Victim& newVictim){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}
	currentData[possiblePosition] = newVictim;

	this->saveToFile(currentData);
}

void CSVRepository::erase(std::string victimName){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, victimName);
	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw std::exception("Element doesn't exist");
	}
	currentData.erase(currentData.begin() + possiblePosition);

	this->saveToFile(currentData);
}

std::vector<Victim> CSVRepository::getAllEntries(){
	std::vector <Victim> previousData = this->loadFromFile();
	return previousData;
}

std::vector<Victim> CSVRepository::getFilteredEntries(const Filter& currentFilter){
	std::vector <Victim> temporaryVector;
	std::vector <Victim> previousData = this->loadFromFile();

	for (auto victim : previousData) {
		if (currentFilter.isPassed(victim) == true) {
			temporaryVector.push_back(victim);
		}
	}

	return temporaryVector;
}

CSVRepository::CSVRepository(const CSVRepository& originalCSVRepository){
	this->filePath = originalCSVRepository.filePath;
	this->savedVictimList = originalCSVRepository.savedVictimList;
}

CSVRepository& CSVRepository::operator=(const CSVRepository& originalCSVRepository){
	if (this != &originalCSVRepository) {
		this->filePath = originalCSVRepository.filePath;
		this->savedVictimList = originalCSVRepository.savedVictimList;
	}
	return *this;
}

CSVRepository::~CSVRepository(){
	if (createdTemporaryFile == true) {
		remove(TEMPORARY_CSV_FILE_NAME.c_str());
	}
}
