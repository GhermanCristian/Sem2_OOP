#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

class GUI : public QWidget{
	private:
		Controller actionController;

		QListWidget* mainListWidget;
		QLineEdit* priorityLineEdit;
		QPushButton* showDurationButton;
		QLabel* totalDurationLabel;

		void showDurationButtonAction();

	public:
		GUI();
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Task>& entityList);
		~GUI();
};

