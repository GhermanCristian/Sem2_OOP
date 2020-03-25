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

void AddToVector_MultipleInputs_AddedInTheCorrectOrder() {
	DynamicVector newVector;

	for (char letter = 'f'; letter >= 'a'; letter--) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newVector.addToVector(newVictim);
	}// no resize here

	// checks if the element are in increasing order
	for (int index = 0; index < newVector.getNumberOfElements() - 1; index++) {
		assert(newVector[index].getName() < newVector[index + 1].getName());
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

void VectorResize_MultipleInputs_SuccessfulResize() {
	DynamicVector newVector;

	for (char letter = 'a'; letter <= 'z'; letter++) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newVector.addToVector(newVictim);
	}

	assert(newVector.getNumberOfElements() == 26 && newVector.getCapacity() == INITIAL_VECTOR_CAPACITY * MULTIPLICATION_FACTOR);
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

void DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy() {
	DynamicVector vector1;
	DynamicVector vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector2.addToVector(newVictim);
	vector1 = vector2;

	assert(vector1.getNumberOfElements() == vector2.getNumberOfElements() and vector1[0] == newVictim);
}

void DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy() {
	DynamicVector vector1;
	DynamicVector vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.addToVector(newVictim);
	vector1 = vector2;

	assert(vector1.getNumberOfElements() == 0);
}

void DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy() {
	DynamicVector vector1;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.addToVector(newVictim);

	DynamicVector vector2(vector1);
	assert(vector2.getNumberOfElements() == vector2.getNumberOfElements() and vector2[0] == newVictim);
}

void DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy() {
	DynamicVector vector1;
	DynamicVector vector2(vector1);

	assert(vector2.getNumberOfElements() == 0);
}

void runAllTests() {
	VictimConstructor_CorrectInput_CorrectName();
	VictimConstructor_CorrectInput_CorrectPlaceOfOrigin();
	VictimConstructor_CorrectInput_CorrectAge();
	VictimConstructor_CorrectInput_CorrectPhotograph();

	DynamicVectorConstructor_NoInput_CorrectCapacity();
	DynamicVectorConstructor_NoInput_CorrectNumberOfElements();
	AddToVector_CorrectInput_ElementAdded();
	AddToVector_DuplicateElement_ThrowsError();
	AddToVector_MultipleInputs_AddedInTheCorrectOrder();
	UpdateInVector_CorrectInput_ElementUpdated();
	UpdateInVector_InexistentElement_ThrowsError();
	DeleteFromVector_CorrectInput_ElementDeleted();
	DeleteFromVector_InexistentElement_ThrowsError();
	DeleteFromVector_EmptyVector_ThrowsError();
	VectorResize_MultipleInputs_SuccessfulResize();
	DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy();
	DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy();

	GetAllEntries_EmptyRepository_NoOutput();
	GetAllEntries_FilledRepository_CorrectOutput();

	AddVictim_CorrectInput_AddsVictim();
	UpdateVictim_CorrectInput_UpdatesVictim();
	DeleteVictim_CorrectInput_DeletesVictim();
}