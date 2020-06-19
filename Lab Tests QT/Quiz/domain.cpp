#include "domain.h"

std::string Question::toStringPresenter(){
	std::string representation;

	representation += (std::to_string(this->ID) + " | ");
	representation += (this->text + " | ");
	representation += (this->correctAnswer + " | ");
	representation += (std::to_string(this->score));

	return representation;
}

std::string Question::toStringParticipant(){
	std::string representation;

	representation += (std::to_string(this->ID) + " | ");
	representation += (this->text + " | ");
	representation += (std::to_string(this->score));

	return representation;
}

int Question::getScore() const{
	return this->score;
}

int Question::getID() const{
	return this->ID;
}

std::string Question::getText() const{
	return this->text;
}

std::string Question::getCorrectAnswer() const{
	return this->correctAnswer;
}

std::string Participant::toStringPresenter() {
	std::string representation;

	representation += (this->name + " | ");
	representation += (std::to_string(this->score));

	return representation;
}

std::string Participant::getName() const{
	return this->name;
}

void Participant::addScore(int increment){
	this->score += increment;
}

int Participant::getScore() const{
	return this->score;
}

Question::Question(){
	this->ID = 0;
	this->text = "";
	this->correctAnswer = "";
	this->score = 0;
}

Question::Question(int ID, std::string text, std::string correctAnswer, int score){
	this->ID = ID;
	this->text = text;
	this->correctAnswer = correctAnswer;
	this->score = score;
}

Participant::Participant(){
	this->name = "";
	this->score = 0;
}

Participant::Participant(std::string name){
	this->name = name;
	this->score = 0;
}
