#include "tests.h"
#include <assert.h>
#include "userInterface.h"

void VictimConstructor_CorrectInput_CorrectName() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getName() == "vasile");
}

void VictimConstructor_CorrectInput_CorrectPlaceOfOrigin() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getPlaceOfOrigin() == "place");
}

void VictimConstructor_CorrectInput_CorrectAge() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getAge() == 123);
}

void VictimConstructor_CorrectInput_CorrectPhotograph() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getPhotographLink() == "photo.jpg");
}

void DynamicVectorConstructor_NoInput_CorrectCapacity() {
	DynamicVector newVector;
	assert(newVector.getCapacity() == INITIAL_VECTOR_CAPACITY);
}

void DynamicVectorConstructor_NoInput_CorrectNumberOfElements() {
	DynamicVector newVector;
	assert(newVector.getNumberOfElements() == 0);
}

void AddToVector_CorrectInput_ElementAdded() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim);
	assert(newVector[0] == newVictim && newVector.getNumberOfElements() == 1);
}

void AddToVector_MultipleInputs_ElementsAdded() {
	DynamicVector newVector;

	for (char letter = 'a'; letter <= 'z'; letter++) {
		std::string word;
		word += letter;
		Victim newVictim{word, word, 123, word};
		newVector.addToVector(newVictim);
	}

	assert(newVector.getNumberOfElements() == 26 && newVector.getCapacity() == INITIAL_VECTOR_CAPACITY * MULTIPLICATION_FACTOR);
}

void AddToVector_DuplicateElement_ThrowsError() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim);
	try {
		newVector.addToVector(newVictim1);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void UpdateInVector_CorrectInput_ElementUpdated() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newVector.addToVector(newVictim);
	newVector.updateInVector(newVictim1);
	assert(newVector[0] == newVictim1 && newVector.getNumberOfElements() == 1);
}

void UpdateInVector_InexistentElement_ThrowsError() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasileeee", "newplace", 1233, "newphoto.jpg" };

	newVector.addToVector(newVictim);
	try {
		newVector.updateInVector(newVictim1);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromVector_CorrectInput_ElementDeleted() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim);
	newVector.deleteFromVector(newVictim.getName());
	assert(newVector.getNumberOfElements() == 0);
}

void DeleteFromVector_InexistentElement_ThrowsError() {
	DynamicVector newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim);
	try {
		newVector.deleteFromVector("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromVector_EmptyVector_ThrowsError() {
	DynamicVector newVector;

	try {
		newVector.deleteFromVector("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void GetAllEntries_EmptyRepository_NoOutput() {
	Repository newRepository;
	DynamicVector* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->getNumberOfElements() == 0);
}

void GetAllEntries_FilledRepository_CorrectOutput() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasilee", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasileee", "place", 123, "photo.jpg" };

	newRepository.addToRepository(newVictim);
	newRepository.addToRepository(newVictim1);
	newRepository.addToRepository(newVictim2);

	DynamicVector* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->getNumberOfElements() == 3);
}

void AddVictim_CorrectInput_AddsVictim() {
	Controller newController;
	DynamicVector* pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	pointerToData = newController.getAllVictims();
	assert((*pointerToData)[0] == newVictim);
}

void UpdateVictim_CorrectInput_UpdatesVictim() {
	Controller newController;
	DynamicVector* pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.updateVictim("vasile", "newplace", 1233, "newphoto.jpg");
	pointerToData = newController.getAllVictims();
	assert((*pointerToData)[0] == newVictim1);
}

void DeleteVictim_CorrectInput_DeletesVictim() {
	Controller newController;
	DynamicVector* pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.deleteVictim("vasile");
	pointerToData = newController.getAllVictims();
	assert(pointerToData->getNumberOfElements() == 0);
}

void runAllTests() {
	VictimConstructor_CorrectInput_CorrectName();
	VictimConstructor_CorrectInput_CorrectPlaceOfOrigin();
	VictimConstructor_CorrectInput_CorrectAge();
	VictimConstructor_CorrectInput_CorrectPhotograph();

	DynamicVectorConstructor_NoInput_CorrectCapacity();
	DynamicVectorConstructor_NoInput_CorrectNumberOfElements();
	AddToVector_CorrectInput_ElementAdded();
	AddToVector_MultipleInputs_ElementsAdded();
	AddToVector_DuplicateElement_ThrowsError();
	UpdateInVector_CorrectInput_ElementUpdated();
	UpdateInVector_InexistentElement_ThrowsError();
	DeleteFromVector_CorrectInput_ElementDeleted();
	DeleteFromVector_InexistentElement_ThrowsError();
	DeleteFromVector_EmptyVector_ThrowsError();

	GetAllEntries_EmptyRepository_NoOutput();
	GetAllEntries_FilledRepository_CorrectOutput();

	AddVictim_CorrectInput_AddsVictim();
	UpdateVictim_CorrectInput_UpdatesVictim();
	DeleteVictim_CorrectInput_DeletesVictim();
}