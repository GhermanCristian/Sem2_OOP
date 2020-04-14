#include "testRepository.h"

void TestMemoryRepository::runAllTests(){
	this->AddToMemoryRepository_DuplicateElement_ThrowsError();
	this->AddToMemoryRepository_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder();
	this->UpdateInMemoryRepository_InexistentElement_ThrowsError();
	this->UpdateInMemoryRepository_ExistingElement_SuccessfulUpdate();
	this->DeleteFromMemoryRepository_InexistentElement_ThrowsError();
	this->DeleteFromMemoryRepository_EmptyMemoryRepository_ThrowsError();
	this->DeleteFromMemoryRepository_FilledMemoryRepository_SuccessfulDeletion();
	this->IsInMemoryRepository_EmptyMemoryRepository_NotFound();
	this->IsInMemoryRepository_InvalidPosition_NotFound();
	this->IsInMemoryRepository_ElementExists_ElementFound();
	this->IsInMemoryRepository_NonExistingElement_ElementNotFound();
	this->GetVictimByName_NonExistingVictim_ThrowsException();
	this->GetVictimByName_ExistingVicitm_ReturnsVictim();
	this->GetFilteredEntriesMemoryRepository_EmptyMemoryRepository_NoOutput();
	this->GetFilteredEntriesMemoryRepository_FilledMemoryRepository_CorrectNumberOfElements();
	this->GetFilteredEntriesMemoryRepository_NothingThroughFilter_NoOutput();
	this->GetFilteredEntriesMemoryRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
	//this->MemoryRepositoryAssignmentOperator_FilledMemoryRepository_CorrectCopy();
	//this->MemoryRepositoryCopyConstructor_FilledMemoryRepository_CorrectCopy();
	this->GetAllEntries_EmptyMemoryRepository_NoOutput();
	this->GetAllEntries_FilledMemoryRepository_CorrectNumberOfElements();
	this->GetAllEntries_FilledMemoryRepository_CorrectElements();
}

void TestCSVRepository::runAllTests(){
	this->CSVRepositoryConstructor_InexistentFile_FileCreated();
	this->CSVRepositoryConstructor_InexistentFile_NoOutput();
	this->LoadFromCSVFile_EmptyFile_NoOutput();
	this->LoadFromCSVFile_FilledFile_CorrectNumberOfObjects();
	this->LoadFromCSVFile_FilledFile_CorrectObjects();
	this->LoadFromCSVFile_InvalidLine_ThrowsError();
	this->SaveToCSVFile_EmptyData_NoOutput();
	this->SaveToCSVFile_FilledData_CorrectNumberOfObjects();
	this->SaveToCSVFile_FilledData_CorrectObjects();
	this->AddToCSVRepository_DuplicateElement_ThrowsError();
	this->AddToCSVRepository_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder();
	this->UpdateInCSVRepository_InexistentElement_ThrowsError();
	this->UpdateInCSVRepository_ExistentElement_CorrectUpdate();
	this->DeleteFromCSVRepository_InexistentElement_ThrowsError();
	this->DeleteFromCSVRepository_EmptyCSVRepository_ThrowsError();
	this->DeleteFromCSVRepository_FilledCSVRepository_SuccessfulDeletion();
	this->IsInCSVRepository_EmptyCSVRepository_NotFound();
	this->IsInCSVRepository_InvalidPosition_NotFound();
	this->IsInCSVRepository_ElementExists_ElementFound();
	this->IsInCSVRepository_NonExistingElement_ElementNotFound();
	this->GetFilteredEntries_EmptyCSVRepository_NoOutput();
	this->GetFilteredEntries_FilledCSVRepository_CorrectNumberOfElements();
	this->GetFilteredEntriesCSVRepository_NothingThroughFilter_NoOutput();
	this->GetFilteredEntriesCSVRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
	//this->CSVRepositoryAssignmentOperator_FilledCSVRepository_CorrectCopy();
	//this->CSVRepositoryCopyConstructor_FilledCSVRepository_CorrectCopy();
	this->GetAllEntriesCSVRepository_EmptyCSVRepository_NoOutput();
	this->GetAllEntriesCSVRepository_FilledCSVRepository_CorrectNumberOfElements();
}

void TestMemoryRepository::AddToMemoryRepository_DuplicateElement_ThrowsError() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	try {
		newRepository.add(newVictim);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestMemoryRepository::AddToMemoryRepository_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder() {
	MemoryRepository newRepository;
	std::vector <Victim> pointerToData;

	for (char letter = 'f'; letter >= 'a'; letter--) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newRepository.add(newVictim);
	}

	// checks if the elements are in increasing order
	pointerToData = newRepository.getAllEntries();
	for (int index = 0; index < pointerToData.size() - 1; index++) {
		assert(pointerToData[index].getName() < pointerToData[index + 1].getName());
	}
}

void TestMemoryRepository::UpdateInMemoryRepository_InexistentElement_ThrowsError() {
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

void TestMemoryRepository::UpdateInMemoryRepository_ExistingElement_SuccessfulUpdate() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newRepository.add(newVictim);
	newRepository.update(newVictim1);
	assert(newRepository.getAllEntries()[0] == newVictim1);
}

void TestMemoryRepository::DeleteFromMemoryRepository_InexistentElement_ThrowsError() {
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

void TestMemoryRepository::DeleteFromMemoryRepository_EmptyMemoryRepository_ThrowsError() {
	MemoryRepository newRepository;

	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestMemoryRepository::DeleteFromMemoryRepository_FilledMemoryRepository_SuccessfulDeletion() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.erase("vasile");
	assert(newRepository.getAllEntries().size() == 0);
}

void TestMemoryRepository::IsInMemoryRepository_EmptyMemoryRepository_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile") == false);
}

void TestMemoryRepository::IsInMemoryRepository_InvalidPosition_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile", 1) == false);
}

void TestMemoryRepository::IsInMemoryRepository_ElementExists_ElementFound() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("vasile") == true);
}

void TestMemoryRepository::IsInMemoryRepository_NonExistingElement_ElementNotFound() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("not vasile") == false);
}

void TestMemoryRepository::GetVictimByName_NonExistingVictim_ThrowsException() {
	MemoryRepository newRepository;
	
	try {
		newRepository.getVictimByName("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestMemoryRepository::GetVictimByName_ExistingVicitm_ReturnsVictim() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.getVictimByName("vasile") == newVictim);
}

void TestMemoryRepository::GetFilteredEntriesMemoryRepository_EmptyMemoryRepository_NoOutput() {
	MemoryRepository newRepository;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "location", 222 };
	std::vector <Victim> newVector = newRepository.getFilteredEntries(currentFilter);

	assert(newVector.size() == 0);
}

void TestMemoryRepository::GetFilteredEntriesMemoryRepository_FilledMemoryRepository_CorrectNumberOfElements() {
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

void TestMemoryRepository::GetFilteredEntriesMemoryRepository_NothingThroughFilter_NoOutput() {
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

void TestMemoryRepository::GetFilteredEntriesMemoryRepository_NoPlaceOfOrigin_CorrectNumberOfElements() {
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

//void TestMemoryRepository::MemoryRepositoryAssignmentOperator_FilledRepository_CorrectCopy() {
//	MemoryRepository newRepository;
//	MemoryRepository newRepository1;
//	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
//	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
//	Victim newVictim2{ "vasile2", "place2", 123, "photo.jpg" };
//
//	newRepository.add(newVictim);
//	newRepository.add(newVictim1);
//	newRepository.add(newVictim2);
//
//	newRepository1 = newRepository;
//	assert(newRepository1 == newRepository);
//}
//
//void TestMemoryRepository::MemoryRepositoryCopyConstructor_FilledRepository_CorrectCopy() {
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

void TestMemoryRepository::GetAllEntries_EmptyMemoryRepository_NoOutput() {
	MemoryRepository newRepository;
	std::vector <Victim> pointerToData = newRepository.getAllEntries();
	assert(pointerToData.size() == 0);
}

void TestMemoryRepository::GetAllEntries_FilledMemoryRepository_CorrectNumberOfElements() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasilee", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasileee", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	std::vector <Victim> pointerToData = newRepository.getAllEntries();
	assert(pointerToData.size() == 3);
}

void TestMemoryRepository::GetAllEntries_FilledMemoryRepository_CorrectElements() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasilee", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasileee", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	std::vector <Victim> pointerToData = newRepository.getAllEntries();
	assert(pointerToData[0] == newVictim and pointerToData[1] == newVictim1 and pointerToData[2] == newVictim2);
}

void TestCSVRepository::CSVRepositoryConstructor_InexistentFile_FileCreated() {
	CSVRepository newRepository;
	assert(newRepository.createFile("totally_new_file.txt") == true);
	remove("totally_new_file.txt");
}

void TestCSVRepository::CSVRepositoryConstructor_InexistentFile_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::LoadFromCSVFile_EmptyFile_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::LoadFromCSVFile_FilledFile_CorrectNumberOfObjects() {
	CSVRepository newRepository("testData1.txt");
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 10);
}

void TestCSVRepository::LoadFromCSVFile_FilledFile_CorrectObjects() {
	CSVRepository newRepository("testData1.txt");
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	Victim victim1{ "Cena John", "Roma", 20, "photo122.jpg" };
	Victim victim2{ "John Cena", "Paris", 21, "photo41.jpg" };
	assert(repositoryData[1] == victim1 and repositoryData[4] == victim2);
}

void TestCSVRepository::LoadFromCSVFile_InvalidLine_ThrowsError() {
	/*CSVRepository newRepository;
	std::vector <Victim> repositoryData;
	newRepository.add(Victim{ "name, location, sth else", "some other name, loc, else", 123, "do, whatever" });

	try {
		repositoryData = newRepository.loadFromFile();
		assert(false);
	}
	catch (...) {
		assert(true);
	}*/
}

void TestCSVRepository::SaveToCSVFile_EmptyData_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData; // this can be the aftermath of add, remove, del etc
	newRepository.saveToFile(repositoryData);

	repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::SaveToCSVFile_FilledData_CorrectNumberOfObjects() {
	CSVRepository newRepository("testData2.txt");
	std::vector <Victim> repositoryData;

	repositoryData.push_back(Victim{ "Nelson Judeteanu", "Itcani", 45, "photo11.jpg" });
	repositoryData.push_back(Victim{ "Nelson Nationalu", "Berchisesti", 45, "photo1412.jpg" });
	repositoryData.push_back(Victim{ "Nelson Planetaru", "Obcini", 55, "photo13.jpg" });

	// this is just called here so that the function appears to be tested
	// because I use overloaded <<, I have no use for it right now, so it's never called explicitly
	newRepository.getVictimFileRepresentation(Victim{ "Nelson Judeteanu", "Itcani", 45, "photo11.jpg" });

	newRepository.saveToFile(repositoryData);

	repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 3);

	remove("testData2.txt");
}

void TestCSVRepository::SaveToCSVFile_FilledData_CorrectObjects() {
	CSVRepository newRepository("testData2.txt");
	std::vector <Victim> repositoryData;
	Victim victim1{ "Nelson Judeteanu", "Itcani", 45, "photo11.jpg" };
	Victim victim2{ "Nelson Nationalu", "Berchisesti", 45, "photo1412.jpg" };
	Victim victim3{ "Nelson Planetaru", "Obcini", 55, "photo13.jpg" };

	repositoryData.push_back(victim1);
	repositoryData.push_back(victim2);
	repositoryData.push_back(victim3);

	newRepository.saveToFile(repositoryData);

	repositoryData = newRepository.loadFromFile();
	assert(repositoryData[0] == victim1 and repositoryData[1] == victim2 and repositoryData[2] == victim3);

	remove("testData2.txt");
}

void TestCSVRepository::AddToCSVRepository_DuplicateElement_ThrowsError() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	try {
		newRepository.add(newVictim);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestCSVRepository::AddToCSVRepository_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder() {
	CSVRepository newRepository;
	std::vector <Victim> pointerToData;

	for (char letter = 'f'; letter >= 'a'; letter--) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newRepository.add(newVictim);
	}

	// checks if the elements are in increasing order
	pointerToData = newRepository.getAllEntries();
	for (int index = 0; index < pointerToData.size() - 1; index++) {
		assert(pointerToData[index].getName() < pointerToData[index + 1].getName());
	}
}

void TestCSVRepository::UpdateInCSVRepository_InexistentElement_ThrowsError() {
	CSVRepository newRepository;
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

void TestCSVRepository::UpdateInCSVRepository_ExistentElement_CorrectUpdate() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newRepository.add(newVictim);
	newRepository.update(newVictim1);
	assert(newRepository.getAllEntries()[0] == newVictim1);
}

void TestCSVRepository::DeleteFromCSVRepository_InexistentElement_ThrowsError() {
	CSVRepository newRepository;
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

void TestCSVRepository::DeleteFromCSVRepository_EmptyCSVRepository_ThrowsError() {
	CSVRepository newRepository;

	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestCSVRepository::DeleteFromCSVRepository_FilledCSVRepository_SuccessfulDeletion() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.erase("vasile");
	assert(newRepository.getAllEntries().size() == 0);
}

void TestCSVRepository::IsInCSVRepository_EmptyCSVRepository_NotFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData = newRepository.getAllEntries();

	assert(newRepository.isInRepository(currentData, "vasile") == false);
}

void TestCSVRepository::IsInCSVRepository_InvalidPosition_NotFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData = newRepository.getAllEntries();

	assert(newRepository.isInRepository(currentData, "vasile", 1) == false);
}

void TestCSVRepository::IsInCSVRepository_ElementExists_ElementFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	currentData = newRepository.getAllEntries();
	assert(newRepository.isInRepository(currentData, "vasile") == true);
}

void TestCSVRepository::IsInCSVRepository_NonExistingElement_ElementNotFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	currentData = newRepository.getAllEntries();
	assert(newRepository.isInRepository(currentData, "not vasile") == false);
}

void TestCSVRepository::GetFilteredEntries_EmptyCSVRepository_NoOutput() {
	CSVRepository newRepository;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "location", 222 };
	std::vector <Victim> newVector = newRepository.getFilteredEntries(currentFilter);

	assert(newVector.size() == 0);
}

void TestCSVRepository::GetFilteredEntries_FilledCSVRepository_CorrectNumberOfElements() {
	CSVRepository newRepository;
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

void TestCSVRepository::GetFilteredEntriesCSVRepository_NothingThroughFilter_NoOutput() {
	CSVRepository newRepository;
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

void TestCSVRepository::GetFilteredEntriesCSVRepository_NoPlaceOfOrigin_CorrectNumberOfElements() {
	CSVRepository newRepository;
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

//void TestCSVRepository::CSVRepositoryAssignmentoperator_FilledCSVRepository_CorrectCopy() {
//	;
//}
//
//void TestCSVRepository::CSVRepositoryCopyConstructor_FilledCSVRepository_CorrectCopy() {
//	;
//}

void TestCSVRepository::GetAllEntriesCSVRepository_EmptyCSVRepository_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> pointerToData = newRepository.getAllEntries();

	assert(pointerToData.size() == 0);
}

void TestCSVRepository::GetAllEntriesCSVRepository_FilledCSVRepository_CorrectNumberOfElements() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasilee", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasileee", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.add(newVictim1);
	newRepository.add(newVictim2);

	std::vector <Victim> pointerToData = newRepository.getAllEntries();
	assert(pointerToData.size() == 3);
}
