#pragma once
#include "memoryRepository.h"
#include "CSVRepository.h"
#include "victimIterator.h"

class Controller {
	private:
		Repository* victimRepository;
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

		void setRepositoryFileLocation(std::string repositoryFileLocation);
		/*
			Sets the location for a file-based repository (called only when the repository is of a file type)
			Input:
				- The location we want to set
			Output:
				- The location is set and the file is created (if it didn't exist already)
			Throws:
				- Exception, if the file wasn't opened/ created properly
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

		std::vector <Victim> getAllVictims();
		/*
			Returns a pointer to the data in the repository
			Input:
				- None
			Output:
				- Pointer to a DynamicVector
			Throws:
				- None
		*/

		std::vector <Victim> getFilteredVictims(std::string placeOfOrigin, int age);
		/*
			Determines a list of all the victims which pass a filter
			Input:
				- The filter's place of origin and age properties
			Output:
				- Returns a DynamicVector which contains all the victims that have passed the filter
			Throws:
				- None
		*/

		Victim getNextVictim();
		/*
			Determines the next victim in the list (assistant mode)
			Input:
				- None
			Output:
				- Returns the next available victim in the list
			Throws:
				- Exception, if the list of victims is empty
		*/
		
		void saveVictim(std::string victimName);
		/*
			Saves a given victim to a temporary list
			Input:
				- The victim's name
			Output:
				- The victim with that name is added to a temporary list (if if exists)
			Throws:
				- Exception, if the victim doesn't exist
		*/

		std::vector <Victim>* getSavedVictims();
		/*
			Allows access to the list of saved victims
			Input:
				- None
			Output:
				- Returns a pointer to the list of saved victims
			Throws:
				- None
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
