/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

//inherits LblShape
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle() :LblShape(), m_width(0), m_height(0) {};
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& in);
		void draw(std::ostream& os)const;
	};
}

#endif //SDDS_RECTANGLE_H