#include "archive.h"
#include <string.h>
#include <stdlib.h>

Archive createArchive(int catalogueNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation){
	Archive newArchive;

	newArchive.catalogueNumber = catalogueNumber;
	strcpy(newArchive.stateOfDeterioration, stateOfDeterioration);
	strcpy(newArchive.fileType, fileType);
	newArchive.yearOfCreation = yearOfCreation;

	return newArchive;
}