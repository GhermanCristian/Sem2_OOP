#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    GetTotalDurationWithGivenPriority_NoPriorityMatched_NoOutput();
    GetTotalDurationWithGivenPriority_EmptyRepository_NoOutput();
    GetTotalDurationWithGivenPriority_FilledRepository_CorrectDuration();

    QApplication a(argc, argv);
    GUI userInterface;
    userInterface.setWindowTitle("Lab 13 Test");
    userInterface.show();
    return a.exec();
}
