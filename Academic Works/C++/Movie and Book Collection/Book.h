/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 11, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;

	public:
		Book() :m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_desc("") {}
		Book(const std::string& strBook);

		Book(const Book& other) {
			*this = other;
		}
		Book& operator=(const Book& other) {
			if (this != &other) {
				if (!!other) {
					m_author = other.m_author;
					m_title = other.m_title;
					m_country = other.m_country;
					m_year = other.m_year;
					m_price = other.m_price;
					m_desc = other.m_desc;
				}
				else {
					m_author = "";
					m_title = "";
					m_country = "";
					m_year = 0;
					m_price = 0.0;
					m_desc = "";
				}
			}
			return *this;
		}
		Book(Book&& other) {
			*this = std::move(other);
		}
		Book& operator=(Book&& other) {
			if (this != &other) {
				if (!!other) {
					m_author = other.m_author;
					other.m_author = "";
					m_title = other.m_title;
					other.m_title = "";
					m_country = other.m_country;
					other.m_country = "";
					m_year = other.m_year;
					other.m_year = 0;
					m_price = other.m_price;
					other.m_price = 0.0;
					m_desc = other.m_desc;
					other.m_desc = "";
				}
				else {
					m_author = "";
					m_title = "";
					m_country = "";
					m_year = 0;
					m_price = 0.0;
					m_desc = "";
				}
			}
			return *this;
		}

		~Book() {}

		bool operator!() const {
			return m_author == "";
		}

		const std::string& title() const {
			return m_title;
		}
		const std::string& country() const {
			return m_country;
		}
		const size_t& year() const {
			return m_year;
		}
		double& price() {
			return m_price;
		}

		std::ostream& display(std::ostream&) const;

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}

	};
	std::ostream& operator<<(std::ostream&, const Book&);
}





#endif //SDDS_BOOK_H
