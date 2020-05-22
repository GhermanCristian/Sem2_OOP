#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

typedef Bill TElem;

class GUI : public QWidget{
	private:
		Controller actionController;

		QListWidget* mainListWidget;
		QLineEdit* companyNameLineEdit;
		QPushButton* sortButton;
		QPushButton* calculateButton;
		QLabel* unpaidBillsCostLabel;

		void sortButtonAction();
		void calculateTotalButtonAction();

	public:
		GUI();
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<TElem>& entityList);
		~GUI();
};

