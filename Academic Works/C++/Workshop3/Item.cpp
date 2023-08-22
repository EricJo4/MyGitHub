/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	/*This function sets the itemName member Cstring variable to
	a the Cstring in the name argument up to 20 characters.*/
	void Item:: setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	/*Sets the Item to a recognizable safe Empty State.Do this 
	by setting the price to an impossible value like 0.0 and 
	setting the m_itemName to a blank string(first character set to null).*/
	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
	}
	
	/*Sets the m_itemName attribute to the Cstring pointed by the name argument
	using the setName methodand sets the m_priceand m_taxed attributes to the 
	corresponding arguments. If price is less than 0 or name is null, then the 
	Item is set to a recognizable invalid empty state(safe empty state).*/
	void Item::set(const char* name, double price, bool taxed) {
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	/*Returns the m_price attribute*/
	double Item::price()const {
		return m_price;
	}

	/*Returns the product of m_price and 0.13(define a constant double value for this tax rate).
	Or it returns 0.0 if the m_taxed is false.*/
	double Item::tax()const {
		if (m_taxed) {
			return m_price * 0.13;
		}
		else {
			return 0.0;
		}
	}

	/*Returns true if the Item is not set to the empty state (As done in setEmpty function) .
    This function can not modify its owner.*/
	bool Item::isValid()const {
		return (m_itemName[0] != '\0');
	}

	/*Prints an item in the following format.*/
	void Item::display()const {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout << " | ";
			cout << (m_taxed ? "Yes" : "No ");
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	
	

	

}