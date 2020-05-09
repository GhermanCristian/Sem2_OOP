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
		QListWidget* myListWidget;

		QLineEdit* lineEditVictimName;
		QLineEdit* lineEditVictimPlace;
		QLineEdit* lineEditVictimAge;
		QLineEdit* lineEditVictimPhotograph;
		QLineEdit* lineEditFileLocation;
		QLineEdit* lineEditSaveVictim;
		QLineEdit* lineEditFilterVictimPlace;
		QLineEdit* lineEditFilterVictimAge;
		QLineEdit* lineEditMyListLocation;

		QPushButton* addVictimButton;
		QPushButton* updateVictimButton;
		QPushButton* deleteVictimButton;
		QPushButton* fileLocationButton;
		QPushButton* saveVictimButton;
		QPushButton* filterVictimsButton;
		QPushButton* myListLocationButton;

		QWidget* initializeWidgetModeA();
		QWidget* initializeWidgetModeB();
		void changeToModeA();
		void changeToModeB();

		void addVictim();
		void updateVictim();
		void deleteVictim();
		void setFileLocation();
		void saveVictim();
		void filterVictims();
		void setMyListLocation();

		void initializeGUI();
		void connectSignalsAndSlots();
		void populateVictimList();
		void populateMyList();

	public:
		GUI();
};

