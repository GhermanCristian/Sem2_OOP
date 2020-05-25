#pragma once
#include <string>

class Car{
	private:
		std::string manufacturerName;
		std::string model;
		int fabricationYear;
		std::string color;

	public:
		Car(std::string manufacturerName, std::string model, int fabricationYear, std::string color);
		std::string toString();
		std::string getManufacturerName() const;
		std::string getColor();
};