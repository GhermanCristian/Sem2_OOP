#include "ChatSession.h"

ChatSession::ChatSession(){
	;
}

void ChatSession::addMessage(UserMessage newMessage){
	this->messages.push_back(newMessage);
	this->notify();
}

std::vector<UserMessage> ChatSession::getAllMessages(){
	return this->messages;
}

ChatSession::~ChatSession(){
	;
}
