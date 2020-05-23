#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    RemoveAtIndex_EmptyList_ThrowsException();
    RemoveAtIndex_FilledList_CorrectNumberOfItems();

    QApplication a(argc, argv);
    GUI userInterface;
    userInterface.setWindowTitle("Lab 13 Test");
    userInterface.show();
    return a.exec();
}
