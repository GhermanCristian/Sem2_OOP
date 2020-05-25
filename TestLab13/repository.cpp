#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

void Repository::loadFromFile(std::string filePath){
	const int MANUFACTURER_NAME_POSITION = 0;
	const int MODEL_POSITION = 1;
	const int FABRICATION_YEAR_POSITION = 2;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string manufacturerName;
	std::string model;
	int fabricationYear;
	std::string color;

	this->cars.clear();

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

			if (propertyPosition == MANUFACTURER_NAME_POSITION) {
				manufacturerName = currentProperty;
			}
			else if (propertyPosition == MODEL_POSITION) {
				model = currentProperty;
			}
			else if (propertyPosition == FABRICATION_YEAR_POSITION) {
				fabricationYear = stoi(currentProperty);
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		color = currentLine;

		this->cars.push_back(Car(manufacturerName, model, fabricationYear, color));
	}

	inputStream.close();
}

std::vector <Car> Repository::getAllEntries(){
	return this->cars;
}

void Repository::add(const Car& newCar){
	this->cars.push_back(newCar);
}

Repository::~Repository(){
	;
}
