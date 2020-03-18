#include <assert.h>
#include <string.h>
#include "tests.h"
#include "archive.h"
#include "repository.h"
#include "controller.h"

/*
	add 1 f a 4
	add 2 q a 14
	add 3 y a 11
	add 4 qw a 21
	add 5 po a 2
	add 6 xyz a 3
	
*/

void CreateArchive_ValidInput_ArchiveCreated() {
	Archive newArchive;
	newArchive = createArchive(1, "good", "book", 2000);
	assert(newArchive.catalogueNumber == 1);
	assert(strcmp(newArchive.stateOfDeterioration, "good") == 0);
	assert(strcmp(newArchive.fileType, "book") == 0);
	assert(newArchive.yearOfCreation == 2000);
}

void CreateArchive_InvalidInput_ReturnsError() {
	/*Archive newArchive;
	newArchive = createArchive(1, 1, 1, 1);
	assert(0);*/
}

void CreateRepository_ValidInput_RepositoryCreated() {
	Repository* newRepository;
	newRepository = createRepository(INITIAL_CAPACITY);
	assert(newRepository != NULL);
	assert(newRepository->data.archiveList != NULL);
	assert(newRepository->data.capacity == INITIAL_CAPACITY);
	assert(newRepository->data.numberOfObjects == 0);
	repositoryDestructor(newRepository);
}

void CreateRepository_InvalidInput_ReturnsError() {
	;
}

void AddArchive_ValidInput_AddedToRepository() {
	Archive newArchive = createArchive(1, "good", "book", 2019);;
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	int operationResult = addToRepository(newRepository, newArchive);
	assert(operationResult == 1);
	assert(getNumberOfObjects(&newRepository->data) == 1);

	Archive archiveFromRepository = getArchiveAtIndex(getPointerToData(newRepository), 0);
	assert(archiveFromRepository.catalogueNumber == newArchive.catalogueNumber);
	assert(strcmp(archiveFromRepository.stateOfDeterioration, newArchive.stateOfDeterioration) == 0);
	assert(strcmp(archiveFromRepository.fileType, newArchive.fileType) == 0);
	assert(archiveFromRepository.yearOfCreation == newArchive.yearOfCreation);

	repositoryDestructor(newRepository);
}

void AddArchive_DuplicateCatalogueNumber_ReturnsError() {
	Archive newArchive = createArchive(1, "good", "book", 2019);;
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	addToRepository(newRepository, newArchive);
	int operationResult = addToRepository(newRepository, newArchive);

	assert(operationResult == 0);
	assert(getNumberOfObjects(&newRepository->data) == 1);

	repositoryDestructor(newRepository);
}

void DeleteArchive_ValidInput_DeletedFromRepository() {
	Archive newArchive = createArchive(1, "good", "book", 2019);;
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	addToRepository(newRepository, newArchive);
	int operationResult = deleteRepositoryEntry(newRepository, newArchive.catalogueNumber);
	assert(operationResult == 1);
	assert(getNumberOfObjects(&newRepository->data) == 0);

	repositoryDestructor(newRepository);
}

void DeleteArchive_InexistentCatalogueNumber_ReturnsError() {
	Archive newArchive = createArchive(1, "good", "book", 2019);;
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	addToRepository(newRepository, newArchive);
	int operationResult = deleteRepositoryEntry(newRepository, 100);
	assert(operationResult == 0);
	assert(getNumberOfObjects(&newRepository->data) == 1);

	repositoryDestructor(newRepository);
}

void UpdateArchive_ValidInput_SuccessfulUpdate() {
	Archive newArchive = createArchive(1, "good", "book", 2019);;
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	addToRepository(newRepository, newArchive);
	int operationResult = updateRepositoryEntry(newRepository, newArchive.catalogueNumber, "better", "magazine", 2012);
	assert(operationResult == 1);
	assert(getNumberOfObjects(&newRepository->data) == 1);

	Archive archiveFromRepository = getArchiveAtIndex(getPointerToData(newRepository), 0);
	assert(archiveFromRepository.catalogueNumber == newArchive.catalogueNumber);
	assert(strcmp(archiveFromRepository.stateOfDeterioration, "better") == 0);
	assert(strcmp(archiveFromRepository.fileType, "magazine") == 0);
	assert(archiveFromRepository.yearOfCreation == 2012);

	repositoryDestructor(newRepository);
}

void UpdateArchive_InexistentArchive_ReturnsError() {
	Archive newArchive = createArchive(1, "good", "book", 2019);
	Repository* newRepository = createRepository(INITIAL_CAPACITY);

	addToRepository(newRepository, newArchive);
	int operationResult = updateRepositoryEntry(newRepository, 2, "better", "magazine", 2012);
	assert(operationResult == 0);
	assert(getNumberOfObjects(&newRepository->data) == 1);

	Archive archiveFromRepository = getArchiveAtIndex(getPointerToData(newRepository), 0);
	assert(archiveFromRepository.catalogueNumber == newArchive.catalogueNumber);
	assert(strcmp(archiveFromRepository.stateOfDeterioration, newArchive.stateOfDeterioration) == 0);
	assert(strcmp(archiveFromRepository.fileType, newArchive.fileType) == 0);
	assert(archiveFromRepository.yearOfCreation == newArchive.yearOfCreation);

	repositoryDestructor(newRepository);
}

void GetAllArchives_EmptyRepository_NoOutput() {
	Repository* newRepository = createRepository(INITIAL_CAPACITY);
	Container* completeData = getPointerToData(newRepository);

	assert(getNumberOfObjects(completeData) == 0);

	repositoryDestructor(newRepository);
}

void GetAllArchives_NonEmptyRepository_CorrectOutput() {
	Repository* newRepository = createRepository(INITIAL_CAPACITY);
	Container* completeData = getPointerToData(newRepository);
	Archive newArchive1 = createArchive(1, "good", "book", 2019);
	Archive newArchive2 = createArchive(2, "goodish", "books", 2020);

	addToRepository(newRepository, newArchive1);
	addToRepository(newRepository, newArchive2);

	assert(getNumberOfObjects(completeData) == 2);

	repositoryDestructor(newRepository);
}

void FilterEntriesByType_EmptyRepository_NoOutput() {
	Controller* newController = createController();
	Container filteredData = filterEntriesByType(newController, "x");

	assert(getNumberOfObjects(&filteredData) == 0);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void FilterEntriesByType_NothingThroughFilter_NoOutput() {
	Controller* newController = createController();
	Container filteredData;

	Archive newArchive1 = createArchive(1, "good", "book", 2019);
	Archive newArchive2 = createArchive(2, "goodish", "books", 2020);
	Archive newArchive3 = createArchive(3, "goodish", "books", 2020);
	Archive newArchive4 = createArchive(4, "goodish", "book", 2020);
	Archive newArchive5 = createArchive(5, "goodish", "bo", 2020);

	addToRepository(newController->archiveRepository, newArchive1);
	addToRepository(newController->archiveRepository, newArchive2);
	addToRepository(newController->archiveRepository, newArchive3);
	addToRepository(newController->archiveRepository, newArchive4);
	addToRepository(newController->archiveRepository, newArchive5);

	filteredData = filterEntriesByType(newController, "bookss");
	assert(getNumberOfObjects(&filteredData) == 0);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void FilterEntriesByType_PassingThroughFilter_CorrectOutput() {
	Controller* newController = createController();
	Container filteredData;

	Archive newArchive1 = createArchive(1, "good", "book", 2019);
	Archive newArchive2 = createArchive(2, "goodish", "books", 2020);
	Archive newArchive3 = createArchive(3, "goodish", "books", 2020);
	Archive newArchive4 = createArchive(4, "goodish", "book", 2020);
	Archive newArchive5 = createArchive(5, "goodish", "bo", 2020);

	addToRepository(newController->archiveRepository, newArchive1);
	addToRepository(newController->archiveRepository, newArchive2);
	addToRepository(newController->archiveRepository, newArchive3);
	addToRepository(newController->archiveRepository, newArchive4);
	addToRepository(newController->archiveRepository, newArchive5);

	filteredData = filterEntriesByType(newController, "books");
	assert(getNumberOfObjects(&filteredData) == 2);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void FilterEntriesByYear_EmptyRepository_NoOutput() {
	Controller* newController = createController();
	Container filteredData = filterEntriesByYear(newController, 2009);

	assert(getNumberOfObjects(&filteredData) == 0);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void FilterEntriesByYear_NothingThroughFilter_NoOutput() {
	Controller* newController = createController();
	Container filteredData;

	Archive newArchive1 = createArchive(1, "good", "book", 2019);
	Archive newArchive2 = createArchive(2, "goodish", "books", 2020);
	Archive newArchive3 = createArchive(3, "goodish", "books", 2020);
	Archive newArchive4 = createArchive(4, "goodish", "book", 2020);
	Archive newArchive5 = createArchive(5, "goodish", "bo", 2020);

	addToRepository(newController->archiveRepository, newArchive1);
	addToRepository(newController->archiveRepository, newArchive2);
	addToRepository(newController->archiveRepository, newArchive3);
	addToRepository(newController->archiveRepository, newArchive4);
	addToRepository(newController->archiveRepository, newArchive5);

	filteredData = filterEntriesByYear(newController, 2004);
	assert(getNumberOfObjects(&filteredData) == 0);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void FilterEntriesByYear_PassingThroughFilter_CorrectOutput() {
	Controller* newController = createController();
	Container filteredData;

	Archive newArchive1 = createArchive(1, "good", "book", 2019);
	Archive newArchive2 = createArchive(2, "goodish", "books", 2020);
	Archive newArchive3 = createArchive(3, "goodish", "books", 2021);
	Archive newArchive4 = createArchive(4, "goodish", "book", 2022);
	Archive newArchive5 = createArchive(5, "goodish", "bo", 2025);

	addToRepository(newController->archiveRepository, newArchive1);
	addToRepository(newController->archiveRepository, newArchive2);
	addToRepository(newController->archiveRepository, newArchive3);
	addToRepository(newController->archiveRepository, newArchive4);
	addToRepository(newController->archiveRepository, newArchive5);

	filteredData = filterEntriesByYear(newController, 2022);
	assert(getNumberOfObjects(&filteredData) == 3);

	controllerDestructor(newController);
	containerDestructor(&filteredData);
}

void UndoAdd_AddExists_UndoesAdd() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	undoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 0);

	controllerDestructor(newController);
}

void UndoAdd_AddNotExisting_ReturnsError() {
	Controller* newController = createController();

	undoLastOperation(newController);
	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 0);

	controllerDestructor(newController);
}

void UndoDelete_DeleteExists_UndoesDelete() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	deleteArchive(newController, 1);
	undoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 1);

	controllerDestructor(newController);
}

void UndoDelete_DeleteNotExisting_ReturnsError() {
	;
}

void UndoUpdate_UpdateExists_UndoesUpdate() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	updateArchive(newController, 1, "ok", "book", 2011);
	undoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 1);
	Archive archiveFromRepository = getArchiveAtIndex(getPointerToData(newController->archiveRepository), 0);
	assert(archiveFromRepository.catalogueNumber == 1);
	assert(strcmp(archiveFromRepository.stateOfDeterioration, "good") == 0);
	assert(strcmp(archiveFromRepository.fileType, "book") == 0);
	assert(archiveFromRepository.yearOfCreation == 2000);

	controllerDestructor(newController);
}

void UndoUpdate_UpdateNotExisting_ReturnsError() {
	;
}

void RedoAdd_AddUndone_RedoesAdd() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	undoLastOperation(newController);
	redoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 1);

	controllerDestructor(newController);
}

void RedoAdd_AddNotUndone_ReturnsError() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	redoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 1);

	controllerDestructor(newController);
}

void RedoDelete_DeleteUndone_RedoesDelete() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	deleteArchive(newController, 1);
	undoLastOperation(newController);
	redoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 0);

	controllerDestructor(newController);
}

void RedoDelete_DeleteNotUndone_ReturnsError() {
	;
}

void RedoUpdate_UpdateUndone_RedoesUpdate() {
	Controller* newController = createController();

	addArchive(newController, 1, "good", "book", 2000);
	updateArchive(newController, 1, "ok", "book", 2011);
	undoLastOperation(newController);
	redoLastOperation(newController);

	assert(getNumberOfObjects(getPointerToData(newController->archiveRepository)) == 1);

	Archive archiveFromRepository = getArchiveAtIndex(getPointerToData(newController->archiveRepository), 0);
	assert(archiveFromRepository.catalogueNumber == 1);
	assert(strcmp(archiveFromRepository.stateOfDeterioration, "ok") == 0);
	assert(strcmp(archiveFromRepository.fileType, "book") == 0);
	assert(archiveFromRepository.yearOfCreation == 2011);

	controllerDestructor(newController);
}

void RedoUpdate_UpdateNotUndone_ReturnsError() {
	;
}

void performTests() {
	CreateArchive_ValidInput_ArchiveCreated();
	CreateArchive_InvalidInput_ReturnsError();
	CreateRepository_ValidInput_RepositoryCreated();
	CreateRepository_InvalidInput_ReturnsError();
	AddArchive_ValidInput_AddedToRepository();
	AddArchive_DuplicateCatalogueNumber_ReturnsError();
	DeleteArchive_ValidInput_DeletedFromRepository();
	DeleteArchive_InexistentCatalogueNumber_ReturnsError();
	UpdateArchive_ValidInput_SuccessfulUpdate();
	UpdateArchive_InexistentArchive_ReturnsError();
	GetAllArchives_EmptyRepository_NoOutput();
	GetAllArchives_NonEmptyRepository_CorrectOutput();
	FilterEntriesByType_EmptyRepository_NoOutput();
	FilterEntriesByType_NothingThroughFilter_NoOutput();
	FilterEntriesByType_PassingThroughFilter_CorrectOutput();
	FilterEntriesByYear_EmptyRepository_NoOutput();
	FilterEntriesByYear_NothingThroughFilter_NoOutput();
	FilterEntriesByYear_PassingThroughFilter_CorrectOutput();
	UndoAdd_AddExists_UndoesAdd();
	UndoAdd_AddNotExisting_ReturnsError();
	UndoDelete_DeleteExists_UndoesDelete();
	UndoDelete_DeleteNotExisting_ReturnsError();
	UndoUpdate_UpdateExists_UndoesUpdate();
	UndoUpdate_UpdateNotExisting_ReturnsError();
	RedoAdd_AddUndone_RedoesAdd();
	RedoAdd_AddNotUndone_ReturnsError();
	RedoDelete_DeleteUndone_RedoesDelete();
	RedoDelete_DeleteNotUndone_ReturnsError();
	RedoUpdate_UpdateUndone_RedoesUpdate();
	RedoUpdate_UpdateNotUndone_ReturnsError();
	// something for when we add a new operation after doing some undo/ redo (the resetting of the repo list)
}