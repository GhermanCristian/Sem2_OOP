#include "controller.h"

Controller::Controller(){
	this->loadFromFile("data.txt");
}

std::vector <ShoppingListItem> Controller::getAllEntities() {
	return this->elements.getAllEntries();
}

std::vector<ShoppingListItem> Controller::filterByCategory(std::string category){
	std::vector<ShoppingListItem> allItems = this->elements.getAllEntries();
	std::vector<ShoppingListItem> filteredItems;

	for (auto currentItem : allItems) {
		if (currentItem.getCategory() == category) {
			filteredItems.push_back(currentItem);
		}
	}

	return filteredItems;
}

void Controller::loadFromFile(std::string filePath){
	this->elements.loadFromFile(filePath);
}

void Controller::deleteItemByIndex(int index){
	this->elements.removeAtIndex(index);
}

Controller::~Controller(){
	;
}
