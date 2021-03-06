#pragma once
#include <assert.h>
#include "../controller.h"

class TestController {
	private:
		void AddVictim_CorrectInput_AddsVictim();
		void UpdateVictim_CorrectInput_UpdatesVictim();
		void DeleteVictim_CorrectInput_DeletesVictim();
		void SaveVictim_EmptyRepository_ThrowsError();
		void SaveVictim_InexistingVictim_ThrowsError();
		void GetFilteredEntries_EmptyRepository_NoOutput();
		void GetFilteredEntries_FilledRepository_CorrectNumberOfElements();
		void GetSavedVictims_MultipleValidSaves_CorrectNumberOfElements();
		void NextVictim_EmptyRepository_ThrowsError();
		void NextVictim_OneCall_CorrectVictim();
		void NextVictim_MultipleCalls_CorrectOutput();
		void SetRepositoryFileLocation_NonexistentFile_TXTFileCreated();
		void SetSavedVictimsFileLocation_NonexistentFile_HTMLFileCreated();

	public:
		void runAllTests();
};