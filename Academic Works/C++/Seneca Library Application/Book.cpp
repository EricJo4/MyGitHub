/***********************************************************************
// OOP244 Book Module
// File	Book.cpp
// Version 1.0
// Date August 1 2023
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
#include "Book.h"
#include "Utils.h"

namespace sdds {
	//Rule of Three
	Book::Book(const Book& other) {
		*this = other;
	}
	Book& Book::operator=(const Book& other) {
		Publication::operator=(other);
		if (this != &other) {
			if (other.m_author != nullptr) {
				delete[]m_author;
				m_author = new char[strLen(other.m_author) + 1];
				strCpy(m_author, other.m_author);
			}
		}
		return *this;
		
	}
	Book::~Book() {
		delete[] m_author;
	}

	//return character 'B'
	char Book::type()const {
		return 'B';
	}

	//Display publication and book
	std::ostream& Book::write(std::ostream& os)const {
		Publication::write(os);
		if (m_author != nullptr) {

			if (conIO(os)) {
				os << " ";
				if (strLen(m_author) <= SDDS_AUTHOR_WIDTH) {
					os.width(SDDS_AUTHOR_WIDTH);
					os << std::left << m_author << " |";
				}
				else {
					for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
						os << std::left << m_author[i];
					}
					os << " |";
				}
			}
			else {
				os << '\t' << m_author;
			}
		}
		return os;
	}

	//Read author name
	std::istream& Book::read(std::istream& in) {
		char author[256];
		Publication::read(in);

			
			if (conIO(in)) {
				std::cout << "Author: ";
				if (!in || !checkoutDate()) {
					in.setstate(std::ios::failbit);
					return in;
				}
				in.ignore();
				in.get(author, 256);

			}
			else {
				in.ignore();
				in.get(author, 256);
			}
			if (!in.fail()) { //copy the character value extracted from input buffer to m_author which is dynamically allocated
				m_author = new char[strLen(author) + 1];
				strCpy(m_author, author);
				m_author[strLen(author)] = '\0';
			}
		
		
		return in;

	}
	
	//Set member id and reset the date
	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

	//all member variables are not empty
	Book::operator bool() const {
		return (Publication::operator bool() && m_author);
	}
}