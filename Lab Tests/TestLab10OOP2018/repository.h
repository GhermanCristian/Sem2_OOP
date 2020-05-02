#pragma once
#include "domain.h"
#include <vector>

class Repository{
	private:
		std::vector<Appliance*> appliances;

		bool isInRepository(Appliance* newAppliance);

	public:
		Repository();
		void addAppliance(Appliance* newAppliance);
		std::vector <Appliance*> getAllEntries();
		~Repository();
};

