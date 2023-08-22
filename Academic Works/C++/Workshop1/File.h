/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 17 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef NAMESPACE_FILE_H // replace with relevant names
#define NAMESPACE_FILE_H

// Your header file content goes here
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "ShoppingRec.h"



namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

}
#endif
