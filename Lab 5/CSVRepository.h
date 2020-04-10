#pragma once
#include "fileRepository.h"

class CSVRepository : public FileRepository{
	private:
		Victim loadVictimFromFile(std::string lineContent) override;
		std::vector<Victim> loadFromFile() override;
		std::string getVictimFileRepresentation(const Victim& currentVictim) override;
		void saveToFile(const std::vector<Victim>& currentData) override;

	public:
		CSVRepository(std::string filePath);

		bool isInRepository(std::string victimName, int possiblePosition = INEXISTENT_POSITION) override;
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

		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
		void add(const Victim& newVictim);
		void update(const Victim& newVictim);
		void erase(std::string victimName);
		std::vector <Victim>* getAllEntries();
		std::vector <Victim> getFilteredEntries(const Filter& currentFilter);
		~CSVRepository();
};

