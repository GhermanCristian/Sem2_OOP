#pragma once
#include <string>

class Victim {
	private:
		std::string name;
		std::string placeOfOrigin;
		int age;
		std::string photographLink;

	public:
		Victim();
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		Victim(std::string name, std::string placeOfOrigin, int age, std::string photographLink);
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		std::string getName() const;
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		std::string getPlaceOfOrigin() const;
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		int getAge() const;
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		std::string getPhotographLink() const;
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		Victim(const Victim& newVictim);
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		bool operator == (const Victim& newVictim);
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		Victim& operator = (const Victim& newVictim);
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

		~Victim();
		/*

				Input:
					-
				Output:
					-
				Throws:
					-
		*/

};