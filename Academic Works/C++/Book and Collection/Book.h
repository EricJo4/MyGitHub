/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book() :m_title(""), m_numChapters(0), m_numPages(0) {}
		Book(const std::string& title, unsigned nChapters, unsigned nPages) :m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

		//For setSmallestItem() and setLargestItem() in Collection module.
		bool operator<(const Book& other) const;
		bool operator>(const Book& other) const;

		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif //SDDS_BOOK_H