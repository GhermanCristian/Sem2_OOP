#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[])
{
    getUnpaidBillsCostForCompany_InexistentCompany_NoOutput();
    getUnpaidBillsCostForCompany_ExistentCompany_CorrectOutput();
    QApplication a(argc, argv);
    GUI userInterface;
    userInterface.setWindowTitle("Lab 13 Test");
    userInterface.show();
    return a.exec();
}
