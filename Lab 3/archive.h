#pragma once
#define MAX_LENGTH_STATE_OF_DETERIORATION 50
#define MAX_LENGTH_FILE_TYPE 20

typedef struct{
	int catalogueNumber;
	char stateOfDeterioration[MAX_LENGTH_STATE_OF_DETERIORATION];
	char fileType[MAX_LENGTH_FILE_TYPE];
	int yearOfCreation;
}Archive;

Archive *createArchive(int catalogueNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation);
/*
	Creates a new Archive with the given parameters
	Input:
		- catalogueNumber = integer
		- stateOfDeterioration = array of characters
		- fileType = array of characters
		- yearOfCreation = integer
	Output:
		- A pointer to an "object" of type Archive
*/