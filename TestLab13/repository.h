#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <Car> cars;

	public:
		Repository();
		void loadFromFile(std::string filePath);
		std::vector <Car> getAllEntries();
		void add(const Car& newCar);
		~Repository();
};

