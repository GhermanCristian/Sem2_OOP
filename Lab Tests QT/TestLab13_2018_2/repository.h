#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <Task> tasks;

	public:
		Repository();
		void add(const Task& newTask);
		void loadFromFile(std::string filePath);
		std::vector <Task> getAllEntries();
		~Repository();
};

