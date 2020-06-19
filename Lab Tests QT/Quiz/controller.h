#pragma once
#include "repository.h"
#include "Subject.h"

class Controller : public Subject{
	private:
		Repository repository;
		std::string questionsFilePath;

	public:
		Controller(std::string questionsFilePath);
		std::vector<Question> getAllQuestions();
		std::vector<Question> getAllQuestionsSortedByScore();
		std::vector<Question> getAllQuestionsSortedByID();
		std::vector<Participant> getAllParticipants();
		void loadQuestionsFromFile(std::string filePath);
		void loadParticipantsFromFile(std::string filePath);
		void addQuestion(int questionID, std::string questionText, std::string correctAnswer, int questionScore);
		void updateQuestionsFile(std::string filePath);
		~Controller();
};

