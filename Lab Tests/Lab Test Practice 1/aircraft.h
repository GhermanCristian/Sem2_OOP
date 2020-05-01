#pragma once
#include <string>

class Aircraft{
	protected:
		int uniqueID;
		int maximumAltitude; // in kilometers
		std::string model;
		bool suitableForPublicTransportation;
		bool suitableForMedicalEmergencies;
		bool suitableForLeisureTime;
		bool suitableForMilitary;
		const std::string PUBLIC_TRANSPORTATION_ACTIVITY = "public";
		const std::string MEDICAL_EMERGENCY_ACTIVITY = "medical";
		const std::string LEISURE_TIME_ACTIVITY = "leisure";
		const std::string MILITARY_ACTIVITY = "military";

	public:
		int getMaximumAltitude();
		bool canPerformActivity(std::string activity);
		virtual std::string getAircraftRepresentation() = 0;
};

