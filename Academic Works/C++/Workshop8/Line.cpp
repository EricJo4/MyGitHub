/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Line.h"

namespace sdds {

	void Line::getSpecs(std::istream& in) {
		LblShape::getSpecs(in); //Read user input and assign it to m_label
		in >> m_length;
		in.ignore(); //ignore newline character
		
	}
	void Line::draw(std::ostream& os)const {
		if (m_length > 0 && LblShape::label() != nullptr) { //m_label != nullptr
			os << label() << std::endl;
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
}