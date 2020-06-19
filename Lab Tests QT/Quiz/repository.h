#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <Question> questions;
		std::vector <Participant> participants;

	public:
		Repository();
		std::vector <Question> getAllQuestions();
		std::vector <Participant> getAllParticipants();
		void loadQuestionsFromFile(std::string filePath);
		void loadParticipantsFromFile(std::string filePath);
		void addQuestion(Question newQuestion);
		/*
			Adds a new question to the list
			Input:
				- The new question
			Output:
				- Throws an exception if the question's text is empty or if there already is a question with this ID
				- Otherwise, it adds the newQuestion to the list
		*/
		~Repository();
};

