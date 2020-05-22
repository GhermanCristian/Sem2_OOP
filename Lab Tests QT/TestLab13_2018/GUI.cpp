#include "GUI.h"
#include <algorithm>

void GUI::sortButtonAction(){
	std::vector<Bill> allBills = this->actionController.getAllEntities();
	std::sort(allBills.begin(), allBills.end(), [this](const Bill& a, const Bill& b) {return a.getCompanyName() < b.getCompanyName(); });
	this->populateList(this->mainListWidget, allBills);
}

void GUI::calculateTotalButtonAction(){
	std::string companyName = this->companyNameLineEdit->text().toStdString();
	this->unpaidBillsCostLabel->setText(QString::number(this->actionController.getUnpaidBillsCostForCompany(companyName)));
}

GUI::GUI() {
	initializeGUI();
	connectSignalsAndSlots();

	std::vector<TElem> allEntities = this->actionController.getAllEntities();
	this->populateList(this->mainListWidget, allEntities);
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* label = new QLabel{"Company name"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->companyNameLineEdit = new QLineEdit;

	this->sortButton = new QPushButton{ "Sort bills" };
	this->calculateButton = new QPushButton{ "Calculate total" };
	this->unpaidBillsCostLabel = new QLabel{ "" };

	mainLayout->addWidget(this->mainListWidget);
	mainLayout->addWidget(label);
	mainLayout->addWidget(this->companyNameLineEdit);
	mainLayout->addWidget(this->sortButton);
	mainLayout->addWidget(this->calculateButton);
	mainLayout->addWidget(this->unpaidBillsCostLabel);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->sortButton, &QPushButton::clicked, this, &GUI::sortButtonAction);
	QObject::connect(this->calculateButton, &QPushButton::clicked, this, &GUI::calculateTotalButtonAction);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<TElem>& entityList){
	const std::string LIST_FONT_NAME = "Arial";
	const int LIST_FONT_SIZE = 14;
	const int FIRST_ROW_INDEX = 0;
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentEntity : entityList) {
		QString entityText = QString::fromStdString(currentEntity.toString());
		QListWidgetItem* listItem = new QListWidgetItem{ entityText };
		listItem->setFont(listFont);
		listWidget->addItem(listItem);
	}

	if (listWidget->count() > 0) {
		listWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

GUI::~GUI() {

}
