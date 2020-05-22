#include "controller.h"

Controller::Controller(){
	;
}

std::vector <Bill> Controller::getAllEntities() {
	return this->elements.getAllEntries();
}

void Controller::setRepositoryLocation(std::string filePath){
	this->elements.loadFromFile(filePath);
}

double Controller::getUnpaidBillsCostForCompany(std::string companyName){
	double unpaidBillsCost = 0;
	std::vector<Bill> allBills = this->elements.getAllEntries();

	for (auto bill : allBills) {
		if (bill.getCompanyName() == companyName && bill.checkIfPaid() == false) {
			unpaidBillsCost += bill.getSum();
		}
	}

	return unpaidBillsCost;
}

Controller::~Controller(){
	;
}
