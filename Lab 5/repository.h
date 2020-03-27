#pragma once
#include "dynamicVector.h"

class Repository {
	private:
		DynamicVector<TElem> data;

		int findPosition(std::string victimName);
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

		bool isInVector(std::string victimName, int possiblePosition = INEXISTENT_POSITION);
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

	public:
		Repository();
		/*
			Constructor for the Repository class
			Input:
				- None
			Output:
				- Creates a new, empty Repository
			Throws:
				- None
		*/

		void addToRepository(const TElem& newVictim);
		/*
			Adds a new Victim to the repository
			Input:
				- The Victim to be added
			Output:
				- A victim is added to the Repository
			Throws:
				- Exception, if the victim already is in the repository
		*/

		void updateInRepository(const TElem& newVictim);
		/*
			Updates a Victim from the repository
			Input:
				- The Victim to be updated (with the new properties, but with the same name)
			Output:
				- A victim from the repository is updated
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		void deleteFromRepository(std::string victimName);
		/*
			Deletes a victim from the repository
			Input:
				- The Victim's name
			Output:
				- A victim is deleted from the repository
			Throws:
				- Exception, if the victim wasn't in the repository
		*/

		DynamicVector<TElem>* getAllEntries();
		/*
			Returns a pointer to the data in the repository
			Input:
				- None
			Output:
				- A pointer to an object of type DynamicVector
			Throws:
				- None
		*/

		Repository(const Repository& originalRepository);
		/*
			Copy constructor for the Repository type
			Input:
				- A repository whose content will be copied to the current one
			Output:
				- The content of the given repository is copied to the current one
			Throws:
				- None
		*/

		Repository& operator = (const Repository& originalRepository);
		/*
			Overloaded assignment operator for the Repository type
			Input:
				- A repository whose content will be copied to a new object 
			Output:
				- A reference to a new object, with the same properties as the original one
			Throws:
				- None
		*/

		~Repository();
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