#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"
#include "customTableModel.h"

int main(int argc, char *argv[]){
    AddStar_NoName_ThrowsException();
    AddStar_InvalidDiameter_ThrowsException();
    AddStar_NameAlreadyExists_ThrowsException();
    AddStar_ValidStar_StarAdded();

    QApplication a(argc, argv);

    Controller actionController;
    actionController.loadStarsFromFile();
    actionController.loadAstronomersFromFile();

    CustomTableModel* tableModel = new CustomTableModel(actionController);
    std::vector<Astronomer> allAstronomers = actionController.getAllAstronomers();
    for (auto astronomer : allAstronomers) {
        GUI* astronomerWindow = new GUI(actionController, tableModel, astronomer);
        astronomerWindow->show();
        astronomerWindow->addObserver(tableModel);
    }

    return a.exec();
}
