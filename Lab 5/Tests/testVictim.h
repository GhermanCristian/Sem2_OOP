#pragma once
#include <assert.h>
#include "../victim.h"

class TestVictim {
	private:
		void VictimConstructor_CorrectInput_CorrectName();
		void VictimConstructor_CorrectInput_CorrectPlaceOfOrigin();
		void VictimConstructor_CorrectInput_CorrectAge();
		void VictimConstructor_CorrectInput_CorrectPhotograph();

	public:
		void runAllTests();
};