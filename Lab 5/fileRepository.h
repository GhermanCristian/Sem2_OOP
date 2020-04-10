#pragma once
#include "repository.h"

class FileRepository : public Repository{
	protected:
		std::string filePath;

	public:
		FileRepository(std::string filePath);
		virtual Victim getOneVictimFromFile(std::string lineContent) = 0;
		virtual std::vector<Victim> loadFromFile() = 0;
		virtual std::string getVictimFileRepresentation(const Victim& currentVictim) = 0;
		virtual void saveToFile(const std::vector<Victim>& currentData) = 0;
		virtual bool createFile(std::string filePath) = 0;
		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
		virtual void add(const Victim& newVictim) = 0;
		virtual void update(const Victim& newVictim) = 0;
		virtual void erase(std::string victimName) = 0;
		virtual std::vector <Victim>* getAllEntries() = 0;
		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		virtual ~FileRepository();
};

