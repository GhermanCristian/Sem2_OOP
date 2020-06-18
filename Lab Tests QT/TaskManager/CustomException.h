#pragma once
#include <string>
#include <exception>

class CustomException : public std::exception {
	protected:
		std::string message;

	public:
		CustomException(std::string exceptionMessage);
		const char* what() const noexcept override;
};

class UnopenedTask : public CustomException {
	public:
		UnopenedTask(std::string exceptionMessage);
};

