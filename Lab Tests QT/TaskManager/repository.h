#pragma once
#include <vector>
#include "domain.h"
#include "CustomException.h"

class Repository{
	private:
		std::vector <Programmer> programmers;
		std::vector <Task> tasks;

	public:
		Repository();
		std::vector <Programmer> getAllProgrammers();
		std::vector <Task> getAllTasks();
		void loadProgrammersFromFile(std::string filePath);
		void loadTasksFromFile(std::string filePath);
		void addTask(Task newTask);
		Task removeTask(std::string description);
		/*
			Removes the task with the given description from the list
			Input:
				- The task's description
			Output:
				- The task is removed and retured, if it existed
				- Throws an exception, otherwise
		*/
		Task removeOpenTask(std::string description);
		~Repository();
};

