#pragma once
#include <vector>
#include <algorithm>
#include "victim.h"
#include "filter.h"

const int INEXISTENT_POSITION = -1111;

class Repository {
	protected:
		std::vector <Victim> savedVictimList;
		
	public:
		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
		virtual void add(const Victim& newVictim) = 0;
		virtual void update(const Victim& newVictim) = 0;
		virtual void erase(std::string victimName) = 0;
		virtual std::vector <Victim>* getAllEntries() = 0;
		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		void saveVictim(std::string victimName);
		std::vector <Victim>* getSavedVictimList();
		virtual ~Repository();
};