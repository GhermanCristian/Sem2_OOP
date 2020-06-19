#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

std::vector <Question> Repository::getAllQuestions(){
	return this->questions;
}

std::vector<Participant> Repository::getAllParticipants(){
	return this->participants;
}

void Repository::loadQuestionsFromFile(std::string filePath){
	const int ID_POSITION = 0;
	const int TEXT_POSITION = 1;
	const int ANSWER_POSITION = 2;

	std::fstream inputStream(filePath);
	std::string currentLine;

	int ID;
	std::string text;
	std::string answer;
	int score;

	this->questions.clear();

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

			if (propertyPosition == ID_POSITION) {
				ID = stoi(currentProperty);
			}
			else if (propertyPosition == TEXT_POSITION) {
				text = currentProperty;
			}
			else if (propertyPosition == ANSWER_POSITION) {
				answer = currentProperty;
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		score = stoi(currentLine);

		this->questions.push_back(Question(ID, text, answer, score));
	}

	inputStream.close();
}

void Repository::loadParticipantsFromFile(std::string filePath){
	std::fstream inputStream(filePath);
	std::string currentLine;
	std::string name;

	this->participants.clear();

	while (std::getline(inputStream, currentLine)) {
		name = currentLine;
		this->participants.push_back(Participant(name));
	}

	inputStream.close();
}

void Repository::addQuestion(Question newQuestion){
	if (newQuestion.getText() == "") {
		throw std::exception("Empty text");
	}
	for (auto question : this->questions) {
		if (question.getID() == newQuestion.getID()) {
			throw std::exception("ID already exists");
		}
	}
	this->questions.push_back(newQuestion);
}

Repository::~Repository(){
	;
}
