#pragma once
#include <map>
#include "memoryRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include "victimIterator.h"

class Controller {
	private:
		Repository* victimRepository;
		Repository* savedVictims; //mylist

		VictimIterator victimIterator;
		std::string mylistFilePath; // i need direct access to this for opening the file in an external program

		std::string TXT_FILE_EXTENSION;
		std::string CSV_FILE_EXTENSION;
		std::string HTML_FILE_EXTENSION;

		std::string getFileExtension(const std::string& fileLocation);
		/*
			Determines the file extension of the current file location
			Input:
				- The file location
			Output:
				- The file extension
			Throws:
				- ValidationException, if the fileLocation is invalid
		*/

		void loadRepositoryType();
		/*
			
			Input:
				-
			Output:
				-
			Throws:
				-
		*/

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
			Sets the location for a file-based repository
			Input:
				- The location we want to set
			Output:
				- The location is set and the file is created (if it didn't exist already)
			Throws:
				- Exception, if the file wasn't opened/ created properly
		*/

		void setSavedVictimsFileLocation(std::string myListLocation);
		/*
			Sets the location for the myList repository
			Input:
				- The location where the list will be
			Output:
				- The file is opened (and created if it didn't exist)
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

		std::vector <Victim> getSavedVictims();
		/*
			Determines the list of saved victims
			Input:
				- None
			Output:
				- Returns a list with the victims
			Throws:
				- None
		*/

		std::string getMylistPath();
		/*
			Determines the path of the current myList repository
			Input:
				- None
			Output:
				- Returns the current path
			Throws:
				- None
		*/

		std::map<std::string, int> getVictimCountByPlaceOfOrigin();
		/*
			Filters all victims by their place of origin
			Input:
				- None
			Output:
				- Each location is associated an integer, representing the number of victims from that location
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
