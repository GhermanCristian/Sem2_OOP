#pragma once
#include "fileRepository.h"

class HTMLRepository : public FileRepository{
	friend class TestHTMLRepository;
	private:
		std::string TEMPORARY_HTML_FILE_NAME = "temporaryFile.html";

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

		~HTMLRepository();
};

