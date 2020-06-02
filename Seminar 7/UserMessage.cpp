#include "UserMessage.h"

UserMessage::UserMessage(User currentUser, std::string content, std::string timestamp){
	this->currentUser = currentUser;
	this->content = content;
	this->timestamp = timestamp;
}

std::string UserMessage::getRepresentation(){
	std::string representation;
	representation += (this->timestamp);
	representation += (currentUser.getName() + ": ");
	representation += this->content;
	return representation;
}

User UserMessage::getUser(){
	return this->currentUser;
}
