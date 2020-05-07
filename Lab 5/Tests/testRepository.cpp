#include "testRepository.h"

void TestMemoryRepository::runAllTests(){
	this->Add_DuplicateElement_ThrowsError();
	this->Add_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder();
	this->Update_InexistentElement_ThrowsError();
	this->Update_ExistingElement_SuccessfulUpdate();
	this->Erase_InexistentElement_ThrowsError();
	this->Erase_EmptyMemoryRepository_ThrowsError();
	this->Erase_FilledMemoryRepository_SuccessfulDeletion();
	this->IsInRepository_EmptyMemoryRepository_NotFound();
	this->IsInRepository_InvalidPosition_NotFound();
	this->IsInRepository_ElementExists_ElementFound();
	this->IsInRepository_NonExistingElement_ElementNotFound();
	this->GetVictimByName_NonExistingVictim_ThrowsException();
	this->GetVictimByName_ExistingVicitm_ReturnsVictim();
	this->GetFilteredEntries_EmptyMemoryRepository_NoOutput();
	this->GetFilteredEntries_FilledMemoryRepository_CorrectNumberOfElements();
	this->GetFilteredEntries_NothingThroughFilter_NoOutput();
	this->GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements();
	//this->MemoryRepositoryAssignmentOperator_FilledMemoryRepository_CorrectCopy();
	//this->MemoryRepositoryCopyConstructor_FilledMemoryRepository_CorrectCopy();
	this->GetAllEntries_EmptyMemoryRepository_NoOutput();
	this->GetAllEntries_FilledMemoryRepository_CorrectNumberOfElements();
	this->GetAllEntries_FilledMemoryRepository_CorrectElements();
}

void TestCSVRepository::runAllTests(){
	this->RepositoryConstructor_InexistentFile_FileCreated();
	this->RepositoryConstructor_InexistentFile_NoOutput();
	this->LoadFromFile_EmptyFile_NoOutput();
	this->LoadFromFile_FilledFile_CorrectNumberOfObjects();
	this->LoadFromFile_FilledFile_CorrectObjects();
	this->LoadFromFile_InvalidLine_ThrowsError();
	this->SaveToFile_EmptyData_NoOutput();
	this->SaveToFile_FilledData_CorrectNumberOfObjects();
	this->SaveToFile_FilledData_CorrectObjects();
	this->Add_DuplicateElement_ThrowsError();
	this->Add_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder();
	this->Update_InexistentElement_ThrowsError();
	this->Update_ExistentElement_CorrectUpdate();
	this->Erase_InexistentElement_ThrowsError();
	this->Erase_EmptyCSVRepository_ThrowsError();
	this->Erase_FilledCSVRepository_SuccessfulDeletion();
	this->IsInRepository_EmptyCSVRepository_NotFound();
	this->IsInRepository_InvalidPosition_NotFound();
	this->IsInRepository_ElementExists_ElementFound();
	this->IsInRepository_NonExistingElement_ElementNotFound();
	this->GetFilteredEntries_EmptyCSVRepository_NoOutput();
	this->GetFilteredEntries_FilledCSVRepository_CorrectNumberOfElements();
	this->GetFilteredEntriesCSVRepository_NothingThroughFilter_NoOutput();
	this->GetFilteredEntriesCSVRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
	//this->CSVRepositoryAssignmentOperator_FilledCSVRepository_CorrectCopy();
	//this->CSVRepositoryCopyConstructor_FilledCSVRepository_CorrectCopy();
	this->GetAllEntries_EmptyCSVRepository_NoOutput();
	this->GetAllEntries_FilledCSVRepository_CorrectNumberOfElements();
}

void TestMemoryRepository::Add_DuplicateElement_ThrowsError() {
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

void TestMemoryRepository::Add_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder() {
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

void TestMemoryRepository::Update_InexistentElement_ThrowsError() {
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

void TestMemoryRepository::Update_ExistingElement_SuccessfulUpdate() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newRepository.add(newVictim);
	newRepository.update(newVictim1);
	assert(newRepository.getAllEntries()[0] == newVictim1);
}

void TestMemoryRepository::Erase_InexistentElement_ThrowsError() {
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

void TestMemoryRepository::Erase_EmptyMemoryRepository_ThrowsError() {
	MemoryRepository newRepository;

	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestMemoryRepository::Erase_FilledMemoryRepository_SuccessfulDeletion() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.erase("vasile");
	assert(newRepository.getAllEntries().size() == 0);
}

void TestMemoryRepository::IsInRepository_EmptyMemoryRepository_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile") == false);
}

void TestMemoryRepository::IsInRepository_InvalidPosition_NotFound() {
	MemoryRepository newRepository;
	assert(newRepository.isInRepository("vasile", 1) == false);
}

void TestMemoryRepository::IsInRepository_ElementExists_ElementFound() {
	MemoryRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	assert(newRepository.isInRepository("vasile") == true);
}

void TestMemoryRepository::IsInRepository_NonExistingElement_ElementNotFound() {
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

void TestMemoryRepository::GetFilteredEntries_EmptyMemoryRepository_NoOutput() {
	MemoryRepository newRepository;
	FilterPlaceOfOriginAndYoungerThan currentFilter{ "location", 222 };
	std::vector <Victim> newVector = newRepository.getFilteredEntries(currentFilter);

	assert(newVector.size() == 0);
}

void TestMemoryRepository::GetFilteredEntries_FilledMemoryRepository_CorrectNumberOfElements() {
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

void TestMemoryRepository::GetFilteredEntries_NothingThroughFilter_NoOutput() {
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

void TestMemoryRepository::GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements() {
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
	assert(pointerToData[0] == newVictim && pointerToData[1] == newVictim1 && pointerToData[2] == newVictim2);
}

void TestCSVRepository::RepositoryConstructor_InexistentFile_FileCreated() {
	CSVRepository newRepository;
	assert(newRepository.createFile("totally_new_file.txt") == true);
	remove("totally_new_file.txt");
}

void TestCSVRepository::RepositoryConstructor_InexistentFile_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::LoadFromFile_EmptyFile_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::LoadFromFile_FilledFile_CorrectNumberOfObjects() {
	CSVRepository newRepository("testData1.txt");
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 10);
}

void TestCSVRepository::LoadFromFile_FilledFile_CorrectObjects() {
	CSVRepository newRepository("testData1.txt");
	std::vector <Victim> repositoryData = newRepository.loadFromFile();
	Victim victim1{ "Cena John", "Roma", 20, "photo122.jpg" };
	Victim victim2{ "John Cena", "Paris", 21, "photo41.jpg" };
	assert(repositoryData[1] == victim1 && repositoryData[4] == victim2);
}

void TestCSVRepository::LoadFromFile_InvalidLine_ThrowsError() {
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

void TestCSVRepository::SaveToFile_EmptyData_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> repositoryData; // this can be the aftermath of add, remove, del etc
	newRepository.saveToFile(repositoryData);

	repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 0);
}

void TestCSVRepository::SaveToFile_FilledData_CorrectNumberOfObjects() {
	CSVRepository newRepository("testData2.txt");
	std::vector <Victim> repositoryData;

	repositoryData.push_back(Victim{ "Nelson Judeteanu", "Itcani", 45, "photo11.jpg" });
	repositoryData.push_back(Victim{ "Nelson Nationalu", "Berchisesti", 45, "photo1412.jpg" });
	repositoryData.push_back(Victim{ "Nelson Planetaru", "Obcini", 55, "photo13.jpg" });

	newRepository.saveToFile(repositoryData);

	repositoryData = newRepository.loadFromFile();
	assert(repositoryData.size() == 3);

	remove("testData2.txt");
}

void TestCSVRepository::SaveToFile_FilledData_CorrectObjects() {
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
	assert(repositoryData[0] == victim1 && repositoryData[1] == victim2 && repositoryData[2] == victim3);

	remove("testData2.txt");
}

void TestCSVRepository::Add_DuplicateElement_ThrowsError() {
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

void TestCSVRepository::Add_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder() {
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

void TestCSVRepository::Update_InexistentElement_ThrowsError() {
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

void TestCSVRepository::Update_ExistentElement_CorrectUpdate() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newRepository.add(newVictim);
	newRepository.update(newVictim1);
	assert(newRepository.getAllEntries()[0] == newVictim1);
}

void TestCSVRepository::Erase_InexistentElement_ThrowsError() {
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

void TestCSVRepository::Erase_EmptyCSVRepository_ThrowsError() {
	CSVRepository newRepository;

	try {
		newRepository.erase("not vasile");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestCSVRepository::Erase_FilledCSVRepository_SuccessfulDeletion() {
	CSVRepository newRepository;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	newRepository.erase("vasile");
	assert(newRepository.getAllEntries().size() == 0);
}

void TestCSVRepository::IsInRepository_EmptyCSVRepository_NotFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData = newRepository.getAllEntries();

	assert(newRepository.isInRepository(currentData, "vasile") == false);
}

void TestCSVRepository::IsInRepository_InvalidPosition_NotFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData = newRepository.getAllEntries();

	assert(newRepository.isInRepository(currentData, "vasile", 1) == false);
}

void TestCSVRepository::IsInRepository_ElementExists_ElementFound() {
	CSVRepository newRepository;
	std::vector <Victim> currentData;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newRepository.add(newVictim);
	currentData = newRepository.getAllEntries();
	assert(newRepository.isInRepository(currentData, "vasile") == true);
}

void TestCSVRepository::IsInRepository_NonExistingElement_ElementNotFound() {
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

void TestCSVRepository::GetAllEntries_EmptyCSVRepository_NoOutput() {
	CSVRepository newRepository;
	std::vector <Victim> pointerToData = newRepository.getAllEntries();

	assert(pointerToData.size() == 0);
}

void TestCSVRepository::GetAllEntries_FilledCSVRepository_CorrectNumberOfElements() {
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

void TestHTMLRepository::HTMLRepositoryConstructor_NonexistentFile_FileCreated(){
	HTMLRepository currentRepository;
	assert(currentRepository.createFile("totally_new_file.html") == true);
	remove("totally_new_file.html");
}

void TestHTMLRepository::HTMLRepositoryConstructor_ExistingFile_FileOpenedSuccessfully() {
	HTMLRepository currentRepository;
	assert(currentRepository.createFile("testData1.html") == true);
}

void TestHTMLRepository::LoadFromFile_EmptyFile_NoOutput(){
	HTMLRepository currentRepository;
	std::vector <Victim> currentData;
	currentData = currentRepository.loadFromFile();

	assert(currentData.size() == 0);
}

void TestHTMLRepository::LoadFromFile_FilledFile_CorrectNumberOfObjects(){
	HTMLRepository currentRepository("testData1.html");
	std::vector <Victim> currentData;
	currentData = currentRepository.loadFromFile();

	assert(currentData.size() == 3);
}

void TestHTMLRepository::LoadFromFile_FilledFile_CorrectObjects(){
	HTMLRepository currentRepository("testData1.html");
	std::vector <Victim> currentData;
	Victim newVictim0{ "Amore", "Piata Marasti", 22, "photo151.jpg" };
	Victim newVictim1{ "Cena John", "Roma", 20, "photo122.jpg" };
	Victim newVictim2{ "Ernest", "Burdujeni respect", 31, "photo113.jpg" };
	currentData = currentRepository.loadFromFile();

	assert(currentData[0] == newVictim0 && currentData[1] == newVictim1 && currentData[2] == newVictim2);
}

void TestHTMLRepository::SaveToFile_EmptyData_NoOutput(){
	HTMLRepository currentRepository;
	std::vector <Victim> currentData;
	currentRepository.saveToFile(currentData);

	currentData = currentRepository.loadFromFile();
	assert(currentData.size() == 0);
}

void TestHTMLRepository::SaveToFile_FilledData_CorrectNumberOfObjects(){
	HTMLRepository currentRepository;
	std::vector <Victim> currentData;
	Victim newVictim0{ "Amore", "Piata Marasti", 22, "photo151.jpg" };
	Victim newVictim1{ "Cena John", "Roma", 20, "photo122.jpg" };
	Victim newVictim2{ "Ernest", "Burdujeni respect", 31, "photo113.jpg" };

	currentData.push_back(newVictim0);
	currentData.push_back(newVictim1);
	currentData.push_back(newVictim2);

	currentRepository.saveToFile(currentData);
	currentData = currentRepository.loadFromFile();

	assert(currentData.size() == 3);
}

void TestHTMLRepository::SaveToFile_FilledData_CorrectObjects(){
	HTMLRepository currentRepository;
	std::vector <Victim> currentData;
	Victim newVictim0{ "Amore", "Piata Marasti", 22, "photo151.jpg" };
	Victim newVictim1{ "Cena John", "Roma", 20, "photo122.jpg" };
	Victim newVictim2{ "Ernest", "Burdujeni respect", 31, "photo113.jpg" };

	currentData.push_back(newVictim0);
	currentData.push_back(newVictim1);
	currentData.push_back(newVictim2);

	currentRepository.saveToFile(currentData);
	currentData = currentRepository.loadFromFile();

	assert(currentData[0] == newVictim0 && currentData[1] == newVictim1 && currentData[2] == newVictim2);
}

void TestHTMLRepository::runAllTests(){
	this->HTMLRepositoryConstructor_NonexistentFile_FileCreated();
	this->HTMLRepositoryConstructor_ExistingFile_FileOpenedSuccessfully();
	this->LoadFromFile_EmptyFile_NoOutput();
	this->LoadFromFile_FilledFile_CorrectNumberOfObjects();
	this->LoadFromFile_FilledFile_CorrectObjects();
	this->SaveToFile_EmptyData_NoOutput();
	this->SaveToFile_FilledData_CorrectNumberOfObjects();
	this->SaveToFile_FilledData_CorrectObjects();
}
