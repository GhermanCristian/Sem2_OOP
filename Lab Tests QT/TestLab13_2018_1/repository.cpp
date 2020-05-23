#include "repository.h"
#include <fstream>

Repository::Repository(){
	;
}

std::vector <ShoppingListItem> Repository::getAllEntries(){
	return this->shoppingList;
}

void Repository::loadFromFile(std::string filePath){
	const int CATEGORY_POSITION = 0;
	const int NAME_POSITION = 1;

	std::fstream inputStream(filePath);
	std::string currentLine;

	std::string category;
	std::string name;
	int quantity;

	this->shoppingList.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == CATEGORY_POSITION) {
				category = currentProperty;
			}
			else if (propertyPosition == NAME_POSITION) {
				name = currentProperty;
			}

			propertyPosition++;
		}

		quantity = stoi(currentLine);

		this->shoppingList.push_back(ShoppingListItem(category, name, quantity));
	}

	inputStream.close();
}

void Repository::removeAtIndex(int index){
	if (index >= this->shoppingList.size() || index < 0) {
		throw std::exception("Invalid index");
	}

	this->shoppingList.erase(this->shoppingList.begin() + index);
}

int Repository::getNumberOfItems(){
	return this->shoppingList.size();
}

Repository::~Repository(){
	;
}
