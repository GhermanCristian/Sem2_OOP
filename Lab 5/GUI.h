#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QStackedWidget>
#include <qtoolbar.h>
#include "controller.h"
#include <qtimer.h>
#include <qlabel.h>
#include "inputValidator.h"

class GUI : public QWidget{
	private:
		const std::string DEFAULT_REPOSITORY_LOCATION = "data.txt";
		const std::string DEFAULT_MYLIST_LOCATION = "mylist.txt";
		const int MODE_A_WIDGET_INDEX = 0;
		const int MODE_B_WIDGET_INDEX = 1;
		const int DATA_REPRESENTATION_WIDGET_INDEX = 2;
		const int ERROR_MESSAGE_DISPLAY_TIME = 2000;

		const std::string LIST_FONT_NAME = "Arial";
		const int LIST_FONT_SIZE = 11;

		const int FIRST_ROW_INDEX = 0;

		Controller actionController;
		InputValidator inputValidator;

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

		QLabel* labelErrorMessageModeA;
		QLabel* labelErrorMessageModeB;
		QTimer* errorMessageTimer;

		QWidget* initializeWidgetModeA();
		QWidget* initializeWidgetModeB();
		void changeToModeA();
		void changeToModeB();

		void displayErrorMessage(const std::string& errorMessage);
		void removeErrorMessage();

		int getCurrentIndexInVictimList();
		void changedVictimInList();

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

