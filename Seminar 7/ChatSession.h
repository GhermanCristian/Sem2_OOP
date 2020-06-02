#pragma once
#include "Subject.h"
#include <vector>
#include "UserMessage.h"

class ChatSession : public Subject{
	private:
		std::vector<UserMessage> messages;

	public:
		ChatSession();
		void addMessage(UserMessage newMessage);
		std::vector<UserMessage> getAllMessages();
		~ChatSession();
};

