#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include "Observer.h"
#include <qmessagebox.h>

const int LIST_INDEX_ERROR_CODE = -1;

class GUI : public QWidget, public Observer{
	private:
		Controller& actionController;
		Programmer programmer;

		QListWidget* mainListWidget;
		QLineEdit* addTaskLineEdit;
		QLineEdit* removeTaskLineEdit;
		QLineEdit* startLineEdit;
		QPushButton* addTaskButton;
		QPushButton* removeTaskButton;
		QPushButton* doneButton;
		QPushButton* startButton;

		void addTaskButtonAction();
		void removeTaskButtonAction();
		void startButtonAction();
		void doneButtonAction();

	public:
		GUI(Controller& actionController, Programmer programmer);
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Task>& entityList);
		void update() override;
		int getCurrentTaskIndex();
		Task selectTaskInList();
		~GUI();
};

