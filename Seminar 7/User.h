#pragma once
#include <string>

class User{
	private:
		std::string uniqueUsername;
		std::string name;

	public:
		User(std::string uniqueUsername, std::string name);
		User();
		std::string getName();
		bool operator == (const User& otherUser);
};

