#include "helicopter.h"

Helicopter::Helicopter(int uniqueID, bool isPrivate){
	this->uniqueID = uniqueID;
	this->isPrivate = isPrivate;
	this->suitableForMilitary = true;
	this->suitableForMedicalEmergencies = true;
	this->suitableForPublicTransportation = true;
	this->suitableForLeisureTime = isPrivate;
	this->maximumAltitude = 12;
}

std::string Helicopter::getAircraftRepresentation(){
	std::string representation = "";
	representation += ("helicopter, ");
	representation += ("id: " + std::to_string(uniqueID) + ", ");
	representation += ("isPrivate: " + std::to_string(isPrivate) + "\n");
	return representation;
}
