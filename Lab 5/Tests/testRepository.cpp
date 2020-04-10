#include "testRepository.h"

void AddToRepository_DuplicateElement_ThrowsError() {
	MemoryRepository newRepository;
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
	MemoryRepository newRepository;
	std::vector <Victim>* pointerToData;

	for (char letter = 'f'; letter >= 'a'; letter--) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newRepository.add(newVictim);
	}// no resize here

	// checks if the elements are in increasing order
	pointerToData = newRepository.getAllEntries();
	for (int index = 0; index < pointerToData->size() - 1; index++) {
		assert((*pointerToData)[index].getName() < (*pointerToData)[index + 1].getName());
	}
}

void UpdateInRepository_InexistentElement_ThrowsError() {
	MemoryRepository newRepository;
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
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void DeleteFromRepository_EmptyRepository_ThrowsError() {
	MemoryRepository newRepository;

	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void IsInRepository_EmptyRepository_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile") == false);
}

void IsInRepository_InvalidPosition_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile", 1) == false);
}

void IsInRepository_ElementExists_ElementFound() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("vasile") == true);
}

void IsInRepository_NonExistingElement_ElementNotFound() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("not vasile") == false);
}

void GetFilteredEntries_EmptyRepository_NoOutput() {
	MemoryRepository newRepository;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "location", 222 };
	std::vector <Victim> newVector = newRepository.getFilteredEntries(currentFilter);

	assert(newVector.size() == 0);
}

void GetFilteredEntries_FilledRepository_CorrectNumberOfElements() {
	MemoryRepository newRepository;
	std::vector <Victim> newVector;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "place", 124 };

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

	newVector = newRepository.getFilteredEntries(currentFilter);
	assert(newVector.size() == 3);
}

void GetFilteredEntries_NothingThroughFilter_NoOutput() {
	MemoryRepository newRepository;
	std::vector <Victim> newVector;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "place", 123 };

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

	newVector = newRepository.getFilteredEntries(currentFilter);
	assert(newVector.size() == 0);
}

void GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements() {
	MemoryRepository newRepository;
	std::vector <Victim> newVector;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "", 1 };
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

	newVector = newRepository.getFilteredEntries(currentFilter);
	assert(newVector.size() == 5);
}

//void RepositoryAssignmentOperator_FilledRepository_CorrectCopy() {
//	MemoryRepository newRepository;
//	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
//	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
//	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
//
//	newRepository.add(newVictim);
//	newRepository.add(newVictim1);
//	newRepository.add(newVictim2);
//
//	MemoryRepository newRepository1;
//	newRepository1 = newRepository;
//	assert(newRepository1 == newRepository);
//}
//
//void RepositoryCopyConstructor_FilledRepository_CorrectCopy() {
//	MemoryRepository newRepository;
//	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
//	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
//	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
//
//	newRepository.add(newVictim);
//	newRepository.add(newVictim1);
//	newRepository.add(newVictim2);
//
//	MemoryRepository newRepository1(newRepository);
//	assert(newRepository1 == newRepository);
//}

void GetAllEntries_EmptyRepository_NoOutput() {
	MemoryRepository newRepository;
	std::vector <Victim>* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->size() == 0);
}

void GetAllEntries_FilledRepository_CorrectOutput() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasilee", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasileee", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	std::vector <Victim>* pointerToData = newRepository.getAllEntries();
	assert(pointerToData->size() == 3);
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
	//RepositoryAssignmentOperator_FilledRepository_CorrectCopy();
	//RepositoryCopyConstructor_FilledRepository_CorrectCopy();
	GetAllEntries_EmptyRepository_NoOutput();
	GetAllEntries_FilledRepository_CorrectOutput();
}