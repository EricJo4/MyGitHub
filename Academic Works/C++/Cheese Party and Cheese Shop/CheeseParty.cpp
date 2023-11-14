/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "CheeseParty.h"

namespace sdds {
	//copy constructor and copy assignment operator
	CheeseParty::CheeseParty(const CheeseParty& other) {
		*this = other;
	}
	CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
		if (this != &other) {
			delete[] m_pCheeses;
			if (!!other) {
				m_pCount = other.m_pCount;
				m_pCheeses = new const Cheese*[other.m_pCount];
				for (size_t i = 0; i < other.m_pCount; i++) {
					m_pCheeses[i] = other.m_pCheeses[i];
				}
			}
			else {
				m_pCount = 0;
				m_pCheeses = nullptr;
			}
		}
		return *this;
	}

	//destructor
	CheeseParty::~CheeseParty() {
		delete[] m_pCheeses;
		m_pCheeses = nullptr;
	}

	//move constructor and move assignment operator
	CheeseParty::CheeseParty(CheeseParty&& other) {
		*this = std::move(other);
	}
	CheeseParty& CheeseParty::operator=(CheeseParty&& other) {
		if (this != &other) {
			delete[] m_pCheeses;
			if (!!other) {
				m_pCheeses = new const Cheese*[other.m_pCount];
				for (size_t i = 0; i < other.m_pCount; i++) {
					m_pCheeses[i] = other.m_pCheeses[i];
				}
				delete[] other.m_pCheeses;
				other.m_pCheeses = nullptr;

				m_pCount = other.m_pCount;
				other.m_pCount = 0;
			}
			else {
				m_pCount = 0;
				m_pCheeses = nullptr;
			}
		}
		return *this;
	}

	CheeseParty& CheeseParty::addCheese(const Cheese& other) {
		bool found = false;
		for (size_t i = 0; i < m_pCount; i++) {
			if (m_pCheeses[i] == &other) {
				found = true;
			}
		}

		if (!found) {
			//A temporary array of pointers to resize the current array object.
			const Cheese** newCheeses = new const Cheese * [m_pCount + 1];

			for (size_t i = 0; i < m_pCount; i++) {
				newCheeses[i] = m_pCheeses[i];
			}
			//insert a copy of the argument into the last position of the temp array object.
			newCheeses[m_pCount++] = &other;
			//copy the temp array object to the current array object

			delete[] m_pCheeses;
			m_pCheeses = newCheeses;
		}
		return *this;
	}

	CheeseParty& CheeseParty::removeCheese() {
		for (size_t i = 0; i < m_pCount; i++) {
			if (m_pCheeses[i]->getWeight() == 0) {
				m_pCheeses[i] = nullptr;
			}
		}
		return *this;
	}

	std::ostream& CheeseParty::display(std::ostream& os) const {
		if (m_pCheeses == nullptr) {
			os << "--------------------------" << std::endl;
			os << "Cheese Party" << std::endl;
			os << "--------------------------" << std::endl;
			os << "This party is just getting started!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else {
			os << "--------------------------" << std::endl;
			os << "Cheese Party" << std::endl;
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < m_pCount; i++) {
				if (m_pCheeses[i] != nullptr) {
					os << *m_pCheeses[i];
				}
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty) {
		return cheeseParty.display(os);
	}
}