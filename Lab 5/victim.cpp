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

Victim::Victim(const Victim& originalVictim){
	this->name = originalVictim.name;
	this->placeOfOrigin = originalVictim.placeOfOrigin;
	this->age = originalVictim.age;
	this->photographLink = originalVictim.photographLink;
}

bool Victim::operator==(const Victim& newVictim){
	return (this->age == newVictim.age and this->name == newVictim.name and this->placeOfOrigin == newVictim.placeOfOrigin and this->photographLink == newVictim.photographLink);
}

Victim& Victim::operator=(const Victim& originalVictim){
	if (this != &originalVictim) {
		this->name = originalVictim.name;
		this->placeOfOrigin = originalVictim.placeOfOrigin;
		this->age = originalVictim.age;
		this->photographLink = originalVictim.photographLink;
	}
	return *this;
}

std::string Victim::getCSVRepresentation() const{
	std::string victimRepresentation = "";

	victimRepresentation += this->getName();
	victimRepresentation += ", ";
	victimRepresentation += this->getPlaceOfOrigin();
	victimRepresentation += ", ";
	victimRepresentation += std::to_string(this->getAge());
	victimRepresentation += ", ";
	victimRepresentation += this->getPhotographLink();

	return victimRepresentation;
}

std::string Victim::getHTMLRepresentation() const{
	std::string victimRepresentation = "";

	victimRepresentation += "\t\t<tr>\n";
	victimRepresentation += ("\t\t\t<td>" + this->getName() + "</td>\n");
	victimRepresentation += ("\t\t\t<td>" + this->getPlaceOfOrigin() + "</td>\n");
	victimRepresentation += ("\t\t\t<td>" + std::to_string(this->getAge()) + "</td>\n");
	victimRepresentation += ("\t\t\t<td>" + this->getPhotographLink() + "</td>\n");
	victimRepresentation += "\t\t</tr>\n";

	return victimRepresentation;
}

Victim::~Victim(){
	;
}

std::istream& operator >> (std::istream& inputStream, Victim& currentVictim){
	std::string commaSeparator;
	inputStream >> currentVictim.name >> commaSeparator >> currentVictim.placeOfOrigin >> commaSeparator >> currentVictim.age >> commaSeparator >> currentVictim.photographLink;
	return inputStream;
}

std::ostream& operator << (std::ostream& outputStream, const Victim& currentVictim){
	outputStream << currentVictim.getCSVRepresentation();
	return outputStream;
}
