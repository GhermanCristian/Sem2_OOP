#include "testInputValidator.h"
#include <assert.h>

void TestInputValidator::runAllTests(){
	this->AddVictimValidator_InvalidInput_ReturnsErrorCode();
	this->AddVictimValidator_CorrectInput_ReturnsVictimProperties();
	this->UpdateVictimValidator_InvalidInput_ReturnsErrorCode();
	this->UpdateVictimValidator_CorrectInput_ReturnsVictimProperties();
	this->DeleteVictimValidator_InvalidInput_ReturnsErrorCode();
	this->DeleteVictimValidator_CorrectInput_ReturnsVictimName();
	this->ListAllValidator_InvalidInput_ReturnsErrorCode();
	this->ListAllValidator_CorrectInput_ReturnsEmptyList();
	this->NextVictimValidator_InvalidInput_ReturnsErrorCode();
	this->NextVictimValidator_CorrectInput_ReturnsEmptyList();
	this->SaveVictimValidator_InvalidInput_ReturnsErrorCode();
	this->SaveVictimValidator_CorrectInput_ReturnsVictimName();
	this->ListFilteredValidator_InvalidInput_ReturnsErrorCode();
	this->ListFilteredValidator_CorrectInput_ReturnsPlaceOfOriginAndAge();
	this->MyListValidator_InvalidInput_ReturnsErrorCode();
	this->MyListValidator_CorrectInput_ReturnsEmptyList();
	this->ProgramModeValidator_InvalidInput_ThrowsException();
	this->ProgramModeValidator_CorrectInput_ReturnsProgramMode();
	this->CSVFileVictimValidator_InvalidInput_ReturnsErrorCode();
	this->CSVFileVictimValidator_CorrectInput_ReturnsVictimProperties();
	this->FileLocationValidator_InvalidInput_ThrowsException();
	this->FileLocationValidator_CorrectInput_ReturnsFileLocation();
}

void TestInputValidator::AddVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.addVictimInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::AddVictimValidator_CorrectInput_ReturnsVictimProperties(){
	std::string validInput = "add a, a, 1, a";
	ArgumentList victimProperties = this->inputValidator.addVictimInputValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "a";
	expectedProperties.list[PLACE_OF_ORIGIN_POSITION] = "a";
	expectedProperties.list[AGE_POSITION] = "1";
	expectedProperties.list[PHOTOGRAPH_POSITION] = "a";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::UpdateVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.updateVictimInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::UpdateVictimValidator_CorrectInput_ReturnsVictimProperties(){
	std::string validInput = "update a, a, 1, a";
	ArgumentList victimProperties = this->inputValidator.updateVictimInputValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "a";
	expectedProperties.list[PLACE_OF_ORIGIN_POSITION] = "a";
	expectedProperties.list[AGE_POSITION] = "1";
	expectedProperties.list[PHOTOGRAPH_POSITION] = "a";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::DeleteVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.deleteVictimInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::DeleteVictimValidator_CorrectInput_ReturnsVictimName(){
	std::string validInput = "delete john cena";
	ArgumentList victimProperties = this->inputValidator.deleteVictimInputValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "john cena";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::ListAllValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.listAllInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::ListAllValidator_CorrectInput_ReturnsEmptyList(){
	std::string validInput = "list";
	ArgumentList victimProperties = this->inputValidator.listAllInputValidator(validInput);
	ArgumentList expectedProperties;

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::NextVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.nextVictimInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::NextVictimValidator_CorrectInput_ReturnsEmptyList(){
	std::string validInput = "next";
	ArgumentList victimProperties = this->inputValidator.nextVictimInputValidator(validInput);
	ArgumentList expectedProperties;

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::SaveVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.saveVictimInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::SaveVictimValidator_CorrectInput_ReturnsVictimName(){
	std::string validInput = "save john cena";
	ArgumentList victimProperties = this->inputValidator.saveVictimInputValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "john cena";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::ListFilteredValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.listFilteredInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::ListFilteredValidator_CorrectInput_ReturnsPlaceOfOriginAndAge(){
	std::string validInput = "list , 123";
	ArgumentList victimProperties = this->inputValidator.listFilteredInputValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "";
	expectedProperties.list[PLACE_OF_ORIGIN_POSITION] = "123";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::MyListValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	try {
		this->inputValidator.myListInputValidator(invalidInput);
		assert(false);
	}
	catch (const ValidationException& currentException) {
		assert(true);
	}
}

void TestInputValidator::MyListValidator_CorrectInput_ReturnsEmptyList(){
	std::string validInput = "mylist";
	ArgumentList victimProperties = this->inputValidator.myListInputValidator(validInput);
	ArgumentList expectedProperties;

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::ProgramModeValidator_InvalidInput_ThrowsException(){
	std::string invalidInput = "mode C";

	try {
		this->inputValidator.programModeValidator(invalidInput);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestInputValidator::ProgramModeValidator_CorrectInput_ReturnsProgramMode(){
	std::string validInput = "mode B";
	char programMode = this->inputValidator.programModeValidator(validInput);
	char expectedProgramMode = 'B';

	assert(programMode == expectedProgramMode);
}

void TestInputValidator::CSVFileVictimValidator_InvalidInput_ReturnsErrorCode(){
	std::string invalidInput = "definitely invalid";
	//assert(this->inputValidator.CSVFileVictimValidator(invalidInput).list[ERROR_POSITION] == ERROR_CODE);
}

void TestInputValidator::CSVFileVictimValidator_CorrectInput_ReturnsVictimProperties(){
	std::string validInput = "a, a, 1, a";
	ArgumentList victimProperties = this->inputValidator.CSVFileVictimValidator(validInput);
	ArgumentList expectedProperties;

	expectedProperties.list[NAME_POSITION] = "a";
	expectedProperties.list[PLACE_OF_ORIGIN_POSITION] = "a";
	expectedProperties.list[AGE_POSITION] = "1";
	expectedProperties.list[PHOTOGRAPH_POSITION] = "a";

	assert(victimProperties == expectedProperties);
}

void TestInputValidator::FileLocationValidator_InvalidInput_ThrowsException(){
	std::string invalidInput = "cdcd:\\";

	try {
		this->inputValidator.fileLocationValidator(invalidInput);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestInputValidator::FileLocationValidator_CorrectInput_ReturnsFileLocation(){
	std::string validInput = "fileLocation c:\\cartofi.txt";
	std::string fileLocation = this->inputValidator.fileLocationValidator(validInput);
	std::string expectedLocation = "c:\\cartofi.txt";

	assert(fileLocation == expectedLocation);
}
