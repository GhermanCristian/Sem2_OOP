#include "Subject.h"

void Subject::addObserver(Observer* newObserver) {
	this->observers.push_back(newObserver);
}

void Subject::removeObserver(Observer* removedObserver) {
	auto observerIterator = std::find(observers.begin(), observers.end(), removedObserver);
	if (observerIterator != observers.end())
		observers.erase(observerIterator);
}

void Subject::notify() {
	for (auto observer : this->observers) {
		observer->update();
	}
}

Subject::~Subject() {
	;
}