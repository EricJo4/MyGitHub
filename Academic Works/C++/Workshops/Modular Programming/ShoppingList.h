/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 17 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef NAMESPACE_SHOPPINGLIST_H // replace with relevant names
#define NAMESPACE_SHOPPINGLIST_H

// Your header file content goes here
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ShoppingRec.h"

namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

	const int MAX_NO_OF_RECS = 15;

	
}
#endif
