/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Shape.h"

namespace sdds {
	std::istream& operator >> (std::istream& in, Shape& shape){
		shape.getSpecs(in); //abstract
		return in;
	}
	std::ostream& operator << (std::ostream& os, const Shape& shape) {
		shape.draw(os); //abstract
		return os;
	}
}