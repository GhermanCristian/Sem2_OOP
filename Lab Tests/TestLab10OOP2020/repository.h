#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <HospitalDepartament*> departaments;

	public:
		Repository();
		void addDepartament(HospitalDepartament* newDepartament);
		std::vector <HospitalDepartament*> getAllEntries();
		~Repository();
};

