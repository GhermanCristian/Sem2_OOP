#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    AddIssue_EmptyDescription_ThrowsException();
    AddIssue_IssueAlreadyExists_ThrowsException();
    AddIssue_ValidIssue_IssueIsAdded();

    QApplication a(argc, argv);
    Controller actionController;

    std::vector<User> allUsers = actionController.getAllUsers();

    GUI userWindow1(actionController, allUsers[0]);
    actionController.addObserver(&userWindow1);
    userWindow1.show();
    GUI userWindow2(actionController, allUsers[1]);
    actionController.addObserver(&userWindow2);
    userWindow2.show();
    GUI userWindow3(actionController, allUsers[2]);
    actionController.addObserver(&userWindow3);
    userWindow3.show();
    GUI userWindow4(actionController, allUsers[3]);
    actionController.addObserver(&userWindow4);
    userWindow4.show();
    GUI userWindow5(actionController, allUsers[4]);
    actionController.addObserver(&userWindow5);
    userWindow5.show();

    return a.exec();
}
