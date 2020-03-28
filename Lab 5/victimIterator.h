#pragma once

class VictimIterator {
	private:
		int currentPosition;
		int numberOfElements;

	public:
		VictimIterator();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void setNumberOfElements(int numberOfElements);
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		bool isPositionValid();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		void setNextPosition();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

		int getCurrentPosition();
		/*

			Input:
				-
			Output:
				-
			Throws:
				-
		*/

};