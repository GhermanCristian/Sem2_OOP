#pragma once
#include "victim.h"

class Filter
{
	public:
		virtual bool isPassed(const Victim& currentVictim) const = 0;
		virtual ~Filter();
};

class FilterPlaceOfOriginAndYoungerThan : public Filter {
	private:
		std::string placeOfOrigin;
		int age;

	public:
		FilterPlaceOfOriginAndYoungerThan(std::string placeOfOrigin, int age);
		bool isPassed(const Victim& currentVictim) const override;
};

