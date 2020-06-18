#include "CustomException.h"

UnopenedTask::UnopenedTask(std::string exceptionMessage) : CustomException(exceptionMessage){
	;
}

CustomException::CustomException(std::string exceptionMessage) {
	this->message = exceptionMessage;
}

const char* CustomException::what() const noexcept {
	return this->message.c_str();
}
