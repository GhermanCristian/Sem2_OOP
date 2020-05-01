#include "hotAirBalloon.h"

HotAirBalloon::HotAirBalloon(int uniqueID, int weightLimit){
	this->uniqueID = uniqueID;
	this->weightLimit = weightLimit;
	this->suitableForMilitary = false;
	this->suitableForMedicalEmergencies = false;
	this->suitableForPublicTransportation = false;
	this->suitableForLeisureTime = true;
	this->maximumAltitude = 21;
}

std::string HotAirBalloon::getAircraftRepresentation(){
	std::string representation = "";
	representation += ("hot air balloon, ");
	representation += ("id: " + std::to_string(uniqueID) + ", ");
	representation += ("weightLimit: " + std::to_string(this->weightLimit) + "\n");
	return representation;
}
