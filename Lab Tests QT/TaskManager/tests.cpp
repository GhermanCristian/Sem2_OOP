#include "tests.h"
#include "controller.h"
#include <assert.h>

void RemoveTask_NonExistentTask_ThrowsException(){
	Repository newRepository;
	try {
		newRepository.removeTask("whatever it doesn't exist");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void RemoveTask_ValidTask_TaskRemoved(){
	Repository newRepository;
	newRepository.addTask(Task("abc", "abc", 123));
	newRepository.addTask(Task("abcd", "abcd", 1234));
	newRepository.removeTask("abc");
	assert(newRepository.getAllTasks().size() == 1);
	assert(newRepository.getAllTasks()[0].getDescription() == "abcd");
	assert(newRepository.getAllTasks()[0].getStatus() == "abcd");
	assert(newRepository.getAllTasks()[0].getID() == 1234);
}

void StartTask_NonExistentTask_ThrowsException(){
	Controller newController("");
	try {
		newController.startTask("nope", Programmer());
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void StartTask_ValidTask_TaskStarted(){
	Controller newController("");
	newController.addTask("abc");
	newController.startTask("abc", Programmer(123, "john"));
	assert(newController.getAllTasks().size() == 1);
	assert(newController.getAllTasks()[0].getStatus() == "in progress");
	assert(newController.getAllTasks()[0].getID() == 123);
}

void DoneTask_NonExistentTask_ThrowsException(){
	Controller newController("");
	try {
		newController.doneTask("nope");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DoneTask_ValidTask_TaskDone(){
	Controller newController("");
	newController.addTask("abc");
	newController.startTask("abc", Programmer(123, "john"));
	newController.doneTask("abc");
	assert(newController.getAllTasks().size() == 1);
	assert(newController.getAllTasks()[0].getStatus() == "closed");
	assert(newController.getAllTasks()[0].getID() == 123);
}
