#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"
#include "customTableModel.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Controller actionController;
    actionController.loadIdeasFromFile("ideas.txt");
    actionController.loadWritersFromFile("writers.txt");

    CustomTableModel* tableModel = new CustomTableModel(actionController);
    std::vector<Writer> allWriters = actionController.getAllWriters();
    for (auto writer : allWriters) {
        GUI* writerWindow = new GUI(actionController, tableModel, writer);
        writerWindow->show();
        writerWindow->addObserver(tableModel);
    }
    return a.exec();
}
