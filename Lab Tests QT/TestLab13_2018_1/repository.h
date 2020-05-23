#pragma once
#include <vector>
#include "domain.h"

class Repository{
	private:
		std::vector <ShoppingListItem> shoppingList;

	public:
		Repository();
		std::vector <ShoppingListItem> getAllEntries();
		void loadFromFile(std::string filePath);
		void removeAtIndex(int index);
		/*
			Removes the item which is at a given index in the vector
			Input:
				- The index of the item
			Output:
				- The item is removed from the vector, if the index is valid
				- Throws an exception, otherwise
		*/
		int getNumberOfItems();
		~Repository();
};

