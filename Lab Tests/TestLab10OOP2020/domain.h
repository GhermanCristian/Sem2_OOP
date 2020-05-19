#pragma once
#include <string>

class HospitalDepartament{
	protected:
		std::string hospitalName;
		int numberOfDoctors;

	public:
		virtual bool isEfficient() = 0;
		virtual std::string toString() = 0;
};

class NeonatalUnit : public HospitalDepartament {
	private:
		int numberOfMothers;
		int numberOfNewborns;
	public:
		NeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade);
		double averageGrade;
		bool isEfficient();
		std::string toString();
};

class Surgery : public HospitalDepartament {
	private:
		int numberOfPatients;

	public:
		Surgery(std::string hospitalName, int numberOfDoctors, int numberOfPatients);
		bool isEfficient();
		std::string toString();
};