#pragma once
#include <assert.h>
#include "../memoryRepository.h"
#include "../CSVRepository.h"
#include "../HTMLRepository.h"

class TestMemoryRepository {
	private:
		void Add_DuplicateElement_ThrowsError();
		void Add_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder();
		void Update_InexistentElement_ThrowsError();
		void Update_ExistingElement_SuccessfulUpdate();
		void Erase_InexistentElement_ThrowsError();
		void Erase_EmptyMemoryRepository_ThrowsError();
		void Erase_FilledMemoryRepository_SuccessfulDeletion();
		void IsInRepository_EmptyMemoryRepository_NotFound();
		void IsInRepository_InvalidPosition_NotFound();
		void IsInRepository_ElementExists_ElementFound();
		void IsInRepository_NonExistingElement_ElementNotFound();
		void GetVictimByName_NonExistingVictim_ThrowsException();
		void GetVictimByName_ExistingVicitm_ReturnsVictim();
		void GetFilteredEntries_EmptyMemoryRepository_NoOutput();
		void GetFilteredEntries_FilledMemoryRepository_CorrectNumberOfElements();
		void GetFilteredEntries_NothingThroughFilter_NoOutput();
		void GetFilteredEntries_NoPlaceOfOrigin_CorrectNumberOfElements();
		//void MemoryRepositoryAssignmentOperator_FilledMemoryRepository_CorrectCopy();
		//void MemoryRepositoryCopyConstructor_FilledMemoryRepository_CorrectCopy();
		void GetAllEntries_EmptyMemoryRepository_NoOutput();
		void GetAllEntries_FilledMemoryRepository_CorrectNumberOfElements();
		void GetAllEntries_FilledMemoryRepository_CorrectElements();

	public:
		void runAllTests();
};

class TestCSVRepository {
	private:
		void RepositoryConstructor_InexistentFile_FileCreated();
		void RepositoryConstructor_InexistentFile_NoOutput();
		void LoadFromFile_EmptyFile_NoOutput();
		void LoadFromFile_FilledFile_CorrectNumberOfObjects();
		void LoadFromFile_FilledFile_CorrectObjects();
		void LoadFromFile_InvalidLine_ThrowsError();
		void SaveToFile_EmptyData_NoOutput();
		void SaveToFile_FilledData_CorrectNumberOfObjects();
		void SaveToFile_FilledData_CorrectObjects();
		void Add_DuplicateElement_ThrowsError();
		void Add_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder();
		void Update_InexistentElement_ThrowsError();
		void Update_ExistentElement_CorrectUpdate();
		void Erase_InexistentElement_ThrowsError();
		void Erase_EmptyCSVRepository_ThrowsError();
		void Erase_FilledCSVRepository_SuccessfulDeletion();
		void IsInRepository_EmptyCSVRepository_NotFound();
		void IsInRepository_InvalidPosition_NotFound();
		void IsInRepository_ElementExists_ElementFound();
		void IsInRepository_NonExistingElement_ElementNotFound();
		void GetFilteredEntries_EmptyCSVRepository_NoOutput();
		void GetFilteredEntries_FilledCSVRepository_CorrectNumberOfElements();
		void GetFilteredEntriesCSVRepository_NothingThroughFilter_NoOutput();
		void GetFilteredEntriesCSVRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
		//void CSVRepositoryAssignmentOperator_FilledCSVRepository_CorrectCopy();
		//void CSVRepositoryCopyConstructor_FilledCSVRepository_CorrectCopy();
		void GetAllEntries_EmptyCSVRepository_NoOutput();
		void GetAllEntries_FilledCSVRepository_CorrectNumberOfElements();

	public:
		void runAllTests();
};

class TestHTMLRepository {
	private:
		void HTMLRepositoryConstructor_NonexistentFile_FileCreated();
		void HTMLRepositoryConstructor_ExistingFile_FileOpenedSuccessfully();
		void LoadFromFile_EmptyFile_NoOutput();
		void LoadFromFile_FilledFile_CorrectNumberOfObjects();
		void LoadFromFile_FilledFile_CorrectObjects();
		void SaveToFile_EmptyData_NoOutput();
		void SaveToFile_FilledData_CorrectNumberOfObjects();
		void SaveToFile_FilledData_CorrectObjects();

	public:
		void runAllTests();
};