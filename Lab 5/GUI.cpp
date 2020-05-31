#include "GUI.h"
#include <qboxlayout.h>
#include <QFormLayout>
#include <qdebug.h>
#include <Windows.h>

void GUI::initializeTableView(){
	this->mylistTableModel = new CustomTableModel{ this->actionController };
	this->mylistTableView = new QTableView{};
	this->mylistTableView->setModel(this->mylistTableModel);
	this->mylistTableView->setItemDelegate(new CustomDelegate());
	this->mylistTableView->resizeRowsToContents();
	this->mylistTableView->resizeColumnsToContents();
}

QWidget* GUI::initializeWidgetModeA(){
	QWidget* modeAWidget = new QWidget;
	QVBoxLayout* modeALayout = new QVBoxLayout{ modeAWidget };

	QToolBar* modeAToolbar = new QToolBar{};

	QLabel* labelVictimName = new QLabel{ "&Victim's name:" };
	QLabel* labelVictimPlace = new QLabel{ "&Victim's place of origin:" };
	QLabel* labelVictimAge = new QLabel{ "&Victim's age:" };
	QLabel* labelVictimPhotograph = new QLabel{ "&Victim's photograph link:" };
	QLabel* labelFileLocation = new QLabel{ "&File location:" };

	QWidget* textBoxesAreaWidget = new QWidget{};
	QFormLayout* textBoxesAreaLayout = new QFormLayout{ textBoxesAreaWidget };

	QWidget* buttonAreaWidget = new QWidget{};
	QHBoxLayout* buttonAreaLayout = new QHBoxLayout{ buttonAreaWidget };

	QWidget* fileLocationAreaWidget = new QWidget{};
	QFormLayout* fileLocationAreaLayout = new QFormLayout{ fileLocationAreaWidget };

	QWidget* undoRedoAreaWidget = new QWidget{};
	QHBoxLayout* undoRedoAreaLayout = new QHBoxLayout{ undoRedoAreaWidget };

	this->lineEditVictimName = new QLineEdit{};
	this->lineEditVictimPlace = new QLineEdit{};
	this->lineEditVictimAge = new QLineEdit{};
	this->lineEditVictimPhotograph = new QLineEdit{};
	this->lineEditFileLocation = new QLineEdit{};

	this->addVictimButton = new QPushButton{ "Add victim" };
	this->updateVictimButton = new QPushButton{ "Update victim" };
	this->deleteVictimButton = new QPushButton{ "Delete victim" };
	this->fileLocationButton = new QPushButton{ "Set file location" };
	this->undoModeAButton = new QPushButton{ "Undo" };
	this->redoModeAButton = new QPushButton{ "Redo" };

	modeAToolbar->addAction(menuActionModeA);
	modeAToolbar->addAction(menuActionModeB);
	modeAToolbar->addAction(menuActionDataRepresentation);

	buttonAreaLayout->addWidget(this->addVictimButton);
	buttonAreaLayout->addWidget(this->updateVictimButton);
	buttonAreaLayout->addWidget(this->deleteVictimButton);

	undoRedoAreaLayout->addWidget(this->undoModeAButton);
	undoRedoAreaLayout->addWidget(this->redoModeAButton);

	labelVictimName->setBuddy(lineEditVictimName);
	labelVictimPlace->setBuddy(lineEditVictimPlace);
	labelVictimAge->setBuddy(lineEditVictimAge);
	labelVictimPhotograph->setBuddy(lineEditVictimPhotograph);
	textBoxesAreaLayout->addRow(labelVictimName, lineEditVictimName);
	textBoxesAreaLayout->addRow(labelVictimPlace, lineEditVictimPlace);
	textBoxesAreaLayout->addRow(labelVictimAge, lineEditVictimAge);
	textBoxesAreaLayout->addRow(labelVictimPhotograph, lineEditVictimPhotograph);

	labelFileLocation->setBuddy(lineEditFileLocation);
	fileLocationAreaLayout->addRow(labelFileLocation, lineEditFileLocation);

	modeALayout->addWidget(modeAToolbar);
	modeALayout->addWidget(this->victimListWidget);
	modeALayout->addWidget(textBoxesAreaWidget);
	modeALayout->addWidget(buttonAreaWidget);
	modeALayout->addWidget(fileLocationAreaWidget);
	modeALayout->addWidget(this->fileLocationButton);
	modeALayout->addWidget(undoRedoAreaWidget);
	modeALayout->addWidget(this->labelErrorMessageModeA);

	if (this->actionController.isInMemoryRepository() == true) {
		fileLocationAreaWidget->hide();
		fileLocationButton->hide();
	}

	return modeAWidget;
}

QWidget* GUI::initializeWidgetModeB(){
	QWidget* modeBWidget = new QWidget;
	QWidget* leftSideWidget = new QWidget;

	QVBoxLayout* leftSideLayout = new QVBoxLayout{ leftSideWidget };
	QHBoxLayout* modeBLayout = new QHBoxLayout{ modeBWidget };

	QToolBar* modeBToolbar = new QToolBar;

	QLabel* labelSaveVictim = new QLabel{"&Victim's name:"};
	QLabel* labelFilterVictimPlace = new QLabel{"&Victim's place of origin:"};
	QLabel* labelFilterVictimAge = new QLabel{"&Victim's age:"};
	QLabel* labelMyListLocation = new QLabel{"&MyList location:"};

	QWidget* saveVictimWidget = new QWidget{};
	QFormLayout* saveVictimLayout = new QFormLayout{ saveVictimWidget };

	QWidget* filterVictimsWidget = new QWidget{};
	QFormLayout* filterVictimsLayout = new QFormLayout{ filterVictimsWidget };

	QWidget* myListLocationWidget = new QWidget{};
	QFormLayout* myListLocationLayout = new QFormLayout{ myListLocationWidget };

	QWidget* undoRedoAreaWidget = new QWidget{};
	QHBoxLayout* undoRedoAreaLayout = new QHBoxLayout{ undoRedoAreaWidget };

	modeBToolbar->addAction(menuActionModeA);
	modeBToolbar->addAction(menuActionModeB);
	modeBToolbar->addAction(menuActionDataRepresentation);

	this->initializeTableView();

	this->nextVictimLabel = new QLabel{};
	this->nextVictimLabel->setFixedHeight(NEXT_VICTIM_LABEL_HEIGHT);
	this->nextVictimLabel->setFont(QFont(QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE));

	this->nextVictimButton = new QPushButton{ "Next victim" };
	this->saveVictimButton = new QPushButton{ "Save victim" };
	this->filterVictimsButton = new QPushButton{ "Filter victims" };
	this->myListLocationButton = new QPushButton{ "Set myList location" };
	this->openExternalProgramButton = new QPushButton{ "Open with external application" };
	this->showMylistButton = new QPushButton{ "Show mylist" };
	this->undoModeBButton = new QPushButton{ "Undo" };
	this->redoModeBButton = new QPushButton{ "Redo" };

	this->lineEditSaveVictim = new QLineEdit{};
	this->lineEditFilterVictimPlace = new QLineEdit{};
	this->lineEditFilterVictimAge = new QLineEdit{};
	this->lineEditMyListLocation = new QLineEdit{};

	labelSaveVictim->setBuddy(lineEditSaveVictim);
	saveVictimLayout->addRow(labelSaveVictim, lineEditSaveVictim);

	labelFilterVictimPlace->setBuddy(lineEditFilterVictimPlace);
	filterVictimsLayout->addRow(labelFilterVictimPlace, lineEditFilterVictimPlace);
	labelFilterVictimAge->setBuddy(lineEditFilterVictimAge);
	filterVictimsLayout->addRow(labelFilterVictimAge, lineEditFilterVictimAge);

	labelMyListLocation->setBuddy(lineEditMyListLocation);
	myListLocationLayout->addRow(labelMyListLocation, lineEditMyListLocation);

	undoRedoAreaLayout->addWidget(this->undoModeBButton);
	undoRedoAreaLayout->addWidget(this->redoModeBButton);

	leftSideLayout->addWidget(modeBToolbar);
	leftSideLayout->addWidget(this->nextVictimLabel);
	leftSideLayout->addWidget(this->nextVictimButton);
	leftSideLayout->addWidget(this->showMylistButton);
	leftSideLayout->addWidget(saveVictimWidget);
	leftSideLayout->addWidget(saveVictimButton);
	leftSideLayout->addWidget(filterVictimsWidget);
	leftSideLayout->addWidget(this->filterVictimsButton);
	leftSideLayout->addWidget(myListLocationWidget);
	leftSideLayout->addWidget(this->myListLocationButton);
	leftSideLayout->addWidget(this->openExternalProgramButton);
	leftSideLayout->addWidget(undoRedoAreaWidget);
	leftSideLayout->addWidget(this->labelErrorMessageModeB);

	modeBLayout->addWidget(leftSideWidget);
	modeBLayout->addWidget(this->filteredListWidget);

	if (this->actionController.isInMemoryRepository() == true) {
		myListLocationWidget->hide();
		this->myListLocationButton->hide();
		this->openExternalProgramButton->hide();
	}

	return modeBWidget;
}

QtCharts::QChartView* GUI::createBarChart(){
	QtCharts::QChart* dataRepresentationChart = new QtCharts::QChart;
	QFont* axisTitleFont = new QFont{ QString::fromStdString(AXIS_TITLE_FONT_NAME), AXIS_TITLE_FONT_SIZE };
	QFont* chartTitleFont = new QFont{ QString::fromStdString(CHART_TITLE_FONT_NAME), CHART_TITLE_FONT_SIZE };
	QFont* axisLabelFont = new QFont{ QString::fromStdString(AXIS_LABEL_FONT_NAME), AXIS_LABEL_FONT_SIZE };
	QFont* legendFont = new QFont{ QString::fromStdString(LEGEND_FONT_NAME), LEGEND_FONT_SIZE };

	const int AXIS_MINIMUM_VALUE = 0;
	const int AXIS_MAXIMUM_VALUE = 5;

	this->barSeries = new QtCharts::QBarSeries;
	this->populateBarSeries();
	
	dataRepresentationChart->addSeries(barSeries);
	dataRepresentationChart->setTitle("Victims by place of origin");
	dataRepresentationChart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

	QtCharts::QValueAxis* axisY = new QtCharts::QValueAxis();
	axisY->setRange(AXIS_MINIMUM_VALUE, AXIS_MAXIMUM_VALUE);
	axisY->setLabelsFont(*axisLabelFont);
	axisY->setTitleText("Number of victims");
	axisY->setTitleFont(*axisTitleFont);
	axisY->applyNiceNumbers();
	dataRepresentationChart->addAxis(axisY, Qt::AlignLeft);
	barSeries->attachAxis(axisY);
	dataRepresentationChart->setTitleFont(*chartTitleFont);
	dataRepresentationChart->legend()->setFont(*legendFont);
	dataRepresentationChart->legend()->setVisible(true);
	dataRepresentationChart->legend()->setAlignment(Qt::AlignBottom);
	QtCharts::QChartView* chartView = new QtCharts::QChartView{ dataRepresentationChart };
	chartView->setRenderHint(QPainter::Antialiasing);

	return chartView;
}

QWidget* GUI::initializeWidgetDataRepresentation(){
	QWidget* dataRepresentationWidget = new QWidget{};
	QVBoxLayout* dataRepresentationLayout = new QVBoxLayout{ dataRepresentationWidget };
	QToolBar* dataRepresentationToolbar = new QToolBar;
	QtCharts::QChartView* chartView = createBarChart();

	dataRepresentationToolbar->addAction(menuActionModeA);
	dataRepresentationToolbar->addAction(menuActionModeB);
	dataRepresentationToolbar->addAction(menuActionDataRepresentation);

	dataRepresentationLayout->addWidget(dataRepresentationToolbar);
	dataRepresentationLayout->addWidget(chartView);

	return dataRepresentationWidget;
}

void GUI::changeToModeA(){
	this->allWidgets->setCurrentIndex(MODE_A_WIDGET_INDEX);
}

void GUI::changeToModeB(){
	this->allWidgets->setCurrentIndex(MODE_B_WIDGET_INDEX);
	//this->mylistTableView->show();
}

void GUI::changeToDataRepresentation(){
	this->allWidgets->setCurrentIndex(DATA_REPRESENTATION_WIDGET_INDEX);
}

void GUI::notifyModel(){
	this->mylistTableModel->updateInternalData();
	this->mylistTableView->resizeRowsToContents();
}

void GUI::displayErrorMessage(const std::string& errorMessage) {
	this->labelErrorMessageModeA->setText(QString::fromStdString(errorMessage));
	this->labelErrorMessageModeB->setText(QString::fromStdString(errorMessage));
	this->errorMessageTimer->start(ERROR_MESSAGE_DISPLAY_TIME);
}

void GUI::removeErrorMessage(){
	this->labelErrorMessageModeA->setText(""); // sets the content to an empty string <=> removes it
	this->labelErrorMessageModeB->setText("");
}

int GUI::getCurrentIndexInVictimList(){
	if (this->victimListWidget->count() == 0) {
		return LIST_INDEX_ERROR_CODE;
	}

	const int FIRST_INDEX_LIST_POSITION = 0;
	QModelIndexList victimIndex = this->victimListWidget->selectionModel()->selectedIndexes();
	if (victimIndex.size() == 0) {
		this->lineEditVictimName->clear();
		this->lineEditVictimPlace->clear();
		this->lineEditVictimAge->clear();
		this->lineEditVictimPhotograph->clear();
		return LIST_INDEX_ERROR_CODE;
	}

	return victimIndex.at(FIRST_INDEX_LIST_POSITION).row();
}

void GUI::changedVictimInList(){
	int victimIndex = getCurrentIndexInVictimList();
	std::vector <Victim> allVictims = this->actionController.getAllVictims();

	if (victimIndex == LIST_INDEX_ERROR_CODE || victimIndex >= allVictims.size()) {
		return;
	}

	this->lineEditVictimName->setText(QString::fromStdString(allVictims[victimIndex].getName()));
	this->lineEditVictimPlace->setText(QString::fromStdString(allVictims[victimIndex].getPlaceOfOrigin()));
	this->lineEditVictimAge->setText(QString().setNum(allVictims[victimIndex].getAge()));
	this->lineEditVictimPhotograph->setText(QString::fromStdString(allVictims[victimIndex].getPhotographLink()));
}

bool GUI::eventFilter(QObject* object, QEvent* currentEvent){
	if (currentEvent->type() == QEvent::KeyPress) {
		QKeyEvent* pressedKey = (QKeyEvent*)currentEvent;
		if (pressedKey->key() == Qt::Key_Control) {
			this->pressedCTRLKey = true;
		}
		if (pressedKey->key() == Qt::Key_Y) {
			this->pressedYKey = true;
		}
		if (pressedKey->key() == Qt::Key_Z) {
			this->pressedZKey = true;
		}

		if (this->pressedCTRLKey) {
			if (this->pressedZKey) { // CTRL-Z - undo
				if (this->allWidgets->currentIndex() == MODE_A_WIDGET_INDEX) {
					this->undoModeA();
				}
				else if (this->allWidgets->currentIndex() == MODE_B_WIDGET_INDEX) {
					this->undoModeB();
				}
				this->pressedCTRLKey = this->pressedZKey = false; // reset the pressed key values
			}
			else if (this->pressedYKey) { // CTRL-Y - redo
				if (this->allWidgets->currentIndex() == MODE_A_WIDGET_INDEX) {
					this->redoModeA();
				}
				else if (this->allWidgets->currentIndex() == MODE_B_WIDGET_INDEX) {
					this->redoModeB();
				}
				this->pressedCTRLKey = this->pressedYKey = false; // reset the pressed key values
			}
		}

		return true;
	}

	return false;
}

void GUI::addVictim(){
	try {
		std::string victimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimName->text().toStdString());
		std::string victimPlace = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPlace->text().toStdString());
		int victimAge = this->inputValidator.generalNumberValidator(this->lineEditVictimAge->text().toStdString());
		std::string victimPhotograph = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPhotograph->text().toStdString());

		this->actionController.addVictim(victimName, victimPlace, victimAge, victimPhotograph);
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
		this->populateBarSeries();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::updateVictim(){
	try {
		std::string newVictimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimName->text().toStdString());
		std::string newVictimPlace = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPlace->text().toStdString());
		int newVictimAge = this->inputValidator.generalNumberValidator(this->lineEditVictimAge->text().toStdString());
		std::string newVictimPhotograph = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPhotograph->text().toStdString());

		this->actionController.updateVictim(newVictimName, newVictimPlace, newVictimAge, newVictimPhotograph);
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
		this->populateBarSeries();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::deleteVictim(){
	try {
		std::string victimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimName->text().toStdString());
		this->actionController.deleteVictim(victimName);
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
		this->populateBarSeries();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::setFileLocation(){
	try {
		std::string fileLocation = this->inputValidator.generalNonEmptyStringValidator(this->lineEditFileLocation->text().toStdString());
		this->actionController.setRepositoryFileLocation(fileLocation);
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
		this->populateBarSeries();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::undoModeA(){
	try {
		this->actionController.undoModeA();
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::redoModeA(){
	try {
		this->actionController.redoModeA();
		std::vector<Victim> allVictims = this->actionController.getAllVictims();
		this->populateList(this->victimListWidget, allVictims);
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::nextVictim(){
	try {
		Victim currentVictim = this->actionController.getNextVictim();
		this->nextVictimLabel->setText(QString::fromStdString(currentVictim.getCSVRepresentation()));
		this->lineEditSaveVictim->setText(QString::fromStdString(currentVictim.getName()));
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::saveVictim(){
	try {
		std::string victimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditSaveVictim->text().toStdString());
		this->actionController.saveVictim(victimName);
		this->notifyModel();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::filterVictims(){
	try {
		std::string victimPlaceOfOrigin = this->lineEditFilterVictimPlace->text().toStdString();
		int victimAge = this->inputValidator.generalNumberValidator(this->lineEditFilterVictimAge->text().toStdString());
		std::vector<Victim> filteredVictims = this->actionController.getFilteredVictims(victimPlaceOfOrigin, victimAge);
		this->populateList(this->filteredListWidget, filteredVictims);
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::setMyListLocation(){
	try {
		std::string myListLocation = this->inputValidator.generalNonEmptyStringValidator(this->lineEditMyListLocation->text().toStdString());
		this->actionController.setSavedVictimsFileLocation(myListLocation);
		this->notifyModel();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::openExternalProgram(){
	ShellExecuteA(NULL, "open", this->actionController.getMylistPath().c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void GUI::showMylist(){
	this->mylistTableView->show();
}

void GUI::undoModeB(){
	try {
		this->actionController.undoModeB();
		this->notifyModel();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::redoModeB(){
	try {
		this->actionController.redoModeB();
		this->notifyModel();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::initializeGUI() {
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;

	this->allWidgets = new QStackedWidget{};
	this->menuActionModeA = new QAction{ "&Mode A", this };
	this->menuActionModeB = new QAction{ "&Mode B", this };
	this->menuActionDataRepresentation = new QAction{ "&Data representation", this };

	this->victimListWidget = new QListWidget{};
	this->victimListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	this->filteredListWidget = new QListWidget{};
	this->filteredListWidget->setSelectionMode(QAbstractItemView::SingleSelection);;
	this->labelErrorMessageModeA = new QLabel{};
	this->labelErrorMessageModeB = new QLabel{};
	this->errorMessageTimer = new QTimer{};
	this->errorMessageTimer->setSingleShot(true);

	QWidget* modeAWidget = initializeWidgetModeA(); // these functions need the QActions from the menu to be initialised
	QWidget* modeBWidget = initializeWidgetModeB();
	QWidget* dataRepresentationWidget = initializeWidgetDataRepresentation();

	this->allWidgets->addWidget(modeAWidget);
	this->allWidgets->addWidget(modeBWidget);
	this->allWidgets->addWidget(dataRepresentationWidget);
	mainLayout->addWidget(allWidgets);
	setLayout(mainLayout);

	this->installEventFilter(this);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->menuActionModeA, &QAction::triggered, this, &GUI::changeToModeA);
	QObject::connect(this->menuActionModeB, &QAction::triggered, this, &GUI::changeToModeB);
	QObject::connect(this->menuActionDataRepresentation, &QAction::triggered, this, &GUI::changeToDataRepresentation);

	QObject::connect(this->addVictimButton, &QPushButton::clicked, this, &GUI::addVictim);
	QObject::connect(this->updateVictimButton, &QPushButton::clicked, this, &GUI::updateVictim);
	QObject::connect(this->deleteVictimButton, &QPushButton::clicked, this, &GUI::deleteVictim);
	QObject::connect(this->fileLocationButton, &QPushButton::clicked, this, &GUI::setFileLocation);
	QObject::connect(this->undoModeAButton, &QPushButton::clicked, this, &GUI::undoModeA);
	QObject::connect(this->redoModeAButton, &QPushButton::clicked, this, &GUI::redoModeA);
	QObject::connect(this->nextVictimButton, &QPushButton::clicked, this, &GUI::nextVictim);
	QObject::connect(this->saveVictimButton, &QPushButton::clicked, this, &GUI::saveVictim);
	QObject::connect(this->filterVictimsButton, &QPushButton::clicked, this, &GUI::filterVictims);
	QObject::connect(this->myListLocationButton, &QPushButton::clicked, this, &GUI::setMyListLocation);
	QObject::connect(this->openExternalProgramButton, &QPushButton::clicked, this, &GUI::openExternalProgram);
	QObject::connect(this->showMylistButton, &QPushButton::clicked, this, &GUI::showMylist);
	QObject::connect(this->undoModeBButton, &QPushButton::clicked, this, &GUI::undoModeB);
	QObject::connect(this->redoModeBButton, &QPushButton::clicked, this, &GUI::redoModeB);

	QObject::connect(this->errorMessageTimer, &QTimer::timeout, this, &GUI::removeErrorMessage);

	QObject::connect(this->victimListWidget, &QListWidget::itemSelectionChanged, this, &GUI::changedVictimInList);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Victim>& victimList){
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentVictim : victimList) {
		QString victimText = QString::fromStdString(currentVictim.getCSVRepresentation());
		QListWidgetItem* victimItem = new QListWidgetItem{ victimText };
		victimItem->setFont(listFont);
		listWidget->addItem(victimItem);
	}

	if (listWidget->count() > 0) {
		listWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

void GUI::populateBarSeries(){
	// found a bug with this when creating a new bar from scratch <=> empty starting repo
	// (so basically in_memory)
	if (this->barSeries->count() > 0) {
		this->barSeries->clear();
	}

	std::map<std::string, int> victimCountByPlaceOfOrigin = this->actionController.getVictimCountByPlaceOfOrigin();
	for (auto currentPlaceOfOrigin : victimCountByPlaceOfOrigin) {
		QtCharts::QBarSet* barSet = new QtCharts::QBarSet(QString::fromStdString(currentPlaceOfOrigin.first));
		*barSet << currentPlaceOfOrigin.second;
		this->barSeries->append(barSet);
	}
}

GUI::GUI(){
	// the repository locations need to be set before calling initialize GUI
	// right now they are loaded at run-time from a file
	// if that changes, we can go back to calling setRepositoryLocation and setMyListLocation with default values
	this->initializeGUI();
	this->connectSignalsAndSlots();

	std::vector<Victim> allVictims = this->actionController.getAllVictims();
	this->populateList(this->victimListWidget, allVictims);
	std::vector<Victim> savedVictims = this->actionController.getSavedVictims();

	this->pressedCTRLKey = false;
	this->pressedZKey = false;
	this->pressedYKey = false;
}
