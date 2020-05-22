#pragma once
#include <string>

class Bill{
	private:
		std::string companyName;
		std::string code;
		double sum;
		bool isPaid;

	public:
		Bill(std::string companyName, std::string code, double sum, bool isPaid);
		std::string toString();
		std::string getCompanyName() const;
		double getSum() const;
		bool checkIfPaid() const;
};