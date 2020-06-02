#pragma once
#include <qwidget.h>
#include "Observer.h"
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include "qlayout.h"
#include "User.h"
#include "ChatSession.h"
#include <ctime>
#include <chrono>

class ChatWindow : public QWidget, public Observer{
	private:
		const int CHAT_WINDOW_FONT_SIZE = 14;
		const std::string CHAT_WINDOW_FONT_NAME = "Arial";
		const int FIRST_ROW_INDEX = 0;

		QListWidget* listWidget;
		QLineEdit* messageLineEdit;
		QPushButton* sendMessageButton;
		User currentUser;
		ChatSession& chatSession;

	public:
		ChatWindow(ChatSession& chatSession, User currentUser);
		void sendMessage();
		void update() override;
		~ChatWindow();
};

