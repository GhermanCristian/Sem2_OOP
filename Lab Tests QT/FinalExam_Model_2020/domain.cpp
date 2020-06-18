#include "domain.h"

std::string User::toString(){
	std::string representation;

	representation += (this->name + " - ");
	representation += this->type;

	return representation;
}

std::string User::getName(){
	return this->name;
}

std::string User::getType(){
	return this->type;
}

User::User(){
	this->name = "";
	this->type = "";
}

User::User(std::string name, std::string type){
	this->name = name;
	this->type = type;
}

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver){
	this->description = description;
	this->status = status;
	this->reporter = reporter;
	this->solver = solver;
}

std::string Issue::toString() {
	std::string representation;

	representation += (this->description + " | ");
	representation += (this->status + " | ");
	representation += (this->reporter + " | ");
	representation += (this->solver);

	return representation;
}

std::string Issue::getStatus() const{
	return this->status;
}

std::string Issue::getDescription() const{
	return this->description;
}

std::string Issue::getReporter() const{
	return this->reporter;
}

void Issue::solve(std::string solver){
	this->status = "closed";
	this->solver = solver;
}
