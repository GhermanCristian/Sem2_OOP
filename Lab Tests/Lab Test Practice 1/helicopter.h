#pragma once
#include "aircraft.h"

class Helicopter : public Aircraft{
	private:
		bool isPrivate;

	public:
		Helicopter(int uniqueID, bool isPrivate);
		std::string getAircraftRepresentation();
};

