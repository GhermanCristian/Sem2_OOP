#pragma once
#include "controller.h"

class UserInterface{
	private:
		Controller actionController;

		void addBMIAnalysisInterface(std::string analysisDate);
		void addBPAnalysisInterface(std::string analysisDate);
		void addAnalysisInterface();
		void getAllAnalysesInterface();
		void isPersonIllInterface();
		void writeToFileTheAnalysesBetweenDatesInterface();

	public:
		UserInterface();
		void startProgram();
		~UserInterface();
};

