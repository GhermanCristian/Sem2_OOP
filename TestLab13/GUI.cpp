#include "GUI.h"

GUI::GUI() {
	initializeGUI();
	connectSignalsAndSlots();

	this->actionController.loadFromFile("data.txt");
	std::vector<Car> sortedCars = this->actionController.getAllCarsSortedByManufacturer();
	this->populateList(this->mainListWidget, sortedCars);
}

void GUI::showCarsButtonAction() {
	std::string carManufacturer = this->manufacturerLineEdit->text().toStdString();
	int numberOfCars = this->actionController.getNumberOfCarsByManufacturer(carManufacturer);
	this->numberOfCarsLabel->setText(QString::number(numberOfCars));
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* carManufacturerLabel = new QLabel{"Insert car manufacturer"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->manufacturerLineEdit = new QLineEdit;

	this->showCarsButton = new QPushButton{ "Show cars" };
	this->numberOfCarsLabel = new QLabel{};

	mainLayout->addWidget(this->mainListWidget);
	mainLayout->addWidget(carManufacturerLabel);
	mainLayout->addWidget(this->manufacturerLineEdit);
	mainLayout->addWidget(this->showCarsButton);
	mainLayout->addWidget(this->numberOfCarsLabel);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->showCarsButton, &QPushButton::clicked, this, &GUI::showCarsButtonAction);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Car>& entityList){
	const std::string LIST_FONT_NAME = "Arial";
	const int LIST_FONT_SIZE = 14;
	const int FIRST_ROW_INDEX = 0;
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	// check if it's not empty
	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentEntity : entityList) {
		QString entityText = QString::fromStdString(currentEntity.toString());
		QListWidgetItem* listItem = new QListWidgetItem{ entityText };
		listItem->setFont(listFont);

		// change the text color so that it matches the car's
		listItem->setTextColor(QString::fromStdString(currentEntity.getColor()));
		
		listWidget->addItem(listItem);
	}

	// check if it's not empty <=> there are elements to be selected
	if (listWidget->count() > 0) {
		listWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

GUI::~GUI() {

}
