#include "repository.h"

void Repository::saveVictim(std::string victimName){
	Victim currentVictim = getVictimByName(victimName);
	savedVictimList.push_back(currentVictim);
}

std::vector<Victim>* Repository::getSavedVictimList(){
	return &savedVictimList;
}

Repository::~Repository(){
	;
}
