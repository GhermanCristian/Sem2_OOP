#include "controller.h"
#include <algorithm>

Controller::Controller(){
	;
}

void Controller::loadFromFile(std::string filePath){
	this->elements.loadFromFile(filePath);
}

std::vector <Car> Controller::getAllEntities() {
	return this->elements.getAllEntries();
}

std::vector<Car> Controller::getAllCarsSortedByManufacturer(){
	std::vector<Car> allCars = this->elements.getAllEntries();
	// sort the cars in ascending order by their manufacturer's name
	std::sort(allCars.begin(), allCars.end(), [this](const Car& a, const Car& b) {return a.getManufacturerName() < b.getManufacturerName(); });
	return allCars;
}

int Controller::getNumberOfCarsByManufacturer(std::string manufacturer){
	std::vector<Car> allCars = this->elements.getAllEntries();
	int numberOfCars = 0;
	for (auto currentCar : allCars) {
		if (currentCar.getManufacturerName() == manufacturer) {
			numberOfCars++;
		}
	}
	return numberOfCars;
}

void Controller::addNewCar(std::string manufacturerName, std::string model, int fabricationYear, std::string color){
	this->elements.add(Car(manufacturerName, model, fabricationYear, color));
}

Controller::~Controller(){
	;
}
