/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 15, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Movie.h"

namespace sdds {
	Movie::Movie(const std::string& strMovie) {
		size_t commaPos1 = strMovie.find(",");
		size_t commaPos2 = strMovie.find(",", commaPos1 + 1);

		m_title = strMovie.substr(0, commaPos1);
		m_yearReleased = std::stoul(strMovie.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1));
		m_desc = strMovie.substr(commaPos2 + 1);

		size_t titleStart = m_title.find_first_not_of(" \t");
		size_t titleEnd = m_title.find_last_not_of(" \t");
		size_t descStart = m_desc.find_first_not_of(" \t");
		size_t descEnd = m_desc.find_last_not_of(" \t");
		if (titleStart != std::string::npos && titleEnd != std::string::npos) {
			m_title = m_title.substr(titleStart, titleEnd - titleStart + 1);
		}
		if (descStart != std::string::npos && descEnd != std::string::npos) {
			m_desc = m_desc.substr(descStart, descEnd - descStart + 1);
		}
	}

	std::ostream& Movie::display(std::ostream& os) const {
		os << std::setw(40) << m_title << " | " << std::setw(4) << m_yearReleased << " | " << m_desc;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		return movie.display(os);
	}
}