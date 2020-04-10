#pragma once
#include "repository.h"

class FileRepository : public Repository{
	protected:
		std::string filePath;

		virtual Victim loadVictimFromFile(std::string lineContent) = 0;
		virtual std::vector<Victim> loadFromFile() = 0;
		virtual std::string getVictimFileRepresentation(const Victim& currentVictim) = 0;
		virtual void saveToFile(const std::vector<Victim>& currentData) = 0;

	public:
		FileRepository(std::string filePath);

		virtual bool isInRepository(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
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

		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
		virtual void add(const Victim& newVictim) = 0;
		virtual void update(const Victim& newVictim) = 0;
		virtual void erase(std::string victimName) = 0;
		virtual std::vector <Victim>* getAllEntries() = 0;
		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		virtual ~FileRepository();
};

