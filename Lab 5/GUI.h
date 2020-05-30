#pragma once
#include "inputValidator.h"
#include "controller.h"
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
#include "customTableModel.h"
#include <qtableview.h>

class GUI : public QWidget{
	private:
		const int MODE_A_WIDGET_INDEX = 0;
		const int MODE_B_WIDGET_INDEX = 1;
		const int DATA_REPRESENTATION_WIDGET_INDEX = 2;
		const int ERROR_MESSAGE_DISPLAY_TIME = 2000; // in miliseconds
		const int FILTERED_LIST_WIDGET_HEIGHT = 400;
		const int NEXT_VICTIM_LABEL_HEIGHT = 50;

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
		QListWidget* filteredListWidget;

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
		QPushButton* undoModeAButton;
		QPushButton* redoModeAButton;
		QPushButton* nextVictimButton;
		QPushButton* saveVictimButton;
		QPushButton* filterVictimsButton;
		QPushButton* myListLocationButton;
		QPushButton* openExternalProgramButton;
		QPushButton* showMylistButton;
		QPushButton* undoModeBButton;
		QPushButton* redoModeBButton;

		QLabel* nextVictimLabel;

		CustomTableModel* mylistTableModel;
		QTableView* mylistTableView;

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
		void undoModeA();
		void redoModeA();
		void nextVictim();
		void saveVictim();
		void filterVictims();
		void setMyListLocation();
		void openExternalProgram();
		void showMylist();
		void undoModeB();
		void redoModeB();

		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Victim>& victimList);
		void populateBarSeries();

	public:
		GUI();
};

