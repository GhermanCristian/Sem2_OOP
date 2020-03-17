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
	;
}

void AddArchive_DuplicateCatalogueNumber_ReturnsError() {
	;
}

void DeleteArchive_ValidInput_DeletedFromRepository() {
	;
}

void DeleteArchive_InexistentCatalogueNumber_ReturnsError() {
	;
}

void UpdateArchive_ValidInput_SuccessfulUpdate() {
	;
}

void UpdateArchive_InexistentInput_ReturnsError() {
	;
}

void ListAllArchives_EmptyRepository_NoOutput() {
	;
}

void ListAllArchives_NonEmptyRepository_CorrectOutput() {
	;
}

void FilterEntriesByType_EmptyRepository_NoOutput() {
	;
}

void FilterEntriesByType_NothingThroughFilter_NoOutput() {
	;
}

void FilterEntriesByType_PassingThroughFilter_CorrectOutput() {
	;
}

void FilterEntriesByYear_EmptyRepository_NoOutput() {
	;
}

void FilterEntriesByYear_NothingThroughFilter_NoOutput() {
	;
}

void FilterEntriesByYear_PassingThroughFilter_CorrectOutput() {
	;
}

void UndoAdd_AddExists_UndoesAdd() {
	;
}

void UndoAdd_AddNotExisting_ReturnsError() {
	;
}

void UndoDelete_DeleteExists_UndoesDelete() {
	;
}

void UndoDelete_DeleteNotExisting_ReturnsError() {
	;
}

void UndoUpdate_UpdateExists_UndoesUpdate() {
	;
}

void UndoUpdate_UpdateNotExisting_ReturnsError() {
	;
}

void RedoAdd_AddUndone_RedoesAdd() {
	;
}

void RedoAdd_AddNotUndone_ReturnsError() {
	;
}

void RedoDelete_DeleteUndone_RedoesDelete() {
	;
}

void RedoDelete_DeleteNotUndone_ReturnsError() {
	;
}

void RedoUpdate_UpdateUndone_RedoesUpdate() {
	;
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
	UpdateArchive_InexistentInput_ReturnsError();
	ListAllArchives_EmptyRepository_NoOutput();
	ListAllArchives_NonEmptyRepository_CorrectOutput();
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