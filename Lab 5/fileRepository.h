#pragma once
#include "repository.h"

class FileRepository : public Repository{
	protected:
		//virtual void loadFromFile() = 0;
		//virtual void saveToFile() = 0;

	public:
		FileRepository(std::string filePath);
		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
		virtual void add(const Victim& newVictim) = 0;
		virtual void update(const Victim& newVictim) = 0;
		virtual void erase(std::string victimName) = 0;
		virtual std::vector <Victim>* getAllEntries() = 0;
		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		virtual ~FileRepository();
};

