#include <QtWidgets/QApplication>
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]){
    AddQuestion_EmptyText_ThrowsException();
    AddQuestion_QuestionAlreadyExists_ThrowsException();
    AddQuestion_ValidQuestion_AddsQuestion();
    AddScore_ValidScore_AddsScore();

    QApplication a(argc, argv);
    Controller actionController("questions.txt");
    actionController.loadQuestionsFromFile("questions.txt");
    actionController.loadParticipantsFromFile("participants.txt");
    
    GUI* presenterWindow = new GUI(actionController, Participant());
    presenterWindow->setWindowTitle("Presenter");
    presenterWindow->show();
    actionController.addObserver(presenterWindow);

    std::vector<Participant> allParticipants = actionController.getAllParticipants();
    for (auto participant : allParticipants) {
        GUI* participantWindow = new GUI(actionController, participant);
        participantWindow->show();
        actionController.addObserver(participantWindow);
    }
    
    return a.exec();
}
