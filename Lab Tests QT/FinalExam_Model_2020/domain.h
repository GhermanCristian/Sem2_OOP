#pragma once
#include <string>

class User{
	private:
		std::string name;
		std::string type;

	public:
		User();
		User(std::string name, std::string type);
		std::string toString();
		std::string getName();
		std::string getType();
};

class Issue {
	private:
		std::string description;
		std::string status;
		std::string reporter;
		std::string solver;

	public:
		Issue(std::string description, std::string status, std::string reporter, std::string solver);
		std::string toString();
		std::string getStatus() const;
		std::string getDescription() const;
		std::string getReporter() const;
		void solve(std::string solver);
};