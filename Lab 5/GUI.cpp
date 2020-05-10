#include "GUI.h"
#include <qboxlayout.h>
#include <QFormLayout>
#include <qdebug.h>

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

	this->lineEditVictimName = new QLineEdit{};
	this->lineEditVictimPlace = new QLineEdit{};
	this->lineEditVictimAge = new QLineEdit{};
	this->lineEditVictimPhotograph = new QLineEdit{};
	this->lineEditFileLocation = new QLineEdit{};

	this->addVictimButton = new QPushButton{ "Add victim" };
	this->updateVictimButton = new QPushButton{ "Update victim" };
	this->deleteVictimButton = new QPushButton{ "Delete victim" };
	this->fileLocationButton = new QPushButton{ "Set file location" };

	modeAToolbar->addAction(menuActionModeA);
	modeAToolbar->addAction(menuActionModeB);
	modeAToolbar->addAction(menuActionDataRepresentation);

	buttonAreaLayout->addWidget(this->addVictimButton);
	buttonAreaLayout->addWidget(this->updateVictimButton);
	buttonAreaLayout->addWidget(this->deleteVictimButton);

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
	modeALayout->addWidget(this->labelErrorMessageModeA);

	return modeAWidget;
}

QWidget* GUI::initializeWidgetModeB(){
	QWidget* modeBWidget = new QWidget;
	QVBoxLayout* modeBLayout = new QVBoxLayout{ modeBWidget };
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

	modeBToolbar->addAction(menuActionModeA);
	modeBToolbar->addAction(menuActionModeB);
	modeBToolbar->addAction(menuActionDataRepresentation);

	this->saveVictimButton = new QPushButton{ "Save victim" };
	this->filterVictimsButton = new QPushButton{ "Filter victims" };
	this->myListLocationButton = new QPushButton{ "Set myList location" };

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

	modeBLayout->addWidget(modeBToolbar);
	modeBLayout->addWidget(this->myListWidget);
	modeBLayout->addWidget(saveVictimWidget);
	modeBLayout->addWidget(saveVictimButton);
	modeBLayout->addWidget(filterVictimsWidget);
	modeBLayout->addWidget(filterVictimsButton);
	modeBLayout->addWidget(myListLocationWidget);
	modeBLayout->addWidget(myListLocationButton);
	modeBLayout->addWidget(this->labelErrorMessageModeB);

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
	//this->populateVictimList();
}

void GUI::changeToModeB(){
	this->allWidgets->setCurrentIndex(MODE_B_WIDGET_INDEX);
	//this->populateMyList();
}

void GUI::changeToDataRepresentation(){
	this->allWidgets->setCurrentIndex(DATA_REPRESENTATION_WIDGET_INDEX);
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

void GUI::addVictim(){
	try {
		std::string victimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimName->text().toStdString());
		std::string victimPlace = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPlace->text().toStdString());
		int victimAge = this->inputValidator.generalNumberValidator(this->lineEditVictimAge->text().toStdString());
		std::string victimPhotograph = this->inputValidator.generalNonEmptyStringValidator(this->lineEditVictimPhotograph->text().toStdString());

		this->actionController.addVictim(victimName, victimPlace, victimAge, victimPhotograph);
		this->populateVictimList();
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
		this->populateVictimList();
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
		this->populateVictimList();
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
		this->populateVictimList();
		this->populateBarSeries();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::saveVictim(){
	try {
		std::string victimName = this->inputValidator.generalNonEmptyStringValidator(this->lineEditSaveVictim->text().toStdString());
		this->actionController.saveVictim(victimName);
		this->populateMyList();
	}
	catch (const std::exception& currentException) {
		this->displayErrorMessage(currentException.what());
	}
}

void GUI::filterVictims(){
	//
}

void GUI::setMyListLocation(){
	std::string myListLocation = this->inputValidator.generalNonEmptyStringValidator(this->lineEditMyListLocation->text().toStdString());
	this->actionController.setSavedVictimsFileLocation(myListLocation);
	this->populateMyList();
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
	this->myListWidget = new QListWidget{};
	this->myListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
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
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->menuActionModeA, &QAction::triggered, this, [this]() {this->changeToModeA(); });
	QObject::connect(this->menuActionModeB, &QAction::triggered, this, [this]() {this->changeToModeB(); });
	QObject::connect(this->menuActionDataRepresentation, &QAction::triggered, this, [this]() {this->changeToDataRepresentation(); });

	QObject::connect(this->addVictimButton, &QPushButton::clicked, this, [this]() {this->addVictim(); });
	QObject::connect(this->updateVictimButton, &QPushButton::clicked, this, [this]() {this->updateVictim(); });
	QObject::connect(this->deleteVictimButton, &QPushButton::clicked, this, [this]() {this->deleteVictim(); });
	QObject::connect(this->fileLocationButton, &QPushButton::clicked, this, [this]() {this->setFileLocation(); });
	QObject::connect(this->saveVictimButton, &QPushButton::clicked, this, [this]() {this->saveVictim(); });
	QObject::connect(this->filterVictimsButton, &QPushButton::clicked, this, [this]() {this->filterVictims(); });
	QObject::connect(this->myListLocationButton, &QPushButton::clicked, this, [this]() {this->setMyListLocation(); });

	QObject::connect(this->errorMessageTimer, &QTimer::timeout, this, [this]() {this->removeErrorMessage(); });

	QObject::connect(this->victimListWidget, &QListWidget::itemSelectionChanged, this, [this]() {this->changedVictimInList(); });
}

void GUI::populateVictimList(){
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	if (this->victimListWidget->count() > 0) {
		this->victimListWidget->clear();
	}

	std::vector <Victim> allVictims = this->actionController.getAllVictims();
	for (auto currentVictim : allVictims) {
		QString victimText = QString::fromStdString(currentVictim.getCSVRepresentation());
		QListWidgetItem* victimItem = new QListWidgetItem{ victimText };
		victimItem->setFont(listFont);
		this->victimListWidget->addItem(victimItem);
	}

	if (this->victimListWidget->count() > 0) {
		this->victimListWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

void GUI::populateMyList(){
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE }; // TO-DO: use constants

	if (this->myListWidget->count() > 0) {
		this->myListWidget->clear();
	}

	std::vector <Victim> savedVictims = this->actionController.getSavedVictims();
	for (auto currentVictim : savedVictims) {
		QString victimText = QString::fromStdString(currentVictim.getCSVRepresentation());
		QListWidgetItem* victimItem = new QListWidgetItem{ victimText };
		victimItem->setFont(listFont);
		this->myListWidget->addItem(victimItem);
	}

	if (this->myListWidget->count() > 0) {
		this->myListWidget->setCurrentRow(FIRST_ROW_INDEX);
	}
}

void GUI::populateBarSeries(){
	if (this->barSeries->count() > 0) {
		this->barSeries->clear();
	}

	std::map<std::string, int> victimCountByPlaceOfOrigin = this->actionController.getVictimCountByPlaceOfOrigin();
	for (auto currentPlaceOfOrigin : victimCountByPlaceOfOrigin) {
		QtCharts::QBarSet* barSet = new QtCharts::QBarSet(QString::fromStdString(currentPlaceOfOrigin.first));
		*barSet << currentPlaceOfOrigin.second;
		barSeries->append(barSet);
	}
}

GUI::GUI(){
	this->actionController.setRepositoryFileLocation(DEFAULT_REPOSITORY_LOCATION);
	this->actionController.setSavedVictimsFileLocation(DEFAULT_MYLIST_LOCATION);

	this->initializeGUI();
	this->connectSignalsAndSlots();

	this->populateVictimList();
	this->populateMyList();
}
