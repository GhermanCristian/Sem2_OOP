#include "tests.h"
#include "controller.h"
#include <assert.h>

void AddIssue_EmptyDescription_ThrowsException(){
	Repository newRepository;
	try {
		newRepository.addIssue(Issue("", "", "", ""));
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddIssue_IssueAlreadyExists_ThrowsException(){
	Repository newRepository;
	newRepository.addIssue(Issue("a", "a", "a", "a"));
	try {
		newRepository.addIssue(Issue("a", "a", "a", "a"));
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddIssue_ValidIssue_IssueIsAdded(){
	Repository newRepository;
	newRepository.addIssue(Issue("a", "a", "a", "a"));
	assert(newRepository.getAllIssues().size() == 1);
	assert(newRepository.getAllIssues()[0].getDescription() == "a");
	assert(newRepository.getAllIssues()[0].getReporter() == "a");
	assert(newRepository.getAllIssues()[0].getStatus() == "a");
}
