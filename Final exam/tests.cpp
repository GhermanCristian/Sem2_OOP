#include "tests.h"
#include "controller.h"
#include <assert.h>

void AddStar_NoName_ThrowsException(){
	Repository newRepository;
	try {
		newRepository.addStar(Star()); // the default constructor => name is empty
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddStar_InvalidDiameter_ThrowsException(){
	Repository newRepository;
	try {
		newRepository.addStar(Star()); // the default constructor => diameter = 0 <= 0
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddStar_NameAlreadyExists_ThrowsException(){
	Repository newRepository;
	newRepository.addStar(Star("name", "const", 1, 2, 3));
	try {
		newRepository.addStar(Star("name", "const", 1, 2, 3));
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void AddStar_ValidStar_StarAdded(){
	Repository newRepository;
	newRepository.addStar(Star("name", "const", 1, 2, 3));
	assert(newRepository.getAllStars().size() == 1);
	assert(newRepository.getAllStars()[0].getName() == "name");
	assert(newRepository.getAllStars()[0].getConstellation() == "const");
	assert(newRepository.getAllStars()[0].getRA() == 1);
	assert(newRepository.getAllStars()[0].getDec() == 2);
	assert(newRepository.getAllStars()[0].getDiameter() == 3);
}
