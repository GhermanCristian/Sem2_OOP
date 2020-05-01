#include "plane.h"

Plane::Plane(int uniqueID, bool isPrivate, std::string wingType){
	this->uniqueID = uniqueID;
	this->isPrivate = isPrivate;
	this->suitableForMilitary = true;
	this->suitableForMedicalEmergencies = false;
	this->suitableForPublicTransportation = true;

	if (wingType == MONOPLANE_WING_TYPE) {
		this->suitableForLeisureTime = false;
	}
	else {
		this->suitableForLeisureTime = true;
	}

	this->wingType = wingType;
	this->maximumAltitude = 26;
}

std::string Plane::getAircraftRepresentation(){
	std::string representation = "";
	representation += ("plane, ");
	representation += ("id: " + std::to_string(uniqueID) + ", ");
	representation += ("isPrivate: " + std::to_string(this->isPrivate) + ", ");
	representation += ("wingType: " + this->wingType + "\n");
	return representation;
}
