#pragma once
#include "dynamicVector.h"

class Repository {
	private:
		DynamicVector data;

	public:
		Repository();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void addToRepository(const TElem& newVictim);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void updateInRepository(const TElem& newVictim);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void deleteFromRepository(std::string victimName);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		DynamicVector* getAllEntries();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		Repository(const Repository& newRepository);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		Repository& operator = (const Repository& newRepository);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		~Repository();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

};