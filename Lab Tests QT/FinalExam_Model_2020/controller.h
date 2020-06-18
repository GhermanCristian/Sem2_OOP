#pragma once
#include "repository.h"
#include "Subject.h"

class Controller : public Subject{
	private:
		Repository elements;
		void updateFile(std::string filePath);

	public:
		Controller();
		void loadUsers(std::string filePath);
		void loadIssues(std::string filePath);
		std::vector<Issue> getAllIssues();
		std::vector<User> getAllUsers();
		std::vector<Issue> getAllIssuesSorted();
		void addIssue(std::string description, std::string status, std::string reporter, std::string solver);
		/*
			Adds a new issue to the issue list
			Input:
				- The issue's properties
			Output:
				- If the description is valid and the issue is not already in the list, the new issue is added to the list
				- Otherwise, an exception is thrown
		*/
		void removeIssueByDescription(std::string description);
		void solveIssueByDescription(std::string description, std::string solver);
		/*
			Solves an issue by its description
			Input:
				- The issue's description
				- The User who solved it
			Output:
				- Throws an exception if the description does not exist or is already solved
				- Otherwise, it updates the issue list
		*/
		~Controller();
};

