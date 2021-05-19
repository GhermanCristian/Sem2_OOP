#include "domain.h"

Writer::Writer(){
	;
}

Writer::Writer(std::string name, std::string expertise){
	this->name = name;
	this->expertise = expertise;
}

std::string Writer::getName() const{
	return this->name;
}

std::string Writer::getExpertise() const{
	return this->expertise;
}

std::string Writer::toString(){
	std::string representation;

	return representation;
}

Idea::Idea(){
	;
}

Idea::Idea(std::string description, std::string status, std::string creator, int act){
	this->description = description;
	this->status = status;
	this->creator = creator;
	this->act = act;
}

std::string Idea::getDescription() const{
	return this->description;
}

std::string Idea::getStatus() const{
	return this->status;
}

std::string Idea::getCreator() const{
	return this->creator;
}

int Idea::getAct() const{
	return this->act;
}

std::string Idea::toString() {
	std::string representation;

	return representation;
}
