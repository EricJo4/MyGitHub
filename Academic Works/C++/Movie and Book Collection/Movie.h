/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 15, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds {
	class Movie {
		std::string m_title;
		size_t m_yearReleased;
		std::string m_desc;
	public:
		Movie() :m_title(""), m_yearReleased(0), m_desc("") {}

		//Rule of 5
		Movie(const Movie& other) {
			*this = other;
		}
		Movie& operator=(const Movie& other) {
			if (this != &other) {
				if (!!other) {
					m_title = other.m_title;
					m_yearReleased = other.m_yearReleased;
					m_desc = other.m_desc;
				}
				else {
					m_title = "";
					m_yearReleased = 0;
					m_desc = "";
				}
			}
			return *this;
		}
		Movie(Movie&& other) {
			*this = std::move(other);
		}
		Movie& operator=(Movie&& other) {
			if (this != &other) {
				if (!!other) {
					m_title = other.m_title;
					other.m_title = "";
					m_yearReleased = other.m_yearReleased;
					other.m_yearReleased = 0;
					m_desc = other.m_desc;
					other.m_desc = "";
				}
				else {
					m_title = "";
					m_yearReleased = 0;
					m_desc = "";
				}
			}
			return *this;
		}

		~Movie() {}

		//Operator to check empty state
		bool operator!() const {
			return m_title == "";
		}

		const std::string& title() const {
			return m_title;
		}

		Movie(const std::string& strMovie);

		//A template to check whether the movie object includes any bad words.
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		std::ostream& display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const Movie&);
}
#endif //SDDS_MOVIE_H