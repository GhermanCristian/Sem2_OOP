#include "domain.h"

Task::Task(std::string description, int duration, int priority){
	this->description = description;
	this->duration = duration;
	this->priority = priority;
}

int Task::getPriority() const{
	return this->priority;
}

int Task::getDuration() const{
	return this->duration;
}

std::string Task::toString(){
	std::string representation;

	representation += (this->description + " | ");
	representation += (std::to_string(this->priority));

	return representation;
}
