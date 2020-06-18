#include "domain.h"

std::string Programmer::toString(){
	std::string representation;

	representation += (std::to_string(this->ID) + " | ");
	representation += this->name;

	return representation;
}

std::string Programmer::getName(){
	return this->name;
}

int Programmer::getID(){
	return this->ID;
}

Programmer::Programmer(int ID, std::string name){
	this->ID = ID;
	this->name = name;
}

Programmer::Programmer(){
	this->ID = 0;
	this->name = "";
}

Task::Task(std::string description, std::string status, int ID){
	this->description = description;
	this->status = status;
	this->ID = ID;
}

Task::Task(){
	this->description = "";
	this->status = "";
	this->ID = UNASSIGNED_PROGRAMMER;
}

std::string Task::toString(){
	std::string representation;

	representation += (this->description + " | ");
	representation += (this->status +" | ");
	if (this->ID != UNASSIGNED_PROGRAMMER) {
		representation += (std::to_string(this->ID));
	}

	return representation;
}

std::string Task::getStatus() const{
	return this->status;
}

std::string Task::getDescription() const{
	return this->description;
}

int Task::getID() const{
	return this->ID;
}
