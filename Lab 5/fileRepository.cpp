#include "fileRepository.h"

FileRepository::FileRepository() {
	this->filePath = "";
	this->createdTemporaryFile = true;
}

FileRepository::FileRepository(std::string filePath) {
	this->filePath = filePath;
	this->createdTemporaryFile = false;
	this->createFile(filePath);
}

bool FileRepository::isInRepository(const std::vector<Victim>& currentVector, std::string victimName, int possiblePosition){
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentVector, victimName);
	}
	return possiblePosition >= 0 and possiblePosition < currentVector.size() and currentVector[possiblePosition].getName() == victimName;
}

bool FileRepository::createFile(std::string filePath){
	FILE* currentFile;
	errno_t functionReturnValue = fopen_s(&currentFile, filePath.c_str(), "a");

	if (currentFile == 0 or functionReturnValue != 0) {
		return false;
	}

	// the file has been opened/created successfully
	fclose(currentFile);
	return true;
}

void FileRepository::add(const Victim& newVictim) {
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition)) {
		throw RepositoryException("Element already exists");
	}

	possiblePosition++; // btw, we cannot do sth like begin + pos + 1 when pos is -1
	currentData.insert(currentData.begin() + possiblePosition, newVictim);

	this->saveToFile(currentData);
}

void FileRepository::update(const Victim& newVictim) {
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition) == false) {
		throw RepositoryException("Element doesn't exist");
	}
	currentData[possiblePosition] = newVictim;

	this->saveToFile(currentData);
}

void FileRepository::erase(std::string victimName) {
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, victimName);
	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw RepositoryException("Element doesn't exist");
	}
	currentData.erase(currentData.begin() + possiblePosition);

	this->saveToFile(currentData);
}

std::vector<Victim> FileRepository::getAllEntries() {
	std::vector <Victim> previousData = this->loadFromFile();
	return previousData;
}

std::vector<Victim> FileRepository::getFilteredEntries(const Filter& currentFilter) {
	std::vector <Victim> temporaryVector;
	std::vector <Victim> previousData = this->loadFromFile();

	for (auto victim : previousData) {
		if (currentFilter.isPassed(victim) == true) {
			temporaryVector.push_back(victim);
		}
	}

	return temporaryVector;
}

Victim FileRepository::getVictimByName(std::string victimName, int possiblePosition){
	std::vector <Victim> currentData = this->loadFromFile();

	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentData, victimName);
	}

	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw RepositoryException("Inexistent victim");
	}

	return currentData[possiblePosition];
}

FileRepository::~FileRepository(){
	;
}
