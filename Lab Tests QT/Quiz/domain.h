#pragma once
#include <string>

class Question{
	private:
		int ID;
		std::string text;
		std::string correctAnswer;
		int score;

	public:
		Question();
		Question(int ID, std::string text, std::string correctAnswer, int score);
		std::string toStringPresenter();
		std::string toStringParticipant();
		int getScore() const;
		int getID() const;
		std::string getText() const;
		std::string getCorrectAnswer() const;
};

class Participant{
	private:
		std::string name;
		int score;

	public:
		Participant();
		Participant(std::string name);
		std::string toStringPresenter();
		std::string getName() const;
		void addScore(int increment);
		/*
			Increments the score of a participant by a given amount
			Input:
				- The score increment
			Output:
				- The score is increased
		*/
		int getScore() const;
};