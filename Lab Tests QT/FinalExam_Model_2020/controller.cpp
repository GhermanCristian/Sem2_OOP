#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller(){
	this->loadIssues("issues.txt");
	this->loadUsers("users.txt");
}

void Controller::updateFile(std::string filePath) {
	std::fstream outputStream(filePath);
	std::vector<Issue> allIssues = this->getAllIssues();
	for (auto issue : allIssues) {
		outputStream << issue.toString() << "\n";
	}
	outputStream.close();
}

void Controller::loadUsers(std::string filePath){
	this->elements.loadUsers(filePath);
}

void Controller::loadIssues(std::string filePath){
	this->elements.loadIssues(filePath);
}

std::vector<Issue> Controller::getAllIssues(){
	return this->elements.getAllIssues();;
}

std::vector<User> Controller::getAllUsers(){
	return this->elements.getAllUsers();
}

std::vector<Issue> Controller::getAllIssuesSorted(){
	std::vector<Issue> allIssues = this->getAllIssues();
	std::sort(allIssues.begin(), allIssues.end(), [this](const Issue& a, const Issue& b) {
		if (a.getStatus() == b.getStatus()) {
			return a.getDescription() < b.getDescription();
		}
		return a.getStatus() < b.getStatus();
	});
	return allIssues;
}

void Controller::addIssue(std::string description, std::string status, std::string reporter, std::string solver){
	this->elements.addIssue(Issue(description, status, reporter, solver));
	this->notify();
}

void Controller::removeIssueByDescription(std::string description){
	this->elements.removeIssueByDescription(description);
	this->notify();
}

void Controller::solveIssueByDescription(std::string description, std::string solver){
	std::vector<Issue> allIssues = this->getAllIssues();
	for (int position = 0; position < allIssues.size(); position++) {
		Issue issue = allIssues[position];
		if (issue.getDescription() == description && issue.getStatus() == "open") {
			Issue newIssue(issue.getDescription(), "closed", issue.getReporter(), solver);
			this->elements.update(position, newIssue);
			this->notify();
			return;
		}
	}
	throw std::exception("Issue does not exist or it has been solved");
}

Controller::~Controller(){
	this->updateFile("issues.txt");
}
