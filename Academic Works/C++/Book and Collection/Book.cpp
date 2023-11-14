/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds{
	std::ostream& Book::print(std::ostream& os) const {
		if (m_title.c_str()[0] != '\0') {
			os << std::right << std::setw(56) << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages);
			os << " | ";
			os << std::left << std::setw(15) << "(" + std::to_string((double)m_numPages / m_numChapters) + ")";
		}
		else {
			os << "| Invalid book data";
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		return bk.print(os);

	}

	//Compare ratios when comparing Books in the collection
	bool Book::operator<(const Book& other) const {
		return ((double)m_numPages / m_numChapters) < ((double)other.m_numPages / other.m_numChapters);
	}

	bool Book::operator>(const Book& other) const {
		return ((double)m_numPages / m_numChapters) > ((double)other.m_numPages / other.m_numChapters);
	}
}