#include "GUI.h"

void GUI::addIdeabuttonAction(){
	std::string description = this->descriptionLineEdit->text().toStdString();
	int act = this->actLineEdit->text().toInt();
	try {
		this->actionController.addIdea(description, act, this->writer.getName());
		this->notify();
	}
	catch (...) {
		;
	}
}

GUI::GUI(Controller& actionController, CustomTableModel*& customTableModel, Writer writer) : actionController(actionController), customTableModel(customTableModel) {
	this->writer = writer;
	initializeGUI();
	connectSignalsAndSlots();
	this->setWindowTitle(QString::fromStdString(this->writer.getName()));
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* label = new QLabel{"Description, act"};

	this->descriptionLineEdit = new QLineEdit;
	this->actLineEdit = new QLineEdit;

	this->addIdeaButton = new QPushButton{ "Add idea" };

	this->tableView = new QTableView;
	this->tableView->setModel(this->customTableModel);
	this->tableView->resizeRowsToContents();
	this->tableView->resizeColumnsToContents();

	mainLayout->addWidget(this->tableView);
	mainLayout->addWidget(label);
	mainLayout->addWidget(this->descriptionLineEdit);
	mainLayout->addWidget(this->actLineEdit);
	mainLayout->addWidget(this->addIdeaButton);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->addIdeaButton, &QPushButton::clicked, this, &GUI::addIdeabuttonAction);
}

GUI::~GUI() {

}
