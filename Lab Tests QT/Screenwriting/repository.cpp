#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

std::vector <Idea> Repository::getAllIdeas(){
	return this->ideas;
}

std::vector<Writer> Repository::getAllWriters(){
	return this->writers;
}

void Repository::loadIdeasFromFile(std::string filePath){
	const int DESCRIPTION_POSITION = 0;
	const int STATUS_POSITION = 1;
	const int CREATOR_POSITION = 2;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string description;
	std::string status;
	std::string creator;
	int act;

	this->ideas.clear();

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

			if (propertyPosition == DESCRIPTION_POSITION) {
				description = currentProperty;
			}
			else if (propertyPosition == STATUS_POSITION) {
				status = currentProperty;
			}
			else if (propertyPosition == CREATOR_POSITION) {
				creator = currentProperty;
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		act = stoi(currentLine);

		this->ideas.push_back(Idea(description, status, creator, act));
	}

	inputStream.close();
}

void Repository::loadWritersFromFile(std::string filePath){
	const int NAME_POSITION = 0;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string name;
	std::string expertise;

	this->writers.clear();

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
		expertise = currentLine;

		this->writers.push_back(Writer(name, expertise));
	}

	inputStream.close();
}

void Repository::addIdea(Idea newIdea){
	this->ideas.push_back(newIdea);
}

Repository::~Repository(){
	;
}
