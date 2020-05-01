#include "aircraft.h"

int Aircraft::getMaximumAltitude(){
	return this->maximumAltitude;
}

bool Aircraft::canPerformActivity(std::string activity){
	if (activity == PUBLIC_TRANSPORTATION_ACTIVITY) {
		return this->suitableForPublicTransportation;
	}
	if (activity == MEDICAL_EMERGENCY_ACTIVITY) {
		return this->suitableForMedicalEmergencies;
	}
	if (activity == LEISURE_TIME_ACTIVITY) {
		return this->suitableForLeisureTime;
	}
	if (activity == MILITARY_ACTIVITY) {
		return this->suitableForMilitary;
	}
	return false;
}
