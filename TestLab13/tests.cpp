#include "tests.h"
#include "controller.h"
#include <assert.h>

void GetNumberOfCarsByManufacturer_NonExistentManufacturer_NoOutput(){
	Controller newController;
	newController.addNewCar("manuf 1", "model 1", 2015, "green");
	newController.addNewCar("manuf 1", "model 14", 2015, "green");
	newController.addNewCar("manuf 2", "model 15", 2015, "green");
	newController.addNewCar("manuf 2", "model 16", 2015, "green");
	assert(newController.getNumberOfCarsByManufacturer("not a manuf") == 0);
}

void GetNumberOfCarsByManufacturer_ExistentManufacturer_CorrectNumberOfCars(){
	Controller newController;
	newController.addNewCar("manuf 1", "model 1", 2015, "green");
	newController.addNewCar("manuf 1", "model 14", 2015, "green");
	newController.addNewCar("manuf 2", "model 15", 2015, "green");
	newController.addNewCar("manuf 2", "model 16", 2015, "green");
	assert(newController.getNumberOfCarsByManufacturer("manuf 2") == 2);
}

void GetNumberOfCarsByManufacturer_NoData_NoOutput(){
	Controller newController;
	assert(newController.getNumberOfCarsByManufacturer("any manuf") == 0);
}
