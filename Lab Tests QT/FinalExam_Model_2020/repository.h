#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <Issue> issues;
		std::vector <User> users;

	public:
		Repository();
		void loadIssues(std::string filePath);
		void loadUsers(std::string filePath);
		std::vector <Issue> getAllIssues();
		std::vector <User> getAllUsers();
		void addIssue(Issue newIssue);
		void removeIssueByDescription(std::string description);
		void update(int position, Issue newIssue);
		~Repository();
};

