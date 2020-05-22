#include "domain.h"

Bill::Bill(std::string companyName, std::string code, double sum, bool isPaid){
	this->companyName = companyName;
	this->code = code;
	this->sum = sum;
	this->isPaid = isPaid;
}

std::string Bill::toString(){
	std::string stringRepresentation = "";
	stringRepresentation += (this->companyName + "; ");
	//stringRepresentation += (this->code + "; ");
	stringRepresentation += (std::to_string(this->sum) + "; ");
	//stringRepresentation += (std::to_string(this->isPaid));
	return stringRepresentation;
}

std::string Bill::getCompanyName() const{
	return this->companyName;
}

double Bill::getSum() const{
	return this->sum;
}

bool Bill::checkIfPaid() const{
	return this->isPaid;
}
