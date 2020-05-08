#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QStackedWidget>
#include <qtoolbar.h>
#include "controller.h"

class GUI : public QWidget{
	private:
		Controller actionController;

		QStackedWidget* allWidgets;

		QAction* menuActionModeA;
		QAction* menuActionModeB;
		QAction* menuActionDataRepresentation;

		QListWidget* victimListWidget;

		QLineEdit* lineEditVictimName;
		QLineEdit* lineEditVictimPlace;
		QLineEdit* lineEditVictimAge;
		QLineEdit* lineEditVictimPhotograph;
		QLineEdit* lineEditFileLocation;
		QLineEdit* lineEditMyListLocation;

		QPushButton* addVictimButton;
		QPushButton* updateVictimButton;
		QPushButton* deleteVictimButton;
		QPushButton* fileLocationButton;
		QPushButton* myListLocationButton;

		QWidget* initializeWidgetModeA();
		QWidget* initializeWidgetModeB();
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateVictimList();

	public:
		GUI();
};

