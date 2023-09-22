/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 17 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef NAMESPACE_SHOPPINGREC_H // replace with relevant names
#define NAMESPACE_SHOPPINGREC_H

// Your header file content goes here
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

namespace sdds {
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif