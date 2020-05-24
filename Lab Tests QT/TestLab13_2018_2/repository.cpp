#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

void Repository::add(const Task& newTask){
	this->tasks.push_back(newTask);
}

void Repository::loadFromFile(std::string filePath){
	const int DESCRIPTION_POSITION = 0;
	const int DURATION_POSITION = 1;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string description;
	int duration;
	int priority;

	this->tasks.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			// subtract 1 from the separator position because there is a space between the property and the separator;
			// this substr will stop just before "separatorPosition - 1" => it will include the entire property
			// and nothing else
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);

			// add 2 to the separator position because there is a space after the separator and before the next property
			// we then subtract 1 from "currentLine.length() - separatorPosition" in order to avoid that space
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == DESCRIPTION_POSITION) {
				description = currentProperty;
			}
			else if (propertyPosition == DURATION_POSITION) {
				duration = stoi(currentProperty);
			}

			propertyPosition++;
		}

		priority = stoi(currentLine);

		this->tasks.push_back(Task(description, duration, priority));
	}

	inputStream.close();
}

std::vector <Task> Repository::getAllEntries(){
	return this->tasks;
}

Repository::~Repository(){
	;
}
