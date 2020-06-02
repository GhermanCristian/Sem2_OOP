#include "ChatWindow.h"

ChatWindow::ChatWindow(ChatSession& chatSession, User currentUser) : chatSession(chatSession){
	this->currentUser = currentUser;
	this->setWindowTitle(QString::fromStdString(this->currentUser.getName()));

	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout{ mainWidget };

	this->listWidget = new QListWidget;
	this->messageLineEdit = new QLineEdit;
	this->sendMessageButton = new QPushButton{ "Send" };

	mainLayout->addWidget(this->listWidget);
	mainLayout->addWidget(this->messageLineEdit);
	mainLayout->addWidget(this->sendMessageButton);
	setLayout(mainLayout);

	QObject::connect(this->sendMessageButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
}

void ChatWindow::sendMessage(){
	std::time_t currentTime;
	std::time(&currentTime);
	std::string timestamp = std::ctime(&currentTime);
	UserMessage newUserMessage(currentUser, this->messageLineEdit->text().toStdString(), timestamp);
	this->chatSession.addMessage(newUserMessage);
	this->messageLineEdit->clear();
}

void ChatWindow::update(){
	QFont listFont{ QString::fromStdString(CHAT_WINDOW_FONT_NAME), CHAT_WINDOW_FONT_SIZE };

	if (listWidget->count() > 0) { // if there already are elements in the list
		listWidget->clear();
	}

	std::vector<UserMessage> allMessages = this->chatSession.getAllMessages();
	for (auto currentMessage : allMessages) {
		QString victimText = QString::fromStdString(currentMessage.getRepresentation());
		QListWidgetItem* listItem = new QListWidgetItem{ victimText };
		listItem->setFont(listFont);

		if (currentMessage.getUser() == this->currentUser) {
			listItem->setTextAlignment(Qt::AlignRight);
			listItem->setTextColor("blue");
		}
		else {
			listItem->setTextAlignment(Qt::AlignLeft);
			listItem->setTextColor("red");
		}

		listWidget->addItem(listItem);
	}
}

ChatWindow::~ChatWindow(){
	this->chatSession.removeObserver(this);
}
