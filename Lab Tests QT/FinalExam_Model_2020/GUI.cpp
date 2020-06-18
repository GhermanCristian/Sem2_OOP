#include "GUI.h"

void GUI::addIssueButtonAction(){
	std::string issueDescription = this->issueLineEdit->text().toStdString();
	std::string issueStatus = "open";
	std::string issueReporter = this->user.getName();
	std::string issueSolver = "-";
	try {
		this->actionController.addIssue(issueDescription, issueStatus, issueReporter, issueSolver);
	}
	catch (const std::exception& exception) {
		QMessageBox* errorMessage = new QMessageBox;
		errorMessage->setText(exception.what());
		errorMessage->show();
	}
}

void GUI::solveIssueButtonAction(){
	std::string description = this->solveIssueLineEdit->text().toStdString();
	std::string solver = this->user.getName();
	try {
		this->actionController.solveIssueByDescription(description, solver);
	}
	catch (const std::exception& exception) {
		QMessageBox* errorMessage = new QMessageBox;
		errorMessage->setText(exception.what());
		errorMessage->show();
	}
}

void GUI::removeIssueButtonAction(){
	std::string description = this->removeIssueLineEdit->text().toStdString();
	try {
		this->actionController.removeIssueByDescription(description);
	}
	catch (const std::exception& exception) {
		QMessageBox* errorMessage = new QMessageBox;
		errorMessage->setText(exception.what());
		errorMessage->show();
	}
}

GUI::GUI(Controller& actionController, User user) : actionController(actionController){
	this->user = user;
	initializeGUI();
	connectSignalsAndSlots();

	std::vector<Issue> allEntities = this->actionController.getAllIssuesSorted();
	this->populateList(this->mainListWidget, allEntities);
	this->setWindowTitle(QString::fromStdString(this->user.toString()));
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* issueDescriptionLabel = new QLabel{"Issue description"};
	QLabel* removeIssueDescriptionLabel = new QLabel{"Remove issue"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->issueLineEdit = new QLineEdit;
	this->removeIssueLineEdit = new QLineEdit;
	this->solveIssueLineEdit = new QLineEdit;

	this->addIssueButton = new QPushButton{ "Add issue" };
	this->solveIssueButton = new QPushButton{ "Solve issue" };
	this->removeIssueButton = new QPushButton{ "Remove issue" };

	mainLayout->addWidget(this->mainListWidget);

	if (this->user.getType() == "tester") {
		mainLayout->addWidget(issueDescriptionLabel);
		mainLayout->addWidget(this->issueLineEdit);
		mainLayout->addWidget(this->addIssueButton);
	}
	else {
		mainLayout->addWidget(this->solveIssueLineEdit);
		mainLayout->addWidget(this->solveIssueButton);
	}

	mainLayout->addWidget(removeIssueDescriptionLabel);
	mainLayout->addWidget(this->removeIssueLineEdit);
	mainLayout->addWidget(this->removeIssueButton);
	
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->addIssueButton, &QPushButton::clicked, this, &GUI::addIssueButtonAction);
	QObject::connect(this->solveIssueButton, &QPushButton::clicked, this, &GUI::solveIssueButtonAction);
	QObject::connect(this->removeIssueButton, &QPushButton::clicked, this, &GUI::removeIssueButtonAction);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Issue>& entityList){
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
	std::vector<Issue> allEntities = this->actionController.getAllIssuesSorted();
	this->populateList(this->mainListWidget, allEntities);
}

GUI::~GUI() {

}
