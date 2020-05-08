#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtoolbar.h>
#include "controller.h"

class GUI : public QWidget{
	private:
		Controller actionController;

		QToolBar* menuToolbar;
		QAction* menuActionModeA;
		QAction* menuActionModeB;
		QAction* menuActionDataRepresentation;

		QListWidget* victimListWidget;

		QLineEdit* lineEditVictimName;
		QLineEdit* lineEditVictimPlace;
		QLineEdit* lineEditVictimAge;
		QLineEdit* lineEditVictimPhotograph;
		QLineEdit* lineEditFileLocation;

		QPushButton* addVictimButton;
		QPushButton* updateVictimButton;
		QPushButton* deleteVictimButton;
		QPushButton* fileLocationButton;

		void initializeGUI();
		void populateVictimList();

	public:
		GUI();
};

