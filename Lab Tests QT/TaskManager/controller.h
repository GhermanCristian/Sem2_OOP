#pragma once
#include "repository.h"
#include "Subject.h"

class Controller : public Subject{
	private:
		Repository elements;
		std::string taskFilePath;

	public:
		Controller(std::string taskFilePath);
		std::vector<Programmer> getAllProgrammers();
		std::vector<Task> getAllTasks();
		std::vector<Task> getAllTasksSorted();
		~Controller();
		void loadProgrammersFromFile(std::string filePath);
		void loadTasksFromFile(std::string filePath);
		void addTask(std::string description);
		void removeTask(std::string description);
		void startTask(std::string description, Programmer programmer);
		/*
			Updates a task to "in progress"
			Input:
				- The task's description and the programmer which starts it
			Output:
				- The task is updated, if everything was valid
				- Throws an exception, otherwise
		*/
		void doneTask(std::string description);
		/*
			Updates a task to "closed"
			Input:
				- The task's description (the programmer who started it is already known)
			Output:
				- The task is updated, if everything was valid
				- Throws an exception, otherwise
		*/
		void updateFile(std::string filePath);
};

