#pragma once
#include <vector>
#include <algorithm>
#include "victim.h"
#include "filter.h"

const int INEXISTENT_POSITION = -1111;

class Repository {
	protected:
		std::vector <Victim> savedVictimList;

		int findPosition(const std::vector <Victim>& currentData, std::string victimName);
		/*
			Finds the position of the largest name <= victimName in the current list (which is sorted in increasing
			order of the names of the victims)
			Input:
				- A Victim's name
			Output:
				- Largest position on which the name <= victimName
			Throws:
				- None
		*/
		
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