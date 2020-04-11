#include "fileRepository.h"

FileRepository::FileRepository(){
	this->filePath = "";
	this->createdTemporaryFile = true;
}

FileRepository::FileRepository(std::string filePath){
	this->filePath = filePath;
	this->createdTemporaryFile = false;
}

FileRepository::~FileRepository(){
	;
}
