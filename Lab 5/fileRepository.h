#pragma once
#include "repository.h"

class FileRepository : public Repository{
	protected:
		std::string filePath;
		bool createdTemporaryFile; // this is set to true when the repository is initiated with no path, in which
								   // case the program automatically creates a file, which is deleted at the end

	public:
		FileRepository();
		/*
			Default constructor for FileRepository
			Input:
				- None
			Output:
				- None
			Throws:
				- None
		*/

		FileRepository(std::string filePath);
		/*
			Constructor for FileRepository
			Input:
				- The path of the file which stores the data
			Output:
				- None
			Throws:
				- None
		*/

		virtual bool createFile(std::string filePath) = 0;
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

		virtual Victim getOneVictimFromFile(std::string lineContent) = 0;
		/*
			Determines a victim object from some given text
			Input:
				- The text which contains the Victim data
			Output:
				- Returns a Victim with the given properties
			Throws:
				- Exception, if the text is invalid
		*/

		virtual std::vector<Victim> loadFromFile() = 0;
		/*
			Loads all the data from a file
			Input:
				- None (the file path is already known)
			Output:
				- Returns a std::vector which contains all the data from a file
			Throws:
				- Exception, if the text in the file is invalid
		*/

		virtual std::string getVictimFileRepresentation(const Victim& currentVictim) = 0;
		/*
			Returns a string representation of a Victim
			Input:
				- The Victim we want to represent
			Output:
				- A string which contains the data that we want to represent
			Throws:
				- None
		*/

		virtual void saveToFile(const std::vector<Victim>& currentData) = 0;
		/*
			Saves all the data from a std::vector to a file
			Input:
				- The vector that we want to write to file (the file path is already known)
			Output:
				- The data from the vector is written to the file
			Throws:
				- None
		*/

		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
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

		virtual void add(const Victim& newVictim) = 0;
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the Repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		virtual void update(const Victim& newVictim) = 0;
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		virtual void erase(std::string victimName) = 0;
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		virtual std::vector <Victim> getAllEntries() = 0;
		/*
			Returns the data in the repository
			Input:
				- None
			Output:
				- An std::vector with the data from the repository
			Throws:
				- None
		*/

		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		/*
			Determines a list of all the victims which pass the given filter
			Input:
				- The filter through which we check the victims
			Output:
				- Returns a std::vector which contains the victims that have passed the filter
			Throws:
				- None
		*/

		virtual ~FileRepository();
		/*
			FileRepository destructor
			Input:
				- None
			Output:
				- Destroys the current FileRepository
			Throws:
				- None
		*/
};

