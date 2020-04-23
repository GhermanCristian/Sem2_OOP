#include "testController.h"

void TestController::runAllTests(){
	AddVictim_CorrectInput_AddsVictim();
	UpdateVictim_CorrectInput_UpdatesVictim();
	DeleteVictim_CorrectInput_DeletesVictim();
	SaveVictim_EmptyRepository_ThrowsError();
	SaveVictim_InexistingVictim_ThrowsError();
	GetFilteredEntries_EmptyRepository_NoOutput();
	GetFilteredEntries_FilledRepository_CorrectNumberOfElements();
	GetSavedVictims_MultipleValidSaves_CorrectNumberOfElements();
	NextVictim_EmptyRepository_ThrowsError();
	NextVictim_OneCall_CorrectVictim();
	NextVictim_MultipleCalls_CorrectOutput();
	SetRepositoryFileLocation_NonexistentFile_FileCreated();
}

void TestController::AddVictim_CorrectInput_AddsVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	pointerToData = newController.getAllVictims();
	assert(pointerToData[0] == newVictim);
}

void TestController::UpdateVictim_CorrectInput_UpdatesVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.updateVictim("vasile", "newplace", 1233, "newphoto.jpg");
	pointerToData = newController.getAllVictims();
	assert(pointerToData[0] == newVictim1);
}

void TestController::DeleteVictim_CorrectInput_DeletesVictim() {
	Controller newController;
	std::vector <Victim> pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.deleteVictim("vasile");
	pointerToData = newController.getAllVictims();
	assert(pointerToData.size() == 0);
}

void TestController::SaveVictim_EmptyRepository_ThrowsError() {
	Controller newController;

	try {
		newController.saveVictim("vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestController::SaveVictim_InexistingVictim_ThrowsError() {
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

void TestController::GetFilteredEntries_EmptyRepository_NoOutput() {
	Controller newController;
	std::vector <Victim> filteredVictims;

	filteredVictims = newController.getFilteredVictims("any place", 1234);
	
	assert(filteredVictims.size() == 0);
}

void TestController::GetFilteredEntries_FilledRepository_CorrectNumberOfElements() {
	Controller newController;
	std::vector <Victim> filteredVictims;

	newController.addVictim("vasile", "place", 123, "p1");
	newController.addVictim("vasile1", "place", 123, "p1");
	newController.addVictim("vasile2", "place", 123, "p1");
	filteredVictims = newController.getFilteredVictims("", 1234);

	assert(filteredVictims.size() == 3);
}

void TestController::GetSavedVictims_MultipleValidSaves_CorrectNumberOfElements() {
	Controller newController;
	std::vector <Victim> savedVictims;

	newController.addVictim("vasile", "place", 123, "photo");
	newController.addVictim("vasile1", "place", 123, "photo");
	newController.addVictim("vasile2", "place", 123, "photo");
	newController.addVictim("vasile3", "place", 123, "photo");
	newController.addVictim("vasile4", "place", 123, "photo");

	newController.saveVictim("vasile");
	newController.saveVictim("vasile2");
	newController.saveVictim("vasile3");

	savedVictims = newController.getSavedVictims();
	assert(savedVictims.size() == 3);
}

void TestController::NextVictim_EmptyRepository_ThrowsError() {
	Controller newController;

	try {
		Victim newVictim = newController.getNextVictim();
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestController::NextVictim_OneCall_CorrectVictim() {
	Controller newController;
	Victim newVictim{ "vasile", "place", 123, "photo" };
	Victim newVictim1;

	newController.addVictim("vasile", "place", 123, "photo");
	newController.addVictim("vasile1", "place", 123, "photo");
	newController.addVictim("vasile2", "place", 123, "photo");

	newVictim1 = newController.getNextVictim();
	assert(newVictim1 == newVictim);
}

void TestController::NextVictim_MultipleCalls_CorrectOutput() {
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

void TestController::SetRepositoryFileLocation_NonexistentFile_FileCreated() {
	Controller newController;
	newController.setRepositoryFileLocation("definitely_a_new_file.txt");
	remove("definitely_a_new_file.txt"); // this is not considered to be a "temporary" file, so it is not deleted automatically
}
