#include "tests.h"
#include "controller.h"
#include <assert.h>

void getUnpaidBillsCostForCompany_InexistentCompany_NoOutput() {
	Controller currentController;
	std::string companyName = "definitely doesn't exist";

	assert(currentController.getUnpaidBillsCostForCompany(companyName) == 0.0);
}

void getUnpaidBillsCostForCompany_ExistentCompany_CorrectOutput(){
	Controller currentController;
	std::string companyName = "company1";
	currentController.setRepositoryLocation("bills_test_1.txt");

	assert(currentController.getUnpaidBillsCostForCompany(companyName) == 100.2);
}
