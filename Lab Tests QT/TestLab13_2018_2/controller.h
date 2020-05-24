#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		void loadFromFile(std::string filePath);
		std::vector<Task> getAllEntities();
		std::vector<Task> getAllEntitiesSortedByPriority();
		void addTask(std::string description, int duration, int priority);
		int getTotalDurationWithGivenPriority(int priority);
		/*
			Returns the total duration of all tasks which have a given priority
			Input:
				- The priority of the tasks
			Output:
				- The total duration is returned
		*/
		~Controller();
};

