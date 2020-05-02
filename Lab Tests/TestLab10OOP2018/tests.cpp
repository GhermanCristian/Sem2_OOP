#include "tests.h"
#include "controller.h"
#include <assert.h>

void AddRefrigerator_NewRefrigerator_RefrigeratorAdded(){
	Controller newController;
	std::vector <Appliance*> controllerData;
	Refrigerator newRefrigerator{ 1, 1, "A++", true };
	newController.addRefrigerator(1, 1, "A++", true);
	controllerData = newController.getAllAppliances();
	assert(*(controllerData[0]) == newRefrigerator);
}

void AddRefrigerator_ExistingRefrigerator_ThrowsException(){
	Controller newController;
	newController.addRefrigerator(1, 1, "A++", true);
	try {
		newController.addRefrigerator(1, 1, "A++", true);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void GetAppliancesSortedByWeight_CorrectInput_AppliancesSorted(){
	Controller newController;
	std::vector <Appliance*> controllerData;
	const int NUMBER_OF_APPLIANCES = 6;

	newController.addRefrigerator(1, 1331, "A++", true);
	newController.addRefrigerator(2, 3321, "A++", true);
	newController.addRefrigerator(3, 1231, "A++", true);
	newController.addRefrigerator(4, 1231, "A++", true);
	newController.addRefrigerator(5, 1321, "A++", true);
	newController.addRefrigerator(6, 1123, "A++", true);
	controllerData = newController.getAppliancesSortedByWeight();

	for (int position = 0; position < controllerData.size() - 1; position++) {
		assert(controllerData[position]->getWeight() <= controllerData[position + 1]->getWeight());
	}
}
