#include "HTMLRepository.h"
#include <iostream>

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

std::string HTMLRepository::processLine(std::string line){
	int lineLength = line.length();
	int IGNORED_STARTING_CHARACTERS = 7;
	int IGNORED_ENDING_CHARACTERS = 5;

	line = line.substr(IGNORED_STARTING_CHARACTERS, lineLength - IGNORED_STARTING_CHARACTERS);
	// we have removed IGNORED_STARTING_CHARACTERS, so the length get modified as well
	line.erase(lineLength - IGNORED_ENDING_CHARACTERS - IGNORED_STARTING_CHARACTERS, IGNORED_ENDING_CHARACTERS);
	
	return line;
}

std::vector<Victim> HTMLRepository::loadFromFile(){
	std::vector <Victim> allData;
	std::string ignoredContent;
	std::string victimName, placeOfOrigin, victimAge, photographLink;
	std::fstream fileStream(this->filePath, std::fstream::in);

	int IGNORED_LINES_COUNT = 13;
	for (int i = 0; i < IGNORED_LINES_COUNT; i++) {
		// this happens when the file is empty (there is nothing to read => getline 'is' false)
		if (!getline(fileStream, ignoredContent)) {
			return allData;
		}
	}

	while (1) {
		getline(fileStream, ignoredContent); // <tr>
		if (ignoredContent == "\t\t</table>") { // this line marks the end of the table, so we don't have any Victims left to read
			break;
		}

		getline(fileStream, victimName);
		victimName = processLine(victimName);
		getline(fileStream, placeOfOrigin);
		placeOfOrigin = processLine(placeOfOrigin);
		getline(fileStream, victimAge);
		victimAge = processLine(victimAge);
		getline(fileStream, photographLink);
		photographLink = processLine(photographLink);

		allData.push_back(Victim{victimName, placeOfOrigin, stoi(victimAge), photographLink});

		getline(fileStream, ignoredContent); // </tr>
	}

	fileStream.close();
	return allData;
}

void HTMLRepository::saveToFile(const std::vector<Victim>& currentData){
	std::string currentLine;
	std::ofstream out(this->filePath);

	out << "<!DOCTYPE html>\n";
	out << "<html>\n";
	out << "\t<head>\n";
	out << "\t\t<title>Victims</title>\n";
	out << "\t</head>\n";
	out << "\t<body>\n";
	out << "\t\t<table border = \"1\">\n";
	out << "\t\t<tr>\n";
	out << "\t\t\t<td><b>Name</b></td>\n";
	out << "\t\t\t<td><b>Location</b></td>\n";
	out << "\t\t\t<td><b>Age</b></td>\n";
	out << "\t\t\t<td><b>Photo</b></td>\n";
	out << "\t\t</tr>\n";
	for (auto currentVictim : currentData) {
		out << currentVictim.getHTMLRepresentation();
	}
	out << "\t\t</table>\n";
	out << "\t</body>\n";
	out << "</html>";

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
