#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

void Repository::loadIssues(std::string filePath){
	const int DESCRIPTION_POSITION = 0;
	const int STATUS_POSITION = 1;
	const int REPORTER_POSITION = 2;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

	this->issues.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == DESCRIPTION_POSITION) {
				description = currentProperty;
			}
			else if (propertyPosition == STATUS_POSITION) {
				status = currentProperty;
			}
			else if (propertyPosition == REPORTER_POSITION) {
				reporter = currentProperty;
			}

			propertyPosition++;
		}

		solver = currentLine;
		this->issues.push_back(Issue(description, status, reporter, solver));
	}

	inputStream.close();
}

void Repository::loadUsers(std::string filePath){
	const int NAME_POSITION = 0;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string name;
	std::string type;

	this->users.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == NAME_POSITION) {
				name = currentProperty;
			}
			propertyPosition++;
		}

		type = currentLine;
		this->users.push_back(User(name, type));
	}

	inputStream.close();
}

std::vector <Issue> Repository::getAllIssues(){
	return this->issues;
}

std::vector<User> Repository::getAllUsers(){
	return this->users;
}

void Repository::addIssue(Issue newIssue){
	if (newIssue.getDescription() == "") {
		throw std::exception("No description");
	}
	for (auto issue : this->issues) {
		if (issue.getDescription() == newIssue.getDescription()) {
			throw std::exception("Issue already exists");
		}
	}
	this->issues.push_back(newIssue);
}

void Repository::removeIssueByDescription(std::string description){
	int issuePosition = -1; // -1 means the issue has not been found
	for (int position = 0; position < this->issues.size(); position++) {
		if (this->issues[position].getDescription() == description && this->issues[position].getStatus() == "closed") {
			issuePosition = position;
			break;
		}
	}
	if (issuePosition == -1) {
		throw std::exception("Issue does not exist or it's still open");
	}
	this->issues.erase(this->issues.begin() + issuePosition);
}

void Repository::update(int position, Issue newIssue){
	this->issues.erase(this->issues.begin() + position);
	this->issues.insert(this->issues.begin() + position, newIssue);
}

Repository::~Repository(){
	;
}
