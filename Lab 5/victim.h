#pragma once
#include <string>

class Victim {
	private:
		std::string name;
		std::string placeOfOrigin;
		int age;
		std::string photographLink;

public:
	Victim();
	Victim(std::string name, std::string placeOfOrigin, int age, std::string photographLink);
	std::string getName();
	std::string getPlaceOfOrigin();
	int getAge();
	std::string getPhotographLink();
	Victim(const Victim& newVictim);
	Victim& operator = (const Victim& newVictim);
	~Victim();
};