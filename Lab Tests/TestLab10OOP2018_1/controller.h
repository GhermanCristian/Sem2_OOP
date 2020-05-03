#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

		std::vector<MedicalAnalysis*> getAnalysesBetweenTwoDates(std::string firstDate, std::string secondDate);
		std::vector<MedicalAnalysis*> getAnalysesFromMonth(std::string analysisMonth);

	public:
		Controller();
		void addBMIAnalysis(std::string analysisDate, double BMIValue);
		void addBPAnalysis(std::string analysisDate, int systolicValue, int diastolicValue);
		std::vector<MedicalAnalysis*> getAllAnalysis();
		void writeAnalysesToFile(std::string fileName, std::string firstDate, std::string secondDate);
		bool isPersonIll(std::string analysisMonth);
		~Controller();
};

