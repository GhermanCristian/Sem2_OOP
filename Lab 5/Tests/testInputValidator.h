#pragma once
#include "../inputValidator.h"

class TestInputValidator {
	private:
		InputValidator inputValidator;
		void AddVictimValidator_InvalidInput_ReturnsErrorCode();
		void AddVictimValidator_CorrectInput_ReturnsVictimProperties();
		void UpdateVictimValidator_InvalidInput_ReturnsErrorCode();
		void UpdateVictimValidator_CorrectInput_ReturnsVictimProperties();
		void DeleteVictimValidator_InvalidInput_ReturnsErrorCode();
		void DeleteVictimValidator_CorrectInput_ReturnsVictimName();
		void ListAllValidator_InvalidInput_ReturnsErrorCode();
		void ListAllValidator_CorrectInput_ReturnsEmptyList();
		void NextVictimValidator_InvalidInput_ReturnsErrorCode();
		void NextVictimValidator_CorrectInput_ReturnsEmptyList();
		void SaveVictimValidator_InvalidInput_ReturnsErrorCode();
		void SaveVictimValidator_CorrectInput_ReturnsVictimName();
		void ListFilteredValidator_InvalidInput_ReturnsErrorCode();
		void ListFilteredValidator_CorrectInput_ReturnsPlaceOfOriginAndAge();
		void MyListValidator_InvalidInput_ReturnsErrorCode();
		void MyListValidator_CorrectInput_ReturnsEmptyList();
		void ProgramModeValidator_InvalidInput_ThrowsException();
		void ProgramModeValidator_CorrectInput_ReturnsProgramMode();
		void CSVFileVictimValidator_InvalidInput_ReturnsErrorCode();
		void CSVFileVictimValidator_CorrectInput_ReturnsVictimProperties();
		void FileLocationValidator_InvalidInput_ThrowsException();
		void FileLocationValidator_CorrectInput_ReturnsFileLocation();
		void MyListLocationValidator_InvalidInput_ThrowsException();
		void MyListLocationValidator_CorrectInput_ReturnsFileLocation();

	public:
		void runAllTests();
};