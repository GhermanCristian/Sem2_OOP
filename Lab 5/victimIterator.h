#pragma once

class VictimIterator {
	private:
		int currentPosition;
		int numberOfElements;

	public:
		VictimIterator();
		void setNumberOfElements(int numberOfElements);
		bool isPositionValid();
		void setNextPosition();
		int getCurrentPosition();
};