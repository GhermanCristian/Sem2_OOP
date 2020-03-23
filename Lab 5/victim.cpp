#include "victim.h"
#include <iostream>

Victim::Victim() {
	//std::cout << "victim def constructor\n";
	this->name = "";
	this->placeOfOrigin = "";
	this->age = 0;
	this->photographLink = "";
}

Victim::Victim(std::string name, std::string placeOfOrigin, int age, std::string photographLink) {
	this->name = name;
	this->placeOfOrigin = placeOfOrigin;
	this->age = age;
	this->photographLink = photographLink;
	//std::cout << "victim constructor\n";
}

std::string Victim::getName() const{
	return this->name;
}

std::string Victim::getPlaceOfOrigin() const{
	return this->placeOfOrigin;
}

int Victim::getAge() const{
	return this->age;
}

std::string Victim::getPhotographLink() const{
	return this->photographLink;
}

Victim::Victim(const Victim& newVictim){
	this->name = newVictim.name;
	this->placeOfOrigin = newVictim.placeOfOrigin;
	this->age = newVictim.age;
	this->photographLink = newVictim.photographLink;
	//std::cout << "victim copy constructor\n";
}

Victim& Victim::operator=(const Victim& newVictim){
	//std::cout << "victim assignment operator\n";
	if (this != &newVictim) {
		this->name = newVictim.name;
		this->placeOfOrigin = newVictim.placeOfOrigin;
		this->age = newVictim.age;
		this->photographLink = newVictim.photographLink;
	}
	return *this;
}

Victim::~Victim(){
	//std::cout << "victim destructor\n";
}
