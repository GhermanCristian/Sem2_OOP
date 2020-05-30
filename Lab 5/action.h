#pragma once
#include "repository.h"

class Action{
	public:
		virtual void executeUndo() = 0;
		virtual void executeRedo() = 0;
};

class AddAction : public Action {
	private:
		Repository*& currentRepository;
		Victim addedVictim;

	public:
		AddAction(Repository*& currentRepository, Victim addedVictim);
		void executeUndo() override;
		void executeRedo() override;
};

class DeleteAction : public Action {
	private:
		Repository*& currentRepository;
		Victim deletedVictim;

	public:
		DeleteAction(Repository*& currentRepository, Victim deletedVictim);
		void executeUndo() override;
		void executeRedo() override;
};

class UpdateAction : public Action {
	private:
		Repository*& currentRepository;
		Victim oldVictim;
		Victim newVictim;

	public:
		UpdateAction(Repository*& currentRepository, Victim oldVictim, Victim newVictim);
		void executeUndo() override;
		void executeRedo() override;
};

