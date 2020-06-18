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
    for (auto user : allUsers) {
        GUI* userWindow = new GUI(actionController, user);
        actionController.addObserver(userWindow);
        userWindow->show();
    }

    return a.exec();
}
