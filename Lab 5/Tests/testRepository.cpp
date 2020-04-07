#include "testRepository.h"

void AddToRepository_DuplicateElement_ThrowsError() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	try {
		newRepository.add(newVictim1);
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
		newRepository.add(newVictim);
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

	newRepository.add(newVictim);
	try {
		newRepository.update(newVictim1);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromRepository_InexistentElement_ThrowsError() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
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

void IsInRepository_EmptyRepository_NotFound() {
	Repository newRepository;
	assert(newRepository.isInRepository("vasile") == false);
}

void IsInRepository_InvalidPosition_NotFound() {
	Repository newRepository;
	assert(newRepository.isInRepository("vasile", 1) == false);
}

void IsInRepository_ElementExists_ElementFound() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("vasile") == true);
}

void IsInRepository_NonExistingElement_ElementNotFound() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("not vasile") == false);
}

void GetFilteredEntries_EmptyRepository_NoOutput() {
	Repository newRepository;
	DynamicVector<TElem> newVector = newRepository.getFilteredEntries("location", 222);

	assert(newVector.getNumberOfElements() == 0);
}

void GetFilteredEntries_FilledRepository_CorrectNumberOfElements() {
	Repository newRepository;
	DynamicVector<TElem> newVector;

	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
	Victim newVictim3{ "vasile3", "place", 123, "photo.jpg" };
	Victim newVictim4{ "vasile4", "place3", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);
	newRepository.add(newVictim3);
	newRepository.add(newVictim4);

	newVector = newRepository.getFilteredEntries("place", 124);
	assert(newVector.getNumberOfElements() == 3);
}

void GetFilteredEntries_NothingThroughFilter_NoOutput() {
	Repository newRepository;
	DynamicVector<TElem> newVector;

	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
	Victim newVictim3{ "vasile3", "place", 123, "photo.jpg" };
	Victim newVictim4{ "vasile4", "place3", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);
	newRepository.add(newVictim3);
	newRepository.add(newVictim4);

	newVector = newRepository.getFilteredEntries("place", 123);
	assert(newVector.getNumberOfElements() == 0);
}

void GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements() {
	Repository newRepository;
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
	Victim newVictim3{ "vasile3", "place", 123, "photo.jpg" };
	Victim newVictim4{ "vasile4", "place3", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);
	newRepository.add(newVictim3);
	newRepository.add(newVictim4);

	newVector = newRepository.getFilteredEntries("", 1);
	assert(newVector.getNumberOfElements() == 5);
}

void RepositoryAssignmentOperator_FilledRepository_CorrectCopy() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	Repository newRepository1;
	newRepository1 = newRepository;
	assert(newRepository1 == newRepository);
}

void RepositoryCopyConstructor_FilledRepository_CorrectCopy() {
	Repository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	Repository newRepository1(newRepository);
	assert(newRepository1 == newRepository);
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

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	DynamicVector<TElem>* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->getNumberOfElements() == 3);
}

void testRepository() {
	AddToRepository_DuplicateElement_ThrowsError();
	AddToRepository_EmptyRepositoryMultipleInputs_AddedInTheCorrectOrder();
	UpdateInRepository_InexistentElement_ThrowsError();
	DeleteFromRepository_InexistentElement_ThrowsError();
	DeleteFromRepository_EmptyRepository_ThrowsError();
	IsInRepository_EmptyRepository_NotFound();
	IsInRepository_InvalidPosition_NotFound();
	IsInRepository_ElementExists_ElementFound();
	IsInRepository_NonExistingElement_ElementNotFound();
	GetFilteredEntries_EmptyRepository_NoOutput();
	GetFilteredEntries_FilledRepository_CorrectNumberOfElements();
	GetFilteredEntries_NothingThroughFilter_NoOutput();
	GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements();
	RepositoryAssignmentOperator_FilledRepository_CorrectCopy();
	RepositoryCopyConstructor_FilledRepository_CorrectCopy();
	GetAllEntries_EmptyRepository_NoOutput();
	GetAllEntries_FilledRepository_CorrectOutput();
}