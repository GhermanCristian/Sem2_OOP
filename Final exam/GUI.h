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
#include "customTableModel.h"
#include "Subject.h"
#include <qtableview.h>
#include <qcheckbox.h>
#include <qpainter.h>
#include <qpicture.h>

class GUI : public QWidget, public Subject{
	private:
		bool isChecked; // when this is true, only show the stars in the constellation; else show all stars

		Controller& actionController;
		CustomTableModel*& customTableModel;
		Astronomer astronomer;

		QTableView* tableView;
		QLineEdit* nameLineEdit;
		QLineEdit* RALineEdit;
		QLineEdit* DecLineEdit;
		QLineEdit* diameterLineEdit;
		QLineEdit* searchLineEdit;
		QPushButton* addStarButton;
		QPushButton* viewStarsButton;
		QListWidget* searchResults;

		QCheckBox* checkBox;

		void addStarButtonAction();
		void updateSearchList();
		void checkBoxAction();
		void viewStarsButtonAction();
		Star getSelectedStar();

	public:
		GUI(Controller& actionController, CustomTableModel*& customTableModel, Astronomer astronomer);
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Star>& entityList);
		~GUI();
};

