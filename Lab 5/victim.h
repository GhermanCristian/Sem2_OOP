#pragma once
#include <string>
#include <iostream>

class Victim {
	private:
		std::string name;
		std::string placeOfOrigin;
		int age;
		std::string photographLink;

	public:
		Victim();
		/*
			Default constructor for the Victim type
			Input:
				- None
			Output:
				- Creates a new, empty object of type Victim 
			Throws:
				- None
		*/

		Victim(std::string name, std::string placeOfOrigin, int age, std::string photographLink);
		/*
			Overloaded constructor for the Victim type
			Input:
				- The Victim's properties
			Output:
				- Creates a new object of type Victim
			Throws:
				- None
		*/

		std::string getName() const;
		/*
			Determines the name of the current Victim
			Input:
				- None
			Output:
				- The name of the current Victim
			Throws:
				- None
		*/

		std::string getPlaceOfOrigin() const;
		/*
			Determines the place of origin of the current victim
			Input:
				- None
			Output:
				- The place of origin of the current victim
			Throws:
				- None
		*/

		int getAge() const;
		/*
			Determines the age of the current victim
			Input:
				- None
			Output:
				- The age of the current victim
			Throws:
				- None
		*/

		std::string getPhotographLink() const;
		/*
			Determines the photograph link of the current victim
			Input:
				- None
			Output:
				- The photograph link of the current victim
			Throws:
				- None
		*/

		Victim(const Victim& originalVictim);
		/*
			Copy constructor for the Victim type
			Input:
				- A reference to an object of type Victim, whose content is copied to the current one
			Output:
				- The content of originalVictim is copied to the current one
			Throws:
				- None
		*/

		bool operator == (const Victim& newVictim);
		/*
			Overloaded equality operator
			Input:
				- Reference to another Victim
			Output:
				- True, if the content of the 2 victims is the same
				- False, otherwise
			Throws: 
				- None
		*/

		Victim& operator = (const Victim& originalVictim);
		/*
			Overloaded assignment operator
			Input:
				- Reference to a victim whose content is copied to a new object
			Output:
				- A reference to a new object of type Victim, with the same content as the given one
			Throws:
				- None
		*/

		friend std::istream& operator >> (std::istream& inputStream, Victim& currentVictim); // victim cannot be const for some reason
		/*
			Overloaded insertion opeator
			Input:
				- A reference to the istream object we read from
				- The Victim whose properties we read
			Output:
				- The victim's properties are read
				- Returns the modified istream object
			Throws:
				- None
		*/
		
		friend std::ostream& operator << (std::ostream& outputStream, const Victim& currentVictim);
		/*
			Overloaded extraction opeator
			Input:
				- A reference to the ostream object we write to
				- The Victim whose properties we write
			Output:
				- The victim's properties are read
				- Returns the modified ostream object
			Throws:
				- None
		*/

		std::string getCSVRepresentation() const;
		std::string getHTMLRepresentation() const;

		~Victim();
		/*
			Victim destructor
			Input:
				- None
			Output:
				- Destroys the current Victim
			Throws:
				- None
		*/

};