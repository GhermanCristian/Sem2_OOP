#pragma once
#include <string>

const int UNASSIGNED_PROGRAMMER = -1;

class Programmer{
	private:
		int ID;
		std::string name;

	public:
		Programmer(int ID, std::string name);
		Programmer();
		std::string toString();
		std::string getName();
		int getID();
};

class Task {
	private:
		std::string description;
		std::string status;
		int ID;

	public:
		Task(std::string description, std::string status, int ID);
		Task();
		std::string toString();
		std::string getStatus() const;
		std::string getDescription() const;
		int getID() const;
};