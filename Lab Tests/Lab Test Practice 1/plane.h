#pragma once
#include "aircraft.h"

class Plane : public Aircraft{
	private:
		bool isPrivate;
		std::string wingType;

		const std::string MONOPLANE_WING_TYPE = "monoplane";
		const std::string BIPLANE_WING_TYPE = "biplane";

	public:
		Plane(int uniqueID, bool isPrivate, std::string wingType);
		std::string getAircraftRepresentation();
};

