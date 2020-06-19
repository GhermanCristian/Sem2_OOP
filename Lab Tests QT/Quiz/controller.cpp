#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller(std::string questionsFilePath){
	this->questionsFilePath = questionsFilePath;
}

std::vector <Question> Controller::getAllQuestions() {
	return this->repository.getAllQuestions();
}

std::vector<Question> Controller::getAllQuestionsSortedByScore(){
	std::vector<Question> allQuestions = this->repository.getAllQuestions();
	std::sort(allQuestions.begin(), allQuestions.end(), [this](const Question& a, const Question& b) {return a.getScore() > b.getScore(); });
	return allQuestions;
}

std::vector<Question> Controller::getAllQuestionsSortedByID(){
	std::vector<Question> allQuestions = this->repository.getAllQuestions();
	std::sort(allQuestions.begin(), allQuestions.end(), [this](const Question& a, const Question& b) {return a.getID() < b.getID(); });
	return allQuestions;
}

std::vector<Participant> Controller::getAllParticipants(){
	return this->repository.getAllParticipants();
}

void Controller::loadQuestionsFromFile(std::string filePath){
	this->repository.loadQuestionsFromFile(filePath);
}

void Controller::loadParticipantsFromFile(std::string filePath){
	this->repository.loadParticipantsFromFile(filePath);
}

void Controller::addQuestion(int questionID, std::string questionText, std::string correctAnswer, int questionScore){
	this->repository.addQuestion(Question(questionID, questionText, correctAnswer, questionScore));
	this->notify();
}

void Controller::updateQuestionsFile(std::string filePath){
	std::ofstream outputStream(filePath);
	std::vector<Question> allQuestions = this->repository.getAllQuestions();

	for (auto question : allQuestions) {
		outputStream << question.toStringPresenter() << "\n";
		// the presenter version is the one which also contains the answer, and that should be in the file
	}

	outputStream.close();
}

Controller::~Controller(){
	if (this->questionsFilePath != "") {
		this->updateQuestionsFile(this->questionsFilePath);
	}
}
