#pragma once
#include <vector>
#include <fstream>
#include "domain.h"

class Repository{
	private:
		std::vector <Bill> bills;

	public:
		Repository();
		void loadFromFile(std::string filePath);
		std::vector <Bill> getAllEntries();
		~Repository();
};

