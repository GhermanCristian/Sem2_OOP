#pragma once
#include "victim.h"

class Filter{
	public:
		virtual bool isPassed(const Victim& currentVictim) const = 0;
		/*
			Checks if a given victim passes the current filter
			Input:
				- The Victim we want to check
			Output:
				- Returns true, if the victim passes the filter
				- Returns false, otherwise
			Throws:
				- None
		*/

		virtual ~Filter();
		/*
			Destructor for the Filter type
			Input:
				- None
			Output:
				- None
			Throws:
				- None
		*/
};

class FilterPlaceOfOriginAndYoungerThan : public Filter {
	private:
		std::string placeOfOrigin;
		int age;

	public:
		FilterPlaceOfOriginAndYoungerThan(std::string placeOfOrigin, int age);
		/*
			Creates a filter which checks if a Victim's place of origin and age are
			in accordance with some given arguments
			Input:
				- The place of origin and the age we check against
			Output:
				- The filter object is created
			Throws:
				- None
		*/

		bool isPassed(const Victim& currentVictim) const override;
		/*
			Checks if a given victim passes the current filter
			Input:
				- The Victim we want to check
			Output:
				- Returns true, if the victim passes the filter
				- Returns false, otherwise
			Throws:
				- None
		*/

		~FilterPlaceOfOriginAndYoungerThan();
		/*
			Destructor for the Filter type
			Input:
				- None
			Output:
				- The current filter object is destroyed
			Throws:
				- None
		*/
};

