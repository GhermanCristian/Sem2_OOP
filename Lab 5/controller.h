#pragma once
#include "repository.h"

class Controller {
	private:
		Repository victimRepository;

	public:
		Controller();
		void addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink);
		void updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink);
		void deleteVictim(std::string victimName);
		DynamicVector* getAllVictims();
		~Controller();
};
