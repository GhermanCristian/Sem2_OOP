#pragma once
#include "fileRepository.h"

class CSVRepository : public FileRepository{
	private:
		//void loadFromFile();
		//void saveToFile();

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

