#include "filter.h"

Filter::~Filter(){
	;
}

FilterPlaceOfOriginAndYoungerThan::FilterPlaceOfOriginAndYoungerThan(std::string placeOfOrigin, int age){
	this->placeOfOrigin = placeOfOrigin;
	this->age = age;
}

bool FilterPlaceOfOriginAndYoungerThan::isPassed(const Victim& currentVictim) const {
	return (placeOfOrigin.length() == 0 or (currentVictim.getAge() < age and currentVictim.getPlaceOfOrigin() == placeOfOrigin));
}

FilterPlaceOfOriginAndYoungerThan::~FilterPlaceOfOriginAndYoungerThan(){
	;
}
