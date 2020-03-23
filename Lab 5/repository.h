#pragma once
#include "dynamicVector.h"

class Repository {
	private:
		DynamicVector data;

	public:
		Repository();
		void addToRepository(const TElem& newVictim);
		void updateInRepository(const TElem& newVictim);
		void deleteFromRepository(std::string victimName);
		DynamicVector* getAllEntries();
		Repository(const Repository& newRepository);
		Repository& operator = (const Repository& newRepository);
		~Repository();
};