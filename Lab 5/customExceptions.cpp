#include "customExceptions.h"

CustomException::CustomException(std::string exceptionMessage){
	this->message = exceptionMessage;
}

const char* CustomException::what() const noexcept{
	return this->message.c_str();
}

RepositoryException::RepositoryException(std::string exceptionMessage) : CustomException(exceptionMessage){
	;
}

ValidationException::ValidationException(std::string exceptionMessage) : CustomException(exceptionMessage) {
	;
}
