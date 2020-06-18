#include "GUI.h"

void GUI::addTaskButtonAction(){
	std::string description = this->addTaskLineEdit->text().toStdString();
	this->actionController.addTask(description);
	this->update();
}

void GUI::removeTaskButtonAction(){
	std::string description = this->removeTaskLineEdit->text().toStdString();
	try {
		this->actionController.removeTask(description);
		this->update();
	}
	catch (const std::exception& exception) {
		QMessageBox::critical(this, "error remove task", exception.what());
	}
}

void GUI::startButtonAction(){
	std::string description = this->startLineEdit->text().toStdString();
	try {
		this->actionController.startTask(description, this->programmer);
		this->update();
	}
	catch (const UnopenedTask& exception) {
		QMessageBox::critical(this, "error start button", exception.what());
	}
}

void GUI::doneButtonAction(){
	Task currentTask = this->selectTaskInList();
	try {
		this->actionController.doneTask(currentTask.getDescription());
		this->update();
	}
	catch (const std::exception& exception) {
		QMessageBox::critical(this, "error done button", exception.what());
	}
}

GUI::GUI(Controller& actionController, Programmer programmer) : actionController(actionController) {
	this->programmer = programmer;
	initializeGUI();
	connectSignalsAndSlots();

	this->update();
	this->setWindowTitle(QString::fromStdString(this->programmer.getName()));
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* addTaskLabel = new QLabel{"Add task"};
	QLabel* removeTaskLabel = new QLabel{"Remove task"};
	QLabel* startLabel = new QLabel{"Start task"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->addTaskLineEdit = new QLineEdit;
	this->removeTaskLineEdit = new QLineEdit;
	this->startLineEdit = new QLineEdit;

	this->addTaskButton = new QPushButton{ "Add task" };
	this->removeTaskButton = new QPushButton{ "Remove task" };
	this->startButton = new QPushButton{ "Start task" };
	this->doneButton = new QPushButton{ "Done task" };
	this->doneButton->setVisible(false);

	mainLayout->addWidget(this->mainListWidget);
	mainLayout->addWidget(addTaskLabel);
	mainLayout->addWidget(this->addTaskLineEdit);
	mainLayout->addWidget(this->addTaskButton);
	mainLayout->addWidget(removeTaskLabel);
	mainLayout->addWidget(this->removeTaskLineEdit);
	mainLayout->addWidget(this->removeTaskButton);
	mainLayout->addWidget(startLabel);
	mainLayout->addWidget(this->startLineEdit);
	mainLayout->addWidget(this->startButton);
	mainLayout->addWidget(this->doneButton);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->addTaskButton, &QPushButton::clicked, this, &GUI::addTaskButtonAction);
	QObject::connect(this->removeTaskButton, &QPushButton::clicked, this, &GUI::removeTaskButtonAction);
	QObject::connect(this->startButton, &QPushButton::clicked, this, &GUI::startButtonAction);
	QObject::connect(this->doneButton, &QPushButton::clicked, this, &GUI::doneButtonAction);
	QObject::connect(this->mainListWidget, &QListWidget::itemSelectionChanged, this, &GUI::selectTaskInList);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Task>& entityList){
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
		listWidget->addItem(listItem);
	}

	// check if it's not empty <=> there are elements to be selected
	if (listWidget->count() > 0) {
		listWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

void GUI::update(){
	std::vector<Task> allEntities = this->actionController.getAllTasksSorted();
	this->populateList(this->mainListWidget, allEntities);
}

int GUI::getCurrentTaskIndex(){
	if (this->mainListWidget->count() == 0) {
		return LIST_INDEX_ERROR_CODE;
	}

	const int FIRST_INDEX_LIST_POSITION = 0;
	QModelIndexList taskIndex = this->mainListWidget->selectionModel()->selectedIndexes();
	if (taskIndex.size() == 0) {
		this->addTaskLineEdit->clear();
		this->removeTaskLineEdit->clear();
		this->startLineEdit->clear();
		return LIST_INDEX_ERROR_CODE;
	}

	return taskIndex.at(FIRST_INDEX_LIST_POSITION).row();
}

Task GUI::selectTaskInList(){
	int taskIndex = this->getCurrentTaskIndex();
	std::vector<Task> sortedTasks = this->actionController.getAllTasksSorted();
	if (taskIndex == LIST_INDEX_ERROR_CODE || taskIndex < 0 || taskIndex > sortedTasks.size()) {
		return Task();
	}
	
	Task currentTask = sortedTasks[taskIndex];

	this->addTaskLineEdit->setText(QString::fromStdString(currentTask.getDescription()));
	this->removeTaskLineEdit->setText(QString::fromStdString(currentTask.getDescription()));
	this->startLineEdit->setText(QString::fromStdString(currentTask.getDescription()));

	if (currentTask.getStatus() == "in progress" && currentTask.getID() == this->programmer.getID()) {
		this->doneButton->setVisible(true);
	}
	else {
		this->doneButton->setVisible(false);
	}

	return currentTask;
}

GUI::~GUI() {

}
