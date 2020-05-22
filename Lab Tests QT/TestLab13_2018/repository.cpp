#include "repository.h"

Repository::Repository(){
	this->loadFromFile("bills.txt");
}

void Repository::loadFromFile(std::string filePath){
	const int COMPANY_NAME_POSITION = 0;
	const int CODE_POSITION = 1;
	const int SUM_POSITION = 2;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string companyName;
	std::string code;
	double sum;
	bool isPaid;

	this->bills.clear();

	while (std::getline(inputStream, currentLine)) {
		int colonPosition = currentLine.find(";");
		int propertyPosition = 0;

		while (colonPosition != std::string::npos) {
			std::string currentProperty = currentLine.substr(0, colonPosition);
			currentLine = currentLine.substr(colonPosition + 1, currentLine.length() - colonPosition - 1);
			colonPosition = currentLine.find(";");

			if (propertyPosition == COMPANY_NAME_POSITION) {
				companyName = currentProperty;
			}
			else if (propertyPosition == CODE_POSITION) {
				code = currentProperty;
			}
			else if (propertyPosition == SUM_POSITION) {
				sum = stod(currentProperty);
			}

			propertyPosition++;
		}

		if (currentLine.find("false") != std::string::npos) {
			isPaid = false;
		}
		else {
			isPaid = true;
		}

		this->bills.push_back(Bill(companyName, code, sum, isPaid));
	}

	inputStream.close();
}

std::vector <Bill> Repository::getAllEntries(){
	return this->bills;
}

Repository::~Repository(){
	;
}
