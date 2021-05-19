#pragma once
#include <string>

class Writer{
	private:
		std::string name;
		std::string expertise;

	public:
		Writer();
		Writer(std::string name, std::string expertise);
		std::string getName() const;
		std::string getExpertise() const;
		std::string toString();
};

class Idea {
	private:
		std::string description;
		std::string status;
		std::string creator;
		int act;

	public:
		Idea();
		Idea(std::string description, std::string status, std::string creator, int act);
		std::string getDescription() const;
		std::string getStatus() const;
		std::string getCreator() const;
		int getAct() const;
		std::string toString();
};