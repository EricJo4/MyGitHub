/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <iostream>
#include "Cheese.h"

namespace sdds {
	class CheeseShop {
		std::string m_name;
		const Cheese** m_cheeses{ nullptr };
		size_t m_count;

	public:
		CheeseShop(const std::string& name):m_name(name), m_cheeses(nullptr), m_count(0) {}

		//Rule of 5
		CheeseShop(const CheeseShop&);
		CheeseShop& operator=(const CheeseShop&);
		~CheeseShop();
		CheeseShop(CheeseShop&&);
		CheeseShop& operator=(CheeseShop&&);
		
		//a modifier that adds a cheese object to the array of pointers.
		CheeseShop& addCheese(const Cheese&);

		std::ostream& display(std::ostream&) const;

		//an operator to check if the current object is empty.
		bool operator!() const {
			return m_cheeses == nullptr;
		}
		
	};

	std::ostream& operator<<(std::ostream&, const CheeseShop&);
}


#endif //SDDS_CHEESESHOP_H