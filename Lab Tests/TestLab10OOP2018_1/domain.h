#pragma once
#include <string>

class MedicalAnalysis{
	protected:
		std::string analysisDate;

	public:
		virtual std::string toString() = 0;
		virtual bool isResultOK() = 0;
		bool sameMonth(std::string analysisMonth);
		std::string getDate();
};

class BMIAnalysis : public MedicalAnalysis {
	private:
		double value;

	public:
		BMIAnalysis(std::string analysisDate, double value);
		bool isResultOK();
		std::string toString();
};

class BPAnalysis : public MedicalAnalysis {
	private:
		int systolicValue;
		int diastolicValue;

	public:
		BPAnalysis(std::string analysisDate, int systolicValue, int diastolicValue);
		bool isResultOK();
		std::string toString();
};