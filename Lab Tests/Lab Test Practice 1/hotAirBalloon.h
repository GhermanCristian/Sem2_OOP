#pragma once
#include "aircraft.h"

class HotAirBalloon : public Aircraft{
	private:
		int weightLimit; // in kilograms

	public:
		HotAirBalloon(int uniqueID, int weightLimit);
		std::string getAircraftRepresentation();
};

