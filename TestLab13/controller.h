#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		void loadFromFile(std::string filePath);
		std::vector<Car> getAllEntities();
		std::vector<Car> getAllCarsSortedByManufacturer();
		int getNumberOfCarsByManufacturer(std::string manufacturer);
		/*
			Computes the number of cars that have a certain manufacturer
			Input:
				- The car manufacturer
			Output:
				- Returns the number of cars with that manufacturer
		*/

		void addNewCar(std::string manufacturerName, std::string model, int fabricationYear, std::string color);
		~Controller();
};

