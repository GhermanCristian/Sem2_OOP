#include "GUI.h"

void GUI::showDurationButtonAction(){
	int priority = this->priorityLineEdit->text().toInt();
	int totalDuration = this->actionController.getTotalDurationWithGivenPriority(priority);
	this->totalDurationLabel->setText(QString::number(totalDuration));
}

GUI::GUI() {
	initializeGUI();
	connectSignalsAndSlots();

	this->actionController.loadFromFile("data.txt");
	//std::vector<Task> allEntities = this->actionController.getAllEntities();
	std::vector<Task> allEntities = this->actionController.getAllEntitiesSortedByPriority();
	this->populateList(this->mainListWidget, allEntities);
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* priorityLabel = new QLabel{"Priority"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->priorityLineEdit = new QLineEdit;

	this->showDurationButton = new QPushButton{ "Show duration" };
	this->totalDurationLabel = new QLabel{ "" };

	mainLayout->addWidget(this->mainListWidget);
	mainLayout->addWidget(priorityLabel);
	mainLayout->addWidget(this->priorityLineEdit);
	mainLayout->addWidget(this->showDurationButton);
	mainLayout->addWidget(this->totalDurationLabel);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->showDurationButton, &QPushButton::clicked, this, &GUI::showDurationButtonAction);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Task>& entityList){
	const std::string LIST_FONT_NAME = "Arial";
	const int LIST_FONT_SIZE = 14;
	const int FIRST_ROW_INDEX = 0;
	const int MAXIMUM_PRIORITY = 1;
	QFont normalListFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };
	QFont boldedListFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };
	boldedListFont.setBold(true);

	// check if it's not empty
	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentEntity : entityList) {
		QString entityText = QString::fromStdString(currentEntity.toString());
		QListWidgetItem* listItem = new QListWidgetItem{ entityText };

		if (currentEntity.getPriority() == MAXIMUM_PRIORITY) {
			listItem->setFont(boldedListFont);
		}
		else {
			listItem->setFont(normalListFont);
		}
		
		listWidget->addItem(listItem);
	}

	// check if it's not empty <=> there are elements to be selected
	if (listWidget->count() > 0) {
		listWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

GUI::~GUI() {

}
