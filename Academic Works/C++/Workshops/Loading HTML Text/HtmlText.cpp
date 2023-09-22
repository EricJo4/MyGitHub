/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 30 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include "HtmlText.h"
#include "cstring.h"

namespace sdds {
	//Shadowing getFileLength()const
	int HtmlText::getFileLength()const {
		int len = 0;
		std::ifstream fin(getFileName());
		while (fin) {
			fin.get();
			len += !!fin;
		}
		return len;
	}
	//constructor which calls constructor of the base class
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename) {
		if (title != nullptr) {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	//Rule of Three
	HtmlText::HtmlText(const HtmlText& other): Text(other), m_title(nullptr) {
		*this = other;
	}
	HtmlText& HtmlText::operator=(const HtmlText& other) {
			Text::operator=(other);
			if (this == &other) {
				return *this;
			}
			if (other.m_title != nullptr) {
				delete[] m_title;
				m_title = new char[strLen(other.m_title) + 1];
				strCpy(m_title, other.m_title);
			}
		return *this;
	}
	HtmlText::~HtmlText() {
		delete[] m_title;
	}


	void HtmlText::write(std::ostream& os)const {
		bool multipleSpaces = false;
		os << "<html><head><title>";
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		os << "<h1>";
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</h1>\n";
		for (int i = 0; i < getFileLength(); i++) {
			switch ((*this)[i]) {
			case ' ':
				if (multipleSpaces) {
					os << "&nbsp;";
				}
				else {
					multipleSpaces = true;
					os << ' ';
				}
				break;
			case '<':
				os << "&lt;";
				multipleSpaces = false;
				break;
			case '>':
				os << "&gt;";
				multipleSpaces = false;
				break;
			case '\n':
				os << "<br />\n";
				multipleSpaces = false;
				break;
			default:
				os << (*this)[i];
				multipleSpaces = false;

			}
		}
		os << "</body>\n</html>";
	}
}