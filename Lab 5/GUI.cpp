#include "GUI.h"
#include <QLabel>
#include <qboxlayout.h>
#include <QFormLayout>
#include <qdebug.h>

QWidget* GUI::initializeWidgetModeA(){
	QWidget* modeAWidget = new QWidget;
	QVBoxLayout* modeALayout = new QVBoxLayout{ modeAWidget };

	QLabel* labelVictimName = new QLabel{ "&Victim's name:" };
	QLabel* labelVictimPlace = new QLabel{ "&Victim's place of origin:" };
	QLabel* labelVictimAge = new QLabel{ "&Victim's age:" };
	QLabel* labelVictimPhotograph = new QLabel{ "&Victim's photograph link:" };
	QLabel* labelFileLocation = new QLabel{ "&File location:" };

	QWidget* textBoxesAreaWidget = new QWidget{};
	QFormLayout* textBoxesAreaLayout = new QFormLayout{ textBoxesAreaWidget };

	QWidget* buttonAreaWidget = new QWidget{};
	QGridLayout* buttonAreaLayout = new QGridLayout{ buttonAreaWidget };

	QWidget* fileLocationAreaWidget = new QWidget{};
	QFormLayout* fileLocationAreaLayout = new QFormLayout{ fileLocationAreaWidget };

	QToolBar* modeAToolbar = new QToolBar{};

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

	buttonAreaLayout->addWidget(this->addVictimButton, 0, 0);
	buttonAreaLayout->addWidget(this->updateVictimButton, 0, 1);
	buttonAreaLayout->addWidget(this->deleteVictimButton, 0, 2);

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

	return modeBWidget;
}

void GUI::changeToModeA(){
	this->allWidgets->setCurrentIndex(0);
	this->populateVictimList();
}

void GUI::changeToModeB(){
	this->allWidgets->setCurrentIndex(1);
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

	QWidget* modeAWidget = initializeWidgetModeA(); // these functions need the QActions from the menu to be initialised
	QWidget* modeBWidget = initializeWidgetModeB();

	this->allWidgets->addWidget(modeAWidget);
	this->allWidgets->addWidget(modeBWidget);
	mainLayout->addWidget(allWidgets);
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->menuActionModeA, &QAction::triggered, this, [this]() {this->changeToModeA(); });
	QObject::connect(this->menuActionModeB, &QAction::triggered, this, [this]() {this->changeToModeB(); });
}

void GUI::populateVictimList(){
	QFont listFont{ "Arial", 12 }; // TO-DO: use constants

	if (this->victimListWidget->count() > 0) {
		this->victimListWidget->clear();
	}

	// this is here only temporarily; i need to implement the user's ability to set/change the location
	// aka implement the fileLocation button
	this->actionController.setRepositoryFileLocation("data.txt"); 

	std::vector <Victim> allVictims = this->actionController.getAllVictims();
	for (auto currentVictim : allVictims) {
		QString victimText = QString::fromStdString(currentVictim.getCSVRepresentation());
		QListWidgetItem* victimItem = new QListWidgetItem{ victimText };
		victimItem->setFont(listFont);
		this->victimListWidget->addItem(victimItem);
	}

	if (this->victimListWidget->count() > 0) {
		this->victimListWidget->setCurrentRow(0);
	}
}

void GUI::populateMyList(){
	QFont listFont{ "Arial", 12 }; // TO-DO: use constants

	if (this->myListWidget->count() > 0) {
		this->myListWidget->clear();
	}

	// this is here only temporarily; i need to implement the user's ability to set/change the location
	// aka implement the fileLocation button
	this->actionController.setSavedVictimsFileLocation("mylist.txt");

	std::vector <Victim> savedVictims = this->actionController.getSavedVictims();
	for (auto currentVictim : savedVictims) {
		QString victimText = QString::fromStdString(currentVictim.getCSVRepresentation());
		QListWidgetItem* victimItem = new QListWidgetItem{ victimText };
		victimItem->setFont(listFont);
		this->myListWidget->addItem(victimItem);
	}

	if (this->myListWidget->count() > 0) {
		this->myListWidget->setCurrentRow(0);
	}
}

GUI::GUI(){
	this->initializeGUI();
	this->connectSignalsAndSlots();
	this->populateVictimList();
	this->populateMyList();
}
