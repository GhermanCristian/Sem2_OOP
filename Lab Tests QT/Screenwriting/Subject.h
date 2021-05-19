#pragma once
#include "Observer.h"
#include <vector>

class Subject {
	private:
		std::vector<Observer*> observers;
	public:
		void addObserver(Observer* newObserver);
		void removeObserver(Observer* removedObserver);
		void notify();
		virtual ~Subject();
};

