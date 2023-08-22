/***********************************************************************
// OOP244 PublicationSelector Module
// File	PublicationSelector.cpp
// Version 1.0
// Date August 5 2023
// Author Eric Jo
// Description Milestone 5
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "PublicationSelector.h"
#include "Utils.h"

namespace sdds {
	PublicationSelector::PublicationSelector(const char* title, int size)
		: m_title(nullptr), m_publications(nullptr), m_size(size), m_noOfMatches(0) {
		m_title = new char[strLen(title) + 1];
		strCpy(const_cast<char*>(m_title), title);
		m_publications = new const Publication * [m_size] {};
	}
	PublicationSelector::~PublicationSelector() {
		delete[] m_title;
		delete[] m_publications;
	}
	PublicationSelector& PublicationSelector::operator+=(const Publication* pub) {
		if (m_noOfMatches < m_size) {
			m_publications[m_noOfMatches++] = pub;
		}
		return *this;
	}

	PublicationSelector::operator bool() const {
		return m_noOfMatches > 0;
	}

	void PublicationSelector::sort() {

		const Publication* temp{};
		for (int i = 0; i < m_noOfMatches - 1; i++) {
			for (int j = 0; j < m_noOfMatches - i - 1; j++) {
				if (m_publications[j]->checkoutDate() > m_publications[j + 1]->checkoutDate()) {
					temp = m_publications[j];
					m_publications[j] = m_publications[j + 1];
					m_publications[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < m_noOfMatches - 1; i++) {
			for (int j = 0; j < m_noOfMatches - i - 1; j++) {
				if (strCmp((const char*)*m_publications[j], (const char*)*m_publications[j + 1]) > 0) {
					temp = m_publications[j];
					m_publications[j] = m_publications[j + 1];
					m_publications[j + 1] = temp;
				}
			}
		}
	}

	int PublicationSelector::run() const {
		int selection = 0;
		if (*this) {
			std::cout << "Select one of the following found matches:" << std::endl;
			std::cout << " Row  |LocID | Title                          |Mem ID | Date       | Author          |" << std::endl;
			std::cout << "------+------+--------------------------------+-------+------------+-----------------|" << std::endl;
			for (int i = 0; i < m_noOfMatches; i++) {
				std::cout << std::setw(4) << std::right << i + 1 << "- ";
				std::cout << *m_publications[i] << std::endl;
			}
			std::cout << "> X (to Exit)" << std::endl;
			std::cout << "> Row Number(select publication)" << std::endl;
			std::cout << "> ";
			int input;
			std::cin >> input;
			if (input >= 0 && input <= m_noOfMatches) {
				selection = input == 0 ? 0 : m_publications[input - 1]->getRef();
			}
			else {
				std::cout << "Invalid selection, try again: ";
				std::cin.clear();
				clearInputBuffer(std::cin);
				selection = run();
			}
		}
		return selection;
	}

	PublicationSelector& PublicationSelector::operator<<(const Publication* pub) {
		if (m_noOfMatches < m_size) {
			m_publications[m_noOfMatches++] = pub;
		}
		return *this;
	}
}