#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include "observer.h"

class GUI : public QWidget, public Observer{
	private:
		Controller& actionController;
		User user;

		QListWidget* mainListWidget;
		QLineEdit* issueLineEdit;
		QLineEdit* removeIssueLineEdit;
		QLineEdit* solveIssueLineEdit;
		QPushButton* addIssueButton;
		QPushButton* solveIssueButton;
		QPushButton* removeIssueButton;

		void addIssueButtonAction();
		void solveIssueButtonAction();
		void removeIssueButtonAction();

	public:
		GUI(Controller& actionController, User user);
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Issue>& entityList);
		void update() override;
		~GUI();
};

