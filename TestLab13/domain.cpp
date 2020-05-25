#include "domain.h"

std::string Car::toString() {
	std::string representation;

	representation += (this->manufacturerName + " | ");
	representation += (this->model);

	return representation;
}

std::string Car::getManufacturerName() const{
	return this->manufacturerName;
}

std::string Car::getColor(){
	return this->color;
}

Car::Car(std::string manufacturerName, std::string model, int fabricationYear, std::string color){
	this->manufacturerName = manufacturerName;
	this->model = model;
	this->fabricationYear = fabricationYear;
	this->color = color;
}