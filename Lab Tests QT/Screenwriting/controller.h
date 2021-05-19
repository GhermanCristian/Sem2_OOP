#pragma once
#include "repository.h"

class Controller{
	private:
		Repository repository;

	public:
		Controller();
		std::vector<Idea> getAllIdeas();
		std::vector<Writer> getAllWriters();
		void loadIdeasFromFile(std::string filePath);
		void loadWritersFromFile(std::string filePath);
		void addIdea(std::string description, int act, std::string creator);
		~Controller();
};

