#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		void addRefrigerator(int uniqueID, int weight, std::string usageClass, bool hasFreezer);
		/*
			Adds a new refrigerator to the repository
			Input:
				- The refrigerator's properties
			Output:
				- Throws exception if there already is a refrigerator with the same ID
				- Otherwise the refrigerator is added to the repository
		*/
		void addDishWashingMachine(int uniqueID, int weight, int washingCycleLength, int electricityPerHour);
		std::vector<Appliance*> getAllAppliances();
		std::vector<Appliance*> getAppliancesSortedByWeight();
		/*
			Returns the appliances in the repository, sorted in increasing order of their weight
			Input:
				- none
			Output:
				- The sorted vector
		*/
		std::vector<Appliance*> getFilteredAppliances(int maximumElectricity);
		~Controller();
};

