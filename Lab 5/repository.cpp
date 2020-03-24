#include "repository.h"
#include <iostream>

Repository::Repository(){
	;
}

void Repository::addToRepository(const TElem& newVictim){
	this->data.addToVector(newVictim);
}

void Repository::updateInRepository(const TElem& newVictim){
	this->data.updateInVector(newVictim);
}

void Repository::deleteFromRepository(std::string victimName){
	this->data.deleteFromVector(victimName);
}

DynamicVector* Repository::getAllEntries(){
	return &this->data;
}

Repository::Repository(const Repository& originalRepository){
	this->data = originalRepository.data;
}

Repository& Repository::operator=(const Repository& originalRepository){
	if (this != &originalRepository) {
		this->data = originalRepository.data;
	}
	return *this;
}

Repository::~Repository(){
	;
}
