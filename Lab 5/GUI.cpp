#include "GUI.h"
#include <QLabel>
#include <qboxlayout.h>
#include <QFormLayout>

void GUI::initializeGUI() {
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	QLabel* labelVictimName = new QLabel{ "&Victim name:" };
	QLabel* labelVictimPlace = new QLabel{ "&Victim place of origin:" };
	QLabel* labelVictimAge = new QLabel{ "&Victim age:" };
	QLabel* labelVictimPhotograph = new QLabel{ "&Victim photograph link:" };
	QLabel* labelFileLocation = new QLabel{ "&File location:" };

	QWidget* textBoxAreaWidget = new QWidget{};
	QFormLayout* textBoxAreaLayout = new QFormLayout{ textBoxAreaWidget };

	QWidget* buttonAreaWidget = new QWidget{};
	QGridLayout* buttonAreaLayout = new QGridLayout{ buttonAreaWidget };

	QWidget* fileLocationAreaWidget = new QWidget{};
	QFormLayout* fileLocationAreaLayout = new QFormLayout{ fileLocationAreaWidget };

	this->menuActionModeA = new QAction{ "&Mode A", this };
	this->menuActionModeB = new QAction{ "&Mode B", this };
	this->menuActionDataRepresentation = new QAction{ "&Data representation", this };
	this->menuToolbar = new QToolBar{};
	this->victimListWidget = new QListWidget{};
	this->lineEditVictimName = new QLineEdit{};
	this->lineEditVictimPlace = new QLineEdit{};
	this->lineEditVictimAge = new QLineEdit{};
	this->lineEditVictimPhotograph = new QLineEdit{};
	this->lineEditFileLocation = new QLineEdit{};
	this->addVictimButton = new QPushButton{ "Add victim" };
	this->updateVictimButton = new QPushButton{ "Update victim" };
	this->deleteVictimButton = new QPushButton{ "Delete victim" };
	this->fileLocationButton = new QPushButton{ "Set file location" };

	this->menuToolbar->addAction(menuActionModeA);
	this->menuToolbar->addAction(menuActionModeB);
	this->menuToolbar->addAction(menuActionDataRepresentation);

	this->victimListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	buttonAreaLayout->addWidget(this->addVictimButton, 0, 0, 1, 1);
	buttonAreaLayout->addWidget(this->updateVictimButton, 0, 1, 1, 1);
	buttonAreaLayout->addWidget(this->deleteVictimButton, 1, 0, 1, 1);
	buttonAreaLayout->addWidget(this->fileLocationButton, 2, 0, 1, 2);

	labelVictimName->setBuddy(lineEditVictimName);
	labelVictimPlace->setBuddy(lineEditVictimPlace);
	labelVictimAge->setBuddy(lineEditVictimAge);
	labelVictimPhotograph->setBuddy(lineEditVictimPhotograph);
	textBoxAreaLayout->addRow(labelVictimName, lineEditVictimName);
	textBoxAreaLayout->addRow(labelVictimPlace, lineEditVictimPlace);
	textBoxAreaLayout->addRow(labelVictimAge, lineEditVictimAge);
	textBoxAreaLayout->addRow(labelVictimPhotograph, lineEditVictimPhotograph);

	labelFileLocation->setBuddy(lineEditFileLocation);
	fileLocationAreaLayout->addRow(labelFileLocation, lineEditFileLocation);

	mainLayout->addWidget(this->menuToolbar);
	mainLayout->addWidget(this->victimListWidget);
	mainLayout->addWidget(textBoxAreaWidget);
	mainLayout->addWidget(buttonAreaWidget);
	mainLayout->addWidget(fileLocationAreaWidget);
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

GUI::GUI(){
	this->initializeGUI();
	this->populateVictimList();
}
