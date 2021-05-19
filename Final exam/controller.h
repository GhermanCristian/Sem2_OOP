#pragma once
#include "repository.h"

class Controller{
	private:
		Repository repository;

	public:
		Controller();
		std::vector<Star> getAllStars();
		std::vector<Star> getAllStarsByName(std::string name);
		std::vector<Star> getAllStarsByConstellation(std::string constellation);
		std::vector<Astronomer> getAllAstronomers();
		void loadStarsFromFile();
		void loadAstronomersFromFile();
		void addStar(std::string name, std::string constellation, int RA, int dec, int diameter);
		void saveStarsToFile();
		~Controller();
};

