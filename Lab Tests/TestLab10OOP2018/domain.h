#pragma once
#include <string>

class Appliance{
	protected:
		int uniqueID;
		int weight;

	public:
		virtual double getMonthlyElectricityQuantity() = 0;
		bool operator== (const Appliance& newAppliance);
		virtual std::string toString() = 0;
		int getWeight();
};

class Refrigerator : public Appliance {
	private:
		std::string electricityUsageClass;
		bool hasFreezer;

	public:
		Refrigerator(int uniqueID, int weight, std::string electricityUsageClass, bool hasFreezer);
		double getMonthlyElectricityQuantity();
		std::string toString();
		~Refrigerator();
};

class DishWashingMachine : public Appliance {
	private:
		int washingCycleLength; // in hours
		int electricityPerHour;

	public:
		DishWashingMachine(int uniqueID, int weight, int washingCycleLength, int electricityPerHour);
		double getMonthlyElectricityQuantity();
		std::string toString();
		~DishWashingMachine();
};