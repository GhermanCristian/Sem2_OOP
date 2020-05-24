#pragma once
#include <string>

class Task{
	private:
		std::string description;
		int duration;
		int priority;

	public:
		Task(std::string description, int duration, int priority);
		int getPriority() const ;
		int getDuration() const ;
		std::string toString();
};