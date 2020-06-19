#pragma once
#include "controller.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include "Observer.h"
#include <qmessagebox.h>

const int LIST_INDEX_ERROR_CODE = -1;
const int NON_EXISTENT = -1;

class GUI : public QWidget, public Observer{
	private:
		Controller& actionController;
		Participant participant;
		bool isPresenter;
		std::vector<std::pair<int, bool>> questionStatus;
		// for each question ID (= unique) -> true = question has been answered, false = not answered
		// this should only be used by the participants
		// this is different for each user, so if X answers a question, it won't affect the list of Y

		QListWidget* mainListWidget;
		QLineEdit* questionIDLineEdit;
		QLineEdit* questionTextLineEdit;
		QLineEdit* correctAnswerLineEdit;
		QLineEdit* questionScoreLineEdit;
		QLineEdit* participantAnswerLineEdit;
		QPushButton* addQuestionButton;
		QPushButton* answerButton;
		QLabel* participantScoreLabel;

		void addQuestionButtonAction();
		void answerButtonAction();

	public:
		GUI(Controller& actionController, Participant participant);
		void initializeGUI();
		void connectSignalsAndSlots();
		void populateList(QListWidget* listWidget, const std::vector<Question>& entityList);
		void update() override;
		int getCurrentQuestionIndex();
		Question getSelectedQuestion();
		~GUI();
};

