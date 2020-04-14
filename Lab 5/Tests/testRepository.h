#pragma once
#include <assert.h>
#include "../memoryRepository.h"
#include "../CSVRepository.h"

class TestMemoryRepository {
	friend class MemoryRepository;

	private:
		void AddToMemoryRepository_DuplicateElement_ThrowsError();
		void AddToMemoryRepository_EmptyMemoryRepositoryMultipleInputs_AddedInTheCorrectOrder();
		void UpdateInMemoryRepository_InexistentElement_ThrowsError();
		void UpdateInMemoryRepository_ExistingElement_SuccessfulUpdate();
		void DeleteFromMemoryRepository_InexistentElement_ThrowsError();
		void DeleteFromMemoryRepository_EmptyMemoryRepository_ThrowsError();
		void DeleteFromMemoryRepository_FilledMemoryRepository_SuccessfulDeletion();
		void IsInMemoryRepository_EmptyMemoryRepository_NotFound();
		void IsInMemoryRepository_InvalidPosition_NotFound();
		void IsInMemoryRepository_ElementExists_ElementFound();
		void IsInMemoryRepository_NonExistingElement_ElementNotFound();
		void GetVictimByName_NonExistingVictim_ThrowsException();
		void GetVictimByName_ExistingVicitm_ReturnsVictim();
		void GetFilteredEntriesMemoryRepository_EmptyMemoryRepository_NoOutput();
		void GetFilteredEntriesMemoryRepository_FilledMemoryRepository_CorrectNumberOfElements();
		void GetFilteredEntriesMemoryRepository_NothingThroughFilter_NoOutput();
		void GetFilteredEntriesMemoryRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
		//void MemoryRepositoryAssignmentOperator_FilledMemoryRepository_CorrectCopy();
		//void MemoryRepositoryCopyConstructor_FilledMemoryRepository_CorrectCopy();
		void GetAllEntries_EmptyMemoryRepository_NoOutput();
		void GetAllEntries_FilledMemoryRepository_CorrectNumberOfElements();
		void GetAllEntries_FilledMemoryRepository_CorrectElements();

	public:
		void runAllTests();
};

class TestCSVRepository {
	friend class CSVRepository;

	private:
		void CSVRepositoryConstructor_InexistentFile_FileCreated();
		void CSVRepositoryConstructor_InexistentFile_NoOutput();
		void LoadFromCSVFile_EmptyFile_NoOutput();
		void LoadFromCSVFile_FilledFile_CorrectNumberOfObjects();
		void LoadFromCSVFile_FilledFile_CorrectObjects();
		void LoadFromCSVFile_InvalidLine_ThrowsError();
		void SaveToCSVFile_EmptyData_NoOutput();
		void SaveToCSVFile_FilledData_CorrectNumberOfObjects();
		void SaveToCSVFile_FilledData_CorrectObjects();
		void AddToCSVRepository_DuplicateElement_ThrowsError();
		void AddToCSVRepository_EmptyCSVRepositoryMultipleInputs_AddedInTheCorrectOrder();
		void UpdateInCSVRepository_InexistentElement_ThrowsError();
		void UpdateInCSVRepository_ExistentElement_CorrectUpdate();
		void DeleteFromCSVRepository_InexistentElement_ThrowsError();
		void DeleteFromCSVRepository_EmptyCSVRepository_ThrowsError();
		void DeleteFromCSVRepository_FilledCSVRepository_SuccessfulDeletion();
		void IsInCSVRepository_EmptyCSVRepository_NotFound();
		void IsInCSVRepository_InvalidPosition_NotFound();
		void IsInCSVRepository_ElementExists_ElementFound();
		void IsInCSVRepository_NonExistingElement_ElementNotFound();
		void GetFilteredEntries_EmptyCSVRepository_NoOutput();
		void GetFilteredEntries_FilledCSVRepository_CorrectNumberOfElements();
		void GetFilteredEntriesCSVRepository_NothingThroughFilter_NoOutput();
		void GetFilteredEntriesCSVRepository_NoPlaceOfOrigin_CorrectNumberOfElements();
		//void CSVRepositoryAssignmentOperator_FilledCSVRepository_CorrectCopy();
		//void CSVRepositoryCopyConstructor_FilledCSVRepository_CorrectCopy();
		void GetAllEntriesCSVRepository_EmptyCSVRepository_NoOutput();
		void GetAllEntriesCSVRepository_FilledCSVRepository_CorrectNumberOfElements();

	public:
		void runAllTests();
};