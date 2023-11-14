/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include "Cheese.h"

namespace sdds {
	class CheeseParty {
		const Cheese** m_pCheeses{ nullptr };
		size_t m_pCount;
	public:
		CheeseParty() :m_pCheeses(nullptr), m_pCount(0) {}

		//Rule of 5
		CheeseParty(const CheeseParty&);
		CheeseParty& operator=(const CheeseParty&);
		~CheeseParty();
		CheeseParty(CheeseParty&&);
		CheeseParty& operator=(CheeseParty&&);

		//a modifier that adds a cheese object to the array of pointers.
		CheeseParty& addCheese(const Cheese&);
		//a modifier that removes any cheeses from the array that have a 0 weight.
		CheeseParty& removeCheese();

		std::ostream& display(std::ostream&) const;

		//an operator to check if the current object is empty.
		bool operator!() const {
			return m_pCheeses == nullptr;
		}
	};
	std::ostream& operator<<(std::ostream&, const CheeseParty&);
}
#endif //SDDS_CHEESEPARTY_H