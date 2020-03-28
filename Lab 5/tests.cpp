#include "tests.h"
#include <assert.h>
#include "userInterface.h"
#include <iostream>

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
	DynamicVector<TElem> newVector;
	assert(newVector.getCapacity() == INITIAL_VECTOR_CAPACITY);
}

void DynamicVectorConstructor_NoInput_CorrectNumberOfElements() {
	DynamicVector<TElem> newVector;
	assert(newVector.getNumberOfElements() == 0);
}

void AddToVector_EmptyVectorOneInput_ElementAdded() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim, 0);
	assert(newVector[0] == newVictim && newVector.getNumberOfElements() == 1);
}

void UpdateInVector_CorrectInput_ElementUpdated() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newVector.addToVector(newVictim, 0);
	newVector.updateInVector(newVictim1, 0);
	assert(newVector[0] == newVictim1 && newVector.getNumberOfElements() == 1);
}

void DeleteFromVector_CorrectInput_ElementDeleted() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.addToVector(newVictim, 0);
	newVector.deleteFromVector(0);
	assert(newVector.getNumberOfElements() == 0);
}

void VectorResize_MultipleInputs_SuccessfulResize() {
	DynamicVector<TElem> newVector;

	for (char letter = 'a'; letter <= 'z'; letter++) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newVector.addToVector(newVictim, letter - 'a');
	}

	assert(newVector.getNumberOfElements() == 26 && newVector.getCapacity() == INITIAL_VECTOR_CAPACITY * MULTIPLICATION_FACTOR);
}

void DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector2.addToVector(newVictim, 0);
	vector1 = vector2;

	assert(vector1.getNumberOfElements() == vector2.getNumberOfElements() and vector1[0] == newVictim);
}

void DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.addToVector(newVictim, 0);
	vector1 = vector2;

	assert(vector1.getNumberOfElements() == 0);
}

void DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.addToVector(newVictim, 0);

	DynamicVector<TElem> vector2(vector1);
	assert(vector2.getNumberOfElements() == vector2.getNumberOfElements() and vector2[0] == newVictim);
}

void DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2(vector1);

	assert(vector2.getNumberOfElements() == 0);
}

void AddToRepository_DuplicateElement_ThrowsError() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "place", 123, "photo.jpg" };

	newRepository.addToRepository(newVictim);
	try {
		newRepository.addToRepository(newVictim1);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddToRepository_EmptyRepositoryMultipleInputs_AddedInTheCorrectOrder() {
	Repository newRepository;
	DynamicVector<TElem>* pointerToData;

	for (char letter = 'f'; letter >= 'a'; letter--) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newRepository.addToRepository(newVictim);
	}// no resize here

	// checks if the elements are in increasing order
	pointerToData = newRepository.getAllEntries();
	for (int index = 0; index < pointerToData->getNumberOfElements() - 1; index++) {
		assert((*pointerToData)[index].getName() < (*pointerToData)[index + 1].getName());
	}
}

void UpdateInRepository_InexistentElement_ThrowsError() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasileeee", "newplace", 1233, "newphoto.jpg" };

	newRepository.addToRepository(newVictim);
	try {
		newRepository.updateInRepository(newVictim1);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromRepository_InexistentElement_ThrowsError() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.addToRepository(newVictim);
	try {
		newRepository.deleteFromRepository("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromRepository_EmptyRepository_ThrowsError() {
	Repository newRepository;

	try {
		newRepository.deleteFromRepository("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void GetAllEntries_EmptyRepository_NoOutput() {
	Repository newRepository;
	DynamicVector<TElem>* pointerToData = newRepository.getAllEntries();
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

	DynamicVector<TElem>* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->getNumberOfElements() == 3);
}

void AddVictim_CorrectInput_AddsVictim() {
	Controller newController;
	DynamicVector<TElem>* pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	pointerToData = newController.getAllVictims();
	assert((*pointerToData)[0] == newVictim);
}

void UpdateVictim_CorrectInput_UpdatesVictim() {
	Controller newController;
	DynamicVector<TElem>* pointerToData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newController.addVictim("vasile", "place", 123, "photo.jpg");
	newController.updateVictim("vasile", "newplace", 1233, "newphoto.jpg");
	pointerToData = newController.getAllVictims();
	assert((*pointerToData)[0] == newVictim1);
}

void DeleteVictim_CorrectInput_DeletesVictim() {
	Controller newController;
	DynamicVector<TElem>* pointerToData;
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
	AddToVector_EmptyVectorOneInput_ElementAdded();
	UpdateInVector_CorrectInput_ElementUpdated();
	DeleteFromVector_CorrectInput_ElementDeleted();
	VectorResize_MultipleInputs_SuccessfulResize();
	DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy();
	DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy();

	AddToRepository_DuplicateElement_ThrowsError(); 
	AddToRepository_EmptyRepositoryMultipleInputs_AddedInTheCorrectOrder(); 
	UpdateInRepository_InexistentElement_ThrowsError(); 
	DeleteFromRepository_InexistentElement_ThrowsError(); 
	DeleteFromRepository_EmptyRepository_ThrowsError(); 

	GetAllEntries_EmptyRepository_NoOutput();
	GetAllEntries_FilledRepository_CorrectOutput();

	AddVictim_CorrectInput_AddsVictim();
	UpdateVictim_CorrectInput_UpdatesVictim();
	DeleteVictim_CorrectInput_DeletesVictim();
}