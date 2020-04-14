#pragma once
#include "repository.h"

class MemoryRepository : public Repository{
	friend class TestMemoryRepository;

	private:
		std::vector <Victim> data;

		bool isInRepository(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
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

		Victim getVictimByName(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
		/*
			Returns the victim with a given name
			Input:
				- The Victim's name
				- The position on which the Victim is supossed to be (-1 by default, in which case we determine it ourselves)
			Output:
				- The Victim with the given name
			Throws:
				- Exception, if the victim doesn't exist
		*/

	public:
		MemoryRepository();
		/*
			Constructor for the MemoryRepository class
			Input:
				- None
			Output:
				- Creates a new, empty MemoryRepository
			Throws:
				- None
		*/

		void add(const Victim& newVictim);
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		void update(const Victim& newVictim);
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		void erase(std::string victimName);
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		std::vector <Victim> getAllEntries();
		/*
			Returns a pointer to the data in the repository
			Input:
				- None
			Output:
				- A std::vector which contains all the data in the repository
			Throws:
				- None
		*/

		std::vector <Victim> getFilteredEntries(const Filter& currentFilter);
		/*
			Determines a list of all the victims which pass the given filter
			Input:
				- The filter through which we check the victims
			Output:
				- Returns a std::vector which contains the victims which have passed the filter
			Throws:
				- None
		*/

		MemoryRepository(const MemoryRepository& originalRepository);
		/*
			Copy constructor for the MemoryRepository type
			Input:
				- A MemoryRepository whose content will be copied to the current one
			Output:
				- The content of the given MemoryRepository is copied to the current one
			Throws:
				- None
		*/

		MemoryRepository& operator = (const MemoryRepository& originalRepository);
		/*
			Overloaded assignment operator for the MemoryRepository type
			Input:
				- A repository whose content will be copied to a new object
			Output:
				- A reference to a new object, with the same properties as the original one
			Throws:
				- None
		*/

		~MemoryRepository();
		/*
			MemoryRepository destructor
			Input:
				- None
			Output:
				- Destroys the current MemoryRepository
			Throws:
				- None
		*/
};

