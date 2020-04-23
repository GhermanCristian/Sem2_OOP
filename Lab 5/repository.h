#pragma once
#include <vector>
#include <algorithm>
#include "victim.h"
#include "filter.h"
#include "customExceptions.h"

const int INEXISTENT_POSITION = -1111;

class Repository {
	protected:
		int findPosition(const std::vector <Victim>& currentData, std::string victimName);
		/*
			Finds the position of the largest name <= victimName in the current list (which is sorted in increasing
			order of the names of the victims)
			Input:
				- The current data of the repository we search through
				- A Victim's name
			Output:
				- Largest position on which the name <= victimName
			Throws:
				- None
		*/
		
	public:
		virtual void add(const Victim& newVictim) = 0;
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the Repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		virtual void update(const Victim& newVictim) = 0;
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		virtual void erase(std::string victimName) = 0;
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		virtual std::vector <Victim> getAllEntries() = 0;
		/*
			Returns the data in the repository
			Input:
				- None
			Output:
				- An std::vector with the data from the repository
			Throws:
				- None
		*/

		virtual std::vector <Victim> getFilteredEntries(const Filter& currentFilter) = 0;
		/*
			Determines a list of all the victims which pass the given filter
			Input:
				- The filter through which we check the victims
			Output:
				- Returns a std::vector which contains the victims that have passed the filter
			Throws:
				- None
		*/

		virtual Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION) = 0;
		/*
			Returns the victim with a given name
			Input:
				- The Victim's name
				- The possible position on which the Victim might be
			Output:
				- The Victim with the given name
			Throws:
				- Exception, if the victim doesn't exist
		*/

		virtual ~Repository();
		/*
			Repository destructor
			Input:
				- None
			Output:
				- Destroys the current Repository
			Throws:
				- None
		*/
};