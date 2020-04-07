#include "testVector.h"

void DynamicVectorConstructor_NoInput_CorrectCapacity() {
	DynamicVector<TElem> newVector;
	assert(newVector.getCapacity() == INITIAL_VECTOR_CAPACITY);
}

void DynamicVectorConstructor_NoInput_CorrectNumberOfElements() {
	DynamicVector<TElem> newVector;
	assert(newVector.getNumberOfElements() == 0);
}

void AddToVector_EmptyVectorOneInput_ElementAdded() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.insert(newVictim, 0);
	assert(newVector[0] == newVictim && newVector.getNumberOfElements() == 1);
}

void UpdateInVector_CorrectInput_ElementUpdated() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile", "newplace", 1233, "newphoto.jpg" };

	newVector.insert(newVictim, 0);
	newVector.update(newVictim1, 0);
	assert(newVector[0] == newVictim1 && newVector.getNumberOfElements() == 1);
}

void DeleteFromVector_OneElementCorrectInput_ElementDeleted() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	newVector.insert(newVictim, 0);
	newVector.deleteFromVector(0);
	assert(newVector.getNumberOfElements() == 0);
}

void DeleteFromVector_MultipleElementsCorrectInput_ElementDeleted() {
	DynamicVector<TElem> newVector;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };
	Victim newVictim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim newVictim2{ "vasile2", "place", 123, "photo.jpg" };

	newVector.insert(newVictim, 0);
	newVector.insert(newVictim1, 1);
	newVector.insert(newVictim2, 1);
	newVector.deleteFromVector(1);
	assert(newVector.getNumberOfElements() == 2);
}

void VectorResize_MultipleInputs_SuccessfulResize() {
	DynamicVector<TElem> newVector;

	for (char letter = 'a'; letter <= 'z'; letter++) {
		std::string word;
		word += letter;
		Victim newVictim{ word, word, 123, word };
		newVector.insert(newVictim, letter - 'a');
	}

	assert(newVector.getNumberOfElements() == 26 && newVector.getCapacity() == INITIAL_VECTOR_CAPACITY * MULTIPLICATION_FACTOR);
}

void DynamicVectorEqualityOperator_EqualVectors_CorrectResult() {
	DynamicVector<TElem> newVector1;
	DynamicVector<TElem> newVector2;
	Victim victim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim victim2{ "vasile2", "place", 123, "photo.jpg" };

	newVector1.insert(victim1, 0);
	newVector1.insert(victim2, 1);
	newVector2.insert(victim1, 0);
	newVector2.insert(victim2, 1);

	assert(newVector1 == newVector2);
}

void DynamicVectorEqualityOperator_DifferentNumberOfElements_CorrectResult() {
	DynamicVector<TElem> newVector1;
	DynamicVector<TElem> newVector2;
	Victim victim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim victim2{ "vasile2", "place", 123, "photo.jpg" };
	Victim victim3{ "vasile3", "place", 123, "photo.jpg" };
	Victim victim4{ "vasile4", "place", 123, "photo.jpg" };

	newVector1.insert(victim1, 0);
	newVector1.insert(victim3, 1);
	newVector2.insert(victim2, 0);
	newVector2.insert(victim3, 1);
	newVector2.insert(victim4, 2);

	assert((newVector1 == newVector2) == false);
}

void DynamicVectorEqualityOperator_SameNumberOfElements_CorrectResult() {
	DynamicVector<TElem> newVector1;
	DynamicVector<TElem> newVector2;
	Victim victim1{ "vasile1", "place", 123, "photo.jpg" };
	Victim victim2{ "vasile2", "place", 123, "photo.jpg" };
	Victim victim3{ "vasile3", "place", 123, "photo.jpg" };

	newVector1.insert(victim1, 0);
	newVector1.insert(victim3, 1);
	newVector2.insert(victim1, 0);
	newVector2.insert(victim2, 1);

	assert((newVector1 == newVector2) == false);
}

void DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector2.insert(newVictim, 0);
	vector1 = vector2;

	assert(vector1 == vector2);
}

void DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.insert(newVictim, 0);
	vector1 = vector2;

	assert(vector1.getNumberOfElements() == 0);
}

void DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	Victim newVictim{ "vasile", "place", 123, "photo.jpg" };

	vector1.insert(newVictim, 0);

	DynamicVector<TElem> vector2(vector1);
	assert(vector2 == vector1);
}

void DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy() {
	DynamicVector<TElem> vector1;
	DynamicVector<TElem> vector2(vector1);

	assert(vector2.getNumberOfElements() == 0);
}

void testVector() {
	DynamicVectorConstructor_NoInput_CorrectCapacity();
	DynamicVectorConstructor_NoInput_CorrectNumberOfElements();
	AddToVector_EmptyVectorOneInput_ElementAdded();
	UpdateInVector_CorrectInput_ElementUpdated();
	DeleteFromVector_OneElementCorrectInput_ElementDeleted();
	DeleteFromVector_MultipleElementsCorrectInput_ElementDeleted();
	VectorResize_MultipleInputs_SuccessfulResize();
	DynamicVectorEqualityOperator_EqualVectors_CorrectResult();
	DynamicVectorEqualityOperator_DifferentNumberOfElements_CorrectResult();
	DynamicVectorEqualityOperator_SameNumberOfElements_CorrectResult();
	DynamicVectorAssignmentOperator_NonEmptySourceVector_CorrectCopy();
	DynamicVectorAssignmentOperator_EmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_NonEmptySourceVector_CorrectCopy();
	DynamicVectorCopyConstructor_EmptySourceVector_CorrectCopy();
}