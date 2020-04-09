#include "CSVRepository.h"
#include "inputValidator.h"
#include <fstream> // for now I'll use this, before I overwrite the >> << operators

CSVRepository::CSVRepository(std::string filePath) : FileRepository(filePath){
	;
}

Victim CSVRepository::loadVictimFromFile(std::string lineContent) {
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
	std::ifstream in("data.txt");

	while (getline(in, currentLine)) {
		allData.push_back(loadVictimFromFile(currentLine));
	}

	in.close();
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
	std::ofstream out("data.txt");

	for (auto currentVictim : currentData) {
		out << getVictimFileRepresentation(currentVictim) << "\n";
	}

	out.close();
}

Victim CSVRepository::getVictimByName(std::string victimName, int possiblePosition){
	return Victim();
}

void CSVRepository::add(const Victim& newVictim){
	;
}

void CSVRepository::update(const Victim& newVictim){
	;
}

void CSVRepository::erase(std::string victimName){
	;
}

std::vector<Victim>* CSVRepository::getAllEntries(){
	return nullptr;
}

std::vector<Victim> CSVRepository::getFilteredEntries(const Filter& currentFilter){
	return std::vector<Victim>();
}

CSVRepository::~CSVRepository(){
	;
}
