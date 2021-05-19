#include "GUI.h"

void GUI::addStarButtonAction(){
	std::string name = this->nameLineEdit->text().toStdString();
	std::string constellation = this->astronomer.getConstellation();
	int RA = this->RALineEdit->text().toInt();
	int dec = this->DecLineEdit->text().toInt();
	int diameter = this->diameterLineEdit->text().toInt();

	try {
		this->actionController.addStar(name, constellation, RA, dec, diameter);
		this->notify();
	}
	catch (const std::exception& exception) {
		QMessageBox::critical(this, "error add star", exception.what());
	}
}

void GUI::updateSearchList(){
	std::string name = this->searchLineEdit->text().toStdString();
	std::vector<Star> filteredStars = this->actionController.getAllStarsByName(name);
	this->populateList(this->searchResults, filteredStars);
}

void GUI::checkBoxAction(){
	this->isChecked = !this->isChecked;

	std::vector<Star> allStars = this->actionController.getAllStars();
	if (this->isChecked) { // show only the stars in the constellation
		// we hide the stars that don't match
		for (int row = 0; row < allStars.size(); row++) {
			if (allStars[row].getConstellation() != this->astronomer.getConstellation()) {
				this->tableView->setRowHidden(row, true);
			}
		}
	}

	else {
		// we show all the stars
		for (int row = 0; row < allStars.size(); row++) {
			this->tableView->setRowHidden(row, false);
		}
	}
}

void GUI::viewStarsButtonAction(){
	Star selectedStar = this->getSelectedStar();
	if (selectedStar.getName() == "") { // if it's the default, empty star => don't do anything, bc no star is selected
		return;
	}

	std::vector<Star> allStars = this->actionController.getAllStarsByConstellation(selectedStar.getConstellation());

	QPicture* p = new QPicture;
	QPainter* drawing = new QPainter(p);
	drawing->setRenderHint(QPainter::Antialiasing);

	for (auto star : allStars) {
		if (star.getName() == selectedStar.getName()) {
			drawing->setBrush(Qt::red);
		}
		else {
			drawing->setBrush(Qt::black);
		}
		drawing->drawEllipse(QPoint(star.getRA(), star.getDec()), star.getDiameter(), star.getDiameter());
	}

	drawing->end();

	QLabel* l = new QLabel;
	l->setPicture(*p);
	l->show();
}

Star GUI::getSelectedStar(){
	QModelIndexList selection = this->tableView->selectionModel()->selectedIndexes();

	if (selection.count() == 0) {
		return Star();
	}

	// in initializeGUI we have set the selection model to single selection,
	//so we know there is exactly 1 element selected at a time
	QModelIndex index = selection.at(0);
	int row = index.row(); // the row of the element is the index of the element in the list

	// if we have the constellation mode, we will need to check another list
	return this->actionController.getAllStars()[row];
}

GUI::GUI(Controller& actionController, CustomTableModel*& customTableModel, Astronomer astronomer) : actionController(actionController), customTableModel(customTableModel) {
	this->astronomer = astronomer;
	this->isChecked = false;
	initializeGUI();
	connectSignalsAndSlots();

	this->setWindowTitle(QString::fromStdString(this->astronomer.getName()));
}

void GUI::initializeGUI() {
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout{mainWidget};
	QLabel* infoLabel = new QLabel{"Name, RA, dec, diameter"};
	QLabel* searchLabel = new QLabel{"Search by name"};

	this->nameLineEdit = new QLineEdit;
	this->RALineEdit = new QLineEdit;
	this->DecLineEdit = new QLineEdit;
	this->diameterLineEdit = new QLineEdit;
	this->searchLineEdit = new QLineEdit;

	this->addStarButton = new QPushButton{ "Add star" };
	this->viewStarsButton = new QPushButton{ "View current star" };

	this->tableView = new QTableView;
	this->tableView->setModel(this->customTableModel);
	this->tableView->resizeRowsToContents();
	this->tableView->resizeColumnsToContents();
	this->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	this->searchResults = new QListWidget;
	this->checkBox = new QCheckBox;

	mainLayout->addWidget(this->tableView);
	mainLayout->addWidget(this->checkBox);
	mainLayout->addWidget(infoLabel);
	mainLayout->addWidget(this->nameLineEdit);
	mainLayout->addWidget(this->RALineEdit);
	mainLayout->addWidget(this->DecLineEdit);
	mainLayout->addWidget(this->diameterLineEdit);
	mainLayout->addWidget(this->addStarButton);
	mainLayout->addWidget(searchLabel);
	mainLayout->addWidget(this->searchLineEdit);
	mainLayout->addWidget(this->searchResults);
	mainLayout->addWidget(this->viewStarsButton);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->addStarButton, &QPushButton::clicked, this, &GUI::addStarButtonAction);
	QObject::connect(this->viewStarsButton, &QPushButton::clicked, this, &GUI::viewStarsButtonAction);
	QObject::connect(this->searchLineEdit, &QLineEdit::textChanged, this, &GUI::updateSearchList);
	QObject::connect(this->checkBox, &QCheckBox::stateChanged, this, &GUI::checkBoxAction);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Star>& entityList){
	const std::string LIST_FONT_NAME = "Arial";
	const int LIST_FONT_SIZE = 14;
	const int FIRST_ROW_INDEX = 0;
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	// check if it's not empty
	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentEntity : entityList) {
		std::string text = currentEntity.toString();

		QString entityText = QString::fromStdString(text);
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
