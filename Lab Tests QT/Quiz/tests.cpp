#include "tests.h"
#include "controller.h"
#include <assert.h>

void AddQuestion_EmptyText_ThrowsException(){
	Repository newRepository;
	try {
		newRepository.addQuestion(Question());
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddQuestion_QuestionAlreadyExists_ThrowsException(){
	Repository newRepository;
	newRepository.addQuestion(Question(123, "abc", "abc", 123));
	try {
		newRepository.addQuestion(Question(123, "abc", "abc", 123));
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddQuestion_ValidQuestion_AddsQuestion(){
	Repository newRepository;
	newRepository.addQuestion(Question(123, "def", "abc", 12345));
	assert(newRepository.getAllQuestions().size() == 1);
	assert(newRepository.getAllQuestions()[0].getCorrectAnswer() == "abc");
	assert(newRepository.getAllQuestions()[0].getScore() == 12345);
	assert(newRepository.getAllQuestions()[0].getText() == "def");
	assert(newRepository.getAllQuestions()[0].getID() == 123);
}

void AddScore_ValidScore_AddsScore(){
	Participant newParticipant;
	assert(newParticipant.getScore() == 0);
	newParticipant.addScore(10);
	assert(newParticipant.getScore() == 10);
}
