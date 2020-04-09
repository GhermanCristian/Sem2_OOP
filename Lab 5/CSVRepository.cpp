#include "CSVRepository.h"

CSVRepository::CSVRepository(std::string filePath) : FileRepository(filePath){
	;
}

Victim CSVRepository::getVictimByName(std::string victimName, int possiblePosition){
	return Victim();
}

void CSVRepository::add(const Victim& newVictim){
	;
}

void CSVRepository::update(const Victim& newVictim){
	;
}

void CSVRepository::erase(std::string victimName){
	;
}

std::vector<Victim>* CSVRepository::getAllEntries(){
	return nullptr;
}

std::vector<Victim> CSVRepository::getFilteredEntries(const Filter& currentFilter){
	return std::vector<Victim>();
}

CSVRepository::~CSVRepository(){
	;
}
