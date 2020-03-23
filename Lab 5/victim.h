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
	std::string getName() const;
	std::string getPlaceOfOrigin() const;
	int getAge() const;
	std::string getPhotographLink() const;
	Victim(const Victim& newVictim);
	bool operator == (const Victim& newVictim);
	Victim& operator = (const Victim& newVictim);
	~Victim();
};