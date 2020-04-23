#pragma once
#include <exception>
#include <string>

class CustomException : public std::exception {
	protected:
		std::string message;

	public:
		CustomException(std::string exceptionMessage);
		const char* what() const noexcept override;
};

class RepositoryException : public CustomException {
	public:
		RepositoryException(std::string exceptionMessage);
};

class ValidationException : public CustomException {
	public:
		ValidationException(std::string exceptionMessage);
};
