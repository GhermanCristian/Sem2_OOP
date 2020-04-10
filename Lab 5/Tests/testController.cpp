#include "testController.h"

void AddVictim_CorrectInput_AddsVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	pointerToData = newController.getAllVictims();
	assert(pointerToData[0] == newVictim);
}

void UpdateVictim_CorrectInput_UpdatesVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.updateVictim("vasile", "newplace", 1233, "newphoto.jpg");
	pointerToData = newController.getAllVictims();
	assert(pointerToData[0] == newVictim1);
}

void DeleteVictim_CorrectInput_DeletesVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.deleteVictim("vasile");
	pointerToData = newController.getAllVictims();
	assert(pointerToData.size() == 0);
}

void SaveVictim_EmptyRepository_ThrowsError() {
	Controller newController;

	try {
		newController.saveVictim("vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void SaveVictim_InexistingVictim_ThrowsError() {
	Controller newController;

	newController.addVictim("vasile", "place", 123, "photo");

	try {
		newController.saveVictim("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void GetSavedVictims_MultipleValidSaves_CorrectNumberOfElements() {
	Controller newController;
	std::vector <Victim>* savedVictims;

	newController.addVictim("vasile", "place", 123, "photo");
	newController.addVictim("vasile1", "place", 123, "photo");
	newController.addVictim("vasile2", "place", 123, "photo");
	newController.addVictim("vasile3", "place", 123, "photo");
	newController.addVictim("vasile4", "place", 123, "photo");

	newController.saveVictim("vasile");
	newController.saveVictim("vasile2");
	newController.saveVictim("vasile3");

	savedVictims = newController.getSavedVictims();
	assert(savedVictims->size() == 3);
}

void NextVictim_EmptyRepository_ThrowsError() {
	Controller newController;

	try {
		Victim newVictim = newController.getNextVictim();
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void NextVictim_OneCall_CorrectVictim() {
	Controller newController;
	Victim newVictim{ "vasile", "place", 123, "photo" };
	Victim newVictim1;

	newController.addVictim("vasile", "place", 123, "photo");
	newController.addVictim("vasile1", "place", 123, "photo");
	newController.addVictim("vasile2", "place", 123, "photo");

	newVictim1 = newController.getNextVictim();
	assert(newVictim1 == newVictim);
}

void NextVictim_MultipleCalls_CorrectOutput() {
	Controller newController;
	Victim newVictim{ "vasile2", "place", 123, "photo" };
	Victim newVictim1;
	int numberOfCycles = 10;
	int numberOfElements = 3;

	newController.addVictim("vasile", "place", 123, "photo");
	newController.addVictim("vasile1", "place", 123, "photo");
	newController.addVictim("vasile2", "place", 123, "photo");

	for (int i = 0; i < numberOfCycles * numberOfElements; i++) {
		newVictim1 = newController.getNextVictim();
	}
	assert(newVictim1 == newVictim);
}

void testController() {
	AddVictim_CorrectInput_AddsVictim();
	UpdateVictim_CorrectInput_UpdatesVictim();
	DeleteVictim_CorrectInput_DeletesVictim();
	SaveVictim_EmptyRepository_ThrowsError();
	SaveVictim_InexistingVictim_ThrowsError();
	GetSavedVictims_MultipleValidSaves_CorrectNumberOfElements();
	NextVictim_EmptyRepository_ThrowsError();
	NextVictim_OneCall_CorrectVictim();
	NextVictim_MultipleCalls_CorrectOutput();
}