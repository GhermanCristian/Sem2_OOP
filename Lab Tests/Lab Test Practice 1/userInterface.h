#pragma once
#include "controller.h"

class UserInterface{
	private:
		Controller actionController;

		void addHelicopterInterface();
		void addPlaneInterface();
		void addHotAirBalloonInterface();
		void displayAircraftByActivity();
		void displayAircraftByAltitude();
		void displayToFile(std::string filePath, std::vector <Aircraft*> filteredAircrafts);

	public:
		void startProgram();
};

