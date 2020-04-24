#include "CSVRepository.h"
#include "inputValidator.h"
#include <fstream>
#include <stdio.h>

CSVRepository::CSVRepository() : FileRepository(){
	this->filePath = TEMPORARY_CSV_FILE_NAME;
	createFile(this->filePath);
}

CSVRepository::CSVRepository(std::string filePath) : FileRepository(filePath){
	;
}

Victim CSVRepository::getOneVictimFromFile(std::string lineContent) {
	InputValidator inputValidator;
	ArgumentList victimProperties;

	try {
		victimProperties = inputValidator.CSVFileVictimValidator(lineContent);
	}
	catch (const ValidationException& currentException) {
		throw ValidationException("Invalid victim line");
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
			throw ValidationException("Invalid victim line");
		}
	}

	fileStream.close();
	return allData;
}

void CSVRepository::saveToFile(const std::vector<Victim>& currentData) {
	std::string currentLine;
	std::ofstream out(this->filePath);

	for (auto currentVictim : currentData) {
		out << currentVictim.getCSVRepresentation() << "\n";
	}

	out.close();
}

CSVRepository::CSVRepository(const CSVRepository& originalCSVRepository){
	this->filePath = originalCSVRepository.filePath;
}

CSVRepository& CSVRepository::operator = (const CSVRepository& originalCSVRepository){
	if (this != &originalCSVRepository) {
		this->filePath = originalCSVRepository.filePath;
	}
	return *this;
}

CSVRepository::~CSVRepository(){
	if (createdTemporaryFile == true) {
		remove(TEMPORARY_CSV_FILE_NAME.c_str());
	}
}
