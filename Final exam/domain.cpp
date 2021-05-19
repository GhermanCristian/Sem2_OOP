#include "domain.h"

std::string Astronomer::toString(){
	std::string representation;

	return representation;
}

Star::Star(){
	this->Dec = 0;
	this->RA = 0;
	this->diameter = 0;
}

Star::Star(std::string name, std::string constellation, int RA, int Dec, int diameter){
	this->name = name;
	this->constellation = constellation;
	this->RA = RA;
	this->Dec = Dec;
	this->diameter = diameter;
}

std::string Star::toString() {
	std::string representation;

	representation += (this->name + " | ");
	representation += (this->constellation + " | ");
	representation += (std::to_string(this->RA) + " | ");
	representation += (std::to_string(this->Dec) + " | ");
	representation += (std::to_string(this->diameter));

	return representation;
}

std::string Star::getName() const{
	return this->name;
}

std::string Star::getConstellation() const{
	return this->constellation;
}

int Star::getRA() const{
	return this->RA;
}

int Star::getDec() const{
	return this->Dec;
}

int Star::getDiameter() const{
	return this->diameter;
}

Astronomer::Astronomer(){
	;
}

Astronomer::Astronomer(std::string name, std::string constellation){
	this->name = name;
	this->constellation = constellation;
}

std::string Astronomer::getName() const{
	return this->name;
}

std::string Astronomer::getConstellation() const{
	return this->constellation;
}
