#include "action.h"

AddAction::AddAction(Repository*& currentRepository, Victim addedVictim) : currentRepository(currentRepository){
	this->addedVictim = addedVictim;
}

void AddAction::executeUndo(){
	this->currentRepository->erase(this->addedVictim.getName());
}

void AddAction::executeRedo(){
	this->currentRepository->add(this->addedVictim);
}

DeleteAction::DeleteAction(Repository*& currentRepository, Victim deletedVictim) : currentRepository(currentRepository) {
	this->deletedVictim = deletedVictim;
}

void DeleteAction::executeUndo(){
	this->currentRepository->add(this->deletedVictim);
}

void DeleteAction::executeRedo(){
	this->currentRepository->erase(this->deletedVictim.getName());
}

UpdateAction::UpdateAction(Repository*& currentRepository, Victim oldVictim, Victim newVictim) : currentRepository(currentRepository) {
	this->oldVictim = oldVictim;
	this->newVictim = newVictim;
}

void UpdateAction::executeUndo(){
	this->currentRepository->update(this->oldVictim);
}

void UpdateAction::executeRedo(){
	this->currentRepository->update(this->newVictim);
}
