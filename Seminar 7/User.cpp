#include "User.h"

User::User(std::string uniqueUsername, std::string name){
	this->uniqueUsername = uniqueUsername;
	this->name = name;
}

User::User(){
	this->uniqueUsername = "";
	this->name = "";
}

std::string User::getName(){
	return this->name;
}

bool User::operator==(const User& otherUser){
	return this->uniqueUsername == otherUser.uniqueUsername && this->name == otherUser.name;
}
