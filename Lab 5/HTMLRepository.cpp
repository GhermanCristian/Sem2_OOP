#include "HTMLRepository.h"

HTMLRepository::HTMLRepository() : FileRepository() {
	this->filePath = TEMPORARY_HTML_FILE_NAME;
	bool successfulCreation = createFile(TEMPORARY_HTML_FILE_NAME);
}

HTMLRepository::HTMLRepository(std::string filePath) : FileRepository(filePath) {
	bool successfulCreation = createFile(filePath);
}

bool HTMLRepository::isInRepository(const std::vector<Victim>& currentVector, std::string victimName, int possiblePosition){
	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentVector, victimName);
	}
	return possiblePosition >= 0 and possiblePosition < currentVector.size() and currentVector[possiblePosition].getName() == victimName;
}

bool HTMLRepository::createFile(std::string filePath){
	FILE* currentFile;
	errno_t functionReturnValue = fopen_s(&currentFile, filePath.c_str(), "a");

	if (currentFile == 0 or functionReturnValue != 0) {
		return false;
	}

	// the file has been opened/created successfully
	fclose(currentFile);
	return true;
}

Victim HTMLRepository::getOneVictimFromFile(std::string lineContent){
	return Victim();
}

std::vector<Victim> HTMLRepository::loadFromFile(){
	std::vector <Victim> allData;
	std::string currentLine;
	std::fstream fileStream(this->filePath, std::fstream::in);

	// in the case in which the file is empty, loadVictim will not throw an exception bc the program won't even
	// reach that point (it doesn't enter the while loop)
	while (0) {
		try {
			allData.push_back(getOneVictimFromFile(currentLine));
		}
		catch (...) {
			fileStream.close();
			throw ValidationException("Invalid victim line");
		}
	}

	fileStream.close();
	return allData;
}

void HTMLRepository::saveToFile(const std::vector<Victim>& currentData){
	std::string currentLine;
	std::ofstream out(this->filePath);

	// write the 'header' part (title, html.. tags) 

	for (auto currentVictim : currentData) {
		out << currentVictim.getHTMLRepresentation() << "\n";
	}

	// write the 'footer' part (close the above tags)

	out.close();
}

void HTMLRepository::add(const Victim& newVictim){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition)) {
		throw RepositoryException("Element already exists");
	}

	possiblePosition++; // btw, we cannot do sth like begin + pos + 1 when pos is -1
	currentData.insert(currentData.begin() + possiblePosition, newVictim);

	this->saveToFile(currentData);
}

void HTMLRepository::update(const Victim& newVictim){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, newVictim.getName());
	if (isInRepository(currentData, newVictim.getName(), possiblePosition) == false) {
		throw RepositoryException("Element doesn't exist");
	}
	currentData[possiblePosition] = newVictim;

	this->saveToFile(currentData);
}

void HTMLRepository::erase(std::string victimName){
	std::vector <Victim> currentData = this->loadFromFile();

	int possiblePosition = findPosition(currentData, victimName);
	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw RepositoryException("Element doesn't exist");
	}
	currentData.erase(currentData.begin() + possiblePosition);

	this->saveToFile(currentData);
}

std::vector<Victim> HTMLRepository::getAllEntries(){
	std::vector <Victim> previousData = this->loadFromFile();
	return previousData;
}

std::vector<Victim> HTMLRepository::getFilteredEntries(const Filter& currentFilter){
	std::vector <Victim> temporaryVector;
	std::vector <Victim> previousData = this->loadFromFile();

	for (auto victim : previousData) {
		if (currentFilter.isPassed(victim) == true) {
			temporaryVector.push_back(victim);
		}
	}

	return temporaryVector;
}

Victim HTMLRepository::getVictimByName(std::string victimName, int possiblePosition) {
	std::vector <Victim> currentData = this->loadFromFile();

	if (possiblePosition == INEXISTENT_POSITION) {
		possiblePosition = findPosition(currentData, victimName);
	}

	if (isInRepository(currentData, victimName, possiblePosition) == false) {
		throw RepositoryException("Inexistent victim");
	}

	return currentData[possiblePosition];
}
