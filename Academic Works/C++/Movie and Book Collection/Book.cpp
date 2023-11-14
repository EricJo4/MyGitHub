/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 11, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <string>
#include <iomanip>
#include "Book.h"


namespace sdds {
	Book::Book(const std::string& strBook) {
		size_t commaPos1 = strBook.find(',');
		size_t commaPos2 = strBook.find(',', commaPos1 + 1);
		size_t commaPos3 = strBook.find(',', commaPos2 + 1);
		size_t commaPos4 = strBook.find(',', commaPos3 + 1);
		size_t commaPos5 = strBook.find(',', commaPos4 + 1);

		m_author = strBook.substr(0, commaPos1);
		m_title = strBook.substr(commaPos1 + 1, commaPos2 - commaPos1 -1);
		m_country = strBook.substr(commaPos2 + 1, commaPos3 - commaPos2 - 1);
		m_price = std::stod(strBook.substr(commaPos3 + 1, commaPos4 - commaPos3 - 1));
		m_year = std::stoul(strBook.substr(commaPos4 + 1, commaPos5 - commaPos4 - 1));
		m_desc = strBook.substr(commaPos5 + 1);

		//Remove leading and trailing spaces
		size_t authorStart = m_author.find_first_not_of(" \t");
		size_t authorEnd = m_author.find_last_not_of(" \t");
		size_t titleStart = m_title.find_first_not_of(" \t");
		size_t titleEnd = m_title.find_last_not_of(" \t");
		size_t countryStart = m_country.find_first_not_of(" \t");
		size_t countryEnd = m_country.find_last_not_of(" \t");
		size_t descStart = m_desc.find_first_not_of(" \t");
		size_t descEnd = m_desc.find_last_not_of(" \t");
		if (authorStart != std::string::npos && authorEnd != std::string::npos) {
			m_author = m_author.substr(authorStart, authorEnd - authorStart + 1);
		}
		if (titleStart != std::string::npos && titleEnd != std::string::npos) {
			m_title= m_title.substr(titleStart, titleEnd - titleStart + 1);
		}
		if (countryStart != std::string::npos && countryEnd != std::string::npos) {
			m_country = m_country.substr(countryStart, countryEnd - countryStart + 1);
		}
		if (descStart != std::string::npos && descEnd != std::string::npos) {
			m_desc = m_desc.substr(descStart, descEnd - descStart + 1);
		}
	}

	std::ostream& Book::display(std::ostream& os) const {
		os << std::setw(20) << std::right << m_author << " | "
			<< std::setw(22) << m_title << " | "
			<< std::setw(5) << m_country << " | "
			<< std::setw(4) << m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | "
			<< m_desc;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		return book.display(os);
	}
}