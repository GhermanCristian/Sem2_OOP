#include "testVictim.h"

void TestVictim::runAllTests(){
	VictimConstructor_CorrectInput_CorrectName();
	VictimConstructor_CorrectInput_CorrectPlaceOfOrigin();
	VictimConstructor_CorrectInput_CorrectAge();
	VictimConstructor_CorrectInput_CorrectPhotograph();
}

void TestVictim::VictimConstructor_CorrectInput_CorrectName() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getName() == "vasile");
}

void TestVictim::VictimConstructor_CorrectInput_CorrectPlaceOfOrigin() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getPlaceOfOrigin() == "place");
}

void TestVictim::VictimConstructor_CorrectInput_CorrectAge() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getAge() == 123);
}

void TestVictim::VictimConstructor_CorrectInput_CorrectPhotograph() {
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	assert(newVictim.getPhotographLink() == "photo.jpg");
}