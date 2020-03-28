#include "victimIterator.h"

VictimIterator::VictimIterator(){
	this->numberOfElements = 0;
	this->currentPosition = 0;
}

void VictimIterator::setNumberOfElements(int numberOfElements){
	this->numberOfElements = numberOfElements;
}

bool VictimIterator::isPositionValid(){
	return (0 <= currentPosition and currentPosition < numberOfElements);
}

void VictimIterator::setNextPosition(){
	currentPosition++;
	if (isPositionValid() == false) {
		currentPosition = 0;
	}
}

int VictimIterator::getCurrentPosition(){
	return this->currentPosition;
}
