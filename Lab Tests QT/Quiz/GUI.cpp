#include "GUI.h"

void GUI::addQuestionButtonAction(){
	int questionID = this->questionIDLineEdit->text().toInt();
	std::string questionText = this->questionTextLineEdit->text().toStdString();
	std::string correctAnswer = this->correctAnswerLineEdit->text().toStdString();
	int questionScore = this->questionScoreLineEdit->text().toInt();

	try {
		this->actionController.addQuestion(questionID, questionText, correctAnswer, questionScore);
	}
	catch (const std::exception& exception) {
		QMessageBox::critical(this, "error add question", exception.what());
	}
}

void GUI::answerButtonAction(){
	Question selectedQuestion = this->getSelectedQuestion();
	std::string userAnswer = this->participantAnswerLineEdit->text().toStdString();

	if (userAnswer == selectedQuestion.getCorrectAnswer()) {
		this->participant.addScore(selectedQuestion.getScore());
		this->participantScoreLabel->setText("Score : " + QString::number(this->participant.getScore()));
	}

	// mark the question as answered (doesn't matter if it was answered correctly or not)
	// remove the old one, which had not been answered, and add it back, but this time it's answered
	auto questionPosition = std::find(this->questionStatus.begin(), this->questionStatus.end(), std::make_pair(selectedQuestion.getID(), false));
	this->questionStatus.erase(questionPosition);
	this->questionStatus.push_back(std::make_pair(selectedQuestion.getID(), true));

	this->update(); // this update is not conditioned by the Subject
}

GUI::GUI(Controller& actionController, Participant participant) : actionController(actionController) {
	this->participant = participant;

	if (this->participant.getName() != "") {
		this->setWindowTitle(QString::fromStdString(this->participant.getName()));
		std::vector<Question> allQuestions = this->actionController.getAllQuestionsSortedByScore();
		for (auto question : allQuestions) {
			// initially all the questions are unanswered
			this->questionStatus.push_back(std::make_pair(question.getID(), false));
		}
		isPresenter = false;
	}
	else {
		isPresenter = true;
	}
	
	initializeGUI();
	connectSignalsAndSlots();

	this->update();
}

void GUI::initializeGUI(){
	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QLabel* addQuestionLabel = new QLabel{"ID, text, correct answer, score"};
	this->participantScoreLabel = new QLabel{ "Score : 0" };

	this->mainListWidget = new QListWidget;
	this->mainListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	this->questionIDLineEdit = new QLineEdit;
	this->questionTextLineEdit = new QLineEdit;
	this->correctAnswerLineEdit = new QLineEdit;
	this->questionScoreLineEdit = new QLineEdit;
	this->participantAnswerLineEdit = new QLineEdit;

	this->addQuestionButton = new QPushButton{ "Add question" };
	this->answerButton = new QPushButton{ "Answer" };

	mainLayout->addWidget(this->mainListWidget);
	if (this->isPresenter == true) {
		mainLayout->addWidget(addQuestionLabel);
		mainLayout->addWidget(this->questionIDLineEdit);
		mainLayout->addWidget(this->questionTextLineEdit);
		mainLayout->addWidget(this->correctAnswerLineEdit);
		mainLayout->addWidget(this->questionScoreLineEdit);
		mainLayout->addWidget(this->addQuestionButton);
	}
	else {
		mainLayout->addWidget(this->participantScoreLabel);
		mainLayout->addWidget(this->participantAnswerLineEdit);
		mainLayout->addWidget(this->answerButton);
	}
	setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots(){
	QObject::connect(this->addQuestionButton, &QPushButton::clicked, this, &GUI::addQuestionButtonAction);
	QObject::connect(this->answerButton, &QPushButton::clicked, this, &GUI::answerButtonAction);
	QObject::connect(this->mainListWidget, &QListWidget::itemSelectionChanged, this, &GUI::getSelectedQuestion);
}

void GUI::populateList(QListWidget* listWidget, const std::vector<Question>& entityList){
	const std::string LIST_FONT_NAME = "Arial";
	const int LIST_FONT_SIZE = 14;
	const int FIRST_ROW_INDEX = 0;
	QFont listFont{ QString::fromStdString(LIST_FONT_NAME), LIST_FONT_SIZE };

	// check if it's not empty
	if (listWidget->count() > 0) {
		listWidget->clear();
	}

	for (auto currentEntity : entityList) {
		std::string text;
		if (this->isPresenter == true) {
			text = currentEntity.toStringPresenter();
		}
		else {
			text = currentEntity.toStringParticipant();
		}

		QString entityText = QString::fromStdString(text);
		QListWidgetItem* listItem = new QListWidgetItem{ entityText };
		listItem->setFont(listFont);

		if (this->isPresenter == false) {
			// if the question is answered, change the background color
			auto questionPosition = std::find(this->questionStatus.begin(), this->questionStatus.end(), std::make_pair(currentEntity.getID(), true));
			if (questionPosition != this->questionStatus.end()) { // found the question
				listItem->setBackground(Qt::green);
			}
		}

		listWidget->addItem(listItem);
	}
}

void GUI::update(){
	std::vector<Question> allQuestions;
	if (this->isPresenter == true) {
		allQuestions = this->actionController.getAllQuestionsSortedByID();
	}
	else {
		allQuestions = this->actionController.getAllQuestionsSortedByScore();
		if (allQuestions.size() == questionStatus.size() + 1) {
			// this update is called when the presenter adds a new question; 
			// the new question is the last from the "allQuestions" list
			this->questionStatus.push_back(std::make_pair(this->actionController.getAllQuestions().back().getID(), false));
			// at the moment the new question is unanswered
		}
	}
	this->populateList(this->mainListWidget, allQuestions);
}

int GUI::getCurrentQuestionIndex() {
	if (this->mainListWidget->count() == 0) {
		return LIST_INDEX_ERROR_CODE;
	}

	const int FIRST_INDEX_LIST_POSITION = 0;
	QModelIndexList questionIndex = this->mainListWidget->selectionModel()->selectedIndexes();

	if (questionIndex.size() == 0) {
		return LIST_INDEX_ERROR_CODE;
	}

	return questionIndex.at(FIRST_INDEX_LIST_POSITION).row();
}

Question GUI::getSelectedQuestion() {
	int questionIndex = this->getCurrentQuestionIndex();
	std::vector<Question> sortedQuestions = this->actionController.getAllQuestionsSortedByScore();
	if (questionIndex == LIST_INDEX_ERROR_CODE || questionIndex < 0 || questionIndex > sortedQuestions.size()) {
		return Question();
	}

	Question currentQuestion = sortedQuestions[questionIndex];

	// if the question is answered, disable the answer button
	auto questionPosition = std::find(this->questionStatus.begin(), this->questionStatus.end(), std::make_pair(currentQuestion.getID(), true));
	if (questionPosition != this->questionStatus.end()) { // found the question
		this->answerButton->setVisible(false);
	}
	else {
		this->answerButton->setVisible(true);
	}

	return currentQuestion;
}

GUI::~GUI() {

}
