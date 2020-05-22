#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		std::vector<Bill> getAllEntities();
		void setRepositoryLocation(std::string filePath);
		double getUnpaidBillsCostForCompany(std::string companyName);
		/*
			For a given company, computes the total sum of money which is owed
			Input:
				- The name of the company
			Output:
				- Returns the owed value
		*/
		~Controller();
};

