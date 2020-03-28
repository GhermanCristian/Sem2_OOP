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
	while (!isPositionValid()) {
		if (currentPosition >= numberOfElements) {
			currentPosition = 0;
			break;
		}
		currentPosition++;
	}
}

int VictimIterator::getCurrentPosition(){
	return this->currentPosition;
}
