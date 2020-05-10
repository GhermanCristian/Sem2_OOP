#pragma once
#include "inputValidator.h"
#include "controller.h"
#include <map>
#include <qwidget.h>
#include <QListWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QStackedWidget>
#include <qtoolbar.h>
#include <qtimer.h>
#include <qlabel.h>
#include <QtCharts/qchart.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qbarset.h>
#include <QtCharts/qbarcategoryaxis.h>
#include <QtCharts/qvalueaxis.h>
#include <QtCharts/qchartview.h>

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
		const std::string AXIS_TITLE_FONT_NAME = "Arial";
		const int AXIS_TITLE_FONT_SIZE = 14;
		const std::string CHART_TITLE_FONT_NAME = "Verdana";
		const int CHART_TITLE_FONT_SIZE = 14;
		const std::string AXIS_LABEL_FONT_NAME = "Arial";
		const int AXIS_LABEL_FONT_SIZE = 14;
		const std::string LEGEND_FONT_NAME = "Candara";
		const int LEGEND_FONT_SIZE = 14;

		const int FIRST_ROW_INDEX = 0;
		const int LIST_INDEX_ERROR_CODE = -1;

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

		QtCharts::QBarSeries* barSeries;

		QWidget* initializeWidgetModeA();
		QWidget* initializeWidgetModeB();
		QtCharts::QChartView* createBarChart();
		QWidget* initializeWidgetDataRepresentation();
		void changeToModeA();
		void changeToModeB();
		void changeToDataRepresentation();

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
		void populateBarSeries();

	public:
		GUI();
};

