#include "controller.h"

Controller::Controller(){
	;
}

void Controller::addHelicopter(bool isPrivate){
	int currentID = aircraftRepository.getCurrentID();
	Helicopter* newHelicopter = new Helicopter(currentID, isPrivate);
	aircraftRepository.add(newHelicopter);
}

void Controller::addPlane(bool isPrivate, std::string wingType){
	int currentID = aircraftRepository.getCurrentID();
	Plane* newPlane = new Plane( currentID, isPrivate, wingType );
	aircraftRepository.add(newPlane);
}

void Controller::addHotAirBalloon(int weightLimit){
	int currentID = aircraftRepository.getCurrentID();
	HotAirBalloon* newHotAirBalloon = new HotAirBalloon(currentID, weightLimit);
	aircraftRepository.add(newHotAirBalloon);
}

std::vector<Aircraft*> Controller::filterByActivity(std::string activity){
	std::vector <Aircraft*> currentData = this->aircraftRepository.getAllAircrafts();
	std::vector <Aircraft*> filteredData;
	for (auto currentAircraft : currentData) {
		if (currentAircraft->canPerformActivity(activity)) {
			filteredData.push_back(currentAircraft);
		}
	}
	return filteredData;
}

std::vector<Aircraft*> Controller::filterByAltitude(int altitude){
	std::vector <Aircraft*> currentData = this->aircraftRepository.getAllAircrafts();
	std::vector <Aircraft*> filteredData;
	for (auto currentAircraft : currentData) {
		if (currentAircraft->getMaximumAltitude() >= altitude) {
			filteredData.push_back(currentAircraft);
		}
	}
	return filteredData;
}
