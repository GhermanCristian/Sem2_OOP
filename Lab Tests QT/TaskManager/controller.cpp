#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller(std::string taskFilePath){
	this->taskFilePath = taskFilePath;
}

std::vector <Programmer> Controller::getAllProgrammers() {
	return this->elements.getAllProgrammers();
}

std::vector<Task> Controller::getAllTasks(){
	return this->elements.getAllTasks();
}

std::vector<Task> Controller::getAllTasksSorted(){
	std::vector<Task> allTasks = this->elements.getAllTasks();
	std::sort(allTasks.begin(), allTasks.end(), [this](const Task& a, const Task& b) {return a.getStatus() < b.getStatus(); });
	return allTasks;
}

Controller::~Controller(){
	if (taskFilePath.length() != 0) {
		this->updateFile(taskFilePath);
	}
}

void Controller::loadProgrammersFromFile(std::string filePath){
	this->elements.loadProgrammersFromFile(filePath);
}

void Controller::loadTasksFromFile(std::string filePath){
	this->elements.loadTasksFromFile(filePath);
}

void Controller::addTask(std::string description){
	this->elements.addTask(Task(description, "open", UNASSIGNED_PROGRAMMER));
	this->notify();
}

void Controller::removeTask(std::string description){
	this->elements.removeTask(description);
	this->notify();
}

void Controller::startTask(std::string description, Programmer programmer){
	Task oldTask = this->elements.removeOpenTask(description);
	Task newTask(oldTask.getDescription(), "in progress", programmer.getID());
	this->elements.addTask(newTask);
	this->notify();
}

void Controller::doneTask(std::string description){
	Task oldTask = this->elements.removeTask(description);
	Task newTask(oldTask.getDescription(), "closed", oldTask.getID());
	this->elements.addTask(newTask);
	this->notify();
}

void Controller::updateFile(std::string filePath){
	std::fstream outputStream(filePath);
	std::vector<Task> allTasks = this->elements.getAllTasks();

	for (auto task : allTasks) {
		outputStream << task.toString() << "\n";
	}

	outputStream.close();
}
