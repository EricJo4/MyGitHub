/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "CheeseShop.h"

namespace sdds {
	//copy constructor and copy assignment operator
	CheeseShop::CheeseShop(const CheeseShop& other) {
		if (!!other) {
			m_name = other.m_name;
			m_count = other.m_count;
			m_cheeses = new const Cheese * [m_count];

			for (size_t i = 0; i < m_count; i++) {
				m_cheeses[i] = new Cheese(other.m_cheeses[i]->getName(), other.m_cheeses[i]->getWeight(), other.m_cheeses[i]->getPrice(), other.m_cheeses[i]->getDesc());
			}
		}
		else {
			m_name = "No Name";
			m_count = 0;
			m_cheeses = nullptr;
		}
	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_count; i++) {
				delete m_cheeses[i];
				m_cheeses[i] = nullptr;
			}
			delete[] m_cheeses;
			m_cheeses = nullptr;
			if (!!other) {
				m_name = other.m_name;
				m_count = other.m_count;
				m_cheeses = new const Cheese*[other.m_count];

				for (size_t i = 0; i < other.m_count; i++) {
					m_cheeses[i] = new Cheese(other.m_cheeses[i]->getName(), other.m_cheeses[i]->getWeight(), other.m_cheeses[i]->getPrice(), other.m_cheeses[i]->getDesc());
				}
			}
			else {
				m_name = "No Name";
				m_count = 0;
				m_cheeses = nullptr;
			}
		}
		return *this;
	}

	//destructor
	CheeseShop::~CheeseShop() {
		for (size_t i = 0; i < m_count; i++) {
			delete m_cheeses[i];
			m_cheeses[i] = nullptr;
		}
		delete[] m_cheeses;
		m_cheeses = nullptr;
	}

	//move constructor and move assignment operator
	CheeseShop::CheeseShop(CheeseShop&& other) {
		*this = std::move(other);
	}
	CheeseShop& CheeseShop::operator=(CheeseShop&& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_count; i++) {
				delete m_cheeses[i];
			}
			delete[] m_cheeses;
			if (!!other) {
				m_name = other.m_name;
				other.m_name = "";
				m_cheeses = new const Cheese*[other.m_count];
				for (size_t i = 0; i < other.m_count; i++) {
					m_cheeses[i] = new Cheese(other.m_cheeses[i]->getName(), other.m_cheeses[i]->getWeight(), other.m_cheeses[i]->getPrice(), other.m_cheeses[i]->getDesc());
				}
				for (size_t i = 0; i < other.m_count; i++) {
					delete other.m_cheeses[i];
				}
				delete[] other.m_cheeses;
				other.m_cheeses = nullptr;
				m_count = other.m_count;
				other.m_count = 0;
			}
			else {
				m_name = "";
				m_count = 0;
				m_cheeses = nullptr;
			}
		}
			return *this;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& other) {
		//A temporary array of pointers to resize the current array object.
		const Cheese** newCheeses = new const Cheese*[m_count + 1];

		for (size_t i = 0; i < m_count; i++) {
			newCheeses[i] = new Cheese(m_cheeses[i]->getName(), m_cheeses[i]->getWeight(), m_cheeses[i]->getPrice(), m_cheeses[i]->getDesc());
		}

		for (size_t i = 0; i < m_count; i++) {
			delete m_cheeses[i];
		}
		delete[] m_cheeses;
		//insert a copy of the argument into the last position of the temp array object.
		newCheeses[m_count] = new Cheese(other.getName(), other.getWeight(), other.getPrice(), other.getDesc());
		++m_count;

		//copy the temp array object to the current array object
		m_cheeses = new const Cheese*[m_count];
		for (size_t i = 0; i < m_count; i++) {
			m_cheeses[i] = new Cheese(newCheeses[i]->getName(), newCheeses[i]->getWeight(), newCheeses[i]->getPrice(), newCheeses[i]->getDesc());
		}

		//delete the temp array
		for (size_t i = 0; i < m_count; i++) {
			delete newCheeses[i];
		}
		delete[] newCheeses;

		return *this;
	}

	std::ostream& CheeseShop::display(std::ostream& os) const {
		if (m_cheeses == nullptr) {
			os << "--------------------------" << std::endl;
			os << m_name << std::endl;
			os << "--------------------------" << std::endl;
			os << "This shop is out of cheese!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else {
			os << "--------------------------" << std::endl;
			os << m_name << std::endl;
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < m_count; i++) {
				os << *m_cheeses[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop) {
		return cheeseShop.display(os);
	}
}