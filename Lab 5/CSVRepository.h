#pragma once
#include "fileRepository.h"

class CSVRepository : public FileRepository{
	friend class TestCSVRepository;

	private:
		std::string TEMPORARY_CSV_FILE_NAME = "temporaryFile.txt";

		Victim getOneVictimFromFile(std::string lineContent);
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

