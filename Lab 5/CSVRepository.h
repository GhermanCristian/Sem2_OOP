#pragma once
#include "fileRepository.h"

const std::string TEMPORARY_CSV_FILE_NAME = "temporaryFile.txt";

class CSVRepository : public FileRepository{
	friend class TestCSVRepository;

	private:
		bool isInRepository(std::vector<Victim>& currentVector, std::string victimName, int possiblePosition = INEXISTENT_POSITION);
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

		Victim getOneVictimFromFile(std::string lineContent) override;
		/*
			Determines a victim object from some given text
			Input:
				- The text which contains the Victim data
			Output:
				- Returns a Victim with the given properties
			Throws:
				- Exception, if the text is invalid
		*/

		std::vector<Victim> loadFromFile() override;
		/*
			Loads all the data from a .txt file
			Input:
				- None (the file path is already known)
			Output:
				- Returns a std::vector which contains all the data from a file
			Throws:
				- Exception, if the text in the file is invalid
		*/

		std::string getVictimFileRepresentation(const Victim& currentVictim) override;
		/*
			Returns a string representation of a Victim
			Input:
				- The Victim we want to represent
			Output:
				- A string which contains the data that we want to represent
			Throws:
				- None
		*/

		void saveToFile(const std::vector<Victim>& currentData) override;
		/*
			Saves all the data from a std::vector to a txt file
			Input:
				- The vector that we want to write to file (the file path is already known)
			Output:
				- The data from the vector is written to the file
			Throws:
				- None
		*/

		virtual bool createFile(std::string filePath) override;
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

		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
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

	public:
		CSVRepository();
		/*
			Default Constructor for the CSVRepository type
			Input:
				- None
			Output:
				- A temporary file is created, on which the repository will operate
			Throws:
				- Exception, if the file was not opened/ created successfully
		*/

		CSVRepository(std::string filePath);
		/*
			Constructor for the CSVRepository type (with a specified path)
			Input:
				- The path of the file which stores the data
			Output:
				- The file is created (if it didn't already exist)
			Throws:
				- Exception, if the file was not opened/ created successfully
		*/

		void add(const Victim& newVictim);
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the Repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		void update(const Victim& newVictim);
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		void erase(std::string victimName);
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		std::vector <Victim> getAllEntries();
		/*
			Returns the data in the repository
			Input:
				- None
			Output:
				- An std::vector with the data from the repository
			Throws:
				- None
		*/

		std::vector <Victim> getFilteredEntries(const Filter& currentFilter);
		/*
			Determines a list of all the victims which pass the given filter
			Input:
				- The filter through which we check the victims
			Output:
				- Returns a std::vector which contains the victims that have passed the filter
			Throws:
				- None
		*/

		CSVRepository(const CSVRepository& originalCSVRepository);
		/*
			Copy constructor for the CSVRepository type
			Input:
				- A CSVRepository whose content will be copied to the current one
			Output:
				- The content of the given CSVRepository is copied to the current one
			Throws:
				- None
		*/

		CSVRepository& operator = (const CSVRepository& originalCSVRepository);
		/*
			Overloaded assignment operator for the CSVRepository type
			Input:
				- A CSVRepository whose content will be copied to a new object
			Output:
				- A reference to a new object, with the same properties as the original one
			Throws:
				- None
		*/

		~CSVRepository();
		/*
			CSVRepository destructor
			Input:
				- None
			Output:
				- Destroys the current CSVRepository
				- Deletes the temporary file on which this repository was based (if that file were created)
			Throws:
				- None
		*/
};

