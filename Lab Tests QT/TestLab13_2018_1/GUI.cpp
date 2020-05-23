#include "GUI.h"

void GUI::deleteButtonAction(){
	QModelIndexList selectedIndices = this->mainListWidget->selectionModel()->selectedIndexes();

	// if there are no selected items => nothing to delete
	if (selectedIndices.empty()) {
		return;
	}

	int positionInList = selectedIndices.at(0).row();

	try {
		this->actionController.deleteItemByIndex(positionInList);
	}
	catch (...) {
		;
	}
	
	std::vector <ShoppingListItem> allItems = this->actionController.getAllEntities();
	this->populateList(this->mainListWidget, allItems);
}

void GUI::filterActionButton(){
	std::string category = this->categoryLineEdit->text().toStdString();
	std::vector <ShoppingListItem> filteredItems = this->actionController.filterByCategory(category);
	this->populateList(this->mainListWidget, filteredItems);
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
	QLabel* label = new QLabel{"Filter items (insert category)"};

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->categoryLineEdit = new QLineEdit;

	this->deleteButton = new QPushButton{ "Delete item" };
	this->filterButton = new QPushButton{ "Filter items" };

	mainLayout->addWidget(this->mainListWidget);
	mainLayout->addWidget(this->deleteButton);
	mainLayout->addWidget(label);
	mainLayout->addWidget(this->categoryLineEdit);
	mainLayout->addWidget(this->filterButton);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteButtonAction);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filterActionButton);
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
