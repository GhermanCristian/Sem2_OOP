#include "domain.h"

Refrigerator::Refrigerator(int uniqueID, int weight, std::string electricityUsageClass, bool hasFreezer){
	this->uniqueID = uniqueID;
	this->weight = weight;
	this->electricityUsageClass = electricityUsageClass;
	this->hasFreezer = hasFreezer;
}

double Refrigerator::getMonthlyElectricityQuantity(){
	const int NUMBER_OF_DAYS_PER_MONTH = 30;
	const int FREEZER_ELECTRICITY_COST = 20;
	const double CONSUMED_ENERGY_MULTIPLIER_APP_CLASS = 2.0; // A++ class
	const double CONSUMED_ENERGY_MULTIPLIER_AP_CLASS = 2.5; // A+ class
	const double CONSUMED_ENERGY_MULTIPLIER_A_CLASS = 3.0; // A class
	const std::string APP_CLASS_NAME = "A++";
	const std::string AP_CLASS_NAME = "A+";
	const std::string A_CLASS_NAME = "A";

	if (this->electricityUsageClass == APP_CLASS_NAME) {
		return NUMBER_OF_DAYS_PER_MONTH * CONSUMED_ENERGY_MULTIPLIER_APP_CLASS + this->hasFreezer * FREEZER_ELECTRICITY_COST;
	}
	if (this->electricityUsageClass == AP_CLASS_NAME) {
		return NUMBER_OF_DAYS_PER_MONTH * CONSUMED_ENERGY_MULTIPLIER_AP_CLASS + this->hasFreezer * FREEZER_ELECTRICITY_COST;
	}
	if (this->electricityUsageClass == A_CLASS_NAME) {
		return NUMBER_OF_DAYS_PER_MONTH * CONSUMED_ENERGY_MULTIPLIER_A_CLASS + this->hasFreezer * FREEZER_ELECTRICITY_COST;
	}
	return 0.0;
}

std::string Refrigerator::toString(){
	std::string representation = "";
	representation += ("ID: " + std::to_string(uniqueID) + ", ");
	representation += ("Weight: " + std::to_string(weight) + ", ");
	representation += ("UsageClass: " + electricityUsageClass + ", ");
	representation += ("HasFreezer: " + std::to_string(hasFreezer));
	return representation;
}

Refrigerator::~Refrigerator(){

}

DishWashingMachine::DishWashingMachine(int uniqueID, int weight, int washingCycleLength, int electricityPerHour){
	this->uniqueID = uniqueID;
	this->weight = weight;
	this->washingCycleLength = washingCycleLength;
	this->electricityPerHour = electricityPerHour;
}

double DishWashingMachine::getMonthlyElectricityQuantity(){
	const int AVERAGE_DISH_WASHING_MACHINE_MONTHLY_USAGE = 8;
	return (AVERAGE_DISH_WASHING_MACHINE_MONTHLY_USAGE * this->electricityPerHour * this->washingCycleLength);
}

std::string DishWashingMachine::toString(){
	std::string representation = "";
	representation += ("ID: " + std::to_string(uniqueID) + ", ");
	representation += ("Weight: " + std::to_string(weight) + ", "); 
	representation += ("CycleLength: " + std::to_string(washingCycleLength) + ", "); 
	representation += ("ElectricityPerHour: " + std::to_string(electricityPerHour)); 
	return representation;
}

DishWashingMachine::~DishWashingMachine(){

}

bool Appliance::operator==(const Appliance& newAppliance){
	return this->uniqueID == newAppliance.uniqueID;
}

int Appliance::getWeight(){
	return this->weight;
}
