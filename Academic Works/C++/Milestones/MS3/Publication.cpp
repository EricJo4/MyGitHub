/***********************************************************************
// OOP244 Publication Module
// File	Publication.cpp
// Version 1.0
// Date July 28 2023
// Author Eric Jo
// Description Milestone 3
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Utils.h"


namespace sdds {
	//clear() is at the bottom of the file
	Publication::Publication(){
		m_title = nullptr;
		m_shelfld[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}
	
	Publication::~Publication() {
		clear();
	}

	//Rule of Three
	//Copy constructor. copy() is at the bottom of the file
	Publication::Publication(const Publication& other) : Publication() {
		copy(other);
	}

	//Copy assignment operator. clear() and copy() are at the bottom of the file
	Publication& Publication::operator=(const Publication& other) {
		if (this != &other) {
			clear();
			copy(other);
		}
		return *this;
	}

	//Inherited virtual functions

	std::ostream& Publication::write(std::ostream& os)const {
		if (m_title != nullptr &&  m_shelfld[0] != 0 && m_date.errCode() == 0) {
			
			if (conIO(os)) {
				os << "| ";
				os.width(SDDS_SHELF_ID_LEN);
				os << m_shelfld << " | ";
				os.width(SDDS_TITLE_WIDTH);
				os.fill('.');
				os << std::left << m_title << " | ";
				if (m_membership == 0) {
					os << " N/A  | ";
				}
				else {
					os.width(5);
					os << m_membership << " | ";
				}
				os << m_date << " |";
			}
			else {
				os << type() << "\t" << m_libRef << "\t" << m_shelfld << "\t"
					<< m_title << "\t" << m_membership << "\t" << m_date;
			}
		}
		return os;
	}

	std::istream& Publication::read(std::istream& is) {
		clear();

		if (conIO(is)) {
			std::cout << "Shelf No: ";
			is >> m_shelfld;
			if (strLen(m_shelfld) != SDDS_SHELF_ID_LEN) {
				is.setstate(std::ios::failbit);
			}

			std::cout << "Title: ";
			if (strLen(m_shelfld) != SDDS_SHELF_ID_LEN) {
				is.setstate(std::ios::failbit);
			}
			else {
				is.ignore();
				char buffer[SDDS_TITLE_WIDTH + 1];
				is.getline(buffer, SDDS_TITLE_WIDTH + 1, '\n');
				m_title = new char[strLen(buffer) + 1];
				strCpy(m_title, buffer);
			}

			std::cout << "Date: ";
			if (strLen(m_shelfld) != SDDS_SHELF_ID_LEN) {
				is.setstate(std::ios::failbit);
			}
			else {
				is >> m_date;
			}
		}
		else {
			is >> m_libRef;
			is.ignore();
			is.getline(m_shelfld, SDDS_SHELF_ID_LEN + 1, '\t');
			char buffer[SDDS_TITLE_WIDTH + 1]{};
			is.getline(buffer, SDDS_TITLE_WIDTH + 1, '\t');
			m_title = new char[strLen(buffer) + 1];
			strCpy(m_title, buffer);
			is >> m_membership >> m_date;
		}

		if (!is || !m_date) {
			is.setstate(std::ios::failbit);
		}

		return is;
	}

	//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
	bool Publication::conIO(std::ios& io) const {
		return (&io == &std::cout || &io == &std::cin);
	}

	Publication::operator bool() const {
		return (m_title && m_title[0] != '\0' && m_shelfld[0] != '\0');
	}

	//Methods

	void Publication::set(int member_id) {
		if (member_id == 0 || (member_id > 10000 && member_id < 99999)) {
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	//Reset the date so the date becomes today.
	void Publication::resetDate() {
		m_date = Date();
	}

	char Publication::type()const {
		const char* published = "P";
		return *published;
	}

	//if the book is on loan, m_membership is not 0
	bool Publication::onLoan()const {
		return (m_membership != 0);
	}

	//Return the date on which the book was borrowed by the member. If it was not borrowed, return today's date
	Date Publication::checkoutDate()const {
		return m_date;
	}

	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title);
	}

	Publication::operator const char* ()const {
		return m_title;
	}

	int Publication::getRef()const {
		return m_libRef;
	}

	//Empty member variables
	void Publication::clear() {
		delete[] m_title;
		m_title = nullptr;
		m_shelfld[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}

	//is used to Copy constructor and Copy assignment operator
	void Publication::copy(const Publication& other) {
		if (other.m_title) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}

		strCpy(m_shelfld, other.m_shelfld);
		m_membership = other.m_membership;
		m_libRef = other.m_libRef;
		m_date = other.m_date;
	}
}