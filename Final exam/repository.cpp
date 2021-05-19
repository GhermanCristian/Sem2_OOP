#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

std::vector <Star> Repository::getAllStars(){
	return this->stars;
}

std::vector <Astronomer> Repository::getAllAstronomers() {
	return this->astronomers;
}

void Repository::loadStarsFromFile(){
	const int NAME_POSITION = 0;
	const int CONSTELLATION_POSITION = 1;
	const int RA_POSITION = 2;
	const int DECLINATION_POSITION = 3;

	std::fstream inputStream(STARS_FILE_PATH);
	std::string currentLine;

	std::string name;
	std::string constellation;
	int RA;
	int declination;
	int diameter;

	this->stars.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			// subtract 1 from the separator position because there is a space between the property and the separator;
			// this substr will stop just before "separatorPosition - 1" => it will include the entire property
			// and nothing else
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);

			// add 2 to the separator position because there is a space between the separator and the next property
			// we then subtract 1 from "currentLine.length() - separatorPosition" in order to avoid that space
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == NAME_POSITION) {
				name = currentProperty;
			}
			else if (propertyPosition == CONSTELLATION_POSITION) {
				constellation = currentProperty;
			}
			else if (propertyPosition == RA_POSITION) {
				RA = stoi(currentProperty);
			}
			else if (propertyPosition == DECLINATION_POSITION) {
				declination = stoi(currentProperty);
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		diameter = stoi(currentLine);

		this->stars.push_back(Star(name, constellation, RA, declination, diameter));
	}

	inputStream.close();
}

void Repository::loadAstronomersFromFile() {
	const int NAME_POSITION = 0;

	std::fstream inputStream(ASTRONOMERS_FILE_PATH);
	std::string currentLine;

	std::string name;
	std::string constellation;

	this->astronomers.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			// subtract 1 from the separator position because there is a space between the property and the separator;
			// this substr will stop just before "separatorPosition - 1" => it will include the entire property
			// and nothing else
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);

			// add 2 to the separator position because there is a space between the separator and the next property
			// we then subtract 1 from "currentLine.length() - separatorPosition" in order to avoid that space
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == NAME_POSITION) {
				name = currentProperty;
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		constellation = currentLine;

		this->astronomers.push_back(Astronomer(name, constellation));
	}

	inputStream.close();
}

void Repository::addStar(Star newStar){
	if (newStar.getDiameter() <= 0 || newStar.getName() == "") {
		throw std::exception("Invalid diameter or name");
	}

	for (auto star : this->stars) {
		if (star.getName() == newStar.getName()) {
			throw std::exception("Star already exists");
		}
	}

	this->stars.push_back(newStar);
}

Repository::~Repository(){
	;
}