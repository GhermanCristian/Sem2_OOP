#pragma once
#include "fileRepository.h"

class CSVRepository : public FileRepository{
	private:
		Victim loadVictimFromFile(std::string lineContent);
		std::vector<Victim> loadFromFile();
		std::string getVictimFileRepresentation(const Victim& currentVictim);
		void saveToFile(const std::vector<Victim>& currentData);

	public:
		CSVRepository(std::string filePath);
		Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
		void add(const Victim& newVictim);
		void update(const Victim& newVictim);
		void erase(std::string victimName);
		std::vector <Victim>* getAllEntries();
		std::vector <Victim> getFilteredEntries(const Filter& currentFilter);
		~CSVRepository();
};

