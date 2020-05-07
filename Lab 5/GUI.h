#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include "controller.h"

class GUI : public QWidget{
	private:
		Controller actionController;

		QListWidget* victimListWidget;
		QLineEdit* lineEditVictimName;
		QLineEdit* lineEditVictimPlace;
		QLineEdit* lineEditVictimAge;
		QLineEdit* lineEditVictimPhotograph;
		QPushButton* addVictimButton;
		QPushButton* updateVictimButton;
		QPushButton* deleteVictimButton;

		void initializeGUI();
		void populateVictimList();

	public:
		GUI();
};

