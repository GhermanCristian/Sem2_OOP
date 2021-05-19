#pragma once
#include <string>

class Astronomer{
	private:
		std::string name;
		std::string constellation;

	public:
		Astronomer();
		Astronomer(std::string name, std::string constellation);
		std::string toString();
		std::string getName() const;
		std::string getConstellation() const;
};

class Star{
	private:
		std::string name;
		std::string constellation;
		int RA;
		int Dec;
		int diameter;

	public:
		Star();
		Star(std::string name, std::string constellation, int RA, int Dec, int diameter);
		std::string toString();
		std::string getName() const;
		std::string getConstellation() const;
		int getRA() const;
		int getDec() const;
		int getDiameter() const;
};