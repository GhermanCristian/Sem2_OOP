#include "controller.h"
#include <algorithm>

Controller::Controller(){
	;
}

void Controller::loadFromFile(std::string filePath){
	this->elements.loadFromFile(filePath);
}

std::vector <Task> Controller::getAllEntities() {
	return this->elements.getAllEntries();
}

std::vector<Task> Controller::getAllEntitiesSortedByPriority(){
	std::vector<Task> allEntities = this->elements.getAllEntries();
	std::sort(allEntities.begin(), allEntities.end(), [this](const Task& a, const Task& b) {return a.getPriority() < b.getPriority(); });
	return allEntities;
}

void Controller::addTask(std::string description, int duration, int priority){
	this->elements.add(Task(description, duration, priority));
}

int Controller::getTotalDurationWithGivenPriority(int priority){
	std::vector<Task> allTasks = this->elements.getAllEntries();
	int totalDuration = 0;

	for (auto currentTask : allTasks) {
		if (currentTask.getPriority() == priority) {
			totalDuration += currentTask.getDuration();
		}
	}

	return totalDuration;
}

Controller::~Controller(){
	;
}
