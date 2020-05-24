#include "tests.h"
#include "controller.h"
#include <assert.h>

void GetTotalDurationWithGivenPriority_NoPriorityMatched_NoOutput(){
	Controller newController;
	newController.addTask("d1", 1, 1);
	newController.addTask("d2", 2, 1);
	newController.addTask("d3", 3, 2);
	newController.addTask("d4", 4, 2);
	assert(newController.getTotalDurationWithGivenPriority(3) == 0);
}

void GetTotalDurationWithGivenPriority_EmptyRepository_NoOutput(){
	Controller newController;
	assert(newController.getTotalDurationWithGivenPriority(3) == 0);
}

void GetTotalDurationWithGivenPriority_FilledRepository_CorrectDuration(){
	Controller newController;
	newController.addTask("d1", 1, 1);
	newController.addTask("d2", 2, 1);
	newController.addTask("d3", 3, 2);
	newController.addTask("d4", 4, 2);
	assert(newController.getTotalDurationWithGivenPriority(2) == 7);
}
