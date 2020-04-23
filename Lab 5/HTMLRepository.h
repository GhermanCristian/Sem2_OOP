#pragma once
#include "fileRepository.h"

const std::string TEMPORARY_HTML_FILE_NAME = "temporaryFile.html";

class HTMLRepository : public FileRepository{
	//friend class TestCSVRepository;
	private:
		bool isInRepository(const std::vector<Victim>& currentVector, std::string victimName, int possiblePosition = INEXISTENT_POSITION);
		/*
			Checks if the victim on the given position is the same as the one that we look for
			Input:
				- A Victim's name
				- The position on which the Victim is supossed to be (-1 by default, in which case we determine it ourselves)
			Output:
				- True, if the two Victims correspond
				- False, otherwise
			Throws:
				- None
		*/

		bool createFile(std::string filePath) override;
		/*
			Creates a file with a given name, if it doesn't exist
			Input:
				- The path of the file which stores the data
			Output:
				- The file is created (if it didn't exist already)
				- Returns true if the file has been opened/ created successfully
				- Returns false otherwise
			Throws:
				- None
		*/

		std::string processLine(std::string line);

		std::vector<Victim> loadFromFile() override;
		/*
			Loads all the data from a file
			Input:
				- None (the file path is already known)
			Output:
				- Returns a std::vector which contains all the data from a file
			Throws:
				- Exception, if the text in the file is invalid
		*/

		void saveToFile(const std::vector<Victim>& currentData) override;
		/*
			Saves all the data from a std::vector to a file
			Input:
				- The vector that we want to write to file (the file path is already known)
			Output:
				- The data from the vector is written to the file
			Throws:
				- None
		*/

	public:
		HTMLRepository();
		HTMLRepository(std::string filePath);

		void add(const Victim& newVictim) override;
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the Repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		void update(const Victim& newVictim) override;
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		void erase(std::string victimName) override;
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		std::vector <Victim> getAllEntries() override;
		/*
			Returns the data in the repository
			Input:
				- None
			Output:
				- An std::vector with the data from the repository
			Throws:
				- None
		*/

		std::vector <Victim> getFilteredEntries(const Filter& currentFilter) override;
		/*
			Determines a list of all the victims which pass the given filter
			Input:
				- The filter through which we check the victims
			Output:
				- Returns a std::vector which contains the victims that have passed the filter
			Throws:
				- None
		*/

		Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) override;
		/*
			Returns the victim with a given name
			Input:
				- The Victim's name
				- The position on which the Victim is supossed to be (-1 by default, in which case we determine it ourselves)
			Output:
				- The Victim with the given name
			Throws:
				- Exception, if the victim doesn't exist
		*/
};

