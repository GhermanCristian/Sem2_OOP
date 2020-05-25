#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    // tests
    GetNumberOfCarsByManufacturer_NonExistentManufacturer_NoOutput();
    GetNumberOfCarsByManufacturer_ExistentManufacturer_CorrectNumberOfCars();
    GetNumberOfCarsByManufacturer_NoData_NoOutput();

    QApplication a(argc, argv);
    GUI userInterface;
    userInterface.setWindowTitle("Lab 13 Test");
    userInterface.show();
    return a.exec();
}
