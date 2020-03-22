#include "repository.h"
#include <iostream>

Repository::Repository(){
	;
}

void Repository::addToRepository(TElem newVictim){
	this->data.addToVector(newVictim);
}

void Repository::updateInRepository(TElem newVictim){
	this->data.updateInVector(newVictim);
}

void Repository::deleteFromRepository(std::string victimName){
	this->data.deleteFromVector(victimName);
}

DynamicVector* Repository::getAllEntries()
{
	return &this->data;
}

Repository::Repository(const Repository& newRepository){
	this->data = newRepository.data;
}

Repository& Repository::operator=(const Repository& newRepository)
{
	if (this != &newRepository) {
		this->data = newRepository.data;
	}
	return *this;
}

Repository::~Repository(){
	;
}
