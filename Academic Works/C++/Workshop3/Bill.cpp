/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
   
    /*Sets the Bill object to an empty state by setting 
    m_title to an Empty Cstring and m_items to nullptr*/
    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    /*Returns true if m_title is not empty and m_items is 
    not null and all the Items in the m_items array are valid.
    hint: First check and make sure m_title and m_items are valid. 
    Then loop through all the Items in the m_items array and make sure they are all valid.*/
    bool Bill::isValid()const {
        int i;
        if(m_title[0] == '\0' || m_items == nullptr) {
            return false;
        }
        for (i = 0; i < m_noOfItems; i++) {
            if (!m_items[i].Item::isValid())
                return false;
        }

        return true;
    }

    /*Adds all the taxes of the items using a loop and returns the sum.*/
    double Bill::totalTax()const {
        int i;
        double total = 0.0;
        for (i = 0; i < m_itemsAdded; i++) {
            total += m_items[i].tax();
        }
        return total;
    }

    /*Adds all the prices of the items using a loop and returns the sum*/
    double Bill::totalPrice()const {
        int i;
        double total = 0.0;
        for (i = 0; i < m_itemsAdded; i++) {
            total += m_items[i].price();
        }
        return total;
    }

    /*Prints the title in the following format:*/
    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    /*Prints the footer in the following format:*/
    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax(); 
            cout << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    /*If any of the arguments are invalid, it will set the Bill to an empty state 
    (ie. title is null or noOfItems is zero or less)*/
    void Bill::init(const char* title, int noOfItems) {
        int i;
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        strnCpy(m_title, title, 36);
        m_title[36] = '\0';
        m_noOfItems = noOfItems;
        m_itemsAdded = 0;
        m_items = new Item[m_noOfItems];
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].setEmpty();
        }
    }
    

    /*If the number of added Items (m_itemsAdded) is less than the length of the m_items array, 
    this function will set the next available subject to the incoming argument values. Then it 
    will add one to the m_itemsAdded and return true;
    Otherwise, this function will do nothing, returning false;*/
    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].Item::set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
            }
        return false;
    }

    /*This function will first print the title(), then it will loop through the m_items elements, 
    printing every one of them, and finally prints the footer(). This function can not modify the Bill.*/
    void Bill::display()const {
        int i;
        Title();
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].Item::display();
        }
        footer();
    }

    /*Deallocates the m_items arrays and sets the pointers to null.*/
    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }

}