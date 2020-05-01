#pragma once
#include "repository.h"

class Controller{
	private:
		Repository aircraftRepository;

	public:
		Controller();
		void addHelicopter(bool isPrivate);
		void addPlane(bool isPrivate, std::string wingType);
		void addHotAirBalloon(int weightLimit);
		std::vector<Aircraft*> filterByActivity(std::string activity);
		std::vector<Aircraft*> filterByAltitude(int altitude);
};

