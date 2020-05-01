#pragma once
#include <vector>
#include "aircraft.h"
#include "helicopter.h"
#include "plane.h"
#include "hotAirBalloon.h"

class Repository{
	private:
		int currentID;
		std::vector <Aircraft*> aircrafts;

	public:
		Repository();
		int getCurrentID();
		void add(Aircraft* newAircraft);
		std::vector<Aircraft*> getAllAircrafts();
		~Repository();
};

