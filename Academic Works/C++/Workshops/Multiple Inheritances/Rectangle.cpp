/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <cstring>
#include "Rectangle.h"


namespace sdds {
	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label) {
		if (height < 3 || width < int(strlen(label) + 2)) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}

	void Rectangle::getSpecs(std::istream& in) {
		LblShape::getSpecs(in); //Read user input and assign it to m_label
		in >> m_width;
		in.ignore(1, ',');
		in >> m_height;
		in.ignore(100, '\n');
	}
	void Rectangle::draw(std::ostream& os)const {
		if (m_width != 0 && m_height != 0) { //Only when the object is valid
			os << "+";
			for (int i = 0; i < int(m_width - 2); i++) {
				os << "-";
			}
			os << "+" << std::endl;


			os << "|" << label();
			for (int i = 0; i < int((m_width - 2) - strlen(label())); i++) {
				os << " ";
			}
			os << "|" << std::endl;

			for (int i = 0; i < int(m_height - 3); i++) {
				os << "|";
				for (int j = 0; j < int(m_width - 2); j++) {
					os << " ";
				}
				os << "|" << std::endl;
			}
			os << "+";
			for (int i = 0; i < int(m_width - 2); i++) {
				os << "-";
			}
			os << "+";
		}
	}
}