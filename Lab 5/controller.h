#pragma once
#include "repository.h"

class Controller {
	private:
		Repository victimRepository;

	public:
		Controller();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void deleteVictim(std::string victimName);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		DynamicVector* getAllVictims();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		~Controller();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

};
