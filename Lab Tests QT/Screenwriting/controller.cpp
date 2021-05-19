#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller(){
	;
}

std::vector <Idea> Controller::getAllIdeas() {
	return this->repository.getAllIdeas();
}

std::vector<Writer> Controller::getAllWriters(){
	return this->repository.getAllWriters();
}

void Controller::loadIdeasFromFile(std::string filePath){
	this->repository.loadIdeasFromFile(filePath);
}

void Controller::loadWritersFromFile(std::string filePath){
	this->repository.loadWritersFromFile(filePath);
}

void Controller::addIdea(std::string description, int act, std::string creator){
	this->repository.addIdea(Idea(description, "proposed", creator, act));
}

Controller::~Controller(){
	;
}
