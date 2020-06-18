#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    RemoveTask_NonExistentTask_ThrowsException();
    RemoveTask_ValidTask_TaskRemoved();
    StartTask_NonExistentTask_ThrowsException();
    StartTask_ValidTask_TaskStarted();
    DoneTask_NonExistentTask_ThrowsException();
    DoneTask_ValidTask_TaskDone();

    QApplication a(argc, argv);
    Controller actionController("tasks.txt");
    actionController.loadProgrammersFromFile("programmers.txt");
    actionController.loadTasksFromFile("tasks.txt");
    std::vector<Programmer> allProgrammers = actionController.getAllProgrammers();

    for (auto programmer : allProgrammers) {
        GUI* window = new GUI(actionController, programmer);
        actionController.addObserver(window);
        window->show();
    }

    return a.exec();
}
