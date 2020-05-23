#include "domain.h"

ShoppingListItem::ShoppingListItem(std::string category, std::string name, int quantity){
	this->category = category;
	this->name = name;
	this->quantity = quantity;
}

std::string ShoppingListItem::getCategory(){
	return this->category;
}

std::string ShoppingListItem::toString(){
	std::string representation;

	representation += (this->category + " | ");
	representation += (this->name + " | ");
	representation += (std::to_string(this->quantity));

	return representation;
}
