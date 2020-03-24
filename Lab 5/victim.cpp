#include "victim.h"

Victim::Victim() {
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
}

bool Victim::operator==(const Victim& newVictim){
	return (this->age == newVictim.age and this->name == newVictim.name and this->placeOfOrigin == newVictim.placeOfOrigin and this->photographLink == newVictim.photographLink);
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
	//std::cout << "victim destructor\n";
}
