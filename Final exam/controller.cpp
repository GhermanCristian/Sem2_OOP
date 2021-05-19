#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller(){
	;
}

std::vector <Star> Controller::getAllStars() {
	return this->repository.getAllStars();
}

std::vector<Star> Controller::getAllStarsByName(std::string name){
	std::vector<Star> allStars = this->repository.getAllStars();
	std::vector<Star> filteredStars;
	for (auto star : allStars) {
		if (star.getName().find(name) != std::string::npos) { // partial string matching
			filteredStars.push_back(star);
		}
	}
	return filteredStars;
}

std::vector<Star> Controller::getAllStarsByConstellation(std::string constellation){
	std::vector<Star> allStars = this->repository.getAllStars();
	std::vector<Star> filteredStars;
	for (auto star : allStars) {
		if (star.getConstellation() == constellation) {
			filteredStars.push_back(star);
		}
	}
	return filteredStars;
}

std::vector <Astronomer> Controller::getAllAstronomers() {
	return this->repository.getAllAstronomers();
}

void Controller::loadStarsFromFile(){
	this->repository.loadStarsFromFile();
}

void Controller::loadAstronomersFromFile() {
	this->repository.loadAstronomersFromFile();
}

void Controller::addStar(std::string name, std::string constellation, int RA, int dec, int diameter){
	this->repository.addStar(Star(name, constellation, RA, dec, diameter));
}

void Controller::saveStarsToFile(){
	std::ofstream outputStream(STARS_FILE_PATH);
	
	std::vector<Star> allStars = this->repository.getAllStars();
	std::sort(allStars.begin(), allStars.end(), [this](const Star& a, const Star& b) {return a.getConstellation() > b.getConstellation(); });
	for (auto star : allStars) {
		outputStream << star.toString() << "\n";
	}

	outputStream.close();
}

Controller::~Controller(){
	this->saveStarsToFile();
}
