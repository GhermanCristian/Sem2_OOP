#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <MedicalAnalysis*> analysisList;

	public:
		Repository();
		void addAnalysis(MedicalAnalysis* newAnalysis);
		std::vector <MedicalAnalysis*> getAllEntries();
		~Repository();
};

