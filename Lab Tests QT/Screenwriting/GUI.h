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

class GUI : public QWidget, public Subject{
	private:
		Controller& actionController;
		CustomTableModel*& customTableModel;
		Writer writer;

		QTableView* tableView;
		QLineEdit* descriptionLineEdit;
		QLineEdit* actLineEdit;
		QPushButton* addIdeaButton;

		void addIdeabuttonAction();

	public:
		GUI(Controller& actionController, CustomTableModel*& customTableModel, Writer writer);
		void initializeGUI();
		void connectSignalsAndSlots();
		~GUI();
};

