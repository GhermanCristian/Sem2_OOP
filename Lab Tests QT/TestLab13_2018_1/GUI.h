#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

typedef ShoppingListItem TElem;

class GUI : public QWidget{
	private:
		Controller actionController;

		QListWidget* mainListWidget;
		QLineEdit* categoryLineEdit;
		QPushButton* deleteButton;
		QPushButton* filterButton;

		void deleteButtonAction();
		void filterActionButton();

	public:
		GUI();
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<TElem>& entityList);
		~GUI();
};

