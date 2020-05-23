#pragma once
#include "repository.h"

class Controller{
	private:
		Repository elements;

	public:
		Controller();
		std::vector<ShoppingListItem> getAllEntities();
		std::vector<ShoppingListItem> filterByCategory(std::string category);
		void loadFromFile(std::string filePath);
		void deleteItemByIndex(int index);
		/*
			Deletes an element from the repository, by the its index
			Input:
				- The index of the element
			Output:
				- The element is removed, if the index is valid
				- Throws an exception, otherwise
		*/
		~Controller();
};

