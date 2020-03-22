#include "victim.h"

Victim::Victim() {
	;
}

Victim::Victim(std::string name, std::string placeOfOrigin, int age, std::string photographLink) {
	this->name = name;
	this->placeOfOrigin = placeOfOrigin;
	this->age = age;
	this->photographLink = photographLink;
}

std::string Victim::getName(){
	return this->name;
}

std::string Victim::getPlaceOfOrigin(){
	return this->placeOfOrigin;
}

int Victim::getAge(){
	return this->age;
}

std::string Victim::getPhotographLink(){
	return this->photographLink;
}

Victim::Victim(const Victim& newVictim){
	this->name = newVictim.name;
	this->placeOfOrigin = newVictim.placeOfOrigin;
	this->age = newVictim.age;
	this->photographLink = newVictim.photographLink;
}

Victim& Victim::operator=(const Victim& newVictim){
	if (this != &newVictim) {
		this->name = newVictim.name;
		this->placeOfOrigin = newVictim.placeOfOrigin;
		this->age = newVictim.age;
		this->photographLink = newVictim.photographLink;
	}
	return *this;
}

Victim::~Victim(){
	;
}
