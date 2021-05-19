#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <Idea> ideas;
		std::vector <Writer> writers;

	public:
		Repository();
		std::vector <Idea> getAllIdeas();
		std::vector <Writer> getAllWriters();
		void loadIdeasFromFile(std::string filePath);
		void loadWritersFromFile(std::string filePath);
		void addIdea(Idea newIdea);
		~Repository();
};

