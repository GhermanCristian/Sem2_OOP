#pragma once
#include <string>

class ShoppingListItem{
	private:
		std::string category;
		std::string name;
		int quantity;

	public:
		ShoppingListItem(std::string category, std::string name, int quantity);
		std::string getCategory();
		std::string toString();
};