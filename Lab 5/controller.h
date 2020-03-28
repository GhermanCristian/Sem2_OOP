#pragma once
#include "repository.h"
#include "victimIterator.h"

class Controller {
	private:
		int positionInSavedList;
		Repository victimRepository;
		DynamicVector<TElem> savedVictimList;
		VictimIterator victimIterator;

	public:
		Controller();
		/*
			Controller constructor
			Input:
				- None
			Output:
				- Creates a new, empty Controller
			Throws:
				- None
		*/

		void addVictim(std::string victimName, std::string placeOfOrigin, int age, std::string photographLink);
		/*
			Adds a new victim
			Input:
				- The victim's name, place of origin, age and photograph link
			Output:
				- A victim is added to the repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		void updateVictim(std::string victimName, std::string newPlaceOfOrigin, int newAge, std::string newPhotographLink);
		/*
			Updates an existing victim
			Input:
				- The victim's name, new place of origin, new age and new photograph link
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim doesn't exist
		*/

		void deleteVictim(std::string victimName);
		/*
			Deletes an existing victim
			Input:
				- The victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim doesn't exist
		*/

		DynamicVector<TElem>* getAllVictims();
		/*
			Returns a pointer to the data in the repository
			Input:
				- None
			Output:
				- Pointer to a DynamicVector
			Throws:
				- None
		*/

		DynamicVector<TElem> getFilteredVictims(std::string placeOfOrigin, int age);
		/*
			
			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		TElem getNextVictim();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/
		
		void saveVictim(std::string victimName);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		DynamicVector<TElem>* getSavedVictims();
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
			Controller destructor
			Input:
				- None
			Output:
				- Destroys the current Controller object
			Throws:
				- None
		*/

};
