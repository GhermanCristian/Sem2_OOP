#include <QtWidgets/QApplication>
#include "ChatSession.h"
#include "ChatWindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    ChatSession currentSession;
    ChatWindow window1(currentSession, User("ID1", "Mike"));
    ChatWindow window2(currentSession, User("ID2", "Dennis"));
    ChatWindow window3(currentSession, User("ID3", "Scottie"));
    ChatWindow window4(currentSession, User("ID4", "Phil"));

    currentSession.addObserver(&window1);
    currentSession.addObserver(&window2);
    currentSession.addObserver(&window3);
    currentSession.addObserver(&window4);

    window1.show();
    window2.show();
    window3.show();
    window4.show();
    
    return a.exec();
}
