#pragma once
#include "User.h"

class UserMessage{
	private:
		User currentUser;
		std::string content;
		std::string timestamp;

	public:
		UserMessage(User currentUser, std::string content, std::string timestamp);
		std::string getRepresentation();
		User getUser();
};

